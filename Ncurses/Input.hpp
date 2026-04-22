//
// Created by alanva on 3/31/26.
//

#ifndef PROJEKT_INPUT_HPP
#define PROJEKT_INPUT_HPP

#include "Command.hpp"
#include <unordered_map>
#include <ncurses.h>

class Input
{

private:
    std::unordered_map<int, Command> key_bindings;

public:
    Input();
    Command getCommand();

};


#endif //PROJEKT_INPUT_HPP