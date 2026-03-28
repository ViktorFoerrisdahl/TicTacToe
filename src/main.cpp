#include "game.h"

int main () {

    //construct game
    game tictactoe;

    //game loop
    while (tictactoe.getWindowStatus()) {
        //opdatering
        tictactoe.update();
        //render
        tictactoe.render();
    }

    return 0;
}