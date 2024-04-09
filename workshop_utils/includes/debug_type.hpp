#ifndef WORKSHOP_UTILS_H_
#define WORKSHOP_UTILS_H_

#include <iostream>
#include <string>
#include <type_traits>

#include <boost/core/demangle.hpp>

template <typename Type> std::string getTypeString() {
  return boost::core::demangle(typeid(Type).name());
}

template <typename Type> std::string getTypeStringEx() {
  std::string ref = (std::is_rvalue_reference_v<Type>
                         ? " &&"
                         : (std::is_lvalue_reference_v<Type> ? " &" : ""));
  return (std::is_const_v<std::remove_reference_t<Type>> ? "const " : "") +
         boost::core::demangle(typeid(Type).name()) + ref;
}

template <typename Type> std::string getTypeString(Type &&obj) {
  return getTypeString<decltype(obj)>();
}

template <typename Type> void printPrettyType() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename Type> void printPrettyType(Type &&) {
  printPrettyType<Type>();
}

template <typename Type> struct TypeError {};

template <typename Type> void typeInError() {
  typename TypeError<Type>::type a{};
  (void)a;
}

template <typename Type> void typeInError(Type &&) { typeInError<Type>(); }

#endif // WORKSHOP_UTILS_H_
