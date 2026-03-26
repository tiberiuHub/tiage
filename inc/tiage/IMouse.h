// Copyright Tiberiu 2025

#pragma once

#include<bitset>
#include <tiage/Vec2.h>

namespace tiage {

class IMouse {
public:

	enum buttons : int {
		left = 0,
		middle = 1,
		side1 = 2,
		side2 = 3,
	};

	void update();
	
	Vec2<size_t> getPos();

	Vec2<size_t> getLastPos();


	bool pressed(int key) const;

	bool released(int key) const;

	bool holding(int key) const;

	void setKey(int key);

	void setPos(Vec2<size_t> pos);

private:

	virtual void doUpdate() = 0;

	std::bitset<4>last_;

	std::bitset<4>current_;

	Vec2<size_t> lastPos_;

	Vec2<size_t> currentPos_;

};

} // tiage
