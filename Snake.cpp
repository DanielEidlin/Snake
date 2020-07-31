//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"

Snake::Snake() : length(0), body('$'), direction(Direction::None), movable(false), apple(false) {}

Snake::Snake(int length, std::pair<int, int> spawnCoordinates) : length(length), body('$'), direction(Direction::Right),
                                                                 movable(false),
                                                                 previousTailCoordinates(spawnCoordinates),
                                                                 apple(false) {
    for (int i = 0; i < this->length; i++) {
        snakeCoordinates.push_back(std::pair<int, int>(spawnCoordinates.first + i, spawnCoordinates.second));
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
            if (!hasApple()) {
                previousTailCoordinates = snakeCoordinates.front();
                snakeCoordinates.erase(snakeCoordinates.begin());
            }
            setApple(false);
            break;
        case Direction::Left:
            // move left
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second));
            if (!hasApple()) {
                previousTailCoordinates = snakeCoordinates.front();
                snakeCoordinates.erase(snakeCoordinates.begin());
            }
            setApple(false);
            break;
        case Direction::Up:
            // move up
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1));
            if (!hasApple()) {
                previousTailCoordinates = snakeCoordinates.front();
                snakeCoordinates.erase(snakeCoordinates.begin());
            }
            setApple(false);
            break;
        case Direction::Down:
            // move down
            snakeCoordinates.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1));
            if (!hasApple()) {
                previousTailCoordinates = snakeCoordinates.front();
                snakeCoordinates.erase(snakeCoordinates.begin());
            }
            setApple(false);
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

char Snake::getBodyChar() const {
    return body;
}

bool Snake::hasApple() const {
    return apple;
}

void Snake::setApple(bool hasApple) {
    apple = hasApple;
}