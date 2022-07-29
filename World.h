//
// Created by luise on 22/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_WORLD_H
#define MPI_ZOMBIE_APOCALYPSE_WORLD_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include "Human.h"
#include "Zombie.h"
#include <ctime>

/**
 * Classe que representa o mundo apocaliptico.
 * Essa classe possui informações sobre todas as células do mundo.
 */
class World {
private:
    static int matrixRow; /*LInhas da matriz*/
    static int matrixColl; /*Colunas da matriz*/
    static std::vector<Cell *> matrixCells;
    sf::Vector2u windowSize;

    /*Private Functions*/
    /**
     * Inicia o mundo. Todas as células da matriz serão vazias inicialmente
     */
    void initWorld() const;

    /**
     * Coloca os humanos em células aleatórias da matriz
     */
    void placeHumans() const;

    /**
     * Coloca os zombies em células aleatórias da matriz
     */
    void placeZombies() const;

    /**
     * Inicia a quantidade de zombies e humanos no mundo
     */
    void initVariables(int matrixRow, int matrixColl);
    void initVariables(int matrixOrder);

    /**
     * Verifica se uma célula não possui entidade alocada
     * @param index indice da matriz
     * @return true caso não tenha entidade alocada, false caso contrário
     */
    static bool isEmptyPlace(int index) ;

    /*Private variables*/
    int numHumans; /*Número de humanos no mundo*/
    int numZombies; /*Número de zombies no mundo*/
    int it; /*Iterator de cada célula. Essa variável só é utilizada para propósitos de depuração*/
    bool flipGeneration = false;

    /**
     * Função responsável por detectar as entidades ao redor de uma determinada célula
     * @param index índice da célula que se quer saber quais entidades estão ao redor
     * @return vetor de entidades ao redor da célula na seguinte sequencia:
     * {top, bottom, left, right, topLeft, topRight, bottomLeft, bottomRight}
     * Cada posição possui uma célula ou nullptr caso não haja vizinho nessa posição
     */
    static std::vector<Cell *> getNeighborhood(int index);

    /**
     * Função responsável por detectar as entidades ao redor de uma determinada célula
     * @param row linha da célula que se quer saber quais entidades estão ao redor
     * @param col coluna da célula que se quer saber quais entidades estão ao redor
     * @return vetor de entidades ao redor da célula na seguinte sequencia:
     * {top, bottom, left, right, topLeft, topRight, bottomLeft, bottomRight}
     * Cada posição possui uma célula ou nullptr caso não haja vizinho nessa posição
     */
    static std::vector<Cell *> getNeighborhood(int row, int col);
public:
    World();

    explicit World(int matrixOrder, sf::Vector2u windowSize);

    World(int row, int coll, sf::Vector2u windowSize);

    virtual ~World();

    void update();

    void render(sf::RenderTarget &target);

    /**
     * Função responsável por detectar as entidades ao redor de uma determinada célula
     * @param cell célula que se quer saber quais entidades estão ao redor
     * @return vetor de entidades ao redor da célula na seguinte sequencia:
     * {top, bottom, left, right, topLeft, topRight, bottomLeft, bottomRight}
     * Cada posição possui uma célula ou nullptr caso não haja vizinho nessa posição
     */
    static std::vector<Cell *> getNeighborhood(Cell &cell);

};


#endif //MPI_ZOMBIE_APOCALYPSE_WORLD_H
