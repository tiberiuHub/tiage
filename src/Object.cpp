// Copyright Tiberiu 2025

#include "tiage/Object.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Object::Object(Vec2<int32_t>pos, int32_t zOrder, std::optional<HitMatrix> hitbox, std::optional<Sprite> sprite):
	pos_(pos),
	zOrder_(zOrder),
	hitbox_(hitbox),
	sprite_(sprite)
{}

// -------------------------------------------------------------------------------------------------

void 
Object::setPos(const Vec2<int32_t>& pos) {
	pos_ = pos;
}

// -------------------------------------------------------------------------------------------------

void 
Object::setSprite(const std::optional <Sprite>& sprite) {
	sprite_ = sprite;
}

// -------------------------------------------------------------------------------------------------

void 
Object::setHitbox(const std::optional <HitMatrix>& hitbox) {
	hitbox_ = hitbox;
}

// -------------------------------------------------------------------------------------------------

void
Object::setZOrder(int32_t zOrder) {
	zOrder_ = zOrder;
}

// -------------------------------------------------------------------------------------------------

const HitMatrix*
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

