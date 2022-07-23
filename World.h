//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_WORLD_H
#define MPI_ZOMBIE_APOCALYPSE_WORLD_H

#include "Cell.h"
#include <vector>
#include <iostream>

class World {
private:
    int matrixOrder;
    sf::Vector2u windowSize;
    std::vector<Cell> matrixCells;

    void initWorld();
public:
    World();

    explicit World(int matrixOrder, sf::Vector2u windowSize);

    virtual ~World();

    void update();
    void render(sf::RenderTarget& target);
};


#endif //MPI_ZOMBIE_APOCALYPSE_WORLD_H
