//
// Created by luise on 22/07/22.
//

#include "World.h"

World::World(int matrixOrder, sf::Vector2u windowSize) : matrixRow(matrixOrder), matrixColl(matrixOrder),
                                                         windowSize(windowSize) {
    this->initWorld();
    this->initVariables();
    this->placeHumans();
    this->placeZombies();
}

World::World(int matrixRow, int matrixColl, sf::Vector2u windowSize) : matrixRow(matrixRow), matrixColl(matrixColl),
                                                                       windowSize(windowSize) {
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
    this->numHumans = static_cast<int>((float) (this->matrixRow * this->matrixColl) * 0.50f);
    this->numZombies = static_cast<int>((float) (this->matrixRow * this->matrixColl) * 0.25);
}

void World::initWorld() {
    int k = 0;

    for (int i = 0; i < this->matrixRow; ++i) {
        for (int j = 0; j < this->matrixColl; ++j) {
            float x = static_cast<float>(static_cast<float>(this->windowSize.x) /
                                         static_cast<float>(this->matrixColl));
            float y = static_cast<float>(static_cast<float>(this->windowSize.y) /
                                         static_cast<float>(this->matrixRow));

            this->matrixCells.push_back(new Cell(sf::Vector2f(x, y), nullptr));

            this->matrixCells[k]->setPosition((float) j * this->matrixCells[k]->getSize().x,
                                              (float) i * this->matrixCells[k]->getSize().y);
            ++k;
        }
    }
}

void World::placeHumans() {
    int humans = this->numHumans;
    while (humans != 0) {
        int randX = rand() % (this->matrixRow);
        int randY = rand() % (this->matrixColl);

        int index = randX * this->matrixColl + randY;
        if (this->isEmptyPlace(index)) {
            this->matrixCells[index]->setEntity(new Human);
            this->matrixCells[index]->getEntity()->setPosition(sf::Vector2i(randX, randY));
            --humans;
        }
    }
}

void World::placeZombies() {
    int zombies = this->numZombies;
    while (zombies != 0) {
        int randX = rand() % (this->matrixRow);
        int randY = rand() % (this->matrixColl);

        int index = randX * this->matrixColl + randY;
        if (this->isEmptyPlace(index)) {
            this->matrixCells[index]->setEntity(new Zombie);
            this->matrixCells[index]->getEntity()->setPosition(sf::Vector2i(randX, randY));
            --zombies;
        }
    }
}

bool World::isEmptyPlace(int index) const {
    return this->matrixCells[index]->isEmpty();
}

void World::update() {
    for (auto &cell: this->matrixCells) {
        cell->updateCell();
    }
}

void World::render(sf::RenderTarget &target) {
    for (auto &cell: this->matrixCells) {
        cell->render(target);
    }
}

std::vector<Cell *> World::getNeighborhood(Cell &cell) {
    return std::vector<Cell *>();
}

std::vector<Cell *> World::getNeighborhood(int index) {
    int posX = (index) / this->matrixColl;
    int posY = (index) % this->matrixColl;

    sf::Vector2i top = posX - 1 >= 0 ? sf::Vector2i(posX - 1, posY) : sf::Vector2i(this->matrixRow - 1, posY);
    sf::Vector2i bottom = posX + 1 <= this->matrixRow - 1 ? sf::Vector2i(posX + 1, posY) : sf::Vector2i(0, posY);
    sf::Vector2i left = posY - 1 >= 0 ? sf::Vector2i(posX, posY - 1) : sf::Vector2i(posX, this->matrixColl - 1);
    sf::Vector2i right = posY + 1 <= this->matrixColl - 1 ? sf::Vector2i(posX, posY + 1) : sf::Vector2i(posX, 0);

    sf::Vector2i topLeft = (posX - 1 >= 0 && posY - 1 >= 0) ? sf::Vector2i(posX - 1, posY - 1) : sf::Vector2i(-1, -1);
    sf::Vector2i topRight = (posX - 1 >= 0 && posY + 1 <= this->matrixColl - 1) ? sf::Vector2i(posX - 1, posY + 1)
                                                                              : sf::Vector2i(-1, -1);
    sf::Vector2i bottomLeft = (posX + 1 <= this->matrixRow - 1 && posY - 1 >= 0) ? sf::Vector2i(posX + 1, posY - 1)
                                                                               : sf::Vector2i(-1, -1);
    sf::Vector2i bottomRight = (posX + 1 <= this->matrixRow - 1 && posY + 1 <= this->matrixColl - 1) ? sf::Vector2i(
            posX + 1, posY + 1) : sf::Vector2i(-1, -1);

    std::vector<sf::Vector2i> cellsPositions{top, bottom, left, right, topLeft, topRight, bottomLeft, bottomRight};
    std::vector<Cell*> neighborhood;
    for(auto &e : cellsPositions) {
        if(e.x != -1) {
            int i = e.x * this->matrixColl + e.y;
            neighborhood.push_back(this->matrixCells[i]);
        } else {
            neighborhood.push_back(nullptr);
        }
    }

    return neighborhood;
}

std::vector<Cell *> World::getNeighborhood(int row, int col) {
    return std::vector<Cell *>();
}
