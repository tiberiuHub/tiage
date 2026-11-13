// Copyright Tiberiu 2025

#include "tiage/Hitbox.h"
#include "fstream"
#include "string"
#include <tiage/Matrix.h>


namespace tiage {

// -------------------------------------------------------------------------------------------------

Hitbox::Hitbox(const V2i32& size, const V2i32& offset)
	: size_(size),
	offset_(offset)
{}

// -------------------------------------------------------------------------------------------------

V2i32
Hitbox::size() const {
	return size_;
}

// -------------------------------------------------------------------------------------------------

void
Hitbox::resize(const V2i32& newSize) {
	size_ = newSize;
}

// -------------------------------------------------------------------------------------------------


V2i32
Hitbox::offset() const {
	return offset_;
}

// -------------------------------------------------------------------------------------------------

void
Hitbox::setOffset(const V2i32& newOffset) {
	offset_ = newOffset;
}

// -------------------------------------------------------------------------------------------------

bool 
Hitbox::intersects(const Hitbox& other) const {
	return (
		offset_.x() < other.offset_.x() + other.size_.x() &&
		offset_.x() + size_.x() > other.offset_.x() &&
		offset_.y() < other.offset_.y() + other.size_.y() &&
		offset_.y() + size_.y() > other.offset_.y()
		);
}

// -------------------------------------------------------------------------------------------------

bool
Hitbox::contains(const V2i32& other) const {
	return other <= offset_ + size_ &&
		   other >= offset_ ;
}

// -------------------------------------------------------------------------------------------------

} // tiage

