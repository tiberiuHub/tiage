// Copyright Tiberiu 2025

#pragma once

#include <tiage/Vec2.h>
#include <cstdint>

namespace tiage {

class Viewport {

    void move(Vec2<uint32_t> increment) { // no .cpp for now
        relativeSize.x += increment.x;
        relativeSize.y += increment.y;
    }

private:

    Vec2 <uint32_t> originPos; // top left pos

    Vec2 <uint32_t> relativeSize; // going toward bottom right , relative to originPos

};

} // tiage
