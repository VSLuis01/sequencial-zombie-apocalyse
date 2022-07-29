//
// Created by luise on 23/07/22.
//

#include "Zombie.h"

Zombie::Zombie() : Entity(3, 20) {
    this->entityType = Type::ZombieEntity;
}

Zombie::Zombie(int reproductionAge, int longevity) : Entity(reproductionAge, longevity) {
    this->entityType = Type::ZombieEntity;
}

Zombie::Zombie(int longevity) : Entity(longevity) {
    this->entityType = Type::ZombieEntity;
}

Zombie::~Zombie() {

}

bool Zombie::isDead(const std::vector<Cell *>& cellsAround) {
    std::vector<Entity *> entitiesAround;
    for (auto &e : cellsAround) {
        if (e != nullptr) {
            entitiesAround.push_back(e->getEntity());
        }
    }

    sf::Vector2i entities = Entity::lookAround(entitiesAround);
    int numH = entities.x;
    int numZ = entities.y;

    if(this->isChild) {
        int i = 0;
        int j = 20;
    }

    if (this->age > this->longevity) return true;
    if (numZ >= 6 && numH == 0) return true;
    if (((double) rand() / (RAND_MAX)) < 1 / 32.f) return true;
    if (this->energy < 0) return true;

    return false;
}

Cell *Zombie::move(const std::vector<Cell *> &cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && (e->getEntity() == nullptr || e->getEntity()->getEntityType() == Type::HumanEntity)) {
            possibleMoves.push_back(e);
        }
    }


    int randIndex;
    if(!possibleMoves.empty()) {
        randIndex = rand() % possibleMoves.size();
        if (possibleMoves[randIndex]->getEntity() != nullptr &&
            possibleMoves[randIndex]->getEntity()->getEntityType() == Type::HumanEntity) this->energy++;
        else this->energy--;
        return possibleMoves[randIndex];
    }

    return nullptr;
}

Entity *Zombie::copy() {
    return new Zombie(*this);
}

Entity *Zombie::reproduce() {
    auto *entity = new Zombie(*this);
    entity->age = 0;
    entity->energy = 5;
    entity->isChild = true;
    this->energy = 5;
    this->age = 0;
    return entity;
}

Cell *Zombie::possibleReproducer(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleMoves.push_back(e);
        }
    }
    return !possibleMoves.empty() ? possibleMoves[rand() % possibleMoves.size()] : nullptr;
}

bool Zombie::reproduceRule(const std::vector<Cell *> &cellsAround) {
    std::vector<Entity *> entitiesAround;
    int numZCanReproduce = 0;
    for (auto &e : cellsAround) {
        if(e != nullptr && e->getEntity() != nullptr) {
            if (e->getEntity()->getEntityType() == Type::ZombieEntity && e->getEntity()->canReproduce()) numZCanReproduce++;
            entitiesAround.push_back(e->getEntity());
        }
    }

    int numH = Entity::lookAround(entitiesAround).x;
    int numZ = Entity::lookAround(entitiesAround).y;

    if((numZ >= 4) && (numZ > numH) && (numZCanReproduce >= 3)) return true;
    return false;
}
