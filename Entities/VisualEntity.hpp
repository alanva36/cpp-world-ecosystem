//
// Created by alanva on 3/31/26.
//

#ifndef PROJEKT_VISUALENTITY_HPP
#define PROJEKT_VISUALENTITY_HPP

class VisualEntity {
private:
    char model;      // ASCII symbol (for example: 'W', 'O', '#')
    int color_pair;  // ID of color pair in ncurses

public:

    VisualEntity(char model = '?', int color_pair = 0);

    char getModel() const;
    int getColor() const;

    void setModel(char new_model);
    void setColor(int new_color);
};


#endif //PROJEKT_VISUALENTITY_HPP