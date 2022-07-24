//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_WORLD_H
#define MPI_ZOMBIE_APOCALYPSE_WORLD_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include "Human.h"
#include "Zombie.h"
#include <ctime>

class World {
private:
    int matrixRow;
    int matrixColl;
    sf::Vector2u windowSize;
    std::vector<Cell*> matrixCells;

    /*Private Functions*/
    void initWorld();
    void placeHumans();
    void placeZombies();
    void initVariables();
    bool isEmptyPlace(int index) const;

    /*Private variables*/
    int numHumans;
    int numZombies;
public:
    World();

    explicit World(int matrixOrder, sf::Vector2u windowSize);
    World(int matrixRow, int matrixColl, sf::Vector2u windowSize);

    virtual ~World();

    void update();
    void render(sf::RenderTarget& target);
};


#endif //MPI_ZOMBIE_APOCALYPSE_WORLD_H
