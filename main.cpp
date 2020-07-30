#include <iostream>
#include "Board.h"
#include "Snake.h"
#include <unistd.h>

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(11, 25);
    Snake& snake = board.getSnake();
    while (true) {  // game loop
        if (snake.CanMove())
            snake.move();
        board.draw();
        board.getInput();
        usleep(110000); /* delay for 110 ms. if you wonder why 110 ms:
                        https://github.com/romanedgn/snake-game/blob/master/fSnakeGame.cpp */
    }

    return 0;
}
