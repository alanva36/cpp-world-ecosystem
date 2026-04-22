//
// Created by alanva on 4/20/26.
//

#include "Nightshade.hpp"
#include "../GameLogic/World.hpp"

Nightshade::Nightshade(World* world, int x, int y)
    : Plant(99, x, y, world, 'J', 1)
{
}

void Nightshade::collision(Organism* other) {
    world->addLog(other->getName() + " zjada " + this->getName() + " i ginie!");

    other->kill();

    this->kill();
}

void Nightshade::spread(int x, int y) {
    world->addOrganism(new Nightshade(world, x, y));
    world->addLog(this->getName() + " rozsialy sie na pole (" + std::to_string(x) + "," + std::to_string(y) + ")");
}