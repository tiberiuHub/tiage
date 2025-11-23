// Copyright Tiberiu 2025

#pragma once

#include <utility>
#include <tiage/IConsole.h>
#include <tiage/Matrix.h>
#include <tiage/Vec2.h>

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

	void doFitToConsole() override;

private:

	Vec2<uint32_t> currentConsoleSize_;//not neccesary for functions

	Vec2<uint32_t> desiredCanvasSize_;

	Vec2<uint32_t> getConsoleSize() const;

	void resizeDesiredCanvasSize(uint32_t width, uint32_t height);

	void resizeCanvas(uint32_t width, uint32_t height);

};

} // tiage
