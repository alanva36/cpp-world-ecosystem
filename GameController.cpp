//
// Created by alanva on 4/2/26.
//

#include "GameController.hpp"

GameController::GameController()
    :
      world_height(20),
      world_width(40),
      world(world_width, world_height),
      terminal(world_width, world_height),
      current_state(GameState::MENU),
      is_running(true)
{
    terminal.showMenuWindow();
}

void GameController::run() {
    while (is_running) {
        Command command = terminal.getInput();

        if (current_state == GameState::MENU) {
            handleMenuMode(command);
        }

        else if (current_state == GameState::PLAYING) {
            handlePlayMode(command);
        }
    }
}

void GameController::handleMenuMode(Command command) {
    // 1. Update the Menu Data
    if (command == Command::UP) {
        main_menu.moveUp();
    }
    else if (command == Command::DOWN) {
        main_menu.moveDown();
    }
    else if (command == Command::ACTION_PRIMARY) {
        int choice = main_menu.getSelectedIndex();

        if (choice == 0) { // "Start Game"
            terminal.showGameWindow();
            terminal.getGameRenderer()->draw(world);
            current_state = GameState::PLAYING;
        }
        else if (choice == 2) { // "Quit"
            is_running = false;
        }
    }

    terminal.getMenuRenderer()->draw(main_menu);
}

void GameController::handlePlayMode(Command command) {
    if (command == Command::TOGGLE_MENU) {
        current_state = GameState::MENU;
        terminal.showMenuWindow();
        return;
    }

    if (command != Command::NONE) {
        // humanPlayer->receiveCommand(cmd);
    }

    world.executeTurn();

    terminal.getGameRenderer()->draw(world);
}