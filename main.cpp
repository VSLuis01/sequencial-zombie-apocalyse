#include "Apocalypse.h"
#include <unistd.h>

int main() {
    std::srand(static_cast<unsigned>(time(nullptr)));
    Apocalypse game;

    while(game.isRunning()) {
        game.update();
        game.render();
        sleep(1);
    }

    return 0;
}