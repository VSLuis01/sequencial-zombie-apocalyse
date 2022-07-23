#include "Apocalypse.h"

int main() {
    Apocalypse game;

    while(game.isRunning()) {
        game.update();
        game.render();
    }

    return 0;
}