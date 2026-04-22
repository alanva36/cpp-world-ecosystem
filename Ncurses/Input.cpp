//
// Created by alanva on 3/31/26.
//

#include "Input.hpp"

Input::Input() {

    key_bindings['l']      = Command::SKILL;
    key_bindings['L']      = Command::SKILL;

    key_bindings['n']      = Command::NEXT_TURN;
    key_bindings['N']      = Command::NEXT_TURN;
    key_bindings[10]       = Command::NEXT_TURN;

    key_bindings['w']      = Command::UP;
    key_bindings['W']      = Command::UP;
    key_bindings[KEY_UP]   = Command::UP;

    key_bindings['s']      = Command::DOWN;
    key_bindings['S']      = Command::DOWN;
    key_bindings[KEY_DOWN] = Command::DOWN;

    key_bindings['a']      = Command::LEFT;
    key_bindings['A']      = Command::LEFT;
    key_bindings[KEY_LEFT] = Command::LEFT;

    key_bindings['d']      = Command::RIGHT;
    key_bindings['D']      = Command::RIGHT;
    key_bindings[KEY_RIGHT]= Command::RIGHT;

    key_bindings['\n']     = Command::ACTION_PRIMARY;
    key_bindings[10]       = Command::ACTION_PRIMARY;
    key_bindings['e']      = Command::ACTION_PRIMARY;
    key_bindings['E']      = Command::ACTION_PRIMARY;

    key_bindings['z']      = Command::SAVE_GAME;
    key_bindings['Z']      = Command::SAVE_GAME;

    key_bindings['x']      = Command::LOAD_GAME;
    key_bindings['X']      = Command::LOAD_GAME;

    key_bindings['q']      = Command::TOGGLE_MENU;
    key_bindings['Q']      = Command::TOGGLE_MENU;
    key_bindings[27]       = Command::TOGGLE_MENU;
}

Command Input::getCommand() {
    int input = getch();
    if (input == ERR) return Command::NONE;

    auto it = key_bindings.find(input);
    if (it != key_bindings.end()) {
        return it->second;
    }

    return Command::NONE;
}