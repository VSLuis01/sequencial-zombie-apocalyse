//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_APOCALYPSE_H
#define MPI_ZOMBIE_APOCALYPSE_APOCALYPSE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.h"

/**
 * Essa classe representa a Janela do jogo.
 * Aqui é definido qual será as dimensões da matrix MxN
 */
class Apocalypse {
private:
    //Window
    sf::RenderWindow *window; /*Window*/
    sf::VideoMode videoMode;
    sf::Event ev; /*Listener de eventos*/

    /*Game control*/
    bool running; /*Controle se o jogo está rodando*/
    World *apoWorld; /*Mundo apocaliptico*/
    int matrixRow;
    int matrixColl;

    /*Private Functions*/
    void initVariables(); /*Inicia variaveis da classe*/

    void initWindow(); /*Inicia atributos da Janela*/

    void initWorld(); /*Inicia mundo apocaliptico*/

public:
    inline static bool roll = false; /*Controle para pausar e despausar o mundo*/

    Apocalypse();

    Apocalypse(int matrixRow, int matrixColl);

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
