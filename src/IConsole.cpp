// Copyright Tiberiu 2025

#pragma once

#include <tiage/IConsole.h>
#include <cassert>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void 
IConsole::create(uint32_t width, uint32_t height) {
	commands_ = std::make_unique<Matrix<cmd_t>>(width, height);
	doCreate(width, height);
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::destroy() {
	doDestroy();
	commands_ = nullptr;
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::setCursorVisible(bool visible) {
	doSetCursorVisible(visible);
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::putChar(uint32_t x, uint32_t y, Color color, char c) {
	assert(commands_);
	commands_->set(x, y, { color, c });
	doPutChar(x, y, color, c);	
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::flush() {
	doFlush();
	clear();
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::clear() {
	assert(commands_);
	doClear();
	commands_->set({});
}

// --------------------------------------------------------------------------------------------------

} // tiage
