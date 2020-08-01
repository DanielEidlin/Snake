//
// Created by Daniel Eidlin on 01/08/2020.
//

#ifndef SNAKE_BODYPART_H
#define SNAKE_BODYPART_H


#include <utility>
#include "Direction.h"

class BodyPart {
private:
    std::pair<int, int> coordinates;
    char symbol;
    Direction direction;

public:
    BodyPart(const std::pair<int, int> &coordinates);

    BodyPart(const std::pair<int, int> &coordinates, char symbol, Direction direction);

    ~BodyPart();

    std::pair<int, int> getCoordinates() const;

    void setCoordinates(std::pair<int, int> newCoordinates);

    char getSymbol() const;

    void setSymbol(char newSymbol);

    Direction getDirection() const;

    void setDirection(Direction newDirection);

};


#endif //SNAKE_BODYPART_H
