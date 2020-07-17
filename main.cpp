#include <iostream>
#include "Board.h"
#include <stdlib.h>

int main() {
    Board board = Board(20, 20);
    board.draw();
    int randomXCoordinate = 1 + (rand() % board.getWidth());    // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % board.getHeight());   // Random y coordinate in the board's range
    std::pair<int, int> spawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    return 0;
}
