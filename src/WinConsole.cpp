// Copyright Tiberiu 2025

#include "tiage/WinConsole.h"
#include "tiage/Color.h"
#include <cassert>
#include <iostream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <algorithm>


namespace tiage {

// -------------------------------------------------------------------------------------------------

bool
WinConsole::doCreate(uint64_t createOptions) {
    FreeConsole();
    if (!AllocConsole()) {
        assert(0);
        return false;
    }
    if (!freopen("CONIN$", "r", stdin) ||
        !freopen("CONOUT$", "w", stdout) ||
        !freopen("CONERR$", "w", stderr)) {
        assert(0);
        return false;
    }
    if (winHandle_ = GetConsoleWindow(); winHandle_ == NULL) {
        assert(0);
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
        assert(0);
    }
    if (inHandle_ = GetStdHandle(STD_INPUT_HANDLE); inHandle_ == INVALID_HANDLE_VALUE) {
        assert(0);
        return false;
    } else {
        DWORD inMode = ENABLE_EXTENDED_FLAGS;
        inMode |= (createOptions & EnableProcessedInput) * ENABLE_PROCESSED_INPUT;
        inMode |= (createOptions & EnableLineInput) * ENABLE_LINE_INPUT;
        inMode |= (createOptions & EnableEchoInput) * ENABLE_ECHO_INPUT;
        inMode |= (createOptions & EnableWindowInput) * ENABLE_WINDOW_INPUT;
        inMode |= (createOptions & EnableMouseInput) * ENABLE_MOUSE_INPUT;
        inMode |= (createOptions & EnableInsertMode) * ENABLE_INSERT_MODE;
        inMode |= (createOptions & EnableQuickEditMode) * ENABLE_QUICK_EDIT_MODE;
        inMode |= (createOptions & EnableExtendedFlags) * ENABLE_EXTENDED_FLAGS;
        inMode |= (createOptions & EnableAutoPosition) * ENABLE_AUTO_POSITION;
        inMode |= (createOptions & EnableVirtualTerminalInput) * ENABLE_VIRTUAL_TERMINAL_INPUT;
        if (!SetConsoleMode(inHandle_, inMode)) {
            assert(0);
            return false;
        }
    }
    if (outHandle_ = GetStdHandle(STD_OUTPUT_HANDLE); outHandle_ == INVALID_HANDLE_VALUE) {
        assert(0);
        return false;
    } else {
        DWORD outMode = 0;
        outMode |= (createOptions & EnableProcessedOutput )  * ENABLE_PROCESSED_OUTPUT;
        outMode |= (createOptions & EnableWrapAtEolOutput ) * ENABLE_WRAP_AT_EOL_OUTPUT;
        outMode |= (createOptions & EnableVirtualTerminalProcessing ) * ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        outMode |= (createOptions & DisableNewlineAutoReturn ) * DISABLE_NEWLINE_AUTO_RETURN;
        outMode |= (createOptions & EnableLvbGridWorldwide ) * ENABLE_LVB_GRID_WORLDWIDE;
        if (!SetConsoleMode(outHandle_, outMode)) {
            assert(0);
            return false;
        }
    }

     commands_ = Matrix<cmd_t>(50, 50);
    
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
WinConsole::doSetTitle(const char* title) {
    if (!SetConsoleTitle(title)) {
        assert(0);
    }
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doMove(std::optional<tiage::V2i32> maybePos, std::optional<tiage::V2i32> maybeSize) {
    if (maybePos) {
        if (!SetWindowPos(winHandle_, 0, maybePos->x(), maybePos->y(), 0, 0,
                          SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE)) {
            assert(0);
            return;
         }
    }
    if (maybeSize) {
        CONSOLE_SCREEN_BUFFER_INFOEX sbi = { sizeof(CONSOLE_SCREEN_BUFFER_INFOEX) };
        GetConsoleScreenBufferInfoEx(outHandle_, &sbi);
        if (!GetConsoleScreenBufferInfoEx(outHandle_, &sbi)) {
            assert(0);
        }
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
WinConsole::doSetCursorVisible(bool visible) {
    CONSOLE_CURSOR_INFO info = { 100, visible };
    if (!SetConsoleCursorInfo(outHandle_, &info)) {
        assert(0);
    }
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doPutChar(uint32_t x, uint32_t y, Color color, char c) {
    commands_.set(x, y, { color, c });
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doFlush() {
    std::stringstream frameBuffer;

    auto consoleSize = getConsoleSize();

    uint32_t rows = commands_.nRows();
    uint32_t cols = commands_.nCols();

    if (currentConsoleSize_ != consoleSize) {
        clear();
    }

    currentConsoleSize_ = consoleSize;

    rows = std::min<int32_t>(consoleSize.y(), rows);
    cols = std::min<int32_t>(consoleSize.x(), cols);

    frameBuffer << "\033[H";
    for (uint32_t y = 0; y < rows; y++) {
        for (uint32_t x = 0; x < cols; x++) {
            auto command = commands_.get(x, y);
            std::pair<std::string, std::string>  code = ansiColorCode(command.color);
            frameBuffer << code.first << command.c << code.second;
        }
        if (y != rows - 1) {
            frameBuffer << '\n';
        }
    }

    std::cout << frameBuffer.str();
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doClear() {
    std::system("cls");
    commands_.set({ Color::White,' ' });
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

