#ifndef CLASS_MOBILITY_HPP_
#define CLASS_MOBILITY_HPP_

struct notcopyable {
  notcopyable() = default;
  notcopyable(notcopyable &&) = default;
  notcopyable &operator=(notcopyable &&) = default;
  notcopyable(const notcopyable &) = delete;
  notcopyable &operator=(const notcopyable &) = delete;
  ~notcopyable() = default;
};

struct notmoveable {
  notmoveable() = default;
  notmoveable(notmoveable &&) = delete;
  notmoveable &operator=(notmoveable &&) = delete;
  notmoveable(const notmoveable &) = default;
  notmoveable &operator=(const notmoveable &) = default;
  ~notmoveable() = default;
};

#endif // CLASS_MOBILITY_HPP_
