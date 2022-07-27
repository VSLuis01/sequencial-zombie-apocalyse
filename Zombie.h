//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
#define MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H

#include "Entity.h"
#include "Cell.h"

class Zombie : public Entity {
private:
    int energy = 5;
public:
    Zombie();

    Zombie(int reproductionAge, int longevity);

    explicit Zombie(int longevity);

    virtual ~Zombie();

    bool isDead(sf::Vector2i entitiesAround) override;

    Cell *move(std::vector<Cell *> cellsAround) override;

    Cell *reproduce(std::vector<Cell *> cellsAround) override;

    Entity *reproduce() override;

    Entity *copy() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
