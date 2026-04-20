//
// Created by alanva
//

#include "Sheep.hpp"
#include "../GameLogic/World.hpp"

Sheep::Sheep(World* world, int x, int y)
    : Animal(4, 4, world, 'O', 0, x, y)
{
}

void Sheep::breed(int x, int y) {
    world->addOrganism(new Sheep(world, x, y));
}