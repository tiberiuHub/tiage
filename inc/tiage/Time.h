// Copyright Tiberiu 2025

#pragma once

#include <chrono>

namespace tiage {

class Time {
public:

	void start();

	double delta();

	void frame(double targetFPS);
	
private:

	using clock = std::chrono::steady_clock;

	clock::time_point last_;

	double deltaTime_ = 0;

};

} // tiage
