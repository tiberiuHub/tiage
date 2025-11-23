// Copyright Tiberiu 2025

#pragma once

#include <functional>
#include <string>
#include <vector>

namespace tiage {

class Menu {
public:

    using Action = std::function<void()>;

    void addMenu(char key, std::string title, Action action);

    void handleKey(char key);

private:

    struct Item {
        char key;
        std::string title;
        Action action;
    };

    std::vector<Item> items_;
};

} // tiage