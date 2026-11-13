// Copyright Tiberiu 2025

#pragma once

#include <tiage/Vec2.h>
#include <string>
#include <tiage/Matrix.h>

namespace tiage {

class Hitbox {
public:

	Hitbox(const V2i32& size = {1,1}, const V2i32& offset = { 0,0 });

	V2i32 size() const;

	void resize(const V2i32& newSize);

	Vec2<int32_t> offset() const;

	void setOffset(const V2i32& newOffset);

	bool intersects(const Hitbox& other) const;

	bool contains(const V2i32& other) const;

private:

	V2i32 offset_ = {0,0};

	V2i32 size_;

};

} // tiage
