//
// Created by alanva
//

#include "Sheep.hpp"
#include "../GameLogic/World.hpp"

Sheep::Sheep(World* world, int x, int y)
    : Animal(4, 4, world, 'S', 0, x, y) // Siła 4, Inicjatywa 4, Symbol S
{
}

void Sheep::breed(int x, int y) {
    world->addOrganism(new Sheep(world, x, y));
}