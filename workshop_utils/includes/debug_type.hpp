#ifndef WORKSHOP_UTILS_H_
#define WORKSHOP_UTILS_H_

#include <iostream>
#include <string>
#include <type_traits>

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
