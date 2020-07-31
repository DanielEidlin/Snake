//
// Created by Daniel Eidlin on 31/07/2020.
//

#include "Apple.h"

Apple::Apple() {}

Apple::Apple(std::pair<int, int> spawnCoordinates, char appleChar) : coordinates(spawnCoordinates),
                                                                     previousCoordinates(spawnCoordinates),
                                                                     appleChar(appleChar) {}

Apple::~Apple() {}

std::pair<int, int> Apple::getCoordinates() const {
    return coordinates;
}

void Apple::setCoordinates(std::pair<int, int> newCoordinates) {
    coordinates = newCoordinates;
}

char Apple::getAppleChar() const {
    return appleChar;
}

std::pair<int, int> Apple::getPreviousCoordinates() const {
    return previousCoordinates;
}

void Apple::setPreviousCoordinates(std::pair<int, int> newCoordinates) {
    previousCoordinates = newCoordinates;
}