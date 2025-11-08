// Copyright Tiberiu 2025

#pragma once

#include <iostream>
#include <utility>

namespace tiage {

enum class Color {
	White,
	Red,
	Purple,
	Brown,
	Gray,
	Green,
	DarkGray
};

/**
 * @return The pair of ansi color codes for the terminal.
 */
inline std::pair<std::string, std::string> 
ansiColorCode(Color colorName) {
	switch (colorName) {
	case Color::Brown:
		return { "\033[33m" ,"\033[0m" };
	case Color::Red:
		return { "\033[31m" ,"\033[0m" };
	case Color::Gray:
		return { "\033[90m" ,"\033[0m" };
	case Color::Purple:
		return { "\033[35m" ,"\033[0m" };
	case Color::Green:
		return { "\033[32m" ,"\033[0m" };
	case Color::DarkGray:
		return { "\033[38;5;240m", "\033[0m" };
	case Color::White:
	default:
		return { "\033[0m" ,"\033[0m" };
	}
}

} // tiage
