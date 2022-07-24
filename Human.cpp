//
// Created by luise on 23/07/22.
//

#include "Human.h"

Human::Human() {}

Human::~Human() {

}

Human::Human(int birth, int longevity, const sf::Vector2i &position) : Entity(birth, longevity, position) {}

Human::Human(int longevity, const sf::Vector2i &position) : Entity(longevity, position) {}

void Human::reproduction() {

}

bool Human::isDead() {
    return false;
}

