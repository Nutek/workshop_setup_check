#include <gmock/gmock.h>

#include <boost/test/unit_test.hpp>

#include "blabber.h"

void dummyPrinter(const Blabber &, const std::string &) {}

using namespace testing;

struct PrinterMock {
  MOCK_METHOD1(calledWith, void(const std::string &));

  auto get() {
    return [this](const Blabber &, const std::string &tag) { calledWith(tag); };
  }
};

BOOST_AUTO_TEST_SUITE(BlabberTest)

BOOST_AUTO_TEST_CASE(keepGivenDescription) {
  const std::string expected_string = "Specific string";
  Blabber b{expected_string, dummyPrinter};

  BOOST_TEST(expected_string == b.description());
}

BOOST_AUTO_TEST_CASE(keepGivenDescriptionWhenCopyConstruct) {
  const std::string expected_string = "Second specific string";
  Blabber b{expected_string, dummyPrinter};

  Blabber b2{b};

  BOOST_TEST(expected_string == b.description());
  BOOST_TEST(expected_string == b2.description());
}

BOOST_AUTO_TEST_CASE(moveGivenDescriptionWhenMoveConstruct) {
  const std::string expected_string = "Third specific string";
  Blabber b{expected_string, dummyPrinter};

  Blabber b2{std::move(b)};

  BOOST_TEST(std::string{} == b.description());
  BOOST_TEST(expected_string == b2.description());
}

BOOST_AUTO_TEST_CASE(keepGivenDescriptionWhenCopyAssign) {
  const std::string expected_string = "Fourth specific string";
  Blabber b{expected_string, dummyPrinter};
  Blabber b2{"Default value", dummyPrinter};

  BOOST_TEST(expected_string != b2.description());

  b2 = b;

  BOOST_TEST(expected_string == b.description());
  BOOST_TEST(expected_string == b2.description());
}

BOOST_AUTO_TEST_CASE(moveGivenDescriptionWhenMoveAssign) {
  const std::string expected_string = "Fifth specific string";
  Blabber b{expected_string, dummyPrinter};
  Blabber b2{"Default value", dummyPrinter};

  BOOST_TEST(expected_string != b2.description());

  b2 = std::move(b);

  BOOST_TEST(std::string{} == b.description());
  BOOST_TEST(expected_string == b2.description());
}

BOOST_AUTO_TEST_CASE(useProperTagsForNormalLifeCycle) {
  PrinterMock mock;

  EXPECT_CALL(mock, calledWith("constructor"));

  {
    Blabber b{"Something", mock.get()};

    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith("destructor"));
  }

  BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));
}

BOOST_AUTO_TEST_CASE(useProperTagsForMoves) {
  PrinterMock mock;
  {
    EXPECT_CALL(mock, calledWith("constructor"));
    Blabber b{"Something", mock.get()};
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith(StartsWith("move constructor from")));
    Blabber b2{std::move(b)};
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith(testing::StartsWith("move assign from")));
    b2 = std::move(b);
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith("destructor")).Times(2);
  }
  BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));
}

BOOST_AUTO_TEST_CASE(useProperTagsForCopies) {
  PrinterMock mock;
  {
    EXPECT_CALL(mock, calledWith("constructor"));
    Blabber b{"Something", mock.get()};
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith(StartsWith("copy constructor from")));
    Blabber b2{b};
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith(testing::StartsWith("copy assign from")));
    b2 = b;
    BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));

    EXPECT_CALL(mock, calledWith("destructor")).Times(2);
  }
  BOOST_TEST(Mock::VerifyAndClearExpectations(&mock));
}

BOOST_AUTO_TEST_SUITE_END()
