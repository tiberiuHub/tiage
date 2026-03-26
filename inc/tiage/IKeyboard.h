// Copyright Tiberiu 2025

#pragma once

#include<bitset>

namespace tiage {

class IKeyboard {
public:

	void update();
	
	bool pressed(int key) const;

	bool released(int key) const;

	bool holding(int key) const;

	void setKey(int key);

private:

	virtual void doUpdate() = 0;

	std::bitset<256>last_;

	std::bitset<256>current_;

};

} // tiage
