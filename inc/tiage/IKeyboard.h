// Copyright Tiberiu 2025

#pragma once

#include<bitset>

namespace tiage {

class Keyboard {
public:

	void update();
	
	//bool justPressed(int key) const;
	//bool justReleased(int key) const;
	//bool isHolding(int key) const;
	//bool isPressed


private:

	last_;

	char current_;

};

} // tiage
