//
// Created by Daniel Eidlin on 01/08/2020.
//

#include "BodyPart.h"

std::map<Direction, char> BodyPart::directionSymbols = {{Direction::Right, '>'},
                                                        {Direction::Left,  '<'},
                                                        {Direction::Up,    '^'},
                                                        {Direction::Down,  'v'}};

BodyPart::BodyPart(const std::pair<int, int> &coordinates) : coordinates(coordinates) {}

BodyPart::BodyPart(const std::pair<int, int> &coordinates, Direction direction) : coordinates(coordinates),
                                                                                  direction(direction) {}

BodyPart::~BodyPart() {}

std::pair<int, int> BodyPart::getCoordinates() const {
    return coordinates;
}

void BodyPart::setCoordinates(std::pair<int, int> newCoordinates) {
    coordinates = newCoordinates;
}

Direction BodyPart::getDirection() const {
    return direction;
}

void BodyPart::setDirection(Direction newDirection) {
    direction = newDirection;
}
