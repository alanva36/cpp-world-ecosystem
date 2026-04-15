//
// Created by alanva on 4/7/26.
//

#include "Plant.hpp"
#include "../GameLogic/World.hpp"

Plant::Plant(int force, int x, int y, World* world, char symbol, int color)
    : Organism(force, 0, world, symbol, color, x, y)
{
}

void Plant::action() {

    if (world->getRandom(100) < 5) {
        int nx = getPositionX() + (world->getRandom(3) - 1);
        int ny = getPositionY() + (world->getRandom(3) - 1);

        if (world->isInBounds(nx, ny) && (nx != getPositionX() || ny != getPositionY())) {
            if (world->getOrganismAt(nx, ny) == nullptr) {
                this->spread(nx, ny);
            }
        }
    }
}

void Plant::collision(Organism* other) {

    if (other->getForce() >= this->getForce()) {
        this->kill();
    }
}
