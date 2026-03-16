// Copyright Tiberiu 2025

#pragma once

#include "tiage/IConsole.h"
#include "tiage/Matrix.h"
#include "tiage/Sprite.h"
#include <cmath>

namespace tiage {

class Renderer {
public:

	Renderer(Vec2<size_t> bufrSize);

	void clear();

	void present(IConsole& console, const V2i32& offset = { 0,0 });

	void clearLayer(uint32_t layerZ);

	void changeZ(uint32_t layerZ);

	void doubleRendering(bool value);

	void drawChar(const Vec2<size_t>& pos, const DrawableChar& chr);

	void drawLine(const DrawableChar& chr, const V2i32& p1, const V2i32& p2);

	void drawTriangle(const DrawableChar& chr, const V2i32& p1, const V2i32& p2, const V2i32& p3, bool filled = false);

	void drawRect(const DrawableChar& chr, const V2i32& pos, const V2i32& size, bool filled = false);

	void drawCircle(const DrawableChar& chr, const V2i32& origin, uint32_t radius, bool filled = false);

	void drawString(const V2i32& pos, const std::string& string, Color foregCol, Color backgCol);

	void drawSprite(const V2i32& pos, const Sprite& sprite);

private:

	bool doubleRenderEnabled = false;

	DrawableChar getTopmostChr(const Vec2<size_t>& pos);

	bool posInside(const Vec2<size_t>& pos) const;

	Vec2<size_t> layerSize;

	uint32_t currentZ;

	uint32_t biggestZ;

	std::vector<Matrix<DrawableChar>> layers;

};

} // tiage
