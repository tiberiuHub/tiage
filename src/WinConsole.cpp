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

WinConsole::WinConsole(uint32_t width, uint32_t height){
	commands_ = tiage::Matrix<cmd_t> (width, height);
	commands_.set({Color::Brown,'W'});
	std::cout << "\033[8;"<< width<<";"<< height <<"t"; 
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doDestroy() {
	FreeConsole();
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doCreate(uint32_t width, uint32_t height) {
	AllocConsole();

	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doPutChar(uint32_t x, uint32_t y, Color color, char c) {
	//commands_->set(x, y, { color,c });
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doFlush() {
	std::stringstream frameBuffer;

	//fitToConsole();

	frameBuffer << "\033[H";
	for (uint32_t y = 0; y < commands_.nRows(); y++) {
		for (uint32_t x = 0; x < commands_.nCols(); x++) {
			if (auto command = commands_.get(x, y); command.c != ' ') {
				auto code = ansiColorCode(command.color);
				frameBuffer << code.first << command.c << code.second;
				//frameBuffer <<command.c;
			} else {
				frameBuffer << ' ';
			}
		}
		frameBuffer << '\n';
	}

	std::cout << frameBuffer.str();
	
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doClear() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::fitToConsole() {

	auto currentConsole = getConsoleSize();

	int width = currentConsole.first;
	int height = currentConsole.second;

	width = std::min(width, static_cast<int>(commands_.nRows()));
	height = std::min(height, static_cast<int>(commands_.nCols()));

	if (width != commands_.nCols() || height != commands_.nRows()) {
		resizeCanvas(width, height);
		clear();
	}

	currentConsoleSize_ = currentConsole;

}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doSetCursorVisible(bool visible) {
	std::cout << (visible ? "\033[?25h" : "\033[?25l");
}

// -------------------------------------------------------------------------------------------------

std::pair<int, int>
WinConsole::getConsoleSize() {
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

void
WinConsole::resizeCanvas(uint32_t width, uint32_t height) {
	commands_ = tiage::Matrix<cmd_t>(width, height);
}

// -------------------------------------------------------------------------------------------------

} // tiage

