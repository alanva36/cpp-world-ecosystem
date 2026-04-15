//
// Created by alanva
//

#ifndef PROJEKT_WOLF_HPP
#define PROJEKT_WOLF_HPP

#include "../Entities/Animal.hpp"

class Wolf : public Animal {
public:
    Wolf(World* world, int x = 0, int y = 0);
    virtual ~Wolf() = default;

    void breed(int x, int y) override;
    std::string getName() override { return "Wilk"; }
};

#endif //PROJEKT_WOLF_HPP