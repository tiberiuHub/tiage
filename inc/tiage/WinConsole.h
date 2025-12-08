// Copyright Tiberiu 2025

#pragma once

#include <utility>
#include <tiage/IConsole.h>
#include <tiage/Vec2.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace tiage {

class WinConsole final : public IConsole {
public:
    
    enum win_in_create_options_t : uint64_t {
        EnableProcessedInput = 0x0001llu << 20,
        EnableLineInput = 0x0002llu << 20,
        EnableEchoInput = 0x0004llu << 20,
        EnableWindowInput = 0x0008llu << 20,
        EnableMouseInput = 0x0010llu << 20,
        EnableInsertMode = 0x0020llu << 20,
        EnableQuickEditMode = 0x0040llu << 20,
        EnableExtendedFlags = 0x0080llu << 20,
        EnableAutoPosition = 0x0100llu << 20,
        EnableVirtualTerminalInput = 0x0200llu <<20
    };
    
    enum win_out_create_options_t : uint64_t {
        EnableProcessedOutput = 0x0001llu << 40,
        EnableWrapAtEolOutput = 0x0002llu << 40,
        EnableVirtualTerminalProcessing = 0x0004llu << 40,
        DisableNewlineAutoReturn = 0x0008llu << 40,
        EnableLvbGridWorldwide = 0x0010llu <<40
    };

    static constexpr uint64_t kWinDefaultCreateOptions = 0;

private:

    bool doCreate(uint64_t createOptions) override;

    void doDestroy() override;

    void doSetTitle(const char* title) override;

    void doMove(std::optional<tiage::V2i32> maybePos, std::optional<tiage::V2i32> maybeSize);

    void doSetCursorVisible(bool visible) override;

    void doPutChar(uint32_t x, uint32_t y, Color color, char c) override;

    void doFlush() override;

    void doClear() override;

    std::string doGetHostProcess() override;

    Vec2<uint32_t> currentConsoleSize_;

    Vec2<uint32_t> getConsoleSize() const;

    HWND winHandle_ = GetConsoleWindow();

    HANDLE inHandle_ = INVALID_HANDLE_VALUE;

    HANDLE outHandle_ = INVALID_HANDLE_VALUE;
};

} // tiage
