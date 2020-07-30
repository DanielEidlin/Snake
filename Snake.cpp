//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"

Snake::Snake() : length(0), body('$'), direction(Direction::None), HORIZONTAL_SPEED(250), VERTICAL_SPEED(450) {}

Snake::Snake(std::pair<int, int> spawnCoordinates) : length(1), body('$'), direction(Direction::None),
                                                     HORIZONTAL_SPEED(250), VERTICAL_SPEED(450) {
    snakeCoordinates.insert(snakeCoordinates.begin(), spawnCoordinates);
}

Snake::~Snake() {}

std::pair<int, int> Snake::getHeadCoordinates() const {
    return snakeCoordinates.back();
}

std::vector<std::pair<int, int>> Snake::getSnakeCoordinates() const {
    return snakeCoordinates;
}

void Snake::move() {
    std::pair<int, int> headCoordinates = getHeadCoordinates();

    switch (direction) {
        case Direction::Right:
            // move right
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first + 1, headCoordinates.second));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Left:
            // move left
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Up:
            // move up
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Down:
            // move down
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1));
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        default:
            // do nothing
            break;

    }
}

Direction Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(Direction newDirection) {
    direction = newDirection;
}

int Snake::getSpeed(Direction direction) const {
    if (direction == Direction::Right || direction == Direction::Left) {
        return HORIZONTAL_SPEED;
    } else {
        return VERTICAL_SPEED;
    }
}