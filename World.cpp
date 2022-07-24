//
// Created by luise on 22/07/22.
//

#include "World.h"

World::World(int matrixOrder, sf::Vector2u windowSize) : matrixOrder(matrixOrder), windowSize(windowSize) {
    this->initWorld();
}

World::World() {}

World::~World() {
    for (auto &e: this->matrixCells) {
        delete e;
    }
}

void World::initWorld() {
    int k = 0;
    for (int i = 0; i < this->matrixOrder; ++i) {
        for (int j = 0; j < this->matrixOrder; ++j) {
            float x = static_cast<float>(static_cast<float>(this->windowSize.x) / static_cast<float>(this->matrixOrder));
            float y = static_cast<float>(static_cast<float>(this->windowSize.y) / static_cast<float>(this->matrixOrder));
            this->matrixCells.push_back(new Cell(sf::Vector2f(x,y), new Zombie));
            this->matrixCells[k]->setPosition((float) j * this->matrixCells[k]->getSize().x,
                                             (float) i * this->matrixCells[k]->getSize().y);
            ++k;
        }
    }
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
