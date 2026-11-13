// Copyright Tiberiu 2025

#include "tiage/Renderer.h"
#include <algorithm>

namespace tiage {

// --------------------------------------------------------------------------------------------------

Renderer::Renderer(Vec2<size_t> bufrSize) {
	auto x = bufrSize.x();
	auto y = bufrSize.y();
	layerSize = { x,y };
	currentZ = 0;
	layers.resize(1);
}

// --------------------------------------------------------------------------------------------------

void
Renderer::clear() {
	layers.clear();
}

// --------------------------------------------------------------------------------------------------

void
Renderer::present(IConsole& console, const V2i32& offset) {
	std::sort(layers.begin(), layers.end(),
		[](const cmd_t& a, const cmd_t& b) {
			return a.z < b.z;
		}
	);
	for (size_t i = 0; i < layers.size(); i++) {
		const cmd_t& cmd = layers[i];
		const uint8_t& alpha = cmd.chr.bg().a();
		if ( alpha != 255) {
			const Color& bgUnder = console.getChar(cmd.pos).bg();
			Color blended =cmd.chr.bg() * alpha +
						   bgUnder * (255 - alpha);
			console.putChar(cmd.pos, 
							{cmd.chr.c(),cmd.chr.fg(),blended});
		} else {
			console.putChar(cmd.pos, cmd.chr);
		}
	}
	clear();
}

// --------------------------------------------------------------------------------------------------

void
Renderer::doubleRendering(bool value) {
	doubleRenderEnabled = value;
}

// --------------------------------------------------------------------------------------------------

void
Renderer::drawChar(const Vec2<size_t>& pos, const DrawableChar& chr) {
	if (!doubleRenderEnabled) {
		if (posInside(pos)) {
			layers.push_back({ currentZ, pos, chr });
		}
	} else {
		if (posInside({ pos.x() * 2 + 1, pos.y() })) {
			layers.push_back({ currentZ, { pos.x() * 2, pos.y() }, chr });
			layers.push_back({ currentZ, { pos.x() * 2 + 1, pos.y() }, chr });
		}
	}
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
				drawChar({ pos.x() + x,pos.y() + y }, chr);
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
			drawChar({ static_cast<size_t>(x0), static_cast<size_t>(y0) }, chr);
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
				drawChar({ x, y }, chr);
			}

		}
	}

	for (size_t y = v2.y(); y <= v3.y(); ++y) {
		int x1 = edgeInterp(v1, v3, y);
		int x2 = edgeInterp(v2, v3, y);
		if (x1 > x2) std::swap(x1, x2);

		for (size_t x = x1; x <= x2; ++x) {
			if ((!filled && (x == x1 || x == x2)) or filled) {
				drawChar({ x, y }, chr);
			}

		}
	}
}

// --------------------------------------------------------------------------------------------------

void
Renderer::changeZ(uint32_t layerZ) {
	if (layerZ > layers.size() - 1) {
		layers.resize(layerZ + 1);
		currentZ = layerZ;
	}
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
		char chr = string[i];
		drawChar({static_cast<uint64_t>( pos.x() + i),static_cast<uint64_t>(pos.y()) },
			{chr,foregCol,backgCol});
	}
}

// --------------------------------------------------------------------------------------------------

bool
Renderer::posInside(const Vec2<size_t>& pos) const {
	return pos <= layerSize;
}

// --------------------------------------------------------------------------------------------------

void
Renderer::drawSprite(const V2i32& pos, const Sprite& sprite) {
	auto size = sprite.getSize();
	auto ofst = sprite.getOffset();
	for (size_t x = 0; x < size.x(); x++) {
		for (size_t y = 0; y < size.y(); y++) {
			DrawableChar chr = sprite.getChar({ x, y });

			if (pos.x() + x >= layerSize.x() || pos.y() + y >= layerSize.y()) {
				continue;
			}

			if (chr != DrawableChar::kDefault) {
				drawChar({ pos.x() + x + ofst.x(), pos.y() + y + ofst.y() }, chr);
			}
		}
	}
}

// --------------------------------------------------------------------------------------------------

void
Renderer::drawObject(const V2i32& pos, const Object& object) {

	if (!object.hasSprite()) {
		return;
	}

	const Sprite* sprite = object.sprite();
	auto size = sprite->getSize();
	auto ofst = sprite->getOffset() + object.pos();
	for (size_t x = 0; x < size.x(); x++) {
		for (size_t y = 0; y < size.y(); y++) {
			DrawableChar chr = sprite->getChar({ x, y });

			if (pos.x() + x >= layerSize.x() || pos.y() + y >= layerSize.y()) {
				continue;
			}

			if (chr != DrawableChar::kDefault) {
				drawChar({ pos.x() + x + ofst.x(), pos.y() + y + ofst.y() }, chr);
			}
		}
	}
}

// --------------------------------------------------------------------------------------------------

} // tiage
