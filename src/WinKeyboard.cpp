// Copyright Tiberiu 2025

#include "tiage/KeyboardInput.h"
#include <conio.h>
#include <winap>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void 
Keyboard::update() {
    last_ = current_;

    for (int key = 0; key < 256; key++) {
        current[key] = (GetAsyncKeyState(key) & 0x8000);
    }
}

// --------------------------------------------------------------------------------------------------

} // tiage
