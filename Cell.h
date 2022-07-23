//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_CELL_H
#define MPI_ZOMBIE_APOCALYPSE_CELL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Cell: public sf::RectangleShape {
private:
    sf::Color color;
    sf::Color outlineColor;

    void initVariables();
    void initCell();

    //Entidade que está na célula (Zombie, Human)

public:
    Cell();

    explicit Cell(sf::Vector2f size);

    Cell(sf::Vector2f pos, sf::Vector2f size);

    virtual ~Cell();

    void updateCell();
    void render(sf::RenderTarget& target);
};


#endif //MPI_ZOMBIE_APOCALYPSE_CELL_H
