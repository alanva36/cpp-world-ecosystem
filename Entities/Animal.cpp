//
// Created by alanva on 4/7/26.
//

#include "Animal.hpp"
#include "../GameLogic/World.hpp"
#include <string>

Animal::Animal(int force, int initiative, World* world, char symbol, int color, int x, int y)
    : Organism(force, initiative, world, symbol, color, x, y) {}

void Animal::action() {
    int dx = world->getRandom(3) - 1;
    int dy = world->getRandom(3) - 1;

    if (dx == 0 && dy == 0) return;

    int nextX = getPositionX() + dx;
    int nextY = getPositionY() + dy;

    if (nextX >= 0 && nextX < world->getWidth() &&
        nextY >= 0 && nextY < world->getHeight()) {

        Organism* obstacle = world->getOrganismAt(nextX, nextY);

        if (obstacle == nullptr) {
            setPosition(nextX, nextY);

        } else {
            this->collision(obstacle);

        }
    }
}

void Animal::collision(Organism* other) {

    if (this->getVisual().getModel() == other->getVisual().getModel()) {

        int bx = getPositionX() + (world->getRandom(3) - 1);
        int by = getPositionY() + (world->getRandom(3) - 1);

        if (world->getOrganismAt(bx, by) == nullptr) {
            this->breed(bx, by);
            world->addLog("Urodzil sie nowy osobnik gatunku " + std::string(1, getVisual().getModel()));
        }
        return;
    }

    if (this->getForce() >= other->getForce()) {
        world->addLog(std::string(1, getVisual().getModel()) + " zabija " + std::string(1, other->getVisual().getModel()));
        other->kill();
        this->setPosition(other->getPositionX(), other->getPositionY());

    } else {

        world->addLog(std::string(1, other->getVisual().getModel()) + " zabija " + std::string(1, getVisual().getModel()));
        this->kill();
    }
}