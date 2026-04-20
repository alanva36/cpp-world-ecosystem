#include "Organism.hpp"
#include "../GameLogic/World.hpp"

Organism::Organism(int force, int initiative, World* world, char symbol, int color, int x, int y)
    : force(force),
      initiative(initiative),
      position_x(x),
      position_y(y),
      world(world),
      age(0),
      alive(true),
      entity(symbol, color)
{
}

Organism::~Organism() {}

int Organism::getForce() const { return force; }
int Organism::getInitiative() const { return initiative; }
int Organism::getAge() const { return age; }
int Organism::getPositionX() const { return position_x; }
int Organism::getPositionY() const { return position_y; }

void Organism::setPosition(int x, int y) {
    position_x = x;
    position_y = y;
}

void Organism::setForce(int new_force) {

    force = new_force;

}

void Organism::incrementAge() {
    age++;
}

bool Organism::isAlive() const { return alive; }

void Organism::kill() {
    alive = false;
}

const VisualEntity& Organism::getVisual() const {
    return entity;
}