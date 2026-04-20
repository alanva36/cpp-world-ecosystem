//
// Created by alanva on 4/20/26.
//

#ifndef PROJEKT_GUARANA_HPP
#define PROJEKT_GUARANA_HPP

#include "../Entities/Plant.hpp"

class Guarana : public Plant {
public:
    Guarana(World* world, int x = 0, int y = 0);
    virtual ~Guarana() = default;

    void collision(Organism* other) override;
    void spread(int x, int y) override;
    std::string getName() override { return "Guarana"; }
};


#endif //PROJEKT_GUARANA_HPP