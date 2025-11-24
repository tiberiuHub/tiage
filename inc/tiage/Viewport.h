// Copyright Tiberiu 2025

#pragma once

#include <cstdint>
#include <tiage/Vec2.h>

namespace tiage {

class Viewport {
public:

    void moveIncrement(Vec2<uint32_t> increment);

    void moveAbsolute(Vec2<uint32_t> absolutePos);

private:

    Vec2<uint32_t> originPos; // top left pos

    Vec2<uint32_t> relativeSize; // going toward bottom right , relative to originPos

};

} // tiage
