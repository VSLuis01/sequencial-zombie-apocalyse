//
// Created by luise on 22/07/22.
//

#include "World.h"

World::World(int matrixOrder, sf::Vector2u windowSize) : matrixOrder(matrixOrder), windowSize(windowSize) {
    this->initWorld();
    this->initVariables();
    this->placeHumans();
    this->placeZombies();
}

World::World() {}

World::~World() {
    for (auto &e: this->matrixCells) {
        delete e;
    }
}

void World::initVariables() {
    this->numHumans = static_cast<int>((float)(this->matrixOrder * this->matrixOrder) * 0.50f);
    this->numZombies = static_cast<int>((float)(this->matrixOrder * this->matrixOrder) * 0.25);
}

void World::initWorld() {
    int k = 0;

    for (int i = 0; i < this->matrixOrder; ++i) {
        for (int j = 0; j < this->matrixOrder; ++j) {
            float x = static_cast<float>(static_cast<float>(this->windowSize.x) / static_cast<float>(this->matrixOrder));
            float y = static_cast<float>(static_cast<float>(this->windowSize.y) / static_cast<float>(this->matrixOrder));

            this->matrixCells.push_back(new Cell(sf::Vector2f(x,y), nullptr));

            this->matrixCells[k]->setPosition((float) j * this->matrixCells[k]->getSize().x,
                                              (float) i * this->matrixCells[k]->getSize().y);
            ++k;
        }
    }
}

void World::placeHumans() {
    int humans = this->numHumans;
    while(humans != 0) {
        int randX = rand() % (this->matrixOrder);
        int randY = rand() % (this->matrixOrder);

        int index = randX * this->matrixOrder + randY;
        if(this->isEmptyPlace(index)) {
            this->matrixCells[index]->setEntity(new Human);
        }
        --humans;
    }
}

void World::placeZombies() {
    int zombies = this->numZombies;
    while(zombies != 0) {
        int randX = rand() % (this->matrixOrder);
        int randY = rand() % (this->matrixOrder);

        int index = randX * this->matrixOrder + randY;
        if(this->isEmptyPlace(index)) {
            this->matrixCells[index]->setEntity(new Zombie);
        }
        --zombies;
    }
}

bool World::isEmptyPlace(int index) const {
    return this->matrixCells[index]->isEmpty();
}

void World::update() {
    for(auto &cell : this->matrixCells) {
        cell->updateCell();
    }
}

void World::render(sf::RenderTarget &target) {
    for(auto &cell : this->matrixCells) {
        cell->render(target);
    }
}
