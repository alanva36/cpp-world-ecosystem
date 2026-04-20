//
// Created by alanva on 4/20/26.
//

#include "Grass.hpp"

#include "../GameLogic/World.hpp"

Grass::Grass(World* world, int x, int y)
    : Plant(0, x, y, world, 'T', 2)
{
}

void Grass::spread(int x, int y) {
    world->addOrganism(new Grass(world, x, y));
    world->addLog(this->getName() + " rozprzestrzenila sie na pole (" + std::to_string(x) + "," + std::to_string(y) + ")");
}