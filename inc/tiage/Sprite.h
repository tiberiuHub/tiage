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

	void loadFromFile(const std::string& path);

	DrawableChar getChar(V2i32 pos) const;

	 void setChar(V2i32 pos, const DrawableChar& c);

private:

	Matrix<DrawableChar> data_;

};

} // tiage
