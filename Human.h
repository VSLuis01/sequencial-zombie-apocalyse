//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_HUMAN_H
#define MPI_ZOMBIE_APOCALYPSE_HUMAN_H

#include "Entity.h"
#include "Cell.h"

class Human : public Entity {
public:
    Human();

    Human(int reproductionAge, int longevity);

    explicit Human(int longevity);

    virtual ~Human();

    bool isDead(sf::Vector2i entitiesAround) override;

    Cell *move(std::vector<Cell *> cellsAround) override;

    Cell *reproduce(std::vector<Cell *> cellsAround) override;

    Entity *reproduce() override;

    Entity *copy() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_HUMAN_H
