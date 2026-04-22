//
// Created by alanva on 4/16/26.
//

#include "Antelope.hpp"
#include "../GameLogic/World.hpp"
#include <vector>
#include <typeinfo>

Antelope::Antelope(World* world, int x, int y)
    : Animal(4, 4, world, 'A', 0, x, y)
{
}

void Antelope::action() {
    int dx = world->getRandom(5) - 2;
    int dy = world->getRandom(5) - 2;

    if (dx == 0 && dy == 0) return;

    int nextX = getPositionX() + dx;
    int nextY = getPositionY() + dy;

    if (world->isInBounds(nextX, nextY)) {
        Organism* obstacle = world->getOrganismAt(nextX, nextY);

        if (obstacle == nullptr) {
            setPosition(nextX, nextY);
        } else {
            this->collision(obstacle);
        }
    }
}

bool Antelope::didDeflectAttack(Organism* attacker) {
    if (world->getRandom(100) < 50) {
        std::vector<std::pair<int, int>> free_spots;

        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if (dx == 0 && dy == 0) continue;
                int nx = getPositionX() + dx;
                int ny = getPositionY() + dy;

                if (world->isInBounds(nx, ny) && world->getOrganismAt(nx, ny) == nullptr) {
                    free_spots.push_back({nx, ny});
                }
            }
        }

        if (!free_spots.empty()) {
            int idx = world->getRandom(free_spots.size());
            world->addLog(getName() + " ucieka przed walka z " + attacker->getName());
            this->setPosition(free_spots[idx].first, free_spots[idx].second);
            return true;
        }
    }

    return false;
}
void Antelope::breed(int x, int y) {
    world->addOrganism(new Antelope(world, x, y));
}