//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"
#include <iostream>

Snake::Snake(std::pair<int, int> spawnCoordinates) : length(1), body('$'), headCoordinates(spawnCoordinates) {}

Snake::~Snake() {
    std::cout << "Deconstructing Snake" << std::endl;
}

std::pair<int, int> Snake::getHeadCoordinates() {
    return headCoordinates;
}

void Snake::setHeadCoordinates(std::pair<int, int> newCoordinates) {
    headCoordinates = newCoordinates;
}