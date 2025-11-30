// Copyright Tiberiu 2025

#pragma once

#include <utility>

namespace tiage {

template<typename T>
class Vec2 {
public:

    Vec2(T x, T y) :
        x_(x), 
        y_(y) {
    }

    Vec2() :
        x_(0), 
        y_(0) {
    }

    void setX(T x) {
        x_ = std::move(x);
    }

    void setY(T y) {
        y_ = std::move(y);
    }

    const T& x() const {
        return x_;
    }

    const T& y() const {
        return y_;
    }

    bool operator==(const Vec2& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }

    Vec2& operator+=(const Vec2& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    friend Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
        return Vec2(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
    }

    friend Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
        return Vec2(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
    }

private:

    T x_;
    T y_;
};

using V2i32 = Vec2<int32_t>;
using V2u32 = Vec2<uint32_t>;
using V2i64 = Vec2<int64_t>;
using V2u64 = Vec2<uint64_t>;

} // tiage
