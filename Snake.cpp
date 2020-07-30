//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"

Snake::Snake() : length(0), body('$'), direction(Direction::None), movable(false) {}

Snake::Snake(int length, std::pair<int, int> spawnCoordinates) : length(length), body('$'), direction(Direction::None),
                                                                 movable(false),
                                                                 previousTailCoordinates(spawnCoordinates) {
    for (int i = 0; i < this->length; i++) {
        snakeCoordinates.insert(snakeCoordinates.begin(),
                                std::pair<int, int>(spawnCoordinates.first + i, spawnCoordinates.second));
    }
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
            previousTailCoordinates = snakeCoordinates.front();
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Left:
            // move left
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second));
            previousTailCoordinates = snakeCoordinates.front();
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Up:
            // move up
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1));
            previousTailCoordinates = snakeCoordinates.front();
            snakeCoordinates.erase(snakeCoordinates.begin());
            break;
        case Direction::Down:
            // move down
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1));
            previousTailCoordinates = snakeCoordinates.front();
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

std::pair<int, int> Snake::getPreviousTailCoordinates() const {
    return previousTailCoordinates;
}

bool Snake::CanMove() const {
    return movable;
}

void Snake::setCanMove(bool canMove) {
    movable = canMove;
}