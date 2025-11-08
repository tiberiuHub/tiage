// Copyright Tiberiu 2025

#pragma once

#include <tiage/Color.h>

namespace tiage {

class IAsciiRenderer {
public:

	virtual ~IAsciiRenderer() = default;

	virtual void resizeDesiredCanvas(uint32_t width, uint32_t height) = 0;

	virtual void setCursorVisible(bool visible) = 0;

	virtual void beginFrame() = 0;
	
	virtual void putChar(uint32_t x, uint32_t y, Color color, char c) = 0;
	
	virtual void endFrame() = 0;

	virtual void render() = 0;
	
	virtual void clear() = 0;
};

} // tiage
