//
// Created by alanva on 4/7/26.
//

#include "Human.hpp"
#include "../GameLogic/World.hpp"

Human::Human(World* world, int x, int y)
    : Animal(5, 4, world, '@', 0, x, y), // Siła 5, Inicjatywa 4, Symbol @
      skillTimer(0),
      cooldownTimer(0),
      lastCommand(Command::NONE)
{
}

void Human::action() {
    int nextX = getPositionX();
    int nextY = getPositionY();

    if (lastCommand == Command::SKILL) {
        if (cooldownTimer == 0 && skillTimer == 0) {
            skillTimer = 5;
            cooldownTimer = 10;
            world->addLog("Czlowiek aktywowal Tarcze! Jest niezniszczalny przez 5 tur.");
        } else {
            world->addLog("Umiejetnosc jeszcze sie odnawia...");
        }
    }

    switch (lastCommand) {
        case Command::UP:    nextY--; break;
        case Command::DOWN:  nextY++; break;
        case Command::LEFT:  nextX--; break;
        case Command::RIGHT: nextX++; break;
        default: break;
    }

    if (nextX != getPositionX() || nextY != getPositionY()) {
        if (world->isInBounds(nextX, nextY)) {
            Organism* obstacle = world->getOrganismAt(nextX, nextY);
            if (obstacle == nullptr) {
                setPosition(nextX, nextY);
            } else {
                this->collision(obstacle);
            }
        }
    }

    if (skillTimer > 0) skillTimer--;
    if (cooldownTimer > 0) cooldownTimer--;

    lastCommand = Command::NONE;
}

void Human::collision(Organism* other) {
    if (skillTimer > 0) {
        world->addLog("Tarcza aktywna! Czlowiek odpycha atak " + std::string(1, other->getVisual().getModel()));
        return;
    }

    Animal::collision(other);
}

void Human::breed(int x, int y) {
}