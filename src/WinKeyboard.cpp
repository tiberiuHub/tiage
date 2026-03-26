// Copyright Tiberiu 2025

#include "tiage/WinKeyboard.h"
#include <Windows.h>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void
WinKeyboard::doUpdate() {
	for (int key = 0; key < 256; key++) {
		if (GetAsyncKeyState(key) & 0x8000) {
			setKey(key);
		}
	}
}

// --------------------------------------------------------------------------------------------------

} // tiage
