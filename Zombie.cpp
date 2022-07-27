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

bool Zombie::isDead(sf::Vector2i entitiesAround) {
    int numH = entitiesAround.x;
    int numZ = entitiesAround.y;

    if (this->age > this->longevity) return true;
    if (numZ >= 6 && numH == 0) return true;
    if (((double) rand() / (RAND_MAX)) < 1 / 32.f) return true;
    if (this->energy < 0) return true;

    this->age += 1;
    return false;
}

Cell *Zombie::move(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && (e->getEntity() == nullptr || e->getEntity()->getEntityType() == Type::HumanEntity)) {
            possibleMoves.push_back(e);
        }
    }
    /**TODO Melhorar esse negócio aqui*/
    int randIndex = !possibleMoves.empty() ? std::rand() % possibleMoves.size() : 0;
    if (possibleMoves[randIndex]->getEntity() != nullptr &&
        possibleMoves[randIndex]->getEntity()->getEntityType() == Type::HumanEntity) this->energy++;
    else this->energy--;

    return !possibleMoves.empty() ? possibleMoves[randIndex] : nullptr;
}

Entity *Zombie::copy() {
    return new Zombie(*this);
}

Entity *Zombie::reproduce() {
    auto *entity = new Zombie(*this);
    entity->age = 0;
    this->age = 0;
    return entity;
}

Cell *Zombie::reproduce(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && e->getEntity() == nullptr) {
            possibleMoves.push_back(e);
        }
    }
    return !possibleMoves.empty() ? possibleMoves[rand() % possibleMoves.size()] : nullptr;
}
