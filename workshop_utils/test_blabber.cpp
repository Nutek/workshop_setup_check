#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "blabber.h"

using namespace ::testing;

void dummyPrinter(const Blabber &, const std::string &) {}

struct PrinterMock {
  MOCK_METHOD1(calledWith, void(const std::string &));

  auto get() {
    return [this](const Blabber &, const std::string &tag) { calledWith(tag); };
  }
};

TEST(BlabberTest, keepGivenDescription) {
  const std::string expected_string = "Specific string";
  Blabber b{expected_string, dummyPrinter};

  EXPECT_EQ(expected_string, b.description());
}

TEST(BlabberTest, keepGivenDescriptionWhenCopyConstruct) {
  const std::string expected_string = "Second specific string";
  Blabber b{expected_string, dummyPrinter};

  Blabber b2{b};

  EXPECT_EQ(expected_string, b.description());
  EXPECT_EQ(expected_string, b2.description());
}

TEST(BlabberTest, moveGivenDescriptionWhenMoveConstruct) {
  const std::string expected_string = "Third specific string";
  Blabber b{expected_string, dummyPrinter};

  Blabber b2{std::move(b)};

  EXPECT_EQ(std::string{}, b.description());
  EXPECT_EQ(expected_string, b2.description());
}

TEST(BlabberTest, keepGivenDescriptionWhenCopyAssign) {
  const std::string expected_string = "Fourth specific string";
  Blabber b{expected_string, dummyPrinter};
  Blabber b2{"Default value", dummyPrinter};

  EXPECT_NE(expected_string, b2.description());

  b2 = b;

  EXPECT_EQ(expected_string, b.description());
  EXPECT_EQ(expected_string, b2.description());
}

TEST(BlabberTest, moveGivenDescriptionWhenMoveAssign) {
  const std::string expected_string = "Fifth specific string";
  Blabber b{expected_string, dummyPrinter};
  Blabber b2{"Default value", dummyPrinter};

  EXPECT_NE(expected_string, b2.description());

  b2 = std::move(b);

  EXPECT_EQ(std::string{}, b.description());
  EXPECT_EQ(expected_string, b2.description());
}

TEST(BlabberTest, useProperTagsForNormalLifeCycle) {
  PrinterMock mock;

  EXPECT_CALL(mock, calledWith("constructor"));

  {
    Blabber b{"Something", mock.get()};

    testing::Mock::VerifyAndClearExpectations(&mock);

    EXPECT_CALL(mock, calledWith("destructor"));
  }
}

TEST(BlabberTest, useProperTagsForMoves) {
  PrinterMock mock;

  EXPECT_CALL(mock, calledWith("constructor"));
  Blabber b{"Something", mock.get()};
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith(StartsWith("move constructor from")));
  Blabber b2{std::move(b)};
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith(testing::StartsWith("move assign from")));
  b2 = std::move(b);
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith("destructor")).Times(2);
}

TEST(BlabberTest, useProperTagsForCopies) {
  PrinterMock mock;

  EXPECT_CALL(mock, calledWith("constructor"));
  Blabber b{"Something", mock.get()};
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith(StartsWith("copy constructor from")));
  Blabber b2{b};
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith(testing::StartsWith("copy assign from")));
  b2 = b;
  testing::Mock::VerifyAndClearExpectations(&mock);

  EXPECT_CALL(mock, calledWith("destructor")).Times(2);
}
