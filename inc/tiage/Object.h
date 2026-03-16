// Copyright Tiberiu 2025

#pragma once

#include <tiage/Sprite.h>
#include <tiage/HitMatrix.h>
#include <optional>

namespace tiage {

class Object {
public:

	Object(Vec2<int32_t>pos, int32_t zOrder = 0, std::optional<HitMatrix> hitbox = std::nullopt, std::optional<Sprite> sprite = std::nullopt);

	void setPos(const Vec2<int32_t>& pos);

	void setSprite(const std::optional <Sprite>& sprite);

	void setHitbox(const std::optional <HitMatrix>& hitbox);

	void setZOrder(int32_t zOrder);

	const HitMatrix* hitbox() const;

	const Vec2<int32_t> pos() const;

	const Sprite* sprite() const;

	const int32_t zOrder() const;

	bool hasSprite() const;

	bool hasHitbox() const;

private:

	std::optional <HitMatrix> hitbox_;

	Vec2<int32_t> pos_;

	std::optional <Sprite> sprite_;

	int32_t zOrder_;

};

} // tiage
