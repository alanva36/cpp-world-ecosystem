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

void Turtle::breed(int x, int y) {
    world->addOrganism(new Turtle(world, x, y));
}

bool Turtle::didDeflectAttack(Organism* attacker) {
    if (attacker->getForce() < 5) {
        world->addLog("Zolw odpiera atak " + attacker->getName() + " (sila < 5)");
        return true;
    }
    return false;
}