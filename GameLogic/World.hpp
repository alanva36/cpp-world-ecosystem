//
// Created by alanva on 3/30/26.
//

#ifndef PROJEKT_WORLD_HPP
#define PROJEKT_WORLD_HPP

#include <random>
#include <vector>
#include <string>
#include "../GameSettings.hpp"

class Organism;
class Human;

class World
{
private:
    GameSettings& settings;
    int turn;

    std::vector<Organism*> organisms;
    std::vector<std::string> logs;

    std::mt19937 rng;
    Human* human_player;

public:
    World(GameSettings& settings_ref);
    ~World();

    void executeTurn();

    void addOrganism(Organism* organism);
    Organism* getOrganismAt(int x, int y) const;
    std::vector<Organism*> getAliveOrganisms() const;
    Human* getHumanPlayer() const { return human_player; }

    void addLog(const std::string& message);
    const std::vector<std::string>& getLogs() const;
    void clearLogs();

    int getWidth() const;
    int getHeight() const;
    int getTurn() const;
    bool isInBounds(int x, int y) const;

    int getRandom(int max);

    const std::vector<Organism*>& getOrganisms() const;

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    void populate();
    void addAtRandomPos(Organism* organism);
};

#endif //PROJEKT_WORLD_HPP