// Copyright Tiberiu 2025

#pragma once

#include <tiage/Sprite.h>
#include <tiage/Hitbox.h>
#include <optional>

namespace tiage {

class Object {
public:

	Object(std::optional<Hitbox> hitbox = std::nullopt, std::optional<Sprite> sprite = std::nullopt);

	const Hitbox* hitbox() const;

	const Sprite* sprite() const;

	bool hasSprite() const;

	bool hasHitbox() const;

private:

	std::optional <Hitbox> hitbox_;

	std::optional <Sprite> sprite_;

};

} // tiage
