//
// Created by alanva on 4/16/26.
//

#include "Turtle.hpp"
#include "../GameLogic/World.hpp"
#include <typeinfo>

Turtle::Turtle(World* world, int x, int y)
    : Animal(2, 1, world, 'Z', 0, x, y) // Siła 2, Inicjatywa 1, Symbol 'Z'
{
}

void Turtle::action() {
    // Żółw w 75% przypadków nie zmienia położenia
    // getRandom(100) zwraca 0-99, więc < 75 oznacza brak ruchu
    if (world->getRandom(100) < 75) {
        return;
    }

    // Pozostałe 25% czasu wykonuje standardowy ruch zwierzęcia
    Animal::action();
}

void Turtle::collision(Organism* other) {
    // Jeśli to ten sam gatunek - rozmnażanie (logika z Animal)
    if (typeid(*this) == typeid(*other)) {
        Animal::collision(other);
        return;
    }

    // Specjalna obrona: Odpiera ataki zwierząt o sile < 5
    // Uwaga: 'other' to organizm, który wszedł na pole Żółwia (napastnik)
    if (other->getForce() < 5) {
        world->addLog("Zolw odpiera atak " + std::string(1, other->getVisual().getModel()));
        // Napastnik nie zajmuje pola żółwia - w Twoim systemie
        // wystarczy nie wywoływać logiki walki i pozwolić napastnikowi
        // pozostać na jego pozycji (lub nie aktualizować pozycji napastnika).
        return;
    }

    // Jeśli napastnik ma siłę >= 5, następuje normalna walka z Animal
    Animal::collision(other);
}

void Turtle::breed(int x, int y) {
    world->addOrganism(new Turtle(world, x, y));
}