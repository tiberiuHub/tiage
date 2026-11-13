// Copyright Tiberiu 2025

#pragma once

#include <tiage/Sprite.h>
#include <tiage/Hitbox.h>
#include <optional>

namespace tiage {

class Object {
public:

	Object(std::optional<Hitbox> hitbox = std::nullopt, std::optional<Sprite> sprite = std::nullopt, V2i32 pos = {0,0}, int32_t zOrder = 0);

	void setPos(const V2i32& pos);

	void setSprite(const std::optional <Sprite>& sprite);

	void setHitbox(const std::optional <Hitbox>& hitbox);

	void setZOrder(int32_t zOrder);

	const Hitbox* hitbox() const;

	const V2i32 pos() const;

	const Sprite* sprite() const;

	const int32_t zOrder() const;

	bool hasSprite() const;

	bool hasHitbox() const;

private:

	std::optional <Hitbox> hitbox_;

	V2i32 pos_;

	std::optional <Sprite> sprite_;

	int32_t zOrder_;

};

} // tiage
