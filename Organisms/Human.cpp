//
// Created by alanva on 4/7/26.
//

#include "Human.hpp"
#include "../GameLogic/World.hpp"

Human::Human(World* world, int x, int y)
    : Animal(5, 4, world, '@', 6, x, y),
      skillTimer(0),
      cooldownTimer(0),
      lastCommand(Command::NONE)
{
}

void Human::action() {
    int nextX = getPositionX();
    int nextY = getPositionY();
    int move_step = 1;

    if (skillTimer > 0){
        if (skillTimer > 2){
            move_step = 2;
        }
        else{

            if (world->getRandom(100) < 50){

                move_step = 2;

            }
        }
        skillTimer--;
    }
    else {
        entity.setColor(6);
    }


    if (lastCommand == Command::SKILL) {
        if (cooldownTimer == 0 && skillTimer == 0) {
            skillTimer = 5;
            cooldownTimer = 10;
            world->addLog("Czlowiek aktywowal Szybkosc Antylopy! Porusza sie szybciej przez 5 tur.");
            entity.setColor(7);
        } else {
            world->addLog("Umiejetnosc jeszcze sie odnawia...");
        }
    }

    switch (lastCommand) {
        case Command::UP:    nextY -= move_step; break;
        case Command::DOWN:  nextY += move_step; break;
        case Command::LEFT:  nextX -= move_step; break;
        case Command::RIGHT: nextX += move_step; break;
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