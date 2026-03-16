// Copyright Tiberiu 2025

#pragma once

#include <tiage/Matrix.h>
#include <tiage/DrawableChar.h>
#include <tiage/Vec2.h>

namespace tiage {

class Sprite {
public:
		
	Vec2<size_t> getSize() const;

	void setSize(Vec2<size_t> newSize);

	DrawableChar getChar(Vec2<size_t> pos) const;

	 void setChar(Vec2<size_t> pos, const DrawableChar& c);

	 /**
	* Loads sprite from file into memory,first few lines declare the drawableChar pallete used in the sprite, the other
	* lines are the representation of the sprite using the pallete that was declared
	*/
	 void parseFromFile(const std::string& path);

private:

	Matrix<DrawableChar> data_;

};

} // tiage
