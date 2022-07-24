//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_HUMAN_H
#define MPI_ZOMBIE_APOCALYPSE_HUMAN_H

#include "Entity.h"

class Human : public Entity {
private:

public:
    Human();

    Human(int birth, int longevity, const sf::Vector2i &position);

    Human(int longevity, const sf::Vector2i &position);

    virtual ~Human();

    Entity *reproduction() override;

    bool isDead() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_HUMAN_H
