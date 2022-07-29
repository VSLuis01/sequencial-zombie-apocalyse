//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_HUMAN_H
#define MPI_ZOMBIE_APOCALYPSE_HUMAN_H

#include "Entity.h"
#include "Cell.h"

/**
 * Classe que representa uma entidade HUMANO
 */
class Human : public Entity {
public:
    Human();

    Human(int reproductionAge, int longevity);

    explicit Human(int longevity);

    virtual ~Human();

    /**
     * Verifica se o humano morreu de acordo com suas regras
     * @param entitiesAround entidades ao redor do humano
     * @return true caso humano morreu, false caso contrário
     */
    bool isDead(const std::vector<Cell *> &cellsAround) override;

    /**
     * Função de movimentação do humano
     * @param cellsAround possíveis células para se movimento
     * @return Um ponteiro para uma célula que vai se movimentar ou nullptr caso não há movimento
     */
    Cell *move(const std::vector<Cell *> &cellsAround) override;


    Cell *possibleReproducer(std::vector<Cell *> cellsAround) override;

    bool reproduceRule(const std::vector<Cell *> &cellsAround) override;

    /**
     * Cópia da célula humano, porém com outro endereço de memória
     * @return cópia da entidade
     */
    Entity *copy() override;

    /**
     * Cópia da célula humano, todavia a idade das entidades é resetada para 0.
     * @return cópia da entidade
     */
    Entity *reproduce() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_HUMAN_H
