#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Snake.h"

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(11, 25);
    while (true) {  // game loop
        board.getSnake().move();
        board.draw();
        board.getInput();
    }

    return 0;
}
