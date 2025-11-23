// Copyright Tiberiu 2025

#pragma once

<<<<<<< HEAD
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
=======
#include <tiage/IConsole.h>
#include <cassert>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void 
IConsole::create(uint32_t width, uint32_t height) {
	commands_ = Matrix<cmd_t>(width, height);
	doCreate(width, height);
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::destroy() {
	doDestroy();
	//commands_ = nullptr;
}

// --------------------------------------------------------------------------------------------------

void 
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
IConsole::setCursorVisible(bool visible) {
	doSetCursorVisible(visible);
}

<<<<<<< HEAD
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

=======
// --------------------------------------------------------------------------------------------------

void 
IConsole::putChar(uint32_t x, uint32_t y, Color color, char c) {
	//assert(commands_);
	commands_.set(x,y, { color, c });
	doPutChar(x,y, color, c);	
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::flush() {
	doFlush();
	//clear();
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::clear() {
	//assert(commands_);
	doClear();
	commands_.set({});
}

// --------------------------------------------------------------------------------------------------

} // tiage
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
