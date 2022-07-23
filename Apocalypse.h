//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_APOCALYPSE_H
#define MPI_ZOMBIE_APOCALYPSE_APOCALYPSE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.h"

class Apocalypse {
private:
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    /*Game control*/
    bool running;
    World apoWorld;


    /*Private Functions*/
    void initVariables();
    void initWindow();
    void initWorld();

public:

    Apocalypse();

    virtual ~Apocalypse();

    /*Update objects attributes or something*/
    void update();
    /*Listening events*/
    void pollEvents();

    /*Render objects on the window*/
    void render();

    bool isRunning() const;

};


#endif //MPI_ZOMBIE_APOCALYPSE_APOCALYPSE_H
