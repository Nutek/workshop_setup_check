#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/core/demangle.hpp>

#include "debug_type.hpp"

TEST(TypeInfoShould, presentProperType) {
  std::cout << typeid(std::string &).name() << std::endl;
  std::cout << boost::core::demangle(typeid(std::string &).name()) << std::endl;
}

TEST(TypeInfoShould, presentProperTypeByWrapper) {
  std::cout << getTypeString(std::string{}) << std::endl;
}

TEST(TypeInfoShould, printTypeInSomeWay) { printPrettyType<std::string>(); }

#if 0
TEST(TypeInfoShould, presentTypeInCompilerError)
{
  typeInError<std::string>();
}
#endif
