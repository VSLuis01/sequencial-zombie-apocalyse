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
//        this->color = sf::Color(200, 200, 200, 255);
        this->color = sf::Color::Black;
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
    std::vector<Entity*> possibleRepH;
    std::vector<Entity*> possibleRepZ;

    bool destroy = false;


    if (this->entity != nullptr) {
        if(!this->entity->isDead(this->lookAround(neighborhood))) {
            Cell *target = this->entity->move(neighborhood);
            if (target != nullptr) {
                target->placeEntity(this->entity->copy());
                target->updateColor();
                destroy = true;
            }
        } else {
            destroy = true;
        }
    } else {
        for (auto &e: neighborhood) {
            if(e != nullptr && e->getEntity() != nullptr) {
                if(e->getEntity()->getEntityType() == Type::HumanEntity && e->getEntity()->canReproduce()) {
                    possibleRepH.push_back(e->getEntity());
                } else if (e->getEntity()->getEntityType() == Type::ZombieEntity && e->getEntity()->canReproduce()) {
                    possibleRepZ.push_back(e->getEntity());
                }
            }
        }
        if ((numH > 4) && (numH > numZ) && (possibleRepH.size() > 2)) {
            this->entity = !possibleRepH.empty() ? possibleRepH[rand() % possibleRepH.size()]->reproduce() : nullptr;
            this->setFillColor(sf::Color::Yellow);
            return;
        } else if ((numZ > 4) && (numZ > numH) && (possibleRepZ.size() > 2)) {
            this->entity = !possibleRepZ.empty() ? possibleRepZ[rand() % possibleRepZ.size()]->reproduce() : nullptr;
            this->setFillColor(sf::Color::White);
            return;
        }
    }

    if(destroy) {
        this->destroyEntity();
    }
    this->updateColor();
}

void Cell::render(sf::RenderTarget &target) {
    target.draw(*this);
//    if (this->entity != nullptr) {
//        target.draw(this->entity->shape);
//    }
}

bool Cell::isEmpty() const {
    return this->entity == nullptr;
}

Entity *Cell::getEntity() const {
    return entity;
}

void Cell::destroyEntity() {
    delete this->entity;
    this->entity = nullptr;
}

void Cell::updateColor() {
    if (this->entity != nullptr) {
        if (!this->entity->isChild) {
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
    } else {
//        this->color = sf::Color(200, 200, 200, 255);
        this->color = sf::Color::Black;
    }
    this->setFillColor(this->color);
}

void Cell::placeEntity(Entity *entity) {
    this->entity = entity;
    this->entity->shape.setPosition(
            this->getPosition().x + (this->getGlobalBounds().width / 2) - 10.f,
            this->getPosition().y + (this->getGlobalBounds().height / 2) - 10.f);
}

void Cell::placeEntity(Entity *entity, sf::Color color) {
    this->entity = entity;
    this->updateColor();
    this->entity->shape.setPosition(
            this->getPosition().x + (this->getGlobalBounds().width / 2) - 10.f,
            this->getPosition().y + (this->getGlobalBounds().height / 2) - 10.f);
    this->entity->shape.setFillColor(color);
}

const sf::Vector2i &Cell::getPos() const {
    return position;
}

void Cell::setPos(const sf::Vector2i &position) {
    Cell::position = position;
}
