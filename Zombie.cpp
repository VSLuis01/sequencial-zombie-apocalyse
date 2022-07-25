//
// Created by luise on 23/07/22.
//

#include "Zombie.h"

Zombie::Zombie() {
    this->entityType = Type::ZombieEntity;
}

Zombie::Zombie(int birth, int longevity, const sf::Vector2i &position) : Entity(birth, longevity, position) {
    this->entityType = Type::ZombieEntity;
}

Zombie::Zombie(int longevity, const sf::Vector2i &position) : Entity(longevity, position) {
    this->entityType = Type::ZombieEntity;
}

Zombie::~Zombie() {

}

bool Zombie::isDead(sf::Vector2i entitiesAround) {
    return false;
}

Entity *Zombie::reproduction() {
    return nullptr;
}

Cell *Zombie::move(std::vector<Cell *> cellsAround) {
    std::vector<Cell *> possibleMoves;
    for (auto &e: cellsAround) {
        if (e != nullptr && (e->getEntity() == nullptr || e->getEntity()->getEntityType() == Type::HumanEntity)) {
            possibleMoves.push_back(e);
        }
    }
    return !possibleMoves.empty() ? possibleMoves[std::rand() % possibleMoves.size()] : nullptr;
}

Entity *Zombie::copy() {
    auto *entity = new Zombie;
    entity->age = this->age;
    entity->birth = this->birth;
    entity->entityType = this->entityType;
    entity->longevity = this->longevity;
    entity->reproductionAge = this->reproductionAge;
    return entity;
}
