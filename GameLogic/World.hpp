//
// Created by alanva on 3/30/26.
//

#ifndef PROJEKT_WORLD_HPP
#define PROJEKT_WORLD_HPP

#include <random>
#include <vector>
#include <string>

class Organism;
class Human;

class World
{

private:
    int width;
    int height;
    int turn;

    std::vector<Organism*> organisms;
    std::vector<std::string> logs;

    std::mt19937 rng;
    Human* humanPlayer;

public:
    World(int width, int height);
    ~World();

    // Główna logika tury
    void executeTurn();

    void addOrganism(Organism* organism);
    Organism* getOrganismAt(int x, int y) const;
    std::vector<Organism*> getAliveOrganisms() const;
    Human* getHumanPlayer() const { return humanPlayer; }

    void addLog(const std::string& message);
    const std::vector<std::string>& getLogs() const;
    void clearLogs();

    int getWidth() const;
    int getHeight() const;
    int getTurn() const;
    bool isInBounds(int x, int y) const;

    int getRandom(int max);

    const std::vector<Organism*>& getOrganisms() const;
private:
    void populate();
    void addAtRandomPos(Organism* organism);

};


#endif //PROJEKT_WORLD_HPP