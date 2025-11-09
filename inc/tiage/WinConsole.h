// Copyright Tiberiu 2025

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <tiage/IConsole.h>

namespace tiage {

class WinConsole : public IConsole {
public:

	WinConsole(uint32_t width, uint32_t height);

	void doCreate(uint32_t width, uint32_t height) override;

	void doDestroy() override;

	void doSetCursorVisible(bool visible) override;

	void doPutChar(uint32_t x, uint32_t y, Color color, char c) override;

	void doFlush() override;

	void doClear() override;

private:

	std::pair<int, int>currentConsoleSize_;

	void fitToConsole();

	std::pair<int,int>getConsoleSize();

	void resizeCanvas(uint32_t width, uint32_t height);
};

} // tiage
