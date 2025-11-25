// Copyright Tiberiu 2025

#include "tiage/Viewport.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Viewport::Viewport(Vec2<uint32_t> originPos, Vec2<uint32_t> size) :
    originPos_(originPos),
    size_(size)
{}

// -------------------------------------------------------------------------------------------------

void 
Viewport::moveIncrement(Vec2<uint32_t> increment) { // no .cpp for now
    originPos_.x += increment.x;
    originPos_.y += increment.y;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::moveAbsolute(Vec2<uint32_t> absolutePos) { // no .cpp for now
    originPos_.x = absolutePos.x;
    originPos_.y = absolutePos.y;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::resizeIncrement(Vec2<uint32_t> increment) { // no .cpp for now
    size_.x += increment.x;
    size_.y += increment.y;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::resizeAbsolute(Vec2<uint32_t> absolutePos) { // no .cpp for now
    size_.x = absolutePos.x;
    size_.y = absolutePos.y;
}

// -------------------------------------------------------------------------------------------------

} // tiage

