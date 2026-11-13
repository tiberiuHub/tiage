// Copyright Tiberiu 2025

#pragma once

#include "tiage/IConsole.h"
#include "tiage/Matrix.h"
#include "tiage/Sprite.h"
#include "tiage/Object.h"
#include <functional>
#include <cmath>

namespace tiage {

class Renderer {
public:

	Renderer(Vec2<size_t> bufrSize);

	void clear();

	void present(IConsole& console, const V2i32& offset = { 0,0 });

	void changeZ(uint32_t layerZ);

	void doubleRendering(bool value);

	void drawChar(const Vec2<size_t>& pos, const DrawableChar& chr);

	void drawLine(const DrawableChar& chr, const V2i32& p1, const V2i32& p2);

	void drawTriangle(const DrawableChar& chr, const V2i32& p1, const V2i32& p2, const V2i32& p3, bool filled = false);

	void drawRect(const DrawableChar& chr, const V2i32& pos, const V2i32& size, bool filled = false);

	void drawCircle(const DrawableChar& chr, const V2i32& origin, uint32_t radius, bool filled = false);

	void drawString(const V2i32& pos, const std::string& string, Color foregCol = Color::kWhite, Color backgCol = Color::kBlack);

	void drawSprite(const V2i32& pos, const Sprite& sprite);

	void drawObject(const V2i32& pos, const Object& object);

private:

	struct cmd_t {
		uint32_t z;
		Vec2<size_t> pos;
		DrawableChar chr;
	};

	bool doubleRenderEnabled = false;
	
	bool posInside(const Vec2<size_t>& pos) const;

	Vec2<size_t> layerSize;

	uint32_t currentZ;

	std::vector<cmd_t>layers;

};

} // tiage
