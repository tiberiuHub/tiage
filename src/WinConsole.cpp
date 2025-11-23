// Copyright Tiberiu 2025

#pragma once

#include "tiage/WinConsole.h"
#include "tiage/Color.h"
#include <iostream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <algorithm>

namespace tiage {

// -------------------------------------------------------------------------------------------------

<<<<<<< HEAD
WinConsole::WinConsole(uint32_t width, uint32_t height) {
	commands_ = Matrix<cmd_t>(width,height);
	currentConsoleSize_ = { 120,30 };
	desiredCanvasSize_ = { 120,30 };//placeholders
=======
WinConsole::WinConsole(uint32_t width , uint32_t height) {
	commands_ = tiage::Matrix <cmd_t>(width, height);
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
}

// -------------------------------------------------------------------------------------------------

void
<<<<<<< HEAD
WinConsole::doCreate(uint32_t width, uint32_t height) {
	resizeDesiredCanvasSize(width, height);
	resizeCanvas(width, height);
=======
WinConsole::doDestroy() {
	FreeConsole();
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
}

// -------------------------------------------------------------------------------------------------

void
<<<<<<< HEAD
WinConsole::doDestroy() {
	//FreeConsole();
=======
WinConsole::doCreate(uint32_t width, uint32_t height) {
	AllocConsole();

	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
}

// -------------------------------------------------------------------------------------------------

void
<<<<<<< HEAD
WinConsole::doSetCursorVisible(bool visible) {
	std::cout << (visible ? "\033[?25h" : "\033[?25l");
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doPutChar(uint32_t x, uint32_t y, Color color, char c) {
	if (x < commands_.nCols() && y < commands_.nRows()) {
		commands_.set(x, y, { color, c });
	}
=======
WinConsole::doPutChar(uint32_t x, uint32_t y, Color color, char c) {
	//commands_->set(x, y, { color,c });
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doFlush() {
<<<<<<< HEAD

	//doClear();

	std::stringstream frameBuffer;

	doFitToConsole();
=======
	std::stringstream frameBuffer;

	//fitToConsole();
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1

	frameBuffer << "\033[H";
	for (uint32_t y = 0; y < commands_.nRows(); y++) {
		for (uint32_t x = 0; x < commands_.nCols(); x++) {
<<<<<<< HEAD
			auto command = commands_.get(x, y);
			std::pair<std::string, std::string>  code = ansiColorCode(command.color);
			frameBuffer << code.first << command.c << code.second;
		}
		if (y != commands_.nRows() - 1) {
			frameBuffer << '\n';
		}

=======
			if (auto command = commands_.get(x, y); command.c != ' ') {
				auto code = ansiColorCode(command.color);
				frameBuffer << code.first << command.c << code.second;
				//frameBuffer <<command.c;
			} else {
				frameBuffer << ' ';
			}
		}
		frameBuffer << '\n';
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
	}

	std::cout << frameBuffer.str();
	
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doClear() {
<<<<<<< HEAD
	//#ifdef _WIN32
	//	std::system("cls");
	//#else
	//	std::system("clear");
	//#endif
	commands_.set({ Color::White,' ' });
=======
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
}

// -------------------------------------------------------------------------------------------------

void
<<<<<<< HEAD
WinConsole::doFitToConsole() {

	auto currentConsole = getConsoleSize();

	int cols = currentConsole.x;
	int rows = currentConsole.y;
	//std::cout <<"                 " << desiredCanvasSize_.x << ',' << desiredCanvasSize_.y << ';' << rows << ',' << cols;
	cols = std::min(cols, static_cast<int>(desiredCanvasSize_.x));
	rows = std::min(rows, static_cast<int>(desiredCanvasSize_.y));
	
	//if (cols == 0) {
	// cols = 10;
	// }
	//if (rows == 0) {
	// rows = 10;
	// }
	if (cols != commands_.nCols() || rows != commands_.nRows()) {
		resizeCanvas(cols, rows);
=======
WinConsole::fitToConsole() {

	auto currentConsole = getConsoleSize();

	int width = currentConsole.first;
	int height = currentConsole.second;

	width = std::min(width, static_cast<int>(commands_.nRows()));
	height = std::min(height, static_cast<int>(commands_.nCols()));

	if (width != commands_.nCols() || height != commands_.nRows()) {
		resizeCanvas(width, height);
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
		clear();
	}

	currentConsoleSize_ = currentConsole;

}

// -------------------------------------------------------------------------------------------------

<<<<<<< HEAD
Vec2 <uint32_t>
WinConsole::getConsoleSize() const {
=======
void
WinConsole::doSetCursorVisible(bool visible) {
	std::cout << (visible ? "\033[?25h" : "\033[?25l");
}

// -------------------------------------------------------------------------------------------------

std::pair<int, int>
WinConsole::getConsoleSize() {
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
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

	return { static_cast<uint32_t>(cols), static_cast<uint32_t>(rows) };
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::resizeDesiredCanvasSize(uint32_t width, uint32_t height) {
	desiredCanvasSize_ = { width,height };
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::resizeCanvas(uint32_t width, uint32_t height) {
	commands_ = Matrix<cmd_t>(width,height);
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::resizeCanvas(uint32_t width, uint32_t height) {
	commands_ = tiage::Matrix<cmd_t>(width, height);
}

// -------------------------------------------------------------------------------------------------

} // tiage

