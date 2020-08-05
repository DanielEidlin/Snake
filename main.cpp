#include <iostream>
#include "Board.h"
#include "Snake.h"
#include <unistd.h>
#include <unistd.h>

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(16, 35);
    Snake &snake = board.getSnake();
    while (true) {  // game loop
        board.getInput();
        if (snake.CanMove())
            snake.move();
        board.checkAppleEngage();   // check if the snake engaged the apple
        board.draw();   // draw the state of the game
        if (board.snakeCollided()) {
            usleep(300000); // delay for 300 ms to make snake collision detectable
            break;
        }
        usleep(110000); /* delay for 110 ms. if you wonder why 110 ms:
                        https://github.com/romanedgn/snake-game/blob/master/fSnakeGame.cpp */
    }

    board.endGame();

    std::cout << R"(
                 _______  _______  _______  _______
                (  ____ \(  ___  )(       )(  ____ \
                | (    \/| (   ) || () () || (    \/
                | |      | (___) || || || || (__
                | | ____ |  ___  || |(_)| ||  __)
                | | \_  )| (   ) || |   | || (
                | (___) || )   ( || )   ( || (____/\
                (_______)|/     \||/     \|(_______/

                 _______           _______  _______
                (  ___  )|\     /|(  ____ \(  ____ )
                | (   ) || )   ( || (    \/| (    )|
                | |   | || |   | || (__    | (____)|
                | |   | |( (   ) )|  __)   |     __)
                | |   | | \ \_/ / | (      | (\ (
                | (___) |  \   /  | (____/\| ) \ \__
                (_______)   \_/   (_______/|/   \__/

                )";
    std::cout << "Press the Enter key to exit..." << std::endl;
    getchar();

    return 0;
}
