// Copyright Tiberiu 2025

#include "tiage/Viewport.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

void 
Viewport::moveIncrement(Vec2<uint32_t> increment) { // no .cpp for now
    relativeSize.x += increment.x;
    relativeSize.y += increment.y;
}

// -------------------------------------------------------------------------------------------------

void
Viewport::moveAbsolute(Vec2<uint32_t> absolutePos) { // no .cpp for now
    relativeSize.x = absolutePos.x;
    relativeSize.y = absolutePos.y;
}

// -------------------------------------------------------------------------------------------------

} // tiage

