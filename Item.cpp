//
// Created by Daniel Eidlin on 05/08/2020.
//

#include <cstdlib>
#include "Item.h"

Item::Item() {}

Item::Item(std::pair<int, int> spawnCoordinates, char itemChar) : coordinates(spawnCoordinates),
                                                                     previousCoordinates(spawnCoordinates),
                                                                     itemChar(itemChar) {}

Item::~Item() {}

std::pair<int, int> Item::getCoordinates() const {
    return coordinates;
}

void Item::setCoordinates(std::pair<int, int> newCoordinates) {
    coordinates = newCoordinates;
}

char Item::getItemChar() const {
    return itemChar;
}

void Item::setItemChar(char newItemChar) {
    itemChar = newItemChar;
}

std::pair<int, int> Item::getPreviousCoordinates() const {
    return previousCoordinates;
}

void Item::setPreviousCoordinates(std::pair<int, int> newCoordinates) {
    previousCoordinates = newCoordinates;
}

void Item::spawn(int width, int height) {
    int randomXCoordinate = 1 + (rand() % (width - 2));  // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % (height - 2));  // Random y coordinate in the board's range
    std::pair<int, int> spawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    previousCoordinates = coordinates;
    coordinates = spawnCoordinates;
}
