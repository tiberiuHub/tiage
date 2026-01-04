// Copyright Tiberiu 2025

#include "tiage/Hitbox.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Vec2<size_t>
Hitbox::getSize() const {
	return { data_.nCols(),data_.nRows() };
}

// -------------------------------------------------------------------------------------------------

void 
Hitbox::setSize(Vec2<size_t> newSize) {
	data_ = Matrix<bool>(newSize.x(), newSize.y());
}

// -------------------------------------------------------------------------------------------------

void 
Hitbox::loadFromFile(const std::string& path) {

}

// -------------------------------------------------------------------------------------------------

bool
Hitbox::isCollidable(V2i32 pos) const {
	return data_.get(pos.x(), pos.y());
}

// -------------------------------------------------------------------------------------------------

void 
Hitbox::set(V2i32 pos, bool state) {
	data_.set(pos.x(), pos.y(), state);
}

// -------------------------------------------------------------------------------------------------

} // tiage

