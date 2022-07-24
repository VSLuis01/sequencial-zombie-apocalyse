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

void Human::reproduction() {

}

bool Human::isDead() {
    return false;
}

