//
// Created by luise on 23/07/22.
//

#include "Apocalypse.h"

Apocalypse::Apocalypse() {
    this->initVariables();
    this->initWindow();
    this->initWorld();
}

Apocalypse::~Apocalypse() {
    delete this->window;
    delete this->apoWorld;
}

void Apocalypse::initVariables() {
    this->running = true;
}

void Apocalypse::initWindow() {
    this->videoMode.width = 800;
    this->videoMode.height = 800;

    this->window = new sf::RenderWindow(this->videoMode, "MPI-ZombieEntity-Apocalypse",
                                        sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Apocalypse::initWorld() {
    this->apoWorld = new World(this->matrixOrder, this->window->getSize());
}

void Apocalypse::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                this->running = false;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    this->running = false;
                }
                break;
            default:
                break;
        }
    }
}

void Apocalypse::update() {
    this->pollEvents();
    this->apoWorld->update();
}

void Apocalypse::render() {
    this->window->clear(sf::Color::White);

    this->apoWorld->render(*this->window);

    this->window->display();
}

bool Apocalypse::isRunning() const {
    return this->running;
}

