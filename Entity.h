//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>

class Entity {
private:
    int birth;
    int longevity;

    sf::Vector2i position;
public:
    Entity();

    Entity(int birth, int longevity, const sf::Vector2i &position);

    Entity(int longevity, const sf::Vector2i &position);

    virtual ~Entity();

    virtual void reproduction() = 0;

    virtual bool isDead() = 0;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
