// Copyright Tiberiu 2025

#pragma once

namespace tiage {

template<typename T1>
class Vec2 {
public:
	T1 x;
	T1 y;

	Vec2(T1 x_, T1 y_):x(x_),y(y_){}

	Vec2() :x(0), y(0) {}

};

} // tiage
