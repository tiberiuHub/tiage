// Copyright Tiberiu 2025

#include "tiage/WinMouse.h"
#include <Windows.h>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void
WinMouse::doUpdate() {
    static HWND hwnd = GetConsoleWindow(); // cached console window handle
    if (!hwnd) {
        return;
    }
    static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // cached console handle
    if (!hConsole) {
        return;
    }
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }
    RECT rect;
    if (!GetClientRect(hwnd, &rect)) {
        return;
    }

    int cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    POINT p;
    if (!GetCursorPos(&p)) {
        return;
    }
    ScreenToClient(hwnd, &p);
    int col_int = (p.x * cols) / rect.right;
    int row_int = (p.y * rows) / rect.bottom;
    if (col_int < 0) {
        col_int = 0;
    } else if (col_int >= cols) {
        col_int = cols - 1;
    }
    if (row_int < 0) {
        row_int = 0;
    } else if (row_int >= rows) {
        row_int = rows - 1;
    }
    setPos(Vec2<size_t>(static_cast<size_t>(col_int),
        static_cast<size_t>(row_int)));
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		setKey(left);
	}
	if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) {
		setKey(middle);
	}
	if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) {
		setKey(side1);
	}
	if (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) {
		setKey(side2);
	}
}

// --------------------------------------------------------------------------------------------------

} // tiage
