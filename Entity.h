//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

enum Type {
    HumanEntity = 1, ZombieEntity = -1
};

class Cell;

class Entity {
protected:
    int longevity;
    int age = 0;
    int reproductionAge;

    Type entityType;

public:
    sf::RectangleShape shape;

    int getBirth() const;

    int getLongevity() const;

    int getAge() const;

    Type getEntityType() const;

    bool canReproduce() const;

    Entity();

    Entity(int reproductionAge, int longevity);

    Entity(int longevity);

    virtual ~Entity();

    virtual Entity *copy() = 0;

    virtual Cell* reproduce(std::vector<Cell *> cellsAround) = 0;

    virtual Entity* reproduce() = 0;

    virtual bool isDead(sf::Vector2i entitiesAround) = 0;

    virtual Cell *move(std::vector<Cell *> cellsAround) = 0;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
