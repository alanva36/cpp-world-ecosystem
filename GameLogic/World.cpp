//
// Created by alanva on 3/30/26.
//

#include "World.hpp"
#include "../Entities/Organism.hpp"
#include <algorithm>
#include <ctime>
#include "../Organisms/Human.hpp"
#include "../Organisms/Wolf.hpp"
#include "../Organisms/Sheep.hpp"
#include "../Organisms/Fox.hpp"

World::World(int width, int height)
    : width(width), height(height), turn(0), humanPlayer(nullptr)
{
    rng.seed(static_cast<unsigned int>(time(nullptr)));

    populate();
}

World::~World() {

    for (Organism* o : organisms) {
        delete o;
    }
    organisms.clear();
}

void World::executeTurn() {
    turn++;
    clearLogs();

    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if (a->getInitiative() != b->getInitiative()) {
            return a->getInitiative() > b->getInitiative();
        }
        return a->getAge() > b->getAge();
    });

    size_t currentPopulation = organisms.size();
    for (size_t i = 0; i < currentPopulation; ++i) {
        if (organisms[i]->isAlive()) {
            organisms[i]->incrementAge();
            organisms[i]->action();
        }
    }

    auto it = organisms.begin();
    while (it != organisms.end()) {
        if (!(*it)->isAlive()) {
             if (*it == humanPlayer) {
                 humanPlayer = nullptr;
             }
            delete *it;
            it = organisms.erase(it);
        } else {
            ++it;
        }
    }
}

void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);
}

Organism* World::getOrganismAt(int x, int y) const {
    for (Organism* o : organisms) {
        if (o->getPositionX() == x && o->getPositionY() == y && o->isAlive()) {
            return o;
        }
    }
    return nullptr;
}

std::vector<Organism*> World::getAliveOrganisms() const {
    std::vector<Organism*> alive_organims;

    // Loop through all organisms (even the dead ones waiting to be cleaned up)
    for (Organism* org : organisms) {
        if (org->isAlive()) {
            alive_organims.push_back(org); // Only keep the living ones!
        }
    }

    return alive_organims;
}

void World::addLog(const std::string& message) {
    logs.push_back(message);
}

const std::vector<std::string>& World::getLogs() const {
    return logs;
}

void World::clearLogs() {
    logs.clear();
}

bool World::isInBounds(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

int World::getWidth() const { return width; }
int World::getHeight() const { return height; }
int World::getTurn() const { return turn; }

const std::vector<Organism*>& World::getOrganisms() const {
    return organisms;
}

int World::getRandom(int max) {
    if (max <= 0) return 0;
    return rng() % max;
}

void World::addAtRandomPos(Organism* o) {
    int rx, ry;
    int attempts = 0;
    const int maxAttempts = width * height;

    do {
        rx = getRandom(width);
        ry = getRandom(height);
        attempts++;
    } while (getOrganismAt(rx, ry) != nullptr && attempts < maxAttempts);

    if (attempts < maxAttempts) {
        o->setPosition(rx, ry);
        addOrganism(o);
    } else {
        delete o;
    }
}

void World::populate() {

    humanPlayer = new Human(this, width / 2, height / 2);
    addOrganism(humanPlayer);

    const int INITIAL_COUNT = 3;

    for (int i = 0; i < INITIAL_COUNT; ++i) {

        addAtRandomPos(new Wolf(this));
        addAtRandomPos(new Sheep(this));
        addAtRandomPos(new Fox(this));
        // addAtRandomPos(new Turtle(this));
        // addAtRandomPos(new Antelope(this));
        //
        // addAtRandomPos(new Grass(this));
        // addAtRandomPos(new Dandelion(this));
        // addAtRandomPos(new Guarana(this));
        // addAtRandomPos(new WolfBerries(this));
        // addAtRandomPos(new Hogweed(this));
    }
}