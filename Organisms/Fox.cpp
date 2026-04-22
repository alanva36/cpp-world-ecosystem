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
    int next_x, next_y;
    bool safe_spot = false;
    int attempts = 0;

    while (!safe_spot && attempts < 8) {
        dx = world->getRandom(3) - 1;
        dy = world->getRandom(3) - 1;

        if (dx == 0 && dy == 0) {
            attempts++;
            continue;
        }

        next_x = getPositionX() + dx;
        next_y = getPositionY() + dy;

        if (world->isInBounds(next_x, next_y)) {
            Organism* obstacle = world->getOrganismAt(next_x, next_y);

            if (obstacle == nullptr || obstacle->getForce() <= this->getForce()) {
                safe_spot = true;
            }
        }
        attempts++;
    }

    if (safe_spot) {
        Organism* obstacle = world->getOrganismAt(next_x, next_y);

        if (obstacle == nullptr) {
            setPosition(next_x, next_y);
        } else {
            this->collision(obstacle);
        }
    }
}

void Fox::breed(int x, int y) {
    world->addOrganism(new Fox(world, x, y));
}