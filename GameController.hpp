//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_GAMECONTROLLER_HPP
#define PROJEKT_GAMECONTROLLER_HPP

#include "Ncurses/NcursesTerminal.hpp"
#include "GameLogic/World.hpp"
#include "GameLogic/Menu.hpp"
#include "GameState.hpp"

class GameController
{

private:
    int world_height;
    int world_width;

    NcursesTerminal terminal;
    World world;
    Menu main_menu;

    GameState current_state;
    bool is_running;
public:
    GameController();

    void run();
private:
    void handleMenuMode(Command command);
    void handlePlayMode(Command command);
};


#endif //PROJEKT_GAMECONTROLLER_HPP