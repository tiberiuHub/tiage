// Copyright Tiberiu 2025

#pragma once

#include "tiage/IConsole.h"
#include "tiage/Color.h"

namespace tiage {

// --------------------------------------------------------------------------------------------------

bool
IConsole::create(uint64_t createOptions) {
    return doCreate(createOptions);
}

// --------------------------------------------------------------------------------------------------

void 
IConsole::destroy() {
    doDestroy();
}

// --------------------------------------------------------------------------------------------------

void
IConsole::setTitle(const char* title) {
    doSetTitle(title);
}

// --------------------------------------------------------------------------------------------------

void
IConsole::move(std::optional<tiage::V2i32> maybePos, std::optional<tiage::V2i32> maybeSize) {
    doMove(maybePos, maybeSize);
}

// --------------------------------------------------------------------------------------------------

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

std::string
IConsole::getHostProcess() {
    return doGetHostProcess();
}

// -------------------------------------------------------------------------------------------------

} // tiage

