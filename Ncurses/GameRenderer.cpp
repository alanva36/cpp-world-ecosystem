//
// Created by alanva on 4/2/26.
//

#include "GameRenderer.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include "MapRenderer.hpp"
#include "../GameLogic/World.hpp"
#include "../Organisms/Human.hpp"

GameRenderer::GameRenderer(GameSettings& settings_ref, WINDOW* win)
    : BaseRenderer(win),
      map_win(nullptr),
      map_renderer(nullptr),
      settings(settings_ref)
{
    setupDerivedWindows();
}

GameRenderer::~GameRenderer() {
    delete map_renderer;
    if (map_win) delwin(map_win);
}

void GameRenderer::refreshLayout() {
    setupDerivedWindows();
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
        getmaxyx(win, window_y, window_x);

        int m_width = settings.getWorldWidth();
        int m_height = settings.getWorldHeight();

        int start_y = (window_y / 2) - (m_height / 2);
        int start_x = (window_x / 2) - (m_width / 2);

        map_win = derwin(win, m_height, m_width, start_y, start_x);

        if (!map_renderer) {
            map_renderer = new MapRenderer(map_win);
        } else {
            map_renderer->setWindow(map_win);
        }
    } else if (map_renderer) {
        map_renderer->setWindow(nullptr);
    }
}

void GameRenderer::draw(const World& world) {
    if (!win) return;

    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 0, 3, " GRA - Alan Nowak 208282");

    renderStatusBar(world);

    renderBox(window_y/2-1,window_x/2,settings.getWorldHeight()+1, settings.getWorldWidth(), 1);

    if (map_renderer) {
        map_renderer->draw(world);
    }

    renderLogs(world);

    refreshScreen();
}

void GameRenderer::renderStatusBar(const World& world) {
    // INFORMACJE O SWIECIE
    mvwprintw(win, 1, 2, " [Tura: %d] | [Organizmow: %zu] | [Mapa: %dx%d] ",
                  world.getTurn(),
                  world.getAliveOrganisms().size(),
                  settings.getWorldWidth(),
                  settings.getWorldHeight());

    // INFORMACJE O GRACZU
    if (world.getHumanPlayer() != nullptr) {
        Human* h = world.getHumanPlayer();
        mvwprintw(win, 2, 2, " Pozycja: %d, %d | Sila: %d | Umiejetnosc: %s ",
                  h->getPositionX(),
                  h->getPositionY(),
                  h->getForce(),
                  h->getSkillStatus().c_str());
    }
    else {
        mvwprintw(win, 2, 2, " Gracz: NIE ZYJE ");
    }

    // INFORMACJE O STEROWANIU
    mvwprintw(win, window_y - 2, 2, " STEROWANIE: ");
    mvwprintw(win, window_y - 2, 15, " WSAD/Strzalki: Ruch | L: Umiejetnosc | Q: Menu | Z: Zapis | X: Wczytaj | N: Kolejna tura ");
}

void GameRenderer::renderLogs(const World& world) {

    int map_width = std::ranges::max(settings.getWorldWidth(),MIN_WIDTH_LOG);

    int log_start_y = window_y - LOG_ROWS ;
    int log_start_x = (window_x / 2) - (map_width / 2);
    renderBox(log_start_y, window_x/2, LOG_ROWS-1, map_width, 1);

    const std::vector<std::string>& logs = world.getLogs();

    int max_visible_logs = LOG_ROWS - 2;
    int start_index = 0;

    if (logs.size() > max_visible_logs) {
        start_index = logs.size() - max_visible_logs;
    }

    for (int i = 0; i < max_visible_logs && (start_index + i) < logs.size(); ++i) {
        mvwprintw(win, log_start_y + i - 1, log_start_x + 1, "%s", logs[start_index + i].c_str());
    }
    mvwprintw(win, log_start_y-2, log_start_x+1, "LOGI");


}