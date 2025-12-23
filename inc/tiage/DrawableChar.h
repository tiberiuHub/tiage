// Copyright Tiberiu 2025

#pragma once

#include "tiage/Color.h"

namespace tiage {

class DrawableChar {
public:

	DrawableChar(char c = ' ', const Color& fg = Color::kWhite, const Color& bg = Color::kBlack);

	void setC(char c);

	void setFG(const Color& fg);

	void setBG(const Color& bg);

	char c() const;

	Color bg() const;

	Color fg() const;

private:
	
	char c_;
	Color fg_;
	Color bg_;
};

} // tiage
