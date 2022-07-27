#include "Apocalypse.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Apocalypse game;

    while (game.isRunning()) {
        game.update();
        game.render();
    }

    return 0;
}