//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
#define MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H

#include "Entity.h"
#include "Cell.h"

class Zombie : public Entity {
private:

public:
    Zombie();

    Zombie(int birth, int longevity, const sf::Vector2i &position);

    Zombie(int longevity, const sf::Vector2i &position);

    virtual ~Zombie();

    Entity *reproduction() override;

    bool isDead(sf::Vector2i entitiesAround) override;

    Cell *move(std::vector<Cell *> cellsAround) override;

    Entity *copy() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
