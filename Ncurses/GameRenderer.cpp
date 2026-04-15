//
// Created by alanva on 4/2/26.
//

#include "GameRenderer.hpp"

#include <string>
#include <vector>
#include "MapRenderer.hpp"
#include "../GameLogic/World.hpp"
#include "../Organisms/Human.hpp"

#define LOG_ROWS 5

GameRenderer::GameRenderer(WINDOW* win, int world_width, int world_height)
    : BaseRenderer(win),
      map_win(nullptr),
      map_renderer(nullptr),
      map_width(world_width),
      map_height(world_height)
{
    setupDerivedWindows();
}

GameRenderer::~GameRenderer() {
    delete map_renderer;
    if (map_win) delwin(map_win);
}

void GameRenderer::setWindow(WINDOW* new_win) {
    BaseRenderer::setWindow(new_win);

    setupDerivedWindows();
}

void GameRenderer::setupDerivedWindows() {
    if (map_win) {
        delwin(map_win);
        map_win = nullptr;
    }

    if (win) {
        int start_y = (window_y / 2) - (map_height / 2);
        int start_x = (window_x / 2) - (map_width / 2);

        map_win = derwin(win, map_height, map_width, start_y, start_x);

        if (!map_renderer) {
            map_renderer = new MapRenderer(map_win);
        } else {
            map_renderer->setWindow(map_win);
        }
    }
    else {
        if (map_renderer) {
            map_renderer->setWindow(nullptr);
        }
    }
}

void GameRenderer::draw(const World& world)
{
    if (!win) return;

    clearScreen();

    box(win, 0, 0);

    mvwprintw(win, 0, 3, "GRA - alanva 123456 ");
    mvwprintw(win, 2, 3, "Rozmiar: %d/%d", map_width, map_height);
    if (world.getHumanPlayer() != nullptr) {
        mvwprintw(win, 3, 3, "Pozycja: %d/%d", world.getHumanPlayer()->getPositionX(), world.getHumanPlayer()->getPositionY());
    }
    renderStatusBar(world);
    renderBox(window_y/2-1,window_x/2,map_height+1, map_width, 1);
    if (map_renderer) {
        map_renderer->draw(world);
    }
    renderLogs(world);

    refreshScreen();
}

void GameRenderer::renderStatusBar(const World& world)
{
    std::string status = "Tura: " + std::to_string(world.getTurn()) +
                         " | Organizmow: " + std::to_string(world.getAliveOrganisms().size());
    mvwprintw(win, 1, 3, "%s", status.c_str());
}

void GameRenderer::renderLogs(const World& world)
{
    renderBox(window_y-LOG_ROWS, window_x/2, LOG_ROWS-1, map_width, 1);
}