// Copyright Tiberiu 2025

#pragma once

#include "tiage/WinConsole.h"
#include "tiage/Color.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

void
IConsole::create(uint32_t width, uint32_t height) {
	doCreate(width, height);
}

// -------------------------------------------------------------------------------------------------

void
IConsole::destroy() {
	doDestroy();
}

// -------------------------------------------------------------------------------------------------

void
IConsole::setCursorVisible(bool visible) {
	doSetCursorVisible(visible);
}

// -------------------------------------------------------------------------------------------------

void
IConsole::putChar(uint32_t x, uint32_t y, Color color, char c) {
	doPutChar(x, y, color, c);
}


// -------------------------------------------------------------------------------------------------

void
IConsole::flush() {
	doFlush();
}

// -------------------------------------------------------------------------------------------------

void
IConsole::clear() {
	doClear();
}

// -------------------------------------------------------------------------------------------------

void
IConsole::fitToConsole() {
	doFitToConsole();
}

// -------------------------------------------------------------------------------------------------

} // tiage

