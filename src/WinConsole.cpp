// Copyright Tiberiu 2025

#include "tiage/WinConsole.h"
#include "tiage/Color.h"
#include <cassert>
#include <iostream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <tlhelp32.h>
#include <algorithm>

namespace tiage {

// -------------------------------------------------------------------------------------------------

WinConsole::WinConsole(Vec2<size_t> bufferSize) {
	buffer_ = Matrix<DrawableChar>({ bufferSize.x(),bufferSize.y()});
}

// -------------------------------------------------------------------------------------------------

bool
WinConsole::doCreate(uint64_t createOptions) {
	FreeConsole();
	if (!AllocConsole()) {
		throw std::runtime_error("AllocConsole failed");
		return false;
	}


	if (!freopen("CONIN$", "r", stdin) ||
		!freopen("CONOUT$", "w", stdout) ||
		!freopen("CONERR$", "w", stderr)) {
		throw std::runtime_error("freeopen failed");
		return false;
	}
	if (winHandle_ = GetConsoleWindow(); winHandle_ == NULL) {
		throw std::runtime_error("winHandle not found");
		return false;
	}
	LONG style = GetWindowLong(winHandle_, GWL_STYLE);
	if (createOptions & create_options_t::NoMinimize) {
		style &= ~WS_MINIMIZEBOX;
	}
	if (createOptions & create_options_t::NoMaximize) {
		style &= ~WS_MAXIMIZEBOX;
	}
	if (createOptions & create_options_t::NoResize) {
		style &= ~WS_SIZEBOX;
	}
	if (createOptions & create_options_t::NoScrollH) {
		style &= ~WS_HSCROLL;
	}
	if (createOptions & create_options_t::NoScrollV) {
		style &= ~WS_VSCROLL;
	}
	if (!SetWindowLong(winHandle_, GWL_STYLE, style)) {
		throw std::runtime_error("operation failed");
	}
	if (inHandle_ = GetStdHandle(STD_INPUT_HANDLE); inHandle_ == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("operation failed");
		return false;
	} else {
		DWORD inMode = 0;
		//GetConsoleMode(inHandle_, &inMode);
		inMode |= (createOptions & EnableProcessedInput) ? ENABLE_PROCESSED_INPUT : 0;
		inMode |= (createOptions & EnableLineInput) ? ENABLE_LINE_INPUT : 0;
		inMode |= (createOptions & EnableEchoInput) ? ENABLE_ECHO_INPUT : 0;
		inMode |= (createOptions & EnableWindowInput) ? ENABLE_WINDOW_INPUT : 0;
		inMode |= (createOptions & EnableMouseInput) ? ENABLE_MOUSE_INPUT : 0;
		inMode |= (createOptions & EnableInsertMode) ? ENABLE_INSERT_MODE : 0;
		inMode |= (createOptions & EnableQuickEditMode) ? ENABLE_QUICK_EDIT_MODE : 0;
		inMode |= (createOptions & EnableExtendedFlags) ? ENABLE_EXTENDED_FLAGS : 0;
		inMode |= (createOptions & EnableAutoPosition) ? ENABLE_AUTO_POSITION : 0;
		inMode |= (createOptions & EnableVirtualTerminalInput) ? ENABLE_VIRTUAL_TERMINAL_INPUT : 0;
		if (!SetConsoleMode(inHandle_, inMode)) {
			throw std::runtime_error("operation failed");
			return false;
		}
	}
	if (outHandle_ = GetStdHandle(STD_OUTPUT_HANDLE); outHandle_ == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("operation failed");
		return false;
	} else {
		DWORD outMode = 0;
		outMode |= (createOptions & EnableProcessedOutput) ? ENABLE_PROCESSED_OUTPUT : 0;
		outMode |= (createOptions & EnableWrapAtEolOutput) ? ENABLE_WRAP_AT_EOL_OUTPUT : 0;
		outMode |= (createOptions & EnableVirtualTerminalProcessing) ? ENABLE_VIRTUAL_TERMINAL_PROCESSING : 0;
		outMode |= (createOptions & DisableNewlineAutoReturn) ? DISABLE_NEWLINE_AUTO_RETURN : 0;
		outMode |= (createOptions & EnableLvbGridWorldwide) ? ENABLE_LVB_GRID_WORLDWIDE : 0;
		if (!SetConsoleMode(outHandle_, outMode)) {
			assert(0);
			return false;
		}
	}

	system("cls");
	winHandle_ = GetConsoleWindow();
	return true;
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doDestroy() {
	fclose(stdout);
	fclose(stderr);
	fclose(stdin);
	FreeConsole();
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doSetTitle(const std::string& title) {
	if (!SetConsoleTitle(title.c_str())) {
		assert(0);
	}
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doMove(std::optional<tiage::V2i32> maybePos, std::optional<Vec2<size_t>> maybeSize) {
	if (maybePos) {
		if (!SetWindowPos(winHandle_, 0, maybePos->x(), maybePos->y(), 0, 0,
			SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE)) {
			std::cout << GetLastError();
			assert(0);
			return;
		}
	}
	if (maybeSize) {
		CONSOLE_SCREEN_BUFFER_INFOEX sbi = { sizeof(CONSOLE_SCREEN_BUFFER_INFOEX) };
		//GetConsoleScreenBufferInfoEx(outHandle_, &sbi);
		if (!GetConsoleScreenBufferInfoEx(outHandle_, &sbi)) {
			assert(0);
		}
		buffer_ = Matrix<DrawableChar>({ maybeSize->x(), maybeSize->y() });
		sbi.dwSize = { static_cast<SHORT>(maybeSize->x()), static_cast<SHORT>(maybeSize->y()) };
		sbi.srWindow = { 0, 0, static_cast<SHORT>(sbi.dwSize.X - 1), static_cast<SHORT>(sbi.dwSize.Y - 0 * 1) };
		sbi.dwMaximumWindowSize = sbi.dwSize;
		if (!SetConsoleScreenBufferInfoEx(outHandle_, &sbi)) {
			assert(0);
		}
	}
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doResizeFont(size_t fontSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		return;
	}

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	if (!GetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
		return;
	}		

	cfi.dwFontSize.X = 0; 
	cfi.dwFontSize.Y = fontSize;  

	wcscpy_s(cfi.FaceName, L"Consolas");

	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doSetCursorVisible(bool visible) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doPutChar(const Vec2<size_t>& pos, const DrawableChar& ch) {
	buffer_.set(pos, ch);
}

// -------------------------------------------------------------------------------------------------

DrawableChar
WinConsole::doGetChar(const Vec2<size_t>& pos) const {
	return buffer_.get(pos);
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doFlush(const V2i32& offset) {

	auto consoleSize = getConsoleSize();

	currentConsoleSize_ = consoleSize;

	//calculate how far we can flush based on offset and window size
	int32_t rowStart = std::max<int32_t>(0, -offset.x());
	int32_t colStart = std::max<int32_t>(0, -offset.y());
	int32_t rowEnd = std::min<int32_t>(consoleSize.y(), buffer_.nRows() + offset.x());
	int32_t colEnd = std::min<int32_t>(consoleSize.x(), buffer_.nCols() + offset.y());

	if (buffer_.nCols() == 0 && buffer_.nRows() == 0) {
		return;
	} else if (currentConsoleSize_ != consoleSize) {
		clear();
	}

	std::string frameBuffer;
	frameBuffer.reserve(buffer_.nRows() * buffer_.nCols() * 2);
	Color lastFg = Color::kWhite;
	Color lastBg = Color::kBlack;

	frameBuffer += ansiBackgroundColorCode(Color::kBlack) + ansiForegroundColorCode(Color::kWhite);

	for (uint32_t y = rowStart; y < rowEnd - offset.y(); y++) {

		frameBuffer += cursorMoveCode({
		static_cast<uint32_t>(y + offset.y()),
		static_cast<uint32_t>(offset.x())
			});

		for (uint32_t x = colStart; x < colEnd - offset.x(); x++) {
			auto command = buffer_.get({ x, y });

			if (command.bg() != lastBg) {
				lastBg = command.bg();
				frameBuffer += ansiBackgroundColorCode(lastBg);
			 }

			 if (command.fg() != lastFg) {
				lastFg = command.fg();
				frameBuffer += ansiForegroundColorCode(lastFg);
			}

			frameBuffer += command.c();

		}

	}

	frameBuffer += kAnsiColorReset;

	std::cout << frameBuffer.c_str();
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doClear() {
	std::system("cls");
	buffer_.set({ ' ', Color::kWhite, Color::kBlack });
}

// -------------------------------------------------------------------------------------------------

std::string
WinConsole::doGetHostProcess() {
	RECT rect;
	GetWindowRect(winHandle_, &rect);
	if (SetWindowPos(winHandle_, 0, rect.left, rect.top, 0, 0,
		SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE)) {
		return "conhost";
	} else {
		return "cmd";
	}
}

// -------------------------------------------------------------------------------------------------

std::string
WinConsole::cursorMoveCode(const V2u32& pos) const {
	return "\033[" + std::to_string(pos.x() + 1) + ";" + std::to_string(pos.y() + 1) + "H";
}

// -------------------------------------------------------------------------------------------------

Vec2 <uint32_t>
WinConsole::getConsoleSize() const {
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

} // tiage

