// Copyright Tiberiu 2025

#pragma once

#include <cstdint>
#include <tiage/Vec2.h>

namespace tiage {

class Viewport {
public:

	Viewport(Vec2<uint32_t> originPos, Vec2<uint32_t> size);

	Viewport() = default;

	void moveIncrement(Vec2<uint32_t> increment);

	void moveAbsolute(Vec2<uint32_t> absolutePos);

	void resizeIncrement(Vec2<uint32_t> increment);

	void resizeAbsolute(Vec2<uint32_t> absolutePos);

private:

	Vec2<uint32_t> originPos_ = { 0,0 }; // top left pos

	Vec2<uint32_t> size_ = { 0,0 }; // going toward bottom right , relative to originPos

};

} // tiage
