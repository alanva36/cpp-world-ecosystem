//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_MENU_HPP
#define PROJEKT_MENU_HPP

#include <vector>
#include <string>

#include "../GameSettings.hpp"

class Menu {
private:
    int selected_index;
    GameSettings& settings; // Referencja do obiektu w kontrolerze
    std::vector<std::string> options;

public:
    Menu(GameSettings& settings); // Konstruktor przyjmuje referencję

    void moveUp();
    void moveDown();
    void increaseValue();
    void decreaseValue();

    int getSelectedIndex() const;
    const std::vector<std::string>& getOptions() const;

private:
    void updateMenuText();
};


#endif //PROJEKT_MENU_HPP