//
// Created by Daniel Eidlin on 01/08/2020.
//

#ifndef SNAKE_BODYPART_H
#define SNAKE_BODYPART_H


#include <utility>
#include <map>
#include "Direction.h"

class BodyPart {
private:
    std::pair<int, int> coordinates;
    Direction direction;

public:
    static std::map<Direction, char> headDirectionSymbols;
    static std::map<Direction, char> bodyDirectionSymbols;

    BodyPart(const std::pair<int, int> &coordinates);

    BodyPart(const std::pair<int, int> &coordinates, Direction direction);

    ~BodyPart();

    std::pair<int, int> getCoordinates() const;

    void setCoordinates(std::pair<int, int> newCoordinates);

    Direction getDirection() const;

    void setDirection(Direction newDirection);

};


#endif //SNAKE_BODYPART_H
