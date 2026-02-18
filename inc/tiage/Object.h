// Copyright Tiberiu 2025

#pragma once

#include <tiage/Sprite.h>
#include <tiage/HitMatrix.h>
#include <optional>

namespace tiage {

class Object {
public:

	Object(std::optional<HitMatrix> hitbox = std::nullopt, std::optional<Sprite> sprite = std::nullopt);

	const HitMatrix* hitbox() const;

	const Sprite* sprite() const;

	bool hasSprite() const;

	bool hasHitbox() const;

private:

	std::optional <HitMatrix> hitbox_;

	std::optional <Sprite> sprite_;

};

} // tiage
