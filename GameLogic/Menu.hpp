//
// Created by alanva on 4/2/26.
//

#ifndef PROJEKT_MENU_HPP
#define PROJEKT_MENU_HPP

#include <vector>
#include <string>

class Menu {
private:
    std::vector<std::string> options;
    int selectedIndex;

public:
    Menu();

    void moveUp();
    void moveDown();

    int getSelectedIndex() const;
    const std::vector<std::string>& getOptions() const;
};


#endif //PROJEKT_MENU_HPP