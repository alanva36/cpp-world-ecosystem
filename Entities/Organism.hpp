//
// Created by alanva on 3/30/26.
//

#ifndef PROJEKT_ORGANISM_HPP
#define PROJEKT_ORGANISM_HPP
#include <string>

#include "VisualEntity.hpp"
class World;

class Organism {
protected:
    int force;
    int initiative;
    int position_x;
    int position_y;
    int age;
    bool alive;
    World* world;
    VisualEntity entity;

public:

    Organism(int force, int initiative, World* world, char symbol, int color, int x = 0, int y = 0);
    virtual ~Organism();

    virtual void action() = 0;
    virtual void collision(Organism* other) = 0;
    virtual std::string getName() = 0;
    virtual bool didDeflectAttack(Organism* attacker) {
        return false;
    }

    int getForce() const;
    int getInitiative() const;
    int getAge() const;
    int getPositionX() const;
    int getPositionY() const;

    void setPosition(int x, int y);
    void setForce(int new_force);
    void setAge(int new_age);
    bool isAlive() const;
    void kill();

    void incrementAge();

    const VisualEntity& getVisual() const;
};


#endif //PROJEKT_ORGANISM_HPP