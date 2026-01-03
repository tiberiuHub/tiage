// Copyright Tiberiu 2025

#pragma once

#include <string>
#include <utility>
#include <cstdint>

namespace tiage {

class Color {
public:

	static const Color kWhite;	
	static const Color kBlack;
	static const Color kNeonRed;
	static const Color kRed;
	static const Color kPurple;
	static const Color kBrown;
	static const Color kGray;
	static const Color kGreen;
	static const Color kDarkGray;
	static const Color kBlue;
	static const Color kTan;

	std::uint8_t r() const;

	std::uint8_t g() const;

	std::uint8_t b() const;

	std::uint8_t a() const;

	std::uint32_t rgba() const;

	void setR(std::uint8_t val);

	void setG(std::uint8_t val);

	void setB(std::uint8_t val);

	void setA(std::uint8_t val);

	void setRGB(std::uint8_t valR, std::uint8_t valG, std::uint8_t valB);

	void setRGBA(std::uint8_t valR, std::uint8_t valG, std::uint8_t valB, std::uint8_t valA);

	bool operator== (const Color& other) const;

	bool operator!= (const Color& other) const;

	Color(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t a = 255);

private:

	union ColorUnion {
		struct {
			std::uint8_t r_;
			std::uint8_t g_;
			std::uint8_t b_;
			std::uint8_t a_;
		};
		std::uint32_t rgba_;
	};

	ColorUnion data_;

};

/**
 * @return The pair of ansi color codes for the terminal.
 */
std::string ansiForegroundColorCode(Color color);

std::string ansiBackgroundColorCode(Color color);

/**
 * @return The code that resets the colors of the terminal.
 */
inline constexpr const char* kAnsiColorReset = "\033[0m";

} // tiage
