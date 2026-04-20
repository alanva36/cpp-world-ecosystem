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

void Antelope::collision(Organism* other) {
    if (typeid(*this) == typeid(*other)) {
        Animal::collision(other);
        return;
    }

    if (world->getRandom(100) < 50) {
        std::vector<std::pair<int, int>> free_spots;

        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                int check_x = getPositionX() + dx;
                int check_y = getPositionY() + dy;

                if (world->isInBounds(check_x, check_y) && world->getOrganismAt(check_x, check_y) == nullptr) {
                    free_spots.push_back({check_x, check_y});
                }
            }
        }

        if (!free_spots.empty()) {
            int idx = world->getRandom(free_spots.size());
            this->setPosition(free_spots[idx].first, free_spots[idx].second);
            world->addLog(this->getName() + " ucieka przed walka z " + other->getName());
            return;
        }
    }

    Animal::collision(other);
}

void Antelope::breed(int x, int y) {
    world->addOrganism(new Antelope(world, x, y));
}