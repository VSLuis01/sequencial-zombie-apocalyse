//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_CELL_H
#define MPI_ZOMBIE_APOCALYPSE_CELL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"

class Cell: public sf::RectangleShape {
private:
    sf::Color color;
    sf::Color outlineColor;

    void initVariables();
    void initCell();

    //Entidade que está na célula (ZombieEntity, HumanEntity)
    Entity *entity;

public:
    Cell();

    explicit Cell(sf::Vector2f size, Entity* entity);

    Cell(sf::Vector2f pos, sf::Vector2f size, Entity* entity);

    virtual ~Cell();

    void updateCell();
    void render(sf::RenderTarget& target);

    bool isEmpty() const;

    /*Getter Setter*/
    Entity *getEntity() const;
    void setEntity(Entity *entity);
};


#endif //MPI_ZOMBIE_APOCALYPSE_CELL_H
