//
// Created by alanva on 4/20/26.
//

#ifndef PROJEKT_GRASS_HPP
#define PROJEKT_GRASS_HPP

#include "../Entities/Plant.hpp"

class Grass : public Plant {
public:
    Grass(World* world, int x = 0, int y = 0);
    virtual ~Grass() = default;

    void spread(int x, int y) override;
    std::string getName() override { return "Trawa"; }
};


#endif //PROJEKT_GRASS_HPP