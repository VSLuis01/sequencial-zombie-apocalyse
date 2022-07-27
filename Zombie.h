//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
#define MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H

#include "Entity.h"
#include "Cell.h"

/**
 * Classe que representa uma entidade zombie
 */
class Zombie : public Entity {
private:
    int energy = 5;
public:
    Zombie();

    Zombie(int reproductionAge, int longevity);

    explicit Zombie(int longevity);

    virtual ~Zombie();

    /**
     * Verifica se o zombie morreu de acordo com suas regras
     * @param entitiesAround entidades ao redor do zombie
     * @return true caso zombie morreu, false caso contrário
     */
    bool isDead(sf::Vector2i entitiesAround) override;

    /**
     * Função de movimentação do zombie
     * @param cellsAround possíveis células para se movimento
     * @return Um ponteiro para uma célula que vai se movimentar ou nullptr caso não há movimento
     */
    Cell *move(std::vector<Cell *> cellsAround) override;

    Cell *reproduce(std::vector<Cell *> cellsAround) override;

    /**
     * Cópia da célula zombie, todavia a idade das entidades é resetada para 0.
     * @return cópia da entidade
     */
    Entity *reproduce() override;

    /**
     * Cópia da célula zombie, porém com outro endereço de memória
     * @return cópia da entidade
     */
    Entity *copy() override;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ZOMBIE_H
