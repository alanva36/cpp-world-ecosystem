//
// Created by alanva on 4/7/26.
//

#ifndef PROJEKT_HUMAN_HPP
#define PROJEKT_HUMAN_HPP


#include "../Entities/Animal.hpp"
#include "../Ncurses/Input.hpp"
#include <string>

class Human : public Animal {
private:
    int skillTimer;
    int cooldownTimer;
    Command lastCommand;

public:
    Human(World* world, int x = 0, int y = 0);
    virtual ~Human() = default;

    void action() override;
    void collision(Organism* other) override;

    void setNextCommand(Command cmd) { lastCommand = cmd; }

    void breed(int x, int y) override;
    std::string getName() override { return "Czlowiek"; }
};


#endif //PROJEKT_HUMAN_HPP