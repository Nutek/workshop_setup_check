#ifndef EXCEPT_BLABBER_HPP_
#define EXCEPT_BLABBER_HPP_

#include "blabber.h"

struct ObjectExcept {
  ObjectExcept() noexcept(false) = default;
  ObjectExcept(const ObjectExcept &) noexcept(false) = default;
  ObjectExcept(ObjectExcept &&) noexcept(false) = default;
  ObjectExcept &operator=(const ObjectExcept &) noexcept(false) = default;
  ObjectExcept &operator=(ObjectExcept &&) noexcept(false) = default;
  ~ObjectExcept() = default;
};

struct ExceptBlabber : Blabber, ObjectExcept {
  using Blabber::Blabber;
};

#endif // EXCEPT_BLABBER_HPP_
