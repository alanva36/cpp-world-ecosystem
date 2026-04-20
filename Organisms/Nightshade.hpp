//
// Created by alanva on 4/20/26.
//

#ifndef PROJEKT_NIGHTSHADE_HPP
#define PROJEKT_NIGHTSHADE_HPP

#include "../Entities/Plant.hpp"

class Nightshade : public Plant {
public:
    Nightshade(World* world, int x = 0, int y = 0);
    virtual ~Nightshade() = default;

    void collision(Organism* other) override;
    void spread(int x, int y) override;
    std::string getName() override { return "Wilcze Jagody"; }
};

#endif //PROJEKT_NIGHTSHADE_HPP