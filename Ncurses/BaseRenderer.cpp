//
// Created by alanva on 3/30/26.
//

#include "BaseRenderer.hpp"

BaseRenderer::BaseRenderer(WINDOW* window) : win(nullptr) {
    internalSetWindow(window);
}

void BaseRenderer::setWindow(WINDOW* new_window) {
    internalSetWindow(new_window);
}

void BaseRenderer::internalSetWindow(WINDOW* new_window) {
    win = new_window;
    if (win) {
        getmaxyx(win, window_y, window_x);
    } else {
        window_x = 0;
        window_y = 0;
    }
}

void BaseRenderer::clearScreen()
{
    if (win) {
        werase(win);
    }
}

void BaseRenderer::refreshScreen() const
{
    if (win) {
        wrefresh(win);
    }
}

void BaseRenderer::renderBox(int box_y, int box_x, int box_height, int box_width, int padding, bool centered) const
{
    if (win) {
        if (centered == true)
        {
            box_y -= (box_height / 2);
            box_x -= box_width / 2;
        }

        // Top + middle space + bottom
        mvwhline(win, box_y, box_x - padding, ACS_HLINE, box_width + 2 * padding - 1);
        for (int i = box_y + 1; i <= box_y+box_height - 1; i++) {
            mvwhline(win, i, box_x - padding, ' ', box_width + 2 * padding - 1);
        }
        mvwhline(win, box_y+box_height, box_x - padding, ACS_HLINE, box_width + 2 * padding - 1);

        // Vertical lines
        for (int i = box_y; i <= box_y+box_height; i++) {
            mvwaddch(win, i, box_x - padding, ACS_VLINE);
            mvwaddch(win, i, box_x + box_width + (padding - 1), ACS_VLINE);
        }

        // Corners
        mvwaddch(win, box_y, box_x - padding, ACS_ULCORNER);
        mvwaddch(win, box_y, box_x + box_width + (padding - 1), ACS_URCORNER);
        mvwaddch(win, box_y+box_height, box_x - padding, ACS_LLCORNER);
        mvwaddch(win, box_y+box_height, box_x + box_width + (padding - 1), ACS_LRCORNER);
    }
}
