//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_GAMERENDERER_HPP
#define PROJEKT_GAMERENDERER_HPP

#include "BaseRenderer.hpp"
#include "../GameSettings.hpp"

class MapRenderer;
class World;

class GameRenderer : public BaseRenderer
{
private:
    WINDOW* map_win;
    MapRenderer* map_renderer;
    GameSettings& settings;

    const int LOG_ROWS = 6;
    const int MIN_WIDTH_LOG = 60;

public:
    explicit GameRenderer(GameSettings& settings_ref, WINDOW* win = nullptr);
    ~GameRenderer() override;

    void setWindow(WINDOW* win) override;
    void refreshLayout();
    void draw(const World& world);

private:
    void setupDerivedWindows();
    void renderStatusBar(const World& world);
    void renderLogs(const World& world);
};

#endif //PROJEKT_GAMERENDERER_HPP