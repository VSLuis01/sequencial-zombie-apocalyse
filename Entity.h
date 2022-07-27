//
// Created by luise on 23/07/22.
//

#ifndef MPI_ZOMBIE_APOCALYPSE_ENTITY_H
#define MPI_ZOMBIE_APOCALYPSE_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

enum Type {
    HumanEntity = 1, ZombieEntity = -1
};

class Cell;

/**
 * Está classe representa uma entidade.
 * Entity é uma classe abstrata e outras entidades precisam implementar suas funcionalidades
 *
 */
class Entity {
protected:
    int longevity; /*Gerações que uma entidade vive*/
    int age = 0; /*Idade da entidade*/
    int reproductionAge; /*Idade que uma entidade pode reproduzir*/

    Type entityType; /*Tipo da entidade: 1 -> Human, -1 -> Zombie*/

public:
    sf::RectangleShape shape; /*Retangulo que aparece no centro de cada célula. Esse atributo só possui propósitos de depuração*/

    int getBirth() const;

    int getLongevity() const;

    int getAge() const;

    /**
     * Retorna o tipo da entidade
     * @return Tipo da entidade HumanType=1, ZombieType=-1
     */
    Type getEntityType() const;

    /**
     * Retorna se a entidade pode reproduzir
     * @return true caso esteja na idade de reprodução, false caso contrário
     */
    bool canReproduce() const;

    Entity();

    Entity(int reproductionAge, int longevity);

    Entity(int longevity);

    virtual ~Entity();

    /**
     * Retorna uma cópia da entidade. Porém em outro endereço de memória
     * @return Cópia da entidade
     */
    virtual Entity *copy() = 0;

    virtual Cell* reproduce(std::vector<Cell *> cellsAround) = 0;

    /**
     * Retorna uma cópia da entidade, todavia a idade de ambas Entidades é resetada para 0;
     * @return Cópia da entidade
     */
    virtual Entity* reproduce() = 0;

    /**
     * Verifica se a entidade morreu.
     * @param entitiesAround Entidades ao redor da corrente entidade
     * @return true caso a entidade morreu, false caso contrário
     */
    virtual bool isDead(sf::Vector2i entitiesAround) = 0;

    /**
     * Função responsável para verificar se uma célula pode se movimentar
     * @param cellsAround Células ao redor da entidade
     * @return Célula que a entidade vai se movimentar ou nullptr caso não há movimento.
     */
    virtual Cell *move(std::vector<Cell *> cellsAround) = 0;
};


#endif //MPI_ZOMBIE_APOCALYPSE_ENTITY_H
