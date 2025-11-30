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
    originPos_ += increment;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::moveAbsolute(Vec2<uint32_t> absolutePos) { // no .cpp for now
    originPos_ = absolutePos;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::resizeIncrement(Vec2<uint32_t> increment) { // no .cpp for now
    size_ += increment;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::resizeAbsolute(Vec2<uint32_t> absolutePos) { // no .cpp for now
    size_ = absolutePos;
}

// -------------------------------------------------------------------------------------------------

} // tiage

