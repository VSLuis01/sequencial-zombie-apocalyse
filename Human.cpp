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


bool Human::isDead(const std::vector<Cell *>& cellsAround) {
    std::vector<Entity *> entitiesAround;
    for (auto &e : cellsAround) {
        if (e != nullptr) {
            entitiesAround.push_back(e->getEntity());
        }
    }

    sf::Vector2i entities = Entity::lookAround(entitiesAround);
    int numH = entities.x;
    int numZ = entities.y;

    if (this->isChild) {
        int i = 0;
        int j = 0;
    }

    if (numZ >= 5) return true;
    if (numH == 8) {
         int i = 0;
        return true;
    }
    if (this->age > this->longevity) return true;

    return false;
}


Cell *Human::move(const std::vector<Cell *> &cellsAround) {
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
    entity->isChild = true;
    this->age = 0;
    return entity;
}

Cell *Human::possibleReproducer(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleRepoCells;

    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleRepoCells.push_back(e);
        }
    }
    return !possibleRepoCells.empty() ? possibleRepoCells[rand() % possibleRepoCells.size()] : nullptr;
}

bool Human::reproduceRule(const std::vector<Cell *> &cellsAround) {
    std::vector<Entity *> entitiesAround;
    int numHCanReproduce = 0;
    for (auto &e : cellsAround) {
        if(e != nullptr && e->getEntity() != nullptr) {
            if (e->getEntity()->getEntityType() == Type::HumanEntity && e->getEntity()->canReproduce()) numHCanReproduce++;
            entitiesAround.push_back(e->getEntity());
        }
    }

    int numH = Entity::lookAround(entitiesAround).x;
    int numZ = Entity::lookAround(entitiesAround).y;

    if((numH >= 4) && (numH > numZ) && (numHCanReproduce >= 3)) return true;
    return false;
}

