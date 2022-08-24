//
// Created by luise on 22/07/22.
//

#include "World.h"

int World::matrixRow; /*LInhas da matriz*/
int World::matrixColl; /*Colunas da matriz*/
std::vector<Cell *> World::matrixCells;

World::World(int matrixOrder, sf::Vector2u windowSize) : windowSize(windowSize) {
    this->initVariables(matrixOrder);
    this->initWorld();
    this->placeHumans();
    this->placeZombies();
}

World::World(int row, int coll, sf::Vector2u windowSize) : windowSize(windowSize) {
    this->initVariables(row, coll);
    this->initWorld();
    this->placeHumans();
    this->placeZombies();
}

World::World() {}

World::~World() {
    for (auto &e: World::matrixCells) {
        delete e;
    }
}

void World::initVariables(int matrixRow, int matrixColl) {
    World::matrixRow = matrixRow;
    World::matrixColl = matrixColl;
    this->numHumans = static_cast<int>((float) (World::matrixRow * World::matrixColl) * 0.50f);
    this->numZombies = static_cast<int>((float) (World::matrixRow * World::matrixColl) * 0.25);
    this->it = 0;
}

void World::initVariables(int matrixOrder) {
    World::matrixRow = matrixOrder;
    World::matrixColl = matrixOrder;
    this->numHumans = static_cast<int>((float) (World::matrixRow * World::matrixColl) * 0.50f);
    this->numZombies = static_cast<int>((float) (World::matrixRow * World::matrixColl) * 0.25);
    this->it = 0;
}

void World::initWorld() const {
    int k = 0;

    for (int i = 0; i < World::matrixRow; ++i) {
        for (int j = 0; j < World::matrixColl; ++j) {
            float x = static_cast<float>(static_cast<float>(this->windowSize.x) /
                                         static_cast<float>(World::matrixColl));
            float y = static_cast<float>(static_cast<float>(this->windowSize.y) /
                                         static_cast<float>(World::matrixRow));

            World::matrixCells.push_back(new Cell(sf::Vector2f(x, y), nullptr));

            World::matrixCells[k]->setPosition((float) j * World::matrixCells[k]->getSize().x,
                                               (float) i * World::matrixCells[k]->getSize().y);
            World::matrixCells[k]->setPos(sf::Vector2i(i, j));
            ++k;
        }
    }
}

void World::placeHumans() const {
    int humans = this->numHumans;
    while (humans != 0) {
        int randX = random() % (World::matrixRow);
        int randY = random() % (World::matrixColl);

        int index = randX * World::matrixColl + randY;
        if (World::isEmptyPlace(index)) {
            World::matrixCells[index]->placeEntity(new Human);
            --humans;
        }
    }
}

void World::placeZombies() const {
    int zombies = this->numZombies;
    while (zombies != 0) {
        int randX = random() % (World::matrixRow);
        int randY = random() % (World::matrixColl);

        int index = randX * World::matrixColl + randY;
        if (World::isEmptyPlace(index)) {
            World::matrixCells[index]->placeEntity(new Zombie);
            --zombies;
        }
    }
}

bool World::isEmptyPlace(int index) {
    return World::matrixCells[index]->isEmpty();
}

void World::update() {

    /*Atualiza célula por célula, Tem uma visao mais detalhada do movimento de casa entidade
     * É mais lento*/
//    World::matrixCells[it]->updateCell(this->flipGeneration);
//    this->it++;
//    if (this->it >= World::matrixCells.size()) {
//        this->it = 0;
//        for (auto &e: World::matrixCells) {
//            if(e->getEntity() != nullptr)
//                ++*e->getEntity();
//        }
//    }

    /*Atualiza todas as celulas, Tem visao menos detalhada do movimento de cada célula.
     * É mais rápido*/
    for (auto &cell: World::matrixCells) {
        cell->updateCell();
    }
    for (auto &e: World::matrixCells) {
        if (e->getEntity() != nullptr)
            ++*e->getEntity();
    }
    this->gen++;
    std::cout << this->gen << "\n";
}

void World::render(sf::RenderTarget &target) {
    for (auto &cell: World::matrixCells) {
        cell->render(target);
    }
}

std::vector<Cell *> World::getNeighborhood(int index) {
    int posX = (index) / World::matrixColl;
    int posY = (index) % World::matrixColl;

    sf::Vector2i top = posX - 1 >= 0 ? sf::Vector2i(posX - 1, posY) : sf::Vector2i(World::matrixRow - 1, posY);

    sf::Vector2i bottom = posX + 1 <= World::matrixRow - 1 ? sf::Vector2i(posX + 1, posY) : sf::Vector2i(0, posY);

    sf::Vector2i left = posY - 1 >= 0 ? sf::Vector2i(posX, posY - 1) : sf::Vector2i(posX, World::matrixColl - 1);

    sf::Vector2i right = posY + 1 <= World::matrixColl - 1 ? sf::Vector2i(posX, posY + 1) : sf::Vector2i(posX, 0);

    sf::Vector2i topLeft = (posX - 1 >= 0 && posY - 1 >= 0) ? sf::Vector2i(posX - 1, posY - 1) : sf::Vector2i(-1, -1);

    sf::Vector2i topRight = (posX - 1 >= 0 && posY + 1 <= World::matrixColl - 1) ?
                            sf::Vector2i(posX - 1, posY + 1) : sf::Vector2i(-1, -1);

    sf::Vector2i bottomLeft = (posX + 1 <= World::matrixRow - 1 && posY - 1 >= 0) ?
                              sf::Vector2i(posX + 1, posY - 1) : sf::Vector2i(-1, -1);

    sf::Vector2i bottomRight = (posX + 1 <= World::matrixRow - 1 && posY + 1 <= World::matrixColl - 1) ?
                               sf::Vector2i(posX + 1, posY + 1) : sf::Vector2i(-1, -1);

    std::vector<sf::Vector2i> cellsPositions{top, bottom, left, right, topLeft, topRight, bottomLeft, bottomRight};
    std::vector<Cell *> neighborhood;
    for (auto &e: cellsPositions) {
        if (e.x != -1) {
            int i = e.x * World::matrixColl + e.y;
            neighborhood.push_back(World::matrixCells[i]);
        } else {
            neighborhood.push_back(nullptr);
        }
    }

    return neighborhood;
}

std::vector<Cell *> World::getNeighborhood(Cell &cell) {
    return World::getNeighborhood(cell.getPos().x, cell.getPos().y);
}

std::vector<Cell *> World::getNeighborhood(int row, int col) {
    return World::getNeighborhood(row * World::matrixColl + col);
}