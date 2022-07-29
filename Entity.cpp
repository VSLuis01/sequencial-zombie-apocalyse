//
// Created by luise on 23/07/22.
//

#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {

}

Entity::Entity(int reproductionAge, int longevity) : reproductionAge(reproductionAge), longevity(longevity) {
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(2.f);
}

Entity::Entity(int longevity) : longevity(longevity) {}

Type Entity::getEntityType() const {
    return entityType;
}

int Entity::getBirth() const {
    return reproductionAge;
}

int Entity::getLongevity() const {
    return longevity;
}

int Entity::getAge() const {
    return age;
}

Entity &Entity::operator++() {
    this->age += 1;
    return *this;
}

bool Entity::canReproduce() const {
    return this->age >= this->reproductionAge;
}

sf::Vector2i Entity::lookAround(const std::vector<Entity *> &neighborhood) {
    int numHumans = 0;
    int numZombies = 0;
    for (auto &e: neighborhood) {
        if (e != nullptr) {
            if (e->getEntityType() == Type::HumanEntity) {
                ++numHumans;
            } else {
                ++numZombies;
            }
        }
    }
    return {numHumans, numZombies};
}

