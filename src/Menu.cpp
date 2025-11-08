// Copyright Tiberiu 2025

#pragma once

//#include <Menu.h>
#include <tiage/Menu.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <ranges>

namespace tiage {

// -------------------------------------------------------------------------------------------------

void
Menu::addMenu(char key, std::string title, Action action) {
	if (key && !title.empty() && action) {
		items_.push_back(Item{ key, title, action });
	}
}

// -------------------------------------------------------------------------------------------------

void
Menu::handleKey(char key) {
	std::ranges::for_each(
		items_,
		[key](auto& item) {
			if (item.key == key) {
				assert(item.action);
				item.action();
			}
		});
}

// -------------------------------------------------------------------------------------------------

} // tiage

