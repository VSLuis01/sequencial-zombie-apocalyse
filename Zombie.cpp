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

bool Zombie::isDead() {
    return false;
}

Entity *Zombie::reproduction() {
    return nullptr;
}
