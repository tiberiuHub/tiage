// Copyright Tiberiu 2025

#pragma once

#include "tiage/IMouse.h"

namespace tiage {

class WinMouse final : public IMouse {
public:

	void doUpdate() override;

};

} // tiage
