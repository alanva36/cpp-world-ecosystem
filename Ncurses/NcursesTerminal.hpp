//
// Created by alanva on 3/31/26.
//

#ifndef PROJEKT_NCURSESTERMINAL_HPP
#define PROJEKT_NCURSESTERMINAL_HPP
#include "GameRenderer.hpp"
#include "MenuRenderer.hpp"
#include "Input.hpp"
#include "../GameSettings.hpp"

class NcursesTerminal {
private:
    WINDOW* main_window;
    WINDOW* game_window;
    WINDOW* menu_window;

    GameRenderer game_renderer;
    MenuRenderer menu_renderer;
    Input input;

    GameSettings& settings;

    int max_x;
    int max_y;

public:
    NcursesTerminal(GameSettings& settings_ref);
    ~NcursesTerminal();

    GameRenderer* getGameRenderer();
    MenuRenderer* getMenuRenderer();

    void updateTerminalSize();
    void showGameWindow();
    void showMenuWindow();
    void resize();

    Command getInput();

private:
    void clearWindows();
    WINDOW* createCenteredWindow(int width, int height);
};


#endif //PROJEKT_NCURSESTERMINAL_HPP