//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <utility>
#include <vector>
#include "Direction.h"
#include "BodyPart.h"


class Snake {
private:
    int length;
    bool movable;
    Direction direction;
    std::vector<BodyPart> bodyParts;
    std::pair<int, int> previousTailCoordinates;
    bool apple;

public:
    Snake();

    Snake(int length, std::pair<int, int> spawnCoordinates);

    ~Snake();

    BodyPart getHeadPart() const;

    std::vector<BodyPart> getBodyParts() const;

    void move();

    Direction getDirection() const;

    void setDirection(Direction newDirection);

    std::pair<int, int> getPreviousTailCoordinates() const;

    bool CanMove() const;

    void setCanMove(bool status);

    void grow();

    bool hasApple() const;

    void setApple(bool hasApple);

};


#endif //SNAKE_SNAKE_H
