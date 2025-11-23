// Copyright Tiberiu 2025

#pragma once

#include <tiage/Color.h>
#include <tiage/Matrix.h>

namespace tiage {

class IConsole {
public:

	virtual ~IConsole() = default;

	void create(uint32_t width, uint32_t height);

	void destroy();

	void setCursorVisible(bool visible);

	void putChar(uint32_t x, uint32_t y, Color color, char c);
<<<<<<< HEAD

	void flush();

	void clear();

	void fitToConsole();

=======
	
	void flush();
	
	void clear();

>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
protected:

	virtual void doCreate(uint32_t width, uint32_t height) = 0;

	virtual void doDestroy() = 0;

	virtual void doSetCursorVisible(bool visible) = 0;

	virtual void doPutChar(uint32_t x, uint32_t y, Color color, char c) = 0;

	virtual void doFlush() = 0;

	virtual void doClear() = 0;

<<<<<<< HEAD
	virtual void doFitToConsole() = 0;

	struct cmd_t {
		Color color = Color::White;
		char c = ' ';
=======
	struct cmd_t {
		Color color = Color::White;
		char c = 0;
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
	};

	Matrix<cmd_t> commands_;

<<<<<<< HEAD
=======
private:

	
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
};

} // tiage
