//
// Created by alanva on 4/15/26.
//

#ifndef PROJEKT_MAPRENDERER_HPP
#define PROJEKT_MAPRENDERER_HPP

#include "BaseRenderer.hpp"

class World;

class MapRenderer : public BaseRenderer {
public:
    explicit MapRenderer(WINDOW* win = nullptr);

    void draw(const World& world);
};


#endif //PROJEKT_MAPRENDERER_HPP