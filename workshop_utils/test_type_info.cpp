#include <gmock/gmock.h>

#include <boost/core/demangle.hpp>
#include <boost/test/unit_test.hpp>

#include "debug_type.hpp"

BOOST_AUTO_TEST_SUITE(TypeInfoShould)

BOOST_AUTO_TEST_CASE(presentProperType) {
  std::cout << typeid(std::string &).name() << std::endl;
  std::cout << boost::core::demangle(typeid(std::string &).name()) << std::endl;
}

BOOST_AUTO_TEST_CASE(presentProperTypeByWrapper) {
  std::cout << getTypeString(std::string{}) << std::endl;
}

BOOST_AUTO_TEST_CASE(printTypeInSomeWay) { printPrettyType<std::string>(); }

#if 0
BOOST_AUTO_TEST_CASE(presentTypeInCompilerError) { typeInError<std::string>(); }
#endif

BOOST_AUTO_TEST_SUITE_END();
