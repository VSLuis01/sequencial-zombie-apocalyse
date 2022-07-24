//
// Created by luise on 23/07/22.
//

#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {

}

Entity::Entity(int birth, int longevity, const sf::Vector2i &position) : birth(birth), longevity(longevity),
                                                                         position(position) {}

Entity::Entity(int longevity, const sf::Vector2i &position) : longevity(longevity), position(position) {}

Type Entity::getEntityType() const {
    return entityType;
}

const sf::Vector2i &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const sf::Vector2i &position) {
    Entity::position = position;
}
