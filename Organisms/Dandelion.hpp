//
// Created by alanva on 4/20/26.
//

#ifndef PROJEKT_DANDELION_HPP
#define PROJEKT_DANDELION_HPP

#include "../Entities/Plant.hpp"

class Dandelion : public Plant {
public:
    Dandelion(World* world, int x = 0, int y = 0);
    virtual ~Dandelion() = default;

    void action() override;
    void spread(int x, int y) override;
    std::string getName() override { return "Mlecz"; }
};

#endif //PROJEKT_DANDELION_HPP