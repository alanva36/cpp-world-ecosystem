//
// Created by alanva on 4/16/26.
//

#include "Turtle.hpp"
#include "../GameLogic/World.hpp"
#include <typeinfo>

Turtle::Turtle(World* world, int x, int y)
    : Animal(2, 1, world, 'Z', 0, x, y)
{
}

void Turtle::action() {
    if (world->getRandom(100) < 75) {
        return;
    }

    Animal::action();
}

void Turtle::collision(Organism* other) {
    if (typeid(*this) == typeid(*other)) {
        Animal::collision(other);
        return;
    }
    if (other->getForce() < 5) {
        world->addLog(this->getName() + " odpiera atak " + other->getName());
        return;
    }

    Animal::collision(other);
}

void Turtle::breed(int x, int y) {
    world->addOrganism(new Turtle(world, x, y));
}