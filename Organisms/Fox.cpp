//
// Created by alanva
//

#include "Fox.hpp"
#include "../GameLogic/World.hpp"

Fox::Fox(World* world, int x, int y)
    : Animal(3, 7, world, 'L', 0, x, y)
{
}

void Fox::action() {
    int dx, dy;
    int nextX, nextY;
    bool foundSafeSpot = false;
    int attempts = 0;

    while (!foundSafeSpot && attempts < 8) {
        dx = world->getRandom(3) - 1;
        dy = world->getRandom(3) - 1;

        if (dx == 0 && dy == 0) {
            attempts++;
            continue;
        }

        nextX = getPositionX() + dx;
        nextY = getPositionY() + dy;

        if (world->isInBounds(nextX, nextY)) {
            Organism* obstacle = world->getOrganismAt(nextX, nextY);

            if (obstacle == nullptr || obstacle->getForce() <= this->getForce()) {
                foundSafeSpot = true;
            }
        }
        attempts++;
    }

    if (foundSafeSpot) {
        Organism* obstacle = world->getOrganismAt(nextX, nextY);

        if (obstacle == nullptr) {
            setPosition(nextX, nextY);
        } else {
            this->collision(obstacle);
        }
    }
}

void Fox::breed(int x, int y) {
    world->addOrganism(new Fox(world, x, y));
}