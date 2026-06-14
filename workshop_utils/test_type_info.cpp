#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "debug_type.hpp"

TEST(TypeInfoShould, presentProperType) {
  std::cout << typeid(std::string &).name() << std::endl;
}

TEST(TypeInfoShould, printTypeInSomeWay) { printPrettyType<std::string>(); }

#if 0
TEST(TypeInfoShould, presentTypeInCompilerError)
{
  typeInError<std::string>();
}
#endif
