//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>
#include <vector>

enum Type {
    HumanEntity = 1, ZombieEntity = -1
};

class Cell;

class Entity {
protected:
    int birth;
    int longevity;
    int age = 0;
    int reproductionAge;

    Type entityType;

public:
    virtual Entity *copy() = 0;

    int getBirth() const;

    int getLongevity() const;

    int getAge() const;

    Type getEntityType() const;

    Entity();

    Entity(int birth, int longevity, const sf::Vector2i &position);

    Entity(int longevity, const sf::Vector2i &position);

    virtual ~Entity();

    virtual Entity *reproduction() = 0;

    virtual bool isDead(sf::Vector2i entitiesAround) = 0;

    virtual Cell *move(std::vector<Cell *> cellsAround) = 0;

    std::string toString();
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
