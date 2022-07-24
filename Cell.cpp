//
// Created by luise on 22/07/22.
//

#include "Cell.h"

Cell::Cell() {
    this->initVariables();
    this->initCell();
}

Cell::Cell(sf::Vector2f size) : RectangleShape(size) {
    this->initVariables();
    this->initCell();
}


Cell::Cell(sf::Vector2f pos, sf::Vector2f size) : RectangleShape(size) {
    this->initVariables();
    this->initCell();
    this->setPosition(pos);
}

Cell::~Cell() {

}

void Cell::initVariables() {
    this->color = sf::Color::White;
    this->outlineColor = sf::Color::Black;
}

void Cell::initCell() {
    this->setFillColor(this->color);
    this->setOutlineColor(this->outlineColor);
    this->setOutlineThickness(1.f);
}

void Cell::updateCell() {

}

void Cell::render(sf::RenderTarget &target) {
    target.draw(*this);
}
