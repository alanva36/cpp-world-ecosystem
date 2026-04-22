//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_GAMECONTROLLER_HPP
#define PROJEKT_GAMECONTROLLER_HPP

#include "Ncurses/NcursesTerminal.hpp"
#include "GameLogic/World.hpp"
#include "GameLogic/Menu.hpp"
#include "GameSettings.hpp"
#include "GameState.hpp"
#include <memory>

class GameController {
private:
    bool is_running;
    GameState current_state;

    GameSettings settings;
    std::unique_ptr<World> world;
    NcursesTerminal terminal;
    Menu main_menu;

public:
    GameController();

    void run();

private:
    void handleMenuMode(Command command);
    void handlePlayMode(Command command);
};

#endif //PROJEKT_GAMECONTROLLER_HPP