//
// Created by alanva on 4/20/26.
//

#include "Dandelion.hpp"
#include "../GameLogic/World.hpp"

Dandelion::Dandelion(World* world, int x, int y)
    : Plant(0, x, y, world, 'M', 3)
{
}

void Dandelion::action() {

    for (int i = 0; i < 3; ++i) {
        Plant::action();
    }
}

void Dandelion::spread(int x, int y) {
    world->addOrganism(new Dandelion(world, x, y));
    world->addLog(this->getName() + " rozsial sie na pole (" + std::to_string(x) + "," + std::to_string(y) + ")");
}