// Copyright Tiberiu 2025

#include "tiage/Renderer.h"
#include <algorithm>

namespace tiage {

// --------------------------------------------------------------------------------------------------

Renderer::Renderer(Vec2<size_t> bufrSize) {
	auto x = bufrSize.x();
	auto y = bufrSize.y();
	layerSize = { x,y };
	currentLayerID = 0;
}

// --------------------------------------------------------------------------------------------------

void
Renderer::clear() {
	for (size_t i = 0; i < layers.size(); i++) {
		clearLayer(static_cast<int>(i));
	}
}

// --------------------------------------------------------------------------------------------------

void
Renderer::clearLayer(uint32_t layerID) {
	layers[layerID].data.set(DrawableChar::kDefault);
}

// --------------------------------------------------------------------------------------------------

int
Renderer::addLayer(int zOrder) {

	if (zOrderExists(zOrder)) {
		throw std::runtime_error("Cannot have two layers with equal z order");
	}

	layers.push_back({ static_cast<int>(layers.size()), zOrder, Matrix<DrawableChar>(layerSize) });
	sortLayers();
	return static_cast<int>(layers.size() - 1);
}

// --------------------------------------------------------------------------------------------------

void 
Renderer::drawChar(const Vec2<size_t>& pos, const DrawableChar& chr) {
	getLayerByID(currentLayerID).data.set(pos, chr);
}

// --------------------------------------------------------------------------------------------------

void 
Renderer::drawRect(
	const DrawableChar& chr,
	const V2i32& pos,
	const V2i32& size,
	bool filled
) {
	for (size_t x = 0; x < size.x(); x++) {
		for (size_t y = 0; y < size.y(); y++) {

			bool border =
				x == 0 || y == 0 ||
				x == size.x() - 1 || y == size.y() - 1;

			if (pos.x() + x >= layerSize.x() || pos.y() + y >= layerSize.y()) {
				continue; // skip out-of-bounds pixels
			}

			if (filled || border) {
				drawChar({ pos.x() + x,pos.y() + y },chr);
			}
		}
	}
}

// --------------------------------------------------------------------------------------------------


void
Renderer::drawSprite(const V2i32& pos, const Sprite& sprite) {
	auto size = sprite.getSize();

	for (size_t x = 0; x < size.x(); x++) {
		for (size_t y = 0; y < size.y(); y++) {
			DrawableChar chr = sprite.getChar({ x, y });

			if (pos.x() + x >= layerSize.x() || pos.y() + y >= layerSize.y()) {
				continue;
			}

			if (chr != DrawableChar::kDefault) {
				drawChar({ pos.x() + x, pos.y() + y }, chr);
			}
		}
	}
}

// --------------------------------------------------------------------------------------------------

void 
Renderer::drawLine(const DrawableChar& chr, const V2i32& p1, const V2i32& p2) {
	int x0 = p1.x();
	int y0 = p1.y();
	int x1 = p2.x();
	int y1 = p2.y();

	int dx = std::abs(x1 - x0);
	int dy = -std::abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;  

	while (true) {
		if (x0 >= 0 && x0 < layerSize.x() &&
			y0 >= 0 && y0 < layerSize.y()) {
			drawChar({ static_cast<size_t>(x0), static_cast<size_t>(y0)}, chr);
		}

		if (x0 == x1 && y0 == y1) break;

		int e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}
	}
}
// --------------------------------------------------------------------------------------------------

void
Renderer::drawTriangle(
	const DrawableChar& chr,
	const V2i32& p1,
	const V2i32& p2,
	const V2i32& p3,
	bool filled
) {
	

	V2i32 v1 = p1;
	V2i32 v2 = p2;
	V2i32 v3 = p3;

	if (v2.y() < v1.y()) std::swap(v1, v2);
	if (v3.y() < v1.y()) std::swap(v1, v3);
	if (v3.y() < v2.y()) std::swap(v2, v3);

	auto edgeInterp = [](const V2i32& a, const V2i32& b, int y) {
		if (a.y() == b.y()) return a.x();
		return a.x() + (y - a.y()) * (b.x() - a.x()) / (b.y() - a.y());
		};

	for (size_t y = v1.y(); y <= v2.y(); ++y) {
		int x1 = edgeInterp(v1, v3, y);
		int x2 = edgeInterp(v1, v2, y);
		if (x1 > x2) std::swap(x1, x2);


		for (size_t x = x1; x <= x2; ++x) {
			if ((!filled && (x == x1 || x == x2)) or filled) {
				drawChar({x, y}, chr);
			}
			
		}
	}

	for (size_t y = v2.y(); y <= v3.y(); ++y) {
		int x1 = edgeInterp(v1, v3, y);
		int x2 = edgeInterp(v2, v3, y);
		if (x1 > x2) std::swap(x1, x2);

		for (size_t x = x1; x <= x2; ++x) {
			if ((!filled && (x == x1 || x == x2)) or filled ) {
				drawChar({ x, y }, chr);
			}
			
		}
	}
}

// --------------------------------------------------------------------------------------------------

void
Renderer::setLayer(uint32_t layerID) {
	if (layerID >= static_cast<int>(layers.size())) {
		throw std::out_of_range("Invalid layer index");
	}
	currentLayerID = layerID;
}

// --------------------------------------------------------------------------------------------------

Renderer::Layer&
Renderer::getLayerByID(int layerID) {
	for (auto& layer : layers) {
		if (layer.ID == layerID) {
			return layer;
		}
	}
	throw std::out_of_range("ID not found");
}

// --------------------------------------------------------------------------------------------------

void 
Renderer::drawCircle(
	const DrawableChar& chr,
	const V2i32& origin,
	uint32_t radius,
	bool filled
) {
	if (radius == 0) return;

	const int cx = origin.x();
	const int cy = origin.y();
	const int segments = radius * 3; // more segments for bigger circles
	const double angleStep = 2.0 * 3.141 / segments;

	if (filled) {
		// For a filled circle, draw lines from center to perimeter
		for (int i = 0; i < segments; ++i) {
			double theta = i * angleStep;
			int x = cx + static_cast<int>(radius * std::cos(theta));
			int y = cy + static_cast<int>(radius * std::sin(theta));
			drawLine(chr, origin, V2i32{ x, y });
		}
	} else {
		// For outline, just plot points along the perimeter
		for (int i = 0; i < segments; ++i) {
			double theta = i * angleStep;
			size_t x = cx + static_cast<int>(radius * std::cos(theta));
			size_t y = cy + static_cast<int>(radius * std::sin(theta));
			drawChar({ x, y }, chr);
		}
	}
}

// --------------------------------------------------------------------------------------------------

void
Renderer::drawString(
	const V2i32& pos, 
	const std::string& string, 
	Color foregCol, 
	Color backgCol
) {
	for (size_t i = 0; i < string.size(); i++) {
		const char& chr = string[i];
		
	}
}


// --------------------------------------------------------------------------------------------------

void
Renderer::present(IConsole& console, const V2i32& offset) {
	for (size_t x = 0; x < layerSize.x(); x++) {
		for (size_t y = 0; y < layerSize.y(); y++) {
			console.putChar(
				x + offset.x(),
				y + offset.y(),
				getTopmostChr({ x, y })
			);
		}
	}
}

// --------------------------------------------------------------------------------------------------

bool
Renderer::zOrderExists(int zOrder) {
	for (const auto& layer : layers) {
		if (layer.zOrder == zOrder) {
			return true;
		}
	}
	return false;
}

// --------------------------------------------------------------------------------------------------

void
Renderer::sortLayers() {
	std::sort(layers.begin(), layers.end(),
		[](const Layer& a, const Layer& b) {
			return a.zOrder < b.zOrder;
		});
}

// --------------------------------------------------------------------------------------------------

DrawableChar
Renderer::getTopmostChr(const Vec2<size_t>& pos) {
	for (auto i = layers.rbegin(); i != layers.rend(); ++i) {
		const auto& chr = i->data.get(pos);
		if (chr != DrawableChar::kDefault) {
			return chr;
		}
	}
	return DrawableChar::kDefault;
}

// --------------------------------------------------------------------------------------------------

} // tiage
