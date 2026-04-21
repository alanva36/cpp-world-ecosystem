//
// Created by alanva on 4/7/26.
//

#include "Animal.hpp"
#include "../GameLogic/World.hpp"
#include <string>
#include <typeinfo>

#include "Plant.hpp"

Animal::Animal(int force, int initiative, World* world, char symbol, int color, int x, int y)
    : Organism(force, initiative, world, symbol, color, x, y) {}

void Animal::action() {
    int dx = world->getRandom(3) - 1;
    int dy = world->getRandom(3) - 1;

    if (dx == 0 && dy == 0) return;

    int nextX = getPositionX() + dx;
    int nextY = getPositionY() + dy;

    if (world->isInBounds(nextX,nextY) == true) {

        Organism* obstacle = world->getOrganismAt(nextX, nextY);

        if (obstacle == nullptr) {
            setPosition(nextX, nextY);

        } else {
            this->collision(obstacle);

        }
    }
}

void Animal::collision(Organism* other) {

    if (typeid(*this) == typeid(*other)) {
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
            int random_index = world->getRandom(free_spots.size());
            this->breed(free_spots[random_index].first, free_spots[random_index].second);
            world->addLog("Urodzil sie nowy osobnik " + other->getName());
        }

        return;
    }
    std::string message;
    if (this->getForce() >= other->getForce()) {

            if (dynamic_cast<const Plant*>(other)){
                message = " zjada ";

            }
            else{
                message = " zabija ";

            }
            world->addLog(getName() + message + other->getName());
            other->kill();
            this->setPosition(other->getPositionX(), other->getPositionY());
    }
    else{
            if (dynamic_cast<const Plant*>(other)){
                message = " zatruwa ";

            }
            else{
                message = " zabija ";

            }
            world->addLog(other->getName() + message + getName());
            this->kill();
    }
}