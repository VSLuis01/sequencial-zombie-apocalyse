//
// Created by luise on 22/07/22.
//

#include "Cell.h"


Cell::Cell() {
    this->initVariables();
    this->initCell();
}

Cell::Cell(sf::Vector2f size, Entity *entity) : RectangleShape(size) {
    this->entity = entity;
    this->initVariables();
    this->initCell();
}


Cell::Cell(sf::Vector2f pos, sf::Vector2f size, Entity *entity) : RectangleShape(size) {
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

sf::Vector2i Cell::lookAround(const std::vector<Cell *> &neighborhood) {
    int numHumans = 0;
    int numZombies = 0;
    for (auto &e: neighborhood) {
        if (e != nullptr) {
            if (e->getEntity() != nullptr) {
                if (e->getEntity()->getEntityType() == Type::HumanEntity) {
                    ++numHumans;
                } else {
                    ++numZombies;
                }
            }
        }
    }
    return {numHumans, numZombies};
}

void Cell::updateCell(const std::vector<Cell *> &neighborhood) {
    int numH = lookAround(neighborhood).x;
    int numZ = lookAround(neighborhood).y;
    this->updateColor();
    if (this->entity != nullptr) {
        Cell *cell = this->entity->move(neighborhood);
        if(cell != nullptr) {
            cell->setEntity(this->entity->copy());
            delete this->entity;
            this->entity = nullptr;
        }
    }
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

void Cell::updateColor() {
    if(this->entity != nullptr) {
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
    } else {
        this->color = sf::Color(200, 200, 200, 255);
    }
    this->setFillColor(this->color);
}

void Cell::setEntity(Entity *entity) {
    delete this->entity;
    this->entity = entity;
}

const sf::Vector2i &Cell::getPos() const {
    return position;
}

void Cell::setPos(const sf::Vector2i &position) {
    Cell::position = position;
}

std::string Cell::toString() {
    return this->entity != nullptr ? this->entity->toString() : "EMPTY";
}
