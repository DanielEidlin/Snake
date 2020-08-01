//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"
#include "BodyPart.h"

Snake::Snake() : length(0), body('$'), direction(Direction::None), movable(false), apple(false) {}

Snake::Snake(int length, std::pair<int, int> spawnCoordinates) : length(length), body('$'), direction(Direction::Right),
                                                                 movable(false),
                                                                 previousTailCoordinates(spawnCoordinates),
                                                                 apple(false) {
    for (int i = 0; i < this->length; i++) {
        BodyPart bodyPart = BodyPart(std::pair<int, int>(spawnCoordinates.first + i, spawnCoordinates.second));
        bodyParts.push_back(bodyPart);
    }
}

Snake::~Snake() {}

BodyPart Snake::getHeadPart() const {
    return bodyParts.back();
}

std::vector<BodyPart> Snake::getBodyParts() const {
    return bodyParts;
}

void Snake::move() {
    std::pair<int, int> headCoordinates = getHeadPart().getCoordinates();

    switch (direction) {
        case Direction::Right:
            // move right
            bodyParts.push_back(std::pair<int, int>(headCoordinates.first + 1, headCoordinates.second));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Left:
            // move left
            bodyParts.push_back(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Up:
            // move up
            bodyParts.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Down:
            // move down
            bodyParts.push_back(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
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