#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Snake.h"

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(25, 25);
    int randomXCoordinate = 1 + (rand() % board.getWidth());    // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % board.getHeight());   // Random y coordinate in the board's range
    std::pair<int, int> spawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    Snake snake = Snake(spawnCoordinates);

    while (true) {
        board.getInput();
        board.draw();
    }

    return 0;
}
