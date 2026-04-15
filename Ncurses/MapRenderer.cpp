//
// Created by alanva on 4/15/26.
//

#include "MapRenderer.hpp"
#include "../GameLogic/World.hpp"
#include "../Entities/Organism.hpp"

MapRenderer::MapRenderer(WINDOW* win) : BaseRenderer(win) {}

void MapRenderer::draw(const World& world) {
    if (!win) return;

    clearScreen();

    box(win, 0, 0);

    for (const Organism* org : world.getOrganisms()) {
        int x = org->getPositionX();
        int y = org->getPositionY();

        if (x >= 0 && x < window_x && y >= 0 && y < window_y) {

            wattron(win, COLOR_PAIR(org->getVisual().getColor()));
            mvwaddch(win, y, x, org->getVisual().getModel());
            wattroff(win, COLOR_PAIR(org->getVisual().getColor()));

        }
    }

    refreshScreen();

}