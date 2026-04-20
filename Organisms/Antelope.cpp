//
// Created by alanva on 4/16/26.
//

#include "Antelope.hpp"
#include "../GameLogic/World.hpp"
#include <vector>
#include <typeinfo>

Antelope::Antelope(World* world, int x, int y)
    : Animal(4, 4, world, 'A', 0, x, y) // Force 4, Initiative 4, Symbol 'A'
{
}

void Antelope::action() {
    // Antylopa porusza się o 2 pola
    int dx = world->getRandom(5) - 2; // Losuje: -2, -1, 0, 1, 2
    int dy = world->getRandom(5) - 2;

    if (dx == 0 && dy == 0) return;

    int nextX = getPositionX() + dx;
    int nextY = getPositionY() + dy;

    if (world->isInBounds(nextX, nextY)) {
        Organism* obstacle = world->getOrganismAt(nextX, nextY);

        if (obstacle == nullptr) {
            setPosition(nextX, nextY);
        } else {
            // Wywołuje kolizję (może dojść do walki, rozmnażania lub ucieczki)
            this->collision(obstacle);
        }
    }
}

void Antelope::collision(Organism* other) {
    // Jeśli to ten sam gatunek - rozmnażanie (logika z Animal)
    if (typeid(*this) == typeid(*other)) {
        Animal::collision(other);
        return;
    }

    // 50% szans na ucieczkę przed walką
    if (world->getRandom(100) < 50) {
        std::vector<std::pair<int, int>> free_spots;

        // Szukanie wolnego sąsiedniego pola (zasięg 1)
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
            world->addLog("Antylopa ucieka przed walka z " + std::string(1, other->getVisual().getModel()));
            return; // Walka się nie odbywa
        }
    }

    // Jeśli nie uciekła lub nie było miejsca - standardowa walka z Animal
    Animal::collision(other);
}

void Antelope::breed(int x, int y) {
    world->addOrganism(new Antelope(world, x, y));
}