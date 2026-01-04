// Copyright Tiberiu 2025

#include "tiage/Object.h"

namespace tiage {

// -------------------------------------------------------------------------------------------------

Object::Object(std::optional<Hitbox> hitbox, std::optional<Sprite> sprite): 
	hitbox_(hitbox),
	sprite_(sprite)
{

}

// -------------------------------------------------------------------------------------------------

const Hitbox*
Object::hitbox() const {
	if (hasHitbox()) {
		return &*hitbox_;
	}
}

// -------------------------------------------------------------------------------------------------

const Sprite*
Object::sprite() const {
	if (hasSprite()) {
		return &*sprite_;
	}
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

