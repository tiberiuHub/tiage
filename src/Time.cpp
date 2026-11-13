// Copyright Tiberiu 2025

#include "tiage/Time.h"
#include <thread>

namespace tiage {

// --------------------------------------------------------------------------------------------------

void
Time::start() {
	last_ = clock::now();
}

// --------------------------------------------------------------------------------------------------

double
Time::delta() {
    return deltaTime_;
}

// --------------------------------------------------------------------------------------------------

void Time::frame(double targetFPS) {
    auto now = clock::now();
    std::chrono::duration<double> elapsed = now - last_;
    double targetFrameTime = 1.0 / targetFPS;
    if (elapsed.count() < targetFrameTime) {
        std::this_thread::sleep_for(
            std::chrono::duration<double>(targetFrameTime - elapsed.count())
        );
    }
    now = clock::now();
    deltaTime_ = std::chrono::duration<double>(now - last_).count();
    last_ = now;
}

// --------------------------------------------------------------------------------------------------

} // tiage
