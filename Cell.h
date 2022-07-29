//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_CELL_H
#define MPI_ZOMBIE_APOCALYPSE_CELL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"
#include "World.h"

/**
 * Está classe representa uma célula no mundo apocaliptico
 * Uma célula pode assumir 3 estados:
 * Estado 1: Zombie alocado na célula
 * Estado 2: Humano alocado na célula
 * Estado 3: Célula vazia
 */
class Cell : public sf::RectangleShape {
private:
    sf::Color color;
    sf::Color outlineColor;

    /**
     * Inicia cor da célula
     */
    void initVariables();

    /**
     * Inicia atributos graficos da célula
     */
    void initCell();

    /**
     * Atualiza a cor da célula
     * Azul -> Humano
     * Vermelho -> Zombie
     */
    void updateColor();

    /**
     * Destroi a entidade alocada na célula
     */
    void destroyEntity();

    Entity *entity; /*Entidade atribuida a esta célula*/

    sf::Vector2i position; /*Matrix position of the cell*/
public:
    Cell();

    explicit Cell(sf::Vector2f size, Entity *entity);

    Cell(sf::Vector2f pos, sf::Vector2f size, Entity *entity);

    virtual ~Cell();

    void updateCell();

    void render(sf::RenderTarget &target);

    bool isEmpty() const;

    /*Getter Setter*/
    Entity *getEntity() const;

    /**
     * Aloca uma entidade na celula
     * @param entity entidade que será alocada a corrente célula
     */
    void placeEntity(Entity* entity);

    /**
     * Aloca uma entidade na célula e adiciona uma cor ao retangulo central da célula.
     * Está função só existe para propósitos de depuração
     * @param entity entidade que será alocada na corrente célula
     * @param color cor do retangulo central
     */
    void placeEntity(Entity* entity, sf::Color color);

    /**
     * Retorna a posição da matriz da célula, ou seja, posição x,y
     * @return Posição da matriz
     */
    const sf::Vector2i &getPos() const;

    /**
     * Atribui uma posição da matriz na célula
     * @param position posicao da celula na matriz
     */
    void setPos(const sf::Vector2i &position);

};


#endif //MPI_ZOMBIE_APOCALYPSE_CELL_H
