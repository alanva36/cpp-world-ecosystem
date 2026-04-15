//
// Created by alanva on 3/30/26.
//

#ifndef PROJEKT_BASERENDERER_HPP
#define PROJEKT_BASERENDERER_HPP

#include <ncurses.h>


class BaseRenderer
{

protected:
     WINDOW* win;
     int window_x = 0;
     int window_y = 0;

public:
     explicit BaseRenderer(WINDOW* window = nullptr);
     virtual ~BaseRenderer() = default;

     virtual void setWindow(WINDOW* new_window);
     void clearScreen();
     void refreshScreen() const;

protected:
     void renderBox(int box_y, int box_x, int box_height, int box_width, int padding, bool centered = true) const;
private:
     void internalSetWindow(WINDOW* new_window);
};


#endif //PROJEKT_BASERENDERER_HPP