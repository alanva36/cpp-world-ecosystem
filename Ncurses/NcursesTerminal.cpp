//
// Created by alanva on 3/31/26.
//

#include "NcursesTerminal.hpp"

NcursesTerminal::NcursesTerminal(int world_width, int world_height)
    : main_window(initscr()),
      game_window(nullptr),
      menu_window(nullptr),
      game_renderer(game_window, world_width, world_height),
      menu_renderer(menu_window),
      input(main_window)
{


    noecho();
    cbreak();
    curs_set(0);
    flushinp();
    nodelay(main_window, TRUE);
    keypad(main_window, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    }

    updateTerminalSize();

}

NcursesTerminal::~NcursesTerminal() {
    clearWindows();
    endwin();
}

GameRenderer* NcursesTerminal::getGameRenderer() {
    return &game_renderer;
}

MenuRenderer* NcursesTerminal::getMenuRenderer() {
    return &menu_renderer;
}

Command NcursesTerminal::getInput() {
    return input.getCommand();
}

void NcursesTerminal::clearWindows() {
    if (game_window) {
        delwin(game_window);
        game_window = nullptr;
        game_renderer.setWindow(nullptr);
    }
    if (menu_window) {
        delwin(menu_window);
        menu_window = nullptr;
        menu_renderer.setWindow(nullptr);
    }

    wclear(main_window);
    wrefresh(main_window);
}

void NcursesTerminal::updateTerminalSize() {
    getmaxyx(stdscr, max_y, max_x);
}

WINDOW* NcursesTerminal::createCenteredWindow(int width, int height) {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int start_y = (max_y - height) / 2;
    int start_x = (max_x - width) / 2;

    WINDOW* win = newwin(height, width, start_y, start_x);
    return win;
}

void NcursesTerminal::showMenuWindow() {
    clearWindows();

    menu_window = createCenteredWindow(20, 10);
    nodelay(main_window, TRUE);
    menu_renderer.setWindow(menu_window);
}

void NcursesTerminal::showGameWindow() {

    clearWindows();

    game_window = newwin(max_y, max_x, 0, 0);
    nodelay(main_window, FALSE);
    game_renderer.setWindow(game_window);

}