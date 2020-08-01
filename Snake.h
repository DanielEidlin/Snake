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

    std::pair<int, int> getPreviousTailCoordinates() const;

    bool CanMove() const;

    void setCanMove(bool status);

    void grow();

    bool hasApple() const;

    void setApple(bool hasApple);

    void changeHeadDirection(Direction newDirection);

};


#endif //SNAKE_SNAKE_H
