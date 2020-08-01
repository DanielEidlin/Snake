//
// Created by Daniel Eidlin on 01/08/2020.
//

#include "BodyPart.h"

BodyPart::BodyPart(const std::pair<int, int> &coordinates) : coordinates(coordinates) {}

BodyPart::BodyPart(const std::pair<int, int> &coordinates, char symbol, Direction direction) : coordinates(coordinates),
                                                                                               symbol(symbol),
                                                                                               direction(direction) {}

BodyPart::~BodyPart() {}

std::pair<int, int> BodyPart::getCoordinates() const {
    return coordinates;
}

void BodyPart::setCoordinates(std::pair<int, int> newCoordinates) {
    coordinates = newCoordinates;
}

char BodyPart::getSymbol() const {
    return symbol;
}

void BodyPart::setSymbol(char newSymbol) {
    symbol = newSymbol;
}

Direction BodyPart::getDirection() const {
    return direction;
}

void BodyPart::setDirection(Direction newDirection) {
    direction = newDirection;
}
