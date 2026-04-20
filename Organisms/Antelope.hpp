//
// Created by alanva on 4/16/26.
//

#ifndef PROJEKT_ANTELOPE_HPP
#define PROJEKT_ANTELOPE_HPP

#include "../Entities/Animal.hpp"

class Antelope : public Animal {
public:
    Antelope(World* world, int x = 0, int y = 0);
    virtual ~Antelope() = default;

    void action() override;
    void collision(Organism* other) override;
    void breed(int x, int y) override;
    std::string getName() override { return "Antylopa"; }
};


#endif //PROJEKT_ANTELOPE_HPP