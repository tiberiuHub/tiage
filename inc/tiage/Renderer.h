	// Copyright Tiberiu 2025

	#pragma once

	#include "tiage/IConsole.h"
	#include "tiage/Matrix.h"
	#include "tiage/Sprite.h"

	namespace tiage {

	class Renderer {
	public:

		Renderer(V2i32 bufrSize);

		void clear();

		void clearLayer(int layer);

		void setLayer(int layer);

		int addLayer(int zOrder);//return assigned layer id

		void drawSquare(const V2i32& pos, const V2i32& size, bool filled = false, const DrawableChar& chr);

		void drawSprite(const V2i32& pos, const Sprite& sprite);

		void drawLine(const DrawableChar& chr ,const V2i32& p1, const V2i32& p2);

		void drawTriangle(const V2i32& p1, const V2i32& p2, const V2i32& p3, const DrawableChar& chr, bool filled = false);

		//void drawPolygon(const std::vector<V2i32>& points, const DrawableChar& chr, bool filled = false);

		void present(IConsole& console, const V2i32& offset = {0,0});

	private:

		struct Layer {
			int ID;
			int zOrder;
			Matrix<DrawableChar> data;
		};

		bool zOrderExists(int zOrder);

		void sortLayers();

		DrawableChar getTopmostChr(const V2i32& pos);

		Vec2<size_t> layerSize;
		
		int currentLayer;

		std::vector<Layer> layers;

	};

	} // tiage
