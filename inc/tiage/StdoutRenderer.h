// Copyright Tiberiu 2025

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <tiage/IAsciiRenderer.h>
#include <tiage/Matrix.h>

namespace tiage {

class StdoutRenderer : public IAsciiRenderer {
public:

	StdoutRenderer(uint32_t width, uint32_t height);

	void beginFrame() override;

	void resizeDesiredCanvas(uint32_t width, uint32_t height) override;

	void putChar(uint32_t x, uint32_t y, Color color, char c) override;

	void endFrame() override;

	void render() override;

	void clear() override;

	void setCursorVisible(bool visible) override;

	std::pair<int, int>getConsoleSize();

private:

	void fitToConsole();

	void resizeCanvas(uint32_t width, uint32_t height);

	struct cmd_t {
		Color color;
		char c;
	};
	
	Matrix<cmd_t> commands_;

	std::pair<int, int>desiredCanvasSize_;

	std::pair<int, int>consoleSize_;

};

} // tiage
