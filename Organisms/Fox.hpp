//
// Created by alanva
//

#ifndef PROJEKT_FOX_HPP
#define PROJEKT_FOX_HPP

#include "../Entities/Animal.hpp"

class Fox : public Animal {
public:
    Fox(World* world, int x = 0, int y = 0);
    virtual ~Fox() = default;

    void action() override;
    void breed(int x, int y) override;
    std::string getName() override { return "Lis"; }
};

#endif //PROJEKT_FOX_HPP