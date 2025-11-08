// Copyright Tiberiu 2025

#pragma once

#include "tiage/StdoutRenderer.h"
#include "tiage/Color.h"
#include <iostream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <algorithm>

namespace tiage {

// -------------------------------------------------------------------------------------------------

StdoutRenderer::StdoutRenderer(uint32_t width, uint32_t height) :
	commands_(height, width) {
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::beginFrame() {
	for (uint32_t y = 0; y < commands_.nRows(); y++) {
		for (uint32_t x = 0; x < commands_.nCols(); x++) {
			commands_.set(x, y, { Color::White, ' ' }); // x=col, y=row
		}
	}
}


// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::resizeDesiredCanvas(uint32_t width, uint32_t height) {
	desiredCanvasSize_ = { width,height };
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::resizeCanvas(uint32_t width, uint32_t height) {
	commands_ = Matrix<cmd_t>(height, width);
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::putChar(uint32_t x, uint32_t y, Color color, char c) {
	if (y < commands_.nCols() && x < commands_.nRows()) {
		commands_.get(y, x) = { color,c };
	}
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::endFrame() {
	// ?
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::render() {
	std::stringstream frameBuffer;

	fitToConsole();

	frameBuffer << "\033[H";

	for (uint32_t y = 0; y < commands_.nRows(); y++) {
		for (uint32_t x = 0; x < commands_.nCols(); x++) {
			if (auto command = commands_.get(x, y); command.c != ' ') {
				auto code = ansiColorCode(command.color);
				frameBuffer << code.first << command.c << code.second;
			} else {
				frameBuffer << ' ';
			}
		}
		if (y != commands_.nRows() - 1) {
			frameBuffer << '\n';
		}
		
	}

	std::cout << frameBuffer.str();
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::clear() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::fitToConsole() {

	auto currentConsole = getConsoleSize();

	int width = currentConsole.first;
	int height = currentConsole.second;

	width = std::min(width, desiredCanvasSize_.first);
	height = std::min(height, desiredCanvasSize_.second);

	if (width != commands_.nCols() || height != commands_.nRows()) {
		resizeCanvas(width, height);
		clear();
	}

	consoleSize_ = currentConsole;

}

// -------------------------------------------------------------------------------------------------

void
StdoutRenderer::setCursorVisible(bool visible) {
	std::cout << (visible ? "\033[?25h" : "\033[?25l");
}

// -------------------------------------------------------------------------------------------------

std::pair<int, int>
StdoutRenderer::getConsoleSize() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) {
		return { 0, 0 };
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		return { 0, 0 };
	}

	SHORT cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	SHORT rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return { static_cast<int>(cols), static_cast<int>(rows) };
}

// -------------------------------------------------------------------------------------------------

} // tiage

