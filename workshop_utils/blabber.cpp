#include "blabber.h"

#include <cstdint>
#include <format>
#include <iostream>

namespace {
template <typename Type>
std::string getPointerString(Type *ptr) {
  return std::format("[{:#0x}]", reinterpret_cast<uintptr_t>(ptr));
}
std::string getShout(const Blabber &blab, const std::string &msg) {
  return std::format("Blabber {}({}) {}", getPointerString(&blab), blab.description(), msg);
}
} // namespace

Blabber::Blabber(const std::string &description, Blabber::PrintOutputType out)
    : m_description{description}, m_printer{out} {
  m_printer(*this, "constructor");
}

Blabber::Blabber(const Blabber &blab) : m_description{blab.m_description}, m_printer{blab.m_printer} {
  m_printer(*this, "copy constructor from " + getPointerString(&blab));
}

Blabber &Blabber::operator=(const Blabber &blab) {
  m_printer(*this, "copy assign from " + getPointerString(&blab));
  m_description = blab.m_description;
  return *this;
}

Blabber::~Blabber() { m_printer(*this, "destructor"); }

Blabber::Blabber(Blabber &&blab) noexcept : m_description{std::move(blab.m_description)}, m_printer{blab.m_printer} {
  m_printer(*this, "move constructor from " + getPointerString(&blab));
}

Blabber &Blabber::operator=(Blabber &&blab) noexcept {
  m_printer(*this, "move assign from " + getPointerString(&blab));
  m_description = std::move(blab.m_description);
  return *this;
}

void Blabber::present_yourself() const { m_printer(*this, "I am!"); }

const std::string &Blabber::description() const { return m_description; }

void Blabber::description(const std::string &v) {
  m_printer(*this, std::format("changing description from '{}' to '{}'", m_description, v));
  m_description = v;
}

void Blabber::defaultPrinter(const Blabber &instance, const std::string &tag) {
  std::cout << getShout(instance, tag) << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Blabber &blab) { return out << getShout(blab, "Printing"); }
