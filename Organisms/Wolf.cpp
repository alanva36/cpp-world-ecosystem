//
// Created by alanva
//

#include "Wolf.hpp"
#include "../GameLogic/World.hpp"

Wolf::Wolf(World* world, int x, int y)
    : Animal(9, 5, world, 'W', 0, x, y) // Siła 9, Inicjatywa 5, Symbol W
{
}

void Wolf::breed(int x, int y) {
    world->addOrganism(new Wolf(world, x, y));
}