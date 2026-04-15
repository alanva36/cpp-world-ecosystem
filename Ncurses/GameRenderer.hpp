//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_GAMERENDERER_HPP
#define PROJEKT_GAMERENDERER_HPP

#include "BaseRenderer.hpp"

class MapRenderer;

class World;

class GameRenderer : public BaseRenderer
{
private:
    WINDOW* map_win;
    MapRenderer* map_renderer;

    int map_width;
    int map_height;
public:
    explicit GameRenderer(WINDOW* win = nullptr, int world_width = 0, int world_height = 0);
    ~GameRenderer() override;
    void setWindow(WINDOW* win) override;
    void draw(const World& world);

private:
    void setupDerivedWindows();
    void renderStatusBar(const World& world);
    void renderLogs(const World& world);

};
#endif //PROJEKT_GAMERENDERER_HPP