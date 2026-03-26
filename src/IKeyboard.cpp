// Copyright Tiberiu 2025

#include "tiage/IKeyboard.h"

namespace tiage {

// --------------------------------------------------------------------------------------------------

void 
IKeyboard::update() {
    last_ = current_;
    current_.reset();
    doUpdate();
}


// --------------------------------------------------------------------------------------------------

bool 
IKeyboard::pressed(int key) const {
    return current_[key] && !last_[key];
}

// --------------------------------------------------------------------------------------------------

bool
IKeyboard::released(int key) const {
    return !current_[key] && last_[key];
}

// --------------------------------------------------------------------------------------------------

bool
IKeyboard::holding(int key) const {
    return current_[key];
}

// --------------------------------------------------------------------------------------------------

void
IKeyboard::setKey(int key) {
    current_[key] = 1;
}

// --------------------------------------------------------------------------------------------------

} // tiage
