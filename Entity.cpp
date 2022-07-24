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
