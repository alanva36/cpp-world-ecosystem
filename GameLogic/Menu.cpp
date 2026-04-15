//
// Created by alanva on 4/2/26.
//

#include "Menu.hpp"

Menu::Menu() : selectedIndex(0) {
    options.emplace_back("Start Game");
    options.emplace_back("Options");
    options.emplace_back("Quit");
}

void Menu::moveUp() {
    if (selectedIndex > 0) {
        selectedIndex--;
    }
}

void Menu::moveDown() {
    if (selectedIndex < static_cast<int>(options.size()) - 1) {
        selectedIndex++;
    }
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}

const std::vector<std::string>& Menu::getOptions() const {
    return options;
}