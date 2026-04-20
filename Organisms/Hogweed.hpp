//
// Created by alanva on 4/20/26.
//

#ifndef PROJEKT_HOGWEED_HPP
#define PROJEKT_HOGWEED_HPP

#include "../Entities/Plant.hpp"

class Hogweed : public Plant {
public:
    Hogweed(World* world, int x = 0, int y = 0);
    virtual ~Hogweed() = default;

    void action() override;
    void collision(Organism* other) override;
    void spread(int x, int y) override;
    std::string getName() override { return "Barszcz Sosnowskiego"; }
};


#endif //PROJEKT_HOGWEED_HPP