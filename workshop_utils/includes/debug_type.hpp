#ifndef WORKSHOP_UTILS_H_
#define WORKSHOP_UTILS_H_

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

#ifdef USE_BOOST_LIBRARIES
#include <boost/core/demangle.hpp>

template <typename Type>
std::string getTypeString() {
  return boost::core::demangle(typeid(Type).name());
}

template <typename Type>
std::string getTypeStringEx() {
  std::string ref = (std::is_rvalue_reference_v<Type> ? " &&" : (std::is_lvalue_reference_v<Type> ? " &" : ""));
  return (std::is_const_v<std::remove_reference_t<Type>> ? "const " : "") + boost::core::demangle(typeid(Type).name())
         + ref;
}

template <typename Type>
std::string getTypeString(Type&& obj) {
  return getTypeString<decltype(obj)>();
}

template <typename Type>
std::string getTypeStringEx(Type&& obj) {
  return getTypeStringEx<decltype(obj)>();
}
#endif

template <typename Type>
consteval std::string_view getPrettyType() {
#ifndef _MSC_VER
  std::string_view ret = __PRETTY_FUNCTION__;
  std::string_view beginPattern = "Type = ";
  std::string_view endPattern = ";";
  std::size_t it = ret.find(beginPattern);
  if (it != ret.npos) {
    it += beginPattern.size();
    std::size_t endPos = ret.find(endPattern, it);
    if (endPos == ret.npos) {
      endPos = ret.size();
    }
    ret = ret.substr(it, endPos - it);
  }
  return ret;
#else
  return __FUNCTION__;
#endif
}

template <typename Type>
void printPrettyType() {
  std::cout << getPrettyType<Type>() << std::endl;
}

template <typename Type>
void printPrettyType(Type&&) {
  printPrettyType<Type>();
}

template <typename Type>
struct TypeError {};

template <typename Type>
void typeInError() {
  typename TypeError<Type>::type a{};
  (void)a;
}

template <typename Type>
void typeInError(Type&&) {
  typeInError<Type>();
}

#endif // WORKSHOP_UTILS_H_
