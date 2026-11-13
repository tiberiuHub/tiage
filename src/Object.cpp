// Copyright Tiberiu 2025

#include "tiage/Object.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Object::Object(std::optional<Hitbox> hitbox, std::optional<Sprite> sprite, V2i32 pos, int32_t zOrder):
	pos_(pos),
	zOrder_(zOrder),
	hitbox_(hitbox),
	sprite_(sprite)
{}

// -------------------------------------------------------------------------------------------------

void 
Object::setPos(const V2i32& pos) {
	pos_ = pos;
}

// -------------------------------------------------------------------------------------------------

void 
Object::setSprite(const std::optional <Sprite>& sprite) {
	sprite_ = sprite;
}

// -------------------------------------------------------------------------------------------------

void 
Object::setHitbox(const std::optional <Hitbox>& hitbox) {
	hitbox_ = hitbox;
}

// -------------------------------------------------------------------------------------------------

void
Object::setZOrder(int32_t zOrder) {
	zOrder_ = zOrder;
}

// -------------------------------------------------------------------------------------------------

const Hitbox*
Object::hitbox() const {
	if (hasHitbox()) {
		return &*hitbox_;
	}
	return nullptr;
}

// -------------------------------------------------------------------------------------------------

const Vec2<int32_t> 
Object::pos() const {
	return pos_;
}

// -------------------------------------------------------------------------------------------------

const Sprite*
Object::sprite() const {
	if (hasSprite()) {
		return &*sprite_;
	}
	return nullptr;
}

// -------------------------------------------------------------------------------------------------

const int32_t 
Object::zOrder() const {
	return zOrder_;
}

// -------------------------------------------------------------------------------------------------

bool 
Object::hasSprite() const {
	return sprite_ != std::nullopt;
}

// -------------------------------------------------------------------------------------------------

bool 
Object::hasHitbox() const {
	return hitbox_ != std::nullopt;
}

// -------------------------------------------------------------------------------------------------

} // tiage

