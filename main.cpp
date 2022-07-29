#include <csignal>
#include "Apocalypse.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Apocalypse game(10, 10);

    while (game.isRunning()) {
        game.update();
        game.render();
//        sleep(1);
    }

    return 0;
}