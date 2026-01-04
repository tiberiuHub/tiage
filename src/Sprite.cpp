// Copyright Tiberiu 2025

#include "tiage/Sprite.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Vec2<size_t>
Sprite::getSize() const {
	return {data_.nCols(),data_.nRows()};
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::setSize(Vec2<size_t> newSize) {
	data_ = Matrix<DrawableChar>(newSize.x(), newSize.y());
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::loadFromFile(const std::string& path) {

}

// -------------------------------------------------------------------------------------------------

DrawableChar 
Sprite::getChar(V2i32 pos) const {
	return data_.get(pos.x(),pos.y());
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::setChar(V2i32 pos, const DrawableChar& c) {
	data_.set(pos.x(), pos.x(),c);
}

// -------------------------------------------------------------------------------------------------

} // tiage

