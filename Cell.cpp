//
// Created by luise on 22/07/22.
//

#include "Cell.h"


Cell::Cell() {
    this->initVariables();
    this->initCell();
}

Cell::Cell(sf::Vector2f size, Entity* entity) : RectangleShape(size) {
    this->entity = entity;
    this->initVariables();
    this->initCell();
}


Cell::Cell(sf::Vector2f pos, sf::Vector2f size, Entity* entity) : RectangleShape(size) {
    this->entity = entity;
    this->initVariables();
    this->initCell();
    this->setPosition(pos);
}

Cell::~Cell() {
    delete this->entity;
}

void Cell::initVariables() {
    if (this->entity == nullptr) {
        this->color = sf::Color(200, 200, 200, 255);
    } else {
        switch (this->entity->getEntityType()) {
            case Type::HumanEntity:
                this->color = sf::Color::Blue;
                break;
            case Type::ZombieEntity:
                this->color = sf::Color::Red;
                break;
            default:
                break;
        }
    }

    this->outlineColor = sf::Color::Black;
}

void Cell::initCell() {
    this->setFillColor(this->color);
    this->setOutlineColor(this->outlineColor);
    this->setOutlineThickness(1.f);
}

void Cell::updateCell() {
    this->setFillColor(this->color);
}

void Cell::render(sf::RenderTarget &target) {
    target.draw(*this);
}

bool Cell::isEmpty() const {
    return this->entity == nullptr;
}

Entity *Cell::getEntity() const {
    return entity;
}

void Cell::setEntity(Entity *entity) {
    Cell::entity = entity;
    switch (this->entity->getEntityType()) {
        case Type::HumanEntity:
            this->color = sf::Color::Blue;
            break;
        case Type::ZombieEntity:
            this->color = sf::Color::Red;
            break;
        default:
            break;
    }
}
