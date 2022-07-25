//
// Created by luise on 23/07/22.
//

#include "Human.h"

Human::Human() {
    this->entityType = Type::HumanEntity;
}

Human::~Human() {

}

Human::Human(int birth, int longevity, const sf::Vector2i &position) : Entity(birth, longevity, position) {
    this->entityType = Type::HumanEntity;
}

Human::Human(int longevity, const sf::Vector2i &position) : Entity(longevity, position) {
    this->entityType = Type::HumanEntity;
}


bool Human::isDead(sf::Vector2i entitiesAround) {
    int numH = entitiesAround.x;
    int numZ = entitiesAround.y;

    if (numZ >= 5) return true;
    if (numH == 8) return true;

    this->age++;
    return false;
}

Entity *Human::reproduction() {

    return nullptr;
}

Cell *Human::move(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleMoves.push_back(e);
        }
    }
    return !possibleMoves.empty() ? possibleMoves[std::rand() % possibleMoves.size()] : nullptr;
}

Entity *Human::copy() {
    auto *entity = new Human;
    entity->age = this->age;
    entity->birth = this->birth;
    entity->entityType = this->entityType;
    entity->longevity = this->longevity;
    entity->reproductionAge = this->reproductionAge;
    return entity;
}

