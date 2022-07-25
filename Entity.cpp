//
// Created by luise on 23/07/22.
//

#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {

}

Entity::Entity(int birth, int longevity, const sf::Vector2i &position) : birth(birth), longevity(longevity) {}

Entity::Entity(int longevity, const sf::Vector2i &position) : longevity(longevity) {}

Type Entity::getEntityType() const {
    return entityType;
}

int Entity::getBirth() const {
    return birth;
}

int Entity::getLongevity() const {
    return longevity;
}

int Entity::getAge() const {
    return age;
}

std::string Entity::toString() {
    switch (this->entityType) {
        case HumanEntity:
            return "Human";
        case ZombieEntity:
            return "Zombie";
    }
}

