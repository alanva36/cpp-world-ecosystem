//
// Created by alanva on 3/31/26.
//

#include "Input.hpp"

Input::Input(WINDOW* window) : win(window) {

    key_bindings['l']      = Command::SKILL;

    key_bindings['w']      = Command::UP;
    key_bindings[KEY_UP]   = Command::UP;

    key_bindings['s']      = Command::DOWN;
    key_bindings[KEY_DOWN] = Command::DOWN;

    key_bindings['a']      = Command::LEFT;
    key_bindings[KEY_LEFT] = Command::LEFT;

    key_bindings['d']      = Command::RIGHT;
    key_bindings[KEY_RIGHT]= Command::RIGHT;

    key_bindings['\n']     = Command::ACTION_PRIMARY;
    key_bindings[' ']      = Command::ACTION_PRIMARY;
    key_bindings['e']      = Command::ACTION_PRIMARY;

    key_bindings['q']      = Command::TOGGLE_MENU;
    key_bindings[27]       = Command::TOGGLE_MENU;
}

Command Input::getCommand() {
    if (win == nullptr) return Command::NONE;

    int input = wgetch(win);
    if (input == ERR) return Command::NONE;

    auto it = key_bindings.find(input);
    if (it != key_bindings.end()) {
        return it->second;
    }

    return Command::NONE;
}