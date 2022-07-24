//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>

enum Type {HumanEntity, ZombieEntity};

class Entity {
protected:
    int birth;
    int longevity;
    int age;

    sf::Vector2i position;
    Type entityType;

public:
    Type getEntityType() const;

public:
    Entity();

    Entity(int birth, int longevity, const sf::Vector2i &position);

    Entity(int longevity, const sf::Vector2i &position);

    virtual ~Entity();

    virtual void reproduction() = 0;

    virtual bool isDead() = 0;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
