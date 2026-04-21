//
// Created by alanva on 4/20/26.
//

#include "Guarana.hpp"
#include "../GameLogic/World.hpp"
#include "../Entities/Organism.hpp"

Guarana::Guarana(World* world, int x, int y)
    : Plant(0, x, y, world, 'G', 1)
{
}

void Guarana::collision(Organism* other) {

    other->setForce(other->getForce() + 3);

    world->addLog(other->getName() +
                  " zjada " + this->getName() + " i zwieksza sile o 3!");

    Plant::collision(other);
}

void Guarana::spread(int x, int y) {
    world->addOrganism(new Guarana(world, x, y));
    world->addLog(this->getName() + " rozsiala sie na pole (" + std::to_string(x) + "," + std::to_string(y) + ")");
}