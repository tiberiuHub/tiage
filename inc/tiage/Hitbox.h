// Copyright Tiberiu 2025

#pragma once

#include <tiage/Matrix.h>
#include <tiage/Vec2.h>

namespace tiage {

class Hitbox {
public:

	Vec2<size_t> getSize() const;

	void setSize(Vec2<size_t> newSize);

	void loadFromFile(const std::string& path);

	bool isCollidable(V2i32 pos) const;

	void set(V2i32 pos, bool state);

private:

	Matrix<bool>data_;

};

} // tiage
