//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>

enum Type {HumanEntity = 1, ZombieEntity = -1};

class Entity {
protected:
    int birth;
    int longevity;
    int age;
    int reproductionAge;

    sf::Vector2i position;
    Type entityType;

public:
    const sf::Vector2i &getPosition() const;

    void setPosition(const sf::Vector2i &position);

    Type getEntityType() const;

public:
    Entity();

    Entity(int birth, int longevity, const sf::Vector2i &position);

    Entity(int longevity, const sf::Vector2i &position);

    virtual ~Entity();

    virtual Entity* reproduction() = 0;

    virtual bool isDead() = 0;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
