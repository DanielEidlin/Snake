//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"
#include <iostream>

Snake::Snake(std::pair<int, int> spawnCoordinates) : length(1), body('$') {
    snakeCoordinates.insert(snakeCoordinates.begin(), spawnCoordinates);  // Ask Bary if there is a better way to do it
}

Snake::~Snake() {}

std::pair<int, int> Snake::getHeadCoordinates() const {
    return snakeCoordinates.front();
}