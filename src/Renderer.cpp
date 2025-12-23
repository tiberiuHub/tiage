// Copyright Tiberiu 2025

#include "tiage/Color.h"

namespace tiage {

std::uint8_t
Color::r() const {
	return data_.r_;
}

// --------------------------------------------------------------------------------------------------

std::uint8_t
Color::g() const {
	return data_.g_;
}

// --------------------------------------------------------------------------------------------------

std::uint8_t
Color::b() const {
	return data_.b_;
}

// --------------------------------------------------------------------------------------------------

std::uint8_t
Color::a() const {
	return data_.a_;
}

// --------------------------------------------------------------------------------------------------

std::uint32_t
Color::rgba() const {
	return data_.rgba_;
}

// --------------------------------------------------------------------------------------------------

void
Color::setR(std::uint8_t val) {
	data_.r_ = val;
}

// --------------------------------------------------------------------------------------------------

void
Color::setG(std::uint8_t val) {
	data_.g_ = val;
}

// --------------------------------------------------------------------------------------------------

void
Color::setB(std::uint8_t val) {
	data_.b_ = val;
}

// --------------------------------------------------------------------------------------------------

void
Color::setA(std::uint8_t val) {
	data_.a_ = val;
}

// --------------------------------------------------------------------------------------------------

void
Color::setRGB(std::uint8_t valR, std::uint8_t valG, std::uint8_t valB) {
	data_.r_ = valR;
	data_.g_ = valG;
	data_.b_ = valB;
}

// --------------------------------------------------------------------------------------------------

void
Color::setRGBA(std::uint8_t valR, std::uint8_t valG, std::uint8_t valB , std::uint8_t valA) {
	data_.r_ = valR;
	data_.g_ = valG;
	data_.b_ = valB;
	data_.a_ = valA;
}
	
// --------------------------------------------------------------------------------------------------

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
	data_.r_ = r;
	data_.g_ = g;
	data_.b_ = b;
	data_.a_ = a;
}

// --------------------------------------------------------------------------------------------------

bool
Color::operator== (const Color& other) const {
	return (this->rgba() == other.rgba());
}

// --------------------------------------------------------------------------------------------------

bool
Color::operator!= (const Color& other) const {
	return (this->rgba() != other.rgba());
}

// --------------------------------------------------------------------------------------------------

const Color Color::kWhite{ 255, 255, 255 };
const Color Color::kBlack{ 0,0,0 };
const Color Color::kNeonRed{ 255, 0, 0 };
const Color Color::kRed{ 128, 0, 0 };
const Color Color::kPurple{ 155, 90, 220 };
const Color Color::kBrown{ 165, 42, 42 };
const Color Color::kGray{ 128, 128, 128 };
const Color Color::kGreen{ 0, 255, 0 };
const Color Color::kDarkGray{ 64, 64, 64 };
const Color Color::kBlue{ 0, 0, 255 };
const Color Color::kTan{ 230, 180, 140 };

// --------------------------------------------------------------------------------------------------

std::string
ansiForegroundColorCode(Color color) {
	std::string strR = std::to_string(color.r());
	std::string strG = std::to_string(color.g());
	std::string strB = std::to_string(color.b());
	std::string code = "\033[38;2;" + strR + ";" + strG + ";" + strB + "m";
	return code;
}

// --------------------------------------------------------------------------------------------------


std::string
ansiBackgroundColorCode(Color color) {
	std::string strR = std::to_string(color.r());
	std::string strG = std::to_string(color.g());
	std::string strB = std::to_string(color.b());
	std::string code = "\033[48;2;" + strR + ";" + strG + ";" + strB + "m";
	return code;
}

// --------------------------------------------------------------------------------------------------

} // tiage
