//
// Created by alanva on 3/31/26.
//

#include "NcursesTerminal.hpp"

NcursesTerminal::NcursesTerminal(GameSettings& settings_ref)
    : settings(settings_ref),
      main_window(initscr()),
      game_window(nullptr),
      menu_window(nullptr),
      game_renderer(settings_ref, game_window),
      menu_renderer(menu_window),
      input()
{
    noecho();
    cbreak();
    curs_set(0);
    flushinp();
    nodelay(main_window, TRUE);
    keypad(stdscr, TRUE);
    set_escdelay(25);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_CYAN, COLOR_YELLOW);
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

void NcursesTerminal::updateTerminalSize() {
    getmaxyx(stdscr, max_y, max_x);
}

void NcursesTerminal::showMenuWindow() {
    clearWindows();
    menu_window = createCenteredWindow(40, 10);
    nodelay(main_window, TRUE);
    menu_renderer.setWindow(menu_window);
}

void NcursesTerminal::showGameWindow() {
    clearWindows();
    updateTerminalSize();

    game_window = newwin(max_y, max_x, 0, 0);
    nodelay(main_window, FALSE);
    game_renderer.setWindow(game_window);
}

void NcursesTerminal::resize() {
    game_renderer.refreshLayout();

    if (game_window != nullptr) {
        showGameWindow();
    }
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

WINDOW* NcursesTerminal::createCenteredWindow(int width, int height) {
    updateTerminalSize();

    int start_y = (max_y - height) / 2;
    int start_x = (max_x - width) / 2;

    WINDOW* win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    return win;
}