//
// Created by alanva
//

#ifndef PROJEKT_SHEEP_HPP
#define PROJEKT_SHEEP_HPP

#include "../Entities/Animal.hpp"

class Sheep : public Animal {
public:
    Sheep(World* world, int x = 0, int y = 0);
    virtual ~Sheep() = default;

    void breed(int x, int y) override;
    std::string getName() override { return "Owca"; }
};

#endif //PROJEKT_SHEEP_HPP