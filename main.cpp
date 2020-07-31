#include <iostream>
#include "Board.h"
#include "Snake.h"
#include <unistd.h>

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(11, 25);
    Snake& snake = board.getSnake();
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
    // board.lose();

    return 0;
}
