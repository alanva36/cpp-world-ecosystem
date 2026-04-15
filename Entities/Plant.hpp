//
// Created by alanva on 4/7/26.
//

#ifndef PROJEKT_PLANT_HPP
#define PROJEKT_PLANT_HPP


#include "Organism.hpp"

class Plant : public Organism {
public:

    Plant(int force, int x, int y, World* world, char symbol, int color);
    virtual ~Plant() = default;

    virtual void action() override;
    virtual void collision(Organism* other) override;

    virtual void spread(int x, int y) = 0;
};



#endif //PROJEKT_PLANT_HPP