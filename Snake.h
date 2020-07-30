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
    int HORIZONTAL_SPEED;
    int VERTICAL_SPEED;
    Direction direction;
    std::vector<std::pair<int, int>> snakeCoordinates;

public:
    Snake();

    Snake(std::pair<int, int> spawnCoordinates);

    ~Snake();

    std::pair<int, int> getHeadCoordinates() const;

    std::vector<std::pair<int, int>> getSnakeCoordinates() const;

    void move();

    Direction getDirection() const;

    void setDirection(Direction newDirection);

    int getSpeed(Direction direction) const;

};


#endif //SNAKE_SNAKE_H
