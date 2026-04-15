//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_MENURENDERER_HPP
#define PROJEKT_MENURENDERER_HPP

#include "BaseRenderer.hpp"

class Menu;

class MenuRenderer : public BaseRenderer
{
public:
    explicit MenuRenderer(WINDOW* win = nullptr);

    void draw(const Menu& menu);
};


#endif //PROJEKT_MENURENDERER_HPP