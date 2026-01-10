	// Copyright Tiberiu 2025

	#pragma once

	#include "tiage/IConsole.h"
	#include "tiage/Matrix.h"
	#include "tiage/Sprite.h"

	namespace tiage {

	class Renderer {
	public:

		Renderer(Vec2<size_t> bufrSize);

		void clear();

		void present(IConsole& console, const V2i32& offset = { 0,0 });

		void clearLayer(uint32_t layerID);

		void setLayer(uint32_t layerID);

		int addLayer(int zOrder);//return assigned layer id

		void drawLine(const DrawableChar& chr, const V2i32& p1, const V2i32& p2);

		void drawTriangle(const V2i32& p1, const V2i32& p2, const V2i32& p3, const DrawableChar& chr, bool filled = false);

		void drawSquare(const V2i32& pos, const V2i32& size, const DrawableChar& chr, bool filled = false);

		void drawCircle(const V2i32& origin, uint32_t radius, bool filled = false);

		void drawSprite(const V2i32& pos, const Sprite& sprite);

	private:

		struct Layer {
			int ID;
			int zOrder;
			Matrix<DrawableChar> data;
		};

		bool zOrderExists(int zOrder);

		void sortLayers();

		DrawableChar getTopmostChr(const V2i32& pos);

		Layer& getLayerByID(int layerID);

		Vec2<size_t> layerSize;
		
		uint32_t currentLayerID;

		std::vector<Layer> layers;

	};

	} // tiage
