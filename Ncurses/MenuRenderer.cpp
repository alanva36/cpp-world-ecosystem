//
// Created by alanva on 4/2/26.
//

#include "MenuRenderer.hpp"

#include <string>
#include <vector>

#include "../GameLogic/Menu.hpp"

MenuRenderer::MenuRenderer(WINDOW* win) : BaseRenderer(win) {}

void MenuRenderer::draw(const Menu& menu)
{
    if (!win) return;

    clearScreen();

    box(win, 0, 0);

    mvwprintw(win, 0, 2, " WIRTUALNY SWIAT - alanva 363636");

    const std::vector<std::string>& options = menu.getOptions();
    int highlight = menu.getSelectedIndex();

    int start_y = 2;
    int start_x = 2;

    for (size_t i = 0; i < options.size(); ++i) {
        if (highlight == static_cast<int>(i)) {
            wattron(win, A_REVERSE);
            mvwprintw(win, start_y + i, start_x, "> %s", options[i].c_str());
            wattroff(win, A_REVERSE);
        } else {
            mvwprintw(win, start_y + i, start_x, "  %s", options[i].c_str());
        }
    }

    refreshScreen();
}
