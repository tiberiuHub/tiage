// Copyright Tiberiu 2025

#pragma once

<<<<<<< HEAD
#include <utility>
#include <tiage/IConsole.h>
#include <tiage/Matrix.h>
#include <tiage/Vec2.h>
=======
#include <iostream>
#include <vector>
#include <utility>
#include <tiage/IConsole.h>
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1

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

<<<<<<< HEAD
	void doFitToConsole() override;

private:

	Vec2<uint32_t> currentConsoleSize_;//not neccesary for functions

	Vec2<uint32_t> desiredCanvasSize_;

	Vec2<uint32_t> getConsoleSize() const;

	void resizeDesiredCanvasSize(uint32_t width, uint32_t height);

	void resizeCanvas(uint32_t width, uint32_t height);

=======
private:

	std::pair<int, int>currentConsoleSize_;

	void fitToConsole();

	std::pair<int,int>getConsoleSize();

	void resizeCanvas(uint32_t width, uint32_t height);
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
};

} // tiage
