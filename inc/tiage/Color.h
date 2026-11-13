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
	static const Color kNeonGreen;
	static const Color kDarkGray;
	static const Color kNeonBlue;
	static const Color kTan;
	static const Color kNavy;
	static const Color kMidnightBlue;
	static const Color kRoyalBlue;
	static const Color kDodgerBlue;
	static const Color kSkyBlue;
	static const Color kDeepSkyBlue;
	static const Color kSteelBlue;
	static const Color kSlateBlue;
	static const Color kCornflowerBlue;
	static const Color kTeal;
	static const Color kForestGreen;
	static const Color kDarkGreen;
	static const Color kSeaGreen;
	static const Color kMediumSeaGreen;
	static const Color kSpringGreen;
	static const Color kMint;
	static const Color kEmerald;
	static const Color kOliveDrab;
	static const Color kChartreuse;
	static const Color kMoss;
	static const Color kCrimson;
	static const Color kFirebrick;
	static const Color kIndianRed;
	static const Color kCoral;
	static const Color kTomato;
	static const Color kDarkOrange;
	static const Color kLightSalmon;
	static const Color kSalmon;
	static const Color kSienna;
	static const Color kRust;
	static const Color kKhaki;
	static const Color kDarkKhaki;
	static const Color kMustard;
	static const Color kAmber;
	static const Color kLemon;
	static const Color kLavender;
	static const Color kOrchid;
	static const Color kPlum;
	static const Color kHotPink;
	static const Color kDeepPink;
	static const Color kFuchsia;
	static const Color kIndigo;
	static const Color kDarkViolet;
	static const Color kChocolate;
	static const Color kPeru;
	static const Color kBurlyWood;
	static const Color kWheat;
	static const Color kBeige;
	static const Color kSand;
	static const Color kCamel;
	static const Color kDimGray;
	static const Color kSlateGray;
	static const Color kLightSlateGray;
	static const Color kGainsboro;
	static const Color kIvory;
	static const Color kSnow;

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

	Color operator* (uint8_t factor) const;

	Color operator+ (const Color& other) const;

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

Color colFromString(std::string str);

/**
 * @return The pair of ansi color code for changing the terminal foreground.
 */
std::string ansiForegroundColorCode(Color color);
/**
 * @return The pair of ansi color code for changing the terminal background.
 */
std::string ansiBackgroundColorCode(Color color);

/**	
 * @return The code that resets the colors of the terminal.
 */
inline constexpr const char* kAnsiColorReset = "\033[0m";

} // tiage
