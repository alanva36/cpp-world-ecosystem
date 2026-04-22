//
// Created by alanva on 3/30/26.
//

#include "World.hpp"
#include "../Entities/Organism.hpp"
#include <algorithm>
#include <ctime>
#include <fstream>
#include "../Organisms/Human.hpp"
#include "../Organisms/Wolf.hpp"
#include "../Organisms/Sheep.hpp"
#include "../Organisms/Fox.hpp"
#include "../Organisms/Antelope.hpp"
#include "../Organisms/Turtle.hpp"
#include "../Organisms/Grass.hpp"
#include "../Organisms/Guarana.hpp"
#include "../Organisms/Nightshade.hpp"
#include "../Organisms/Hogweed.hpp"
#include "../Organisms/Dandelion.hpp"

World::World(GameSettings& settings_ref)
    : settings(settings_ref), turn(0), human_player(nullptr)
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

    size_t current_population = organisms.size();
    for (size_t i = 0; i < current_population; ++i) {
        if (organisms[i]->isAlive()) {
            organisms[i]->incrementAge();
            organisms[i]->action();
        }
    }

    auto it = organisms.begin();
    while (it != organisms.end()) {
        if (!(*it)->isAlive()) {
             if (*it == human_player) {
                 human_player = nullptr;
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
    for (Organism* org : organisms) {
        if (org->isAlive()) {
            alive_organims.push_back(org);
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
    return (x >= 0 && x < settings.getWorldWidth() && y >= 0 && y < settings.getWorldHeight());
}

int World::getWidth() const { return settings.getWorldWidth(); }
int World::getHeight() const { return settings.getWorldHeight(); }
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
    int w = settings.getWorldWidth();
    int h = settings.getWorldHeight();
    const int max_attempts = w * h;

    do {
        rx = getRandom(w);
        ry = getRandom(h);
        attempts++;
    } while (getOrganismAt(rx, ry) != nullptr && attempts < max_attempts);

    if (attempts < max_attempts) {
        o->setPosition(rx, ry);
        addOrganism(o);
    } else {
        delete o;
    }
}

void World::populate() {
    int w = settings.getWorldWidth();
    int h = settings.getWorldHeight();

    human_player = new Human(this, w / 2, h / 2);
    addOrganism(human_player);

    const int INITIAL_COUNT_PLANTS = 1;
    const int INITIAL_COUNT_ANIMALS = 3;

    for (int i = 0; i < INITIAL_COUNT_ANIMALS; ++i) {
        addAtRandomPos(new Wolf(this));
        addAtRandomPos(new Sheep(this));
        addAtRandomPos(new Fox(this));
        addAtRandomPos(new Turtle(this));
        addAtRandomPos(new Antelope(this));
    }
    for (int i = 0; i < INITIAL_COUNT_PLANTS; ++i) {
        addAtRandomPos(new Grass(this));
        addAtRandomPos(new Dandelion(this));
        addAtRandomPos(new Guarana(this));
        addAtRandomPos(new Nightshade(this));
        addAtRandomPos(new Hogweed(this));
    }


}

void World::saveToFile(const std::string& filename){
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    file << settings.getWorldWidth() << " " << settings.getWorldHeight() << " " << turn << "\n";

    for (Organism* org : organisms) {
        if (org && org->isAlive()) {
            file << org->getVisual().getModel() << " "
                 << org->getPositionX() << " "
                 << org->getPositionY() << " "
                 << org->getForce() << " "
                 << org->getAge() << "\n";
        }
    }

    addLog("Zapisano gre");

    file.close();
}

void World::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    for (Organism* org : organisms) {
        delete org;
    }
    organisms.clear();
    human_player = nullptr;

    int w, h, saved_turn;
    if (!(file >> w >> h >> saved_turn)) return;

    settings.setWorldWidth(w);
    settings.setWorldHeight(h);
    this->turn = saved_turn;

    char symbol;
    int x, y, force, age;

    while (file >> symbol >> x >> y >> force >> age) {
        Organism* new_org = nullptr;

        switch (symbol) {
            case '@': new_org = new Human(this, x, y);
                      human_player = static_cast<Human*>(new_org); break;
            case 'W': new_org = new Wolf(this); break;
            case 'O': new_org = new Sheep(this); break;
            case 'L': new_org = new Fox(this); break;
            case 'Z': new_org = new Turtle(this); break;
            case 'A': new_org = new Antelope(this); break;
            case 'T': new_org = new Grass(this); break;
            case 'M': new_org = new Dandelion(this); break;
            case 'G': new_org = new Guarana(this); break;
            case 'J': new_org = new Nightshade(this); break;
            case 'B': new_org = new Hogweed(this); break;
            default: continue;
        }

        if (new_org) {
            new_org->setPosition(x, y);
            new_org->setForce(force);
            new_org->setAge(age);
            addOrganism(new_org);
        }
    }

    addLog("Wczytano zapis gry");

    file.close();
}