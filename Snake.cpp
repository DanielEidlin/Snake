//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"
#include <iostream>

Snake::Snake() : length(0), body('$'){}

Snake::Snake(std::pair<int, int> spawnCoordinates) : length(1), body('$') {
    std::cout << spawnCoordinates.first << ", " << spawnCoordinates.second << std::endl;
    snakeCoordinates.insert(snakeCoordinates.begin(), spawnCoordinates);
}

Snake::~Snake() {}

std::pair<int, int> Snake::getHeadCoordinates() const {
    return snakeCoordinates.back();
}

std::vector<std::pair<int, int>> Snake::getSnakeCoordinates() const {
    return snakeCoordinates;
}

void Snake::move(int direction) {
    std::pair<int, int> headCoordinates = getHeadCoordinates();

    switch (direction) {
        case 0:
            // move right
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first + 1, headCoordinates.second));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case 1:
            // move left
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case 2:
            // move up
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case 3:
            // move down
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        default:
            // do nothing
            break;

    }
}