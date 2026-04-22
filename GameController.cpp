//
// Created by alanva on 4/2/26.
//

#include "GameController.hpp"
#include "Organisms/Human.hpp"
#include "GameLogic/World.hpp"

GameController::GameController()
    : is_running(true),
      current_state(GameState::MENU),
      settings(),
      world(nullptr),
      terminal(settings),
      main_menu(settings)
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
    if (command == Command::UP) {
        main_menu.moveUp();
    }
    else if (command == Command::DOWN) {
        main_menu.moveDown();
    }
    else if (command == Command::RIGHT) {
        main_menu.increaseValue();
    }
    else if (command == Command::LEFT) {
        main_menu.decreaseValue();
    }
    else if (command == Command::ACTION_PRIMARY) {
        int choice = main_menu.getSelectedIndex();

        if (choice == 0) {

            world = std::make_unique<World>(settings);

            terminal.resize();

            current_state = GameState::PLAYING;
            terminal.showGameWindow();

            if (world) {
                terminal.getGameRenderer()->draw(*world);
            }
        }
        else if (choice == 3) {
            is_running = false;
        }
    }

    terminal.getMenuRenderer()->draw(main_menu);
}

void GameController::handlePlayMode(Command command) {

    if (!world) return;

    if (command == Command::SAVE_GAME) {
        world->saveToFile("savegame.txt");
        terminal.getGameRenderer()->draw(*world);
        return;
    }

    if (command == Command::LOAD_GAME) {
        world->loadFromFile("savegame.txt");

        terminal.resize();
        terminal.getGameRenderer()->draw(*world);
        return;
    }

    if (command == Command::TOGGLE_MENU) {
        current_state = GameState::MENU;
        terminal.showMenuWindow();
        return;
    }

    if (command != Command::NONE) {
        if (world->getHumanPlayer() != nullptr) {
            world->getHumanPlayer()->setNextCommand(command);
        }
    }

    if (command == Command::UP ||
    command == Command::DOWN ||
    command == Command::LEFT ||
    command == Command::RIGHT ||
    command == Command::NEXT_TURN ||
    command== Command::SKILL) {
        world->executeTurn();
    }

    terminal.getGameRenderer()->draw(*world);
}