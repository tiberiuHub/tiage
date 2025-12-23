// Copyright Tiberiu 2025

#pragma once

#include <tiage/Color.h>
#include <tiage/Matrix.h>
#include <tiage/Vec2.h>
#include "tiage/DrawableChar.h"
#include <optional>

namespace tiage {

class IConsole {
public:

    enum create_options_t : uint64_t {
        None = 0,
        NoMinimize = 1 << 0,
        NoMaximize = 1 << 1,
        NoResize = 1 << 2,
        NoScrollV = 1 << 3,
        NoScrollH = 1 << 4
    };

    static constexpr uint64_t kDefaultCreateOptions =
        create_options_t::NoMinimize |
        create_options_t::NoMaximize |
        create_options_t::NoResize |
        create_options_t::NoScrollH |
        create_options_t::NoScrollV;

    virtual ~IConsole() = default;

    /**
     * Creates a console.
     * The default terminal app should be the Windows Console Host.
     */
    bool create(uint64_t createOptions);

    void destroy();

    void setTitle(const char* title);

    /**
     * Sets the position and size of the console.
     * @param maybePos the position of the console in pixels.
     * @param maybeSize the size of the console in characters.
     */
    void move(std::optional<tiage::V2i32> maybePos = std::nullopt, 
              std::optional<tiage::V2i32> maybeSize = std::nullopt);

    void setCursorVisible(bool visible);

    void putChar(uint32_t x, uint32_t y,const DrawableChar& ch);

    void flush(const V2i32& offset = {0,0});
    
    void clear();

    std::string getHostProcess();

protected:

    virtual bool doCreate(uint64_t createOptions) = 0;

    virtual void doDestroy() = 0;

    virtual void doSetTitle(const char* title) = 0;

    virtual void doMove(std::optional<tiage::V2i32> maybePos, 
                        std::optional<tiage::V2i32> maybeSize) = 0;

    virtual void doSetCursorVisible(bool visible) = 0;

    virtual void doPutChar(uint32_t x, uint32_t y,const DrawableChar& ch) = 0;

    virtual void doFlush(const V2i32& offset) = 0;

    virtual void doClear() = 0;

    virtual std::string doGetHostProcess() = 0;

    Matrix<DrawableChar> buffer_;

};

} // tiage
