//
// Created by alanva on 4/20/26.
//

#include "Hogweed.hpp"
#include "../GameLogic/World.hpp"

Hogweed::Hogweed(World* world, int x, int y)
    : Plant(10, x, y, world, 'B', 4)
{
}

void Hogweed::action() {
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;

            int checkX = getPositionX() + dx;
            int checkY = getPositionY() + dy;

            if (world->isInBounds(checkX, checkY)) {
                Organism* target = world->getOrganismAt(checkX, checkY);

                if (target != nullptr && dynamic_cast<Plant*>(target) == nullptr) {
                    world->addLog(this->getName() + " zabija " + target->getName() + " w poblizu");
                    target->kill();
                }
            }
        }
    }

    Plant::action();
}

void Hogweed::collision(Organism* other) {
    world->addLog(other->getName() + " zjada Barszcz i ginie!");

    other->kill();
    this->kill();
}

void Hogweed::spread(int x, int y) {
    world->addOrganism(new Hogweed(world, x, y));
}