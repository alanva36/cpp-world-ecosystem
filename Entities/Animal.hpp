//
// Created by alanva on 4/7/26.
//

#ifndef PROJEKT_ANIMAL_HPP
#define PROJEKT_ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
public:
    Animal(int force, int initiative, World* world, char symbol, int color, int x = 0, int y = 0);
    virtual ~Animal() = default;

    void action() override;
    void collision(Organism* other) override;

    virtual void breed(int x, int y) = 0;
};

#endif //PROJEKT_ANIMAL_HPP