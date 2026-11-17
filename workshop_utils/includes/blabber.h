#ifndef BLABBER_H
#define BLABBER_H

#include <format>
#include <functional>
#include <string>
#include <type_traits>

template <typename Type>
using remove_cvref = std::remove_cv_t<std::remove_reference_t<Type>>;

class Blabber {
public:
  using PrintOutputType = std::function<void(const Blabber&, const std::string&)>;

  // Required by task
  Blabber(const std::string& description = "Default",
          /*Not required*/ PrintOutputType out = &Blabber::defaultPrinter);
  Blabber(const Blabber& blab);
  Blabber& operator=(const Blabber& blab);
  ~Blabber();

  // Required by second task
  Blabber& operator=(Blabber&& blab) noexcept;
  Blabber(Blabber&& blab) noexcept;

  // Additions
  void present_yourself() const;

  const std::string& description() const;
  void description(const std::string& v);

  template <typename Type, typename = std::enable_if_t<!std::is_same_v<Blabber, remove_cvref<Type>>>>
  Blabber& operator=(Type&& value) {
    description(value);
    return *this;
  }

  PrintOutputType printer() { return m_printer; }

  static void defaultPrinter(const Blabber& instance, const std::string& tag);

private:
  std::string m_description;
  PrintOutputType m_printer;
};

std::string getShout(const Blabber& blab, const std::string& msg = "");
std::ostream& operator<<(std::ostream& out, const Blabber& blab);

template <>
struct std::formatter<Blabber, char> {
  template <class ParseContext>
  constexpr ParseContext::iterator parse(ParseContext& ctx) {
    auto it = ctx.begin();
    if (it != ctx.end() && *it != '}')
      throw std::format_error("Invalid format args for Format.");
    return it;
  }

  template <class FmtContext>
  FmtContext::iterator format(const Blabber& b, FmtContext& ctx) const {
    return std::ranges::copy(getShout(b, "Formatted"), ctx.out()).out;
  }
};

#endif // BLABBER_H
