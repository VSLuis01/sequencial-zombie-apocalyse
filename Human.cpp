//
// Created by luise on 23/07/22.
//

#include "Human.h"

Human::Human() : Entity(2, 10) {
    this->entityType = Type::HumanEntity;
}

Human::~Human() {

}

Human::Human(int reproductionAge, int longevity) : Entity(reproductionAge, longevity) {
    this->entityType = Type::HumanEntity;
}

Human::Human(int longevity) : Entity(longevity) {
    this->entityType = Type::HumanEntity;
}


bool Human::isDead(sf::Vector2i entitiesAround) {
    int numH = entitiesAround.x;
    int numZ = entitiesAround.y;

    if (numZ >= 5) return true;
    if (numH == 8) return true;
    if (this->age > this->longevity) return true;

    this->age += 1;
    return false;
}


Cell *Human::move(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleMoves.push_back(e);
        }
    }
    return !possibleMoves.empty() ? possibleMoves[rand() % possibleMoves.size()] : nullptr;
}

Entity *Human::copy() {
    return new Human(*this);
}

Entity *Human::reproduce() {
    auto *entity = new Human(*this);
    entity->age = 0;
    this->age = 0;
    return entity;
}

Cell *Human::reproduce(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleMoves.push_back(e);
        }
    }
    int randIndex = rand() % possibleMoves.size();
    return !possibleMoves.empty() ? possibleMoves[randIndex] : nullptr;
}

