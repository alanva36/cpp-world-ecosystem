//
// Created by alanva on 4/16/26.
//

#ifndef PROJEKT_TURTLE_HPP
#define PROJEKT_TURTLE_HPP

#include "../Entities/Animal.hpp"

class Turtle : public Animal {
public:
    Turtle(World* world, int x = 0, int y = 0);
    virtual ~Turtle() = default;

    void action() override;
    bool didDeflectAttack(Organism* attacker) override;
    void breed(int x, int y) override;
    std::string getName() override { return "Zolw"; }
};

#endif //PROJEKT_TURTLE_HPP