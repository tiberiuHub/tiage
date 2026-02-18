// Copyright Tiberiu 2025

#include "tiage/Color.h"
#include <unordered_map>
#include <stdexcept>

namespace tiage {

// --------------------------------------------------------------------------------------------------

const Color Color::kWhite{ 255, 255, 255 };
const Color Color::kBlack{ 0,0,0 };
const Color Color::kNeonRed{ 255, 0, 0 };
const Color Color::kRed{ 128, 0, 0 };
const Color Color::kPurple{ 155, 90, 220 };
const Color Color::kBrown{ 165, 42, 42 };
const Color Color::kGray{ 128, 128, 128 };
const Color Color::kNeonGreen{ 0, 255, 0 };
const Color Color::kDarkGray{ 64, 64, 64 };
const Color Color::kNeonBlue{ 0, 0, 255 };
const Color Color::kTan{ 230, 180, 140 };
const Color Color::kNavy{ 0, 0, 128 };
const Color Color::kMidnightBlue{ 25, 25, 112 };
const Color Color::kRoyalBlue{ 65, 105, 225 };
const Color Color::kDodgerBlue{ 30, 144, 255 };
const Color Color::kSkyBlue{ 135, 206, 235 };
const Color Color::kDeepSkyBlue{ 0, 191, 255 };
const Color Color::kSteelBlue{ 70, 130, 180 };
const Color Color::kSlateBlue{ 106, 90, 205 };
const Color Color::kCornflowerBlue{ 100, 149, 237 };
const Color Color::kTeal{ 0, 128, 128 };
const Color Color::kForestGreen{ 34, 139, 34 };
const Color Color::kDarkGreen{ 0, 100, 0 };
const Color Color::kSeaGreen{ 46, 139, 87 };
const Color Color::kMediumSeaGreen{ 60, 179, 113 };
const Color Color::kSpringGreen{ 0, 255, 127 };
const Color Color::kMint{ 152, 255, 152 };
const Color Color::kEmerald{ 80, 200, 120 };
const Color Color::kOliveDrab{ 107, 142, 35 };
const Color Color::kChartreuse{ 127, 255, 0 };
const Color Color::kMoss{ 138, 154, 91 };
const Color Color::kCrimson{ 220, 20, 60 };
const Color Color::kFirebrick{ 178, 34, 34 };
const Color Color::kIndianRed{ 205, 92, 92 };
const Color Color::kCoral{ 255, 127, 80 };
const Color Color::kTomato{ 255, 99, 71 };
const Color Color::kDarkOrange{ 255, 140, 0 };
const Color Color::kLightSalmon{ 255, 160, 122 };
const Color Color::kSalmon{ 250, 128, 114 };
const Color Color::kSienna{ 160, 82, 45 };
const Color Color::kRust{ 183, 65, 14 };
const Color Color::kKhaki{ 240, 230, 140 };
const Color Color::kDarkKhaki{ 189, 183, 107 };
const Color Color::kMustard{ 255, 219, 88 };
const Color Color::kAmber{ 255, 191, 0 };
const Color Color::kLemon{ 255, 247, 0 };
const Color Color::kLavender{ 230, 230, 250 };
const Color Color::kOrchid{ 218, 112, 214 };
const Color Color::kPlum{ 221, 160, 221 };
const Color Color::kHotPink{ 255, 105, 180 };
const Color Color::kDeepPink{ 255, 20, 147 };
const Color Color::kFuchsia{ 255, 0, 255 };
const Color Color::kIndigo{ 75, 0, 130 };
const Color Color::kDarkViolet{ 148, 0, 211 };
const Color Color::kChocolate{ 210, 105, 30 };
const Color Color::kPeru{ 205, 133, 63 };
const Color Color::kBurlyWood{ 222, 184, 135 };
const Color Color::kWheat{ 245, 222, 179 };
const Color Color::kBeige{ 245, 245, 220 };
const Color Color::kSand{ 194, 178, 128 };
const Color Color::kCamel{ 193, 154, 107 };
const Color Color::kDimGray{ 105, 105, 105 };
const Color Color::kSlateGray{ 112, 128, 144 };
const Color Color::kLightSlateGray{ 119, 136, 153 };
const Color Color::kGainsboro{ 220, 220, 220 };
const Color Color::kIvory{ 255, 255, 240 };
const Color Color::kSnow{ 255, 250, 250 };

// --------------------------------------------------------------------------------------------------

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

Color 
colFromString(std::string str) {
    std::unordered_map<std::string, Color> kColorLookup = {
    {"kWhite", Color::kWhite},
    {"kBlack", Color::kBlack},
    {"kNeonRed", Color::kNeonRed},
    {"kRed", Color::kRed},
    {"kPurple", Color::kPurple},
    {"kBrown", Color::kBrown},
    {"kGray", Color::kGray},
    {"kNeonGreen", Color::kNeonGreen},
    {"kDarkGray", Color::kDarkGray},
    {"kNeonBlue", Color::kNeonBlue},
    {"kTan", Color::kTan},
    {"kNavy", Color::kNavy},
    {"kMidnightBlue", Color::kMidnightBlue},
    {"kRoyalBlue", Color::kRoyalBlue},
    {"kDodgerBlue", Color::kDodgerBlue},
    {"kSkyBlue", Color::kSkyBlue},
    {"kDeepSkyBlue", Color::kDeepSkyBlue},
    {"kSteelBlue", Color::kSteelBlue},
    {"kSlateBlue", Color::kSlateBlue},
    {"kCornflowerBlue", Color::kCornflowerBlue},
    {"kTeal", Color::kTeal},
    {"kForestGreen", Color::kForestGreen},
    {"kDarkGreen", Color::kDarkGreen},
    {"kSeaGreen", Color::kSeaGreen},
    {"kMediumSeaGreen", Color::kMediumSeaGreen},
    {"kSpringGreen", Color::kSpringGreen},
    {"kMint", Color::kMint},
    {"kEmerald", Color::kEmerald},
    {"kOliveDrab", Color::kOliveDrab},
    {"kChartreuse", Color::kChartreuse},
    {"kMoss", Color::kMoss},
    {"kCrimson", Color::kCrimson},
    {"kFirebrick", Color::kFirebrick},
    {"kIndianRed", Color::kIndianRed},
    {"kCoral", Color::kCoral},
    {"kTomato", Color::kTomato},
    {"kDarkOrange", Color::kDarkOrange},
    {"kLightSalmon", Color::kLightSalmon},
    {"kSalmon", Color::kSalmon},
    {"kSienna", Color::kSienna},
    {"kRust", Color::kRust},
    {"kKhaki", Color::kKhaki},
    {"kDarkKhaki", Color::kDarkKhaki},
    {"kMustard", Color::kMustard},
    {"kAmber", Color::kAmber},
    {"kLemon", Color::kLemon},
    {"kLavender", Color::kLavender},
    {"kOrchid", Color::kOrchid},
    {"kPlum", Color::kPlum},
    {"kHotPink", Color::kHotPink},
    {"kDeepPink", Color::kDeepPink},
    {"kFuchsia", Color::kFuchsia},
    {"kIndigo", Color::kIndigo},
    {"kDarkViolet", Color::kDarkViolet},
    {"kChocolate", Color::kChocolate},
    {"kPeru", Color::kPeru},
    {"kBurlyWood", Color::kBurlyWood},
    {"kWheat", Color::kWheat},
    {"kBeige", Color::kBeige},
    {"kSand", Color::kSand},
    {"kCamel", Color::kCamel},
    {"kDimGray", Color::kDimGray},
    {"kSlateGray", Color::kSlateGray},
    {"kLightSlateGray", Color::kLightSlateGray},
    {"kGainsboro", Color::kGainsboro},
    {"kIvory", Color::kIvory},
    {"kSnow", Color::kSnow}
    };
    auto it = kColorLookup.find(str);
    if (it != kColorLookup.end()) {
        return it->second;
    }

    std::vector<int> values;
    int value = 0;

    for (size_t i = 0; i < str.size(); i++) {
        char c = str[i];
        
        if (!std::isdigit(c) and c != ',') {
            throw std::runtime_error("String must have only numbers and commas to delimit the values");
        }

        if (c == ',') {
            if (value < 0 || value > 255) {
                throw std::runtime_error("Value must be from 0 to 255");
            }
            values.push_back(value);
            value = 0;
        } else {
            value = value * 10 + (c - '0');
        }
        
    }

    if (value < 0 || value > 255) {
        throw std::runtime_error("Value must be from 0 to 255");
    }
    values.push_back(value);

    if (values.size() == 3) {
        return Color(values[0], values[1], values[2]);
    } else {
        throw std::runtime_error("String must have exactly 3 values for RGB");//Alpha not implemented yet and probably never will be
    }
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
