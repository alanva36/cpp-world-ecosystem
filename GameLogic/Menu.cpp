//
// Created by alanva on 4/2/26.
//

#include "Menu.hpp"

Menu::Menu(GameSettings& settings_ref)
    : selected_index(0), settings(settings_ref) {
    updateMenuText();
}

void Menu::updateMenuText() {
    options.clear();
    options.emplace_back("Start Game");
    options.emplace_back("World Width: " + std::to_string(settings.getWorldWidth()));
    options.emplace_back("World Height: " + std::to_string(settings.getWorldHeight()));
    options.emplace_back("Quit");
}

void Menu::moveUp() {
    if (selected_index > 0) {
        selected_index--;
    }
}

void Menu::moveDown() {
    if (selected_index < static_cast<int>(options.size()) - 1) {
        selected_index++;
    }
}

void Menu::increaseValue() {
    if (selected_index == 1) {
        settings.setWorldWidth(settings.getWorldWidth() + 2);
    } else if (selected_index == 2) {
        settings.setWorldHeight(settings.getWorldHeight() + 2);
    }
    settings.validateSettings();
    updateMenuText();
}

void Menu::decreaseValue() {
    if (selected_index == 1) {
        settings.setWorldWidth(settings.getWorldWidth() - 2);
    } else if (selected_index == 2) {
        settings.setWorldHeight(settings.getWorldHeight() - 2);
    }
    settings.validateSettings();
    updateMenuText();
}

int Menu::getSelectedIndex() const {
    return selected_index;
}

const std::vector<std::string>& Menu::getOptions() const {
    return options;
}