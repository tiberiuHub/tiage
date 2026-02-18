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

	void clearLayer(uint32_t layerID);

	void setLayer(uint32_t layerID);

	int addLayer(int zOrder);//return assigned layer id

	void drawChar(const Vec2<size_t>& pos, const DrawableChar& chr);

	void drawLine(const DrawableChar& chr, const V2i32& p1, const V2i32& p2);

	void drawTriangle(const DrawableChar& chr, const V2i32& p1, const V2i32& p2, const V2i32& p3, bool filled = false);

	void drawRect(const DrawableChar& chr, const V2i32& pos, const V2i32& size, bool filled = false);

	void drawCircle(const DrawableChar& chr, const V2i32& origin, uint32_t radius, bool filled = false);

	void drawString(const V2i32& pos, const std::string& string, Color foregCol, Color backgCol);

	void drawSprite(const V2i32& pos, const Sprite& sprite);

private:

	struct Layer {
		int ID;
		int zOrder;
		Matrix<DrawableChar> data;
	};

	bool zOrderExists(int zOrder);

	void sortLayers();

	DrawableChar getTopmostChr(const Vec2<size_t>& pos);

	Layer& getLayerByID(int layerID);

	Vec2<size_t> layerSize;

	uint32_t currentLayerID;

	std::vector<Layer> layers;

};

} // tiage
