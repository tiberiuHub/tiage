// Copyright Tiberiu 2025

#include "tiage/WinConsole.h"
#include "tiage/Color.h"
#include <iostream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <algorithm>

namespace tiage {

// -------------------------------------------------------------------------------------------------

WinConsole::WinConsole(uint32_t width, uint32_t height) {
    commands_ = Matrix<cmd_t>(width,height);
    currentConsoleSize_ = { 120,30 };
    desiredCanvasSize_ = { 120,30 };//placeholders
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doCreate(uint32_t width, uint32_t height) {
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doDestroy() {
    //FreeConsole();
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doSetCursorVisible(bool visible) {
    std::cout << (visible ? "\033[?25h" : "\033[?25l");
}

// -------------------------------------------------------------------------------------------------

void 
WinConsole::doPutChar(uint32_t x, uint32_t y, Color color, char c) {
    // commands_->set(x, y, { color,c });
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doFlush() {
    //doClear();

    std::stringstream frameBuffer;

    // doFitToConsole();

    frameBuffer << "\033[H";
    for (uint32_t y = 0; y < commands_.nRows(); y++) {
        for (uint32_t x = 0; x < commands_.nCols(); x++) {
            auto command = commands_.get(x, y);
            std::pair<std::string, std::string>  code = ansiColorCode(command.color);
            frameBuffer << code.first << command.c << code.second;
        }
        if (y != commands_.nRows() - 1) {
            frameBuffer << '\n';
        }
    }

    std::cout << frameBuffer.str();
    
}

// -------------------------------------------------------------------------------------------------

void
WinConsole::doClear() {
    //#ifdef _WIN32
    //    std::system("cls");
    //#else
    //    std::system("clear");
    //#endif
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

