//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <utility>
#include <vector>
#include "Direction.h"


class Snake {
private:
    int length;
    char body;
    bool movable;
    Direction direction;
    std::vector<std::pair<int, int>> snakeCoordinates;
    std::pair<int, int> previousTailCoordinates;
    bool apple;

public:
    Snake();

    Snake(int length, std::pair<int, int> spawnCoordinates);

    ~Snake();

    std::pair<int, int> getHeadCoordinates() const;

    std::vector<std::pair<int, int>> getSnakeCoordinates() const;

    void move();

    Direction getDirection() const;

    void setDirection(Direction newDirection);

    std::pair<int, int> getPreviousTailCoordinates() const;

    bool CanMove() const;

    void setCanMove(bool status);

    char getBodyChar() const;

    void grow();

    bool hasApple() const;

    void setApple(bool hasApple);

};


#endif //SNAKE_SNAKE_H
