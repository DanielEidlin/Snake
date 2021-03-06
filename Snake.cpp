//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Snake.h"
#include "BodyPart.h"

Snake::Snake() : length(0), movable(false), apple(false) {}

Snake::Snake(int length, std::pair<int, int> spawnCoordinates) : length(length), movable(false),
                                                                 previousTailCoordinates(spawnCoordinates),
                                                                 apple(false) {
    for (int i = 0; i < this->length - 1; i++) {
        BodyPart bodyPart = BodyPart(std::pair<int, int>(spawnCoordinates.first + i, spawnCoordinates.second),
                                     Direction::Right);
        bodyParts.push_back(bodyPart);
    }
    BodyPart bodyPart = BodyPart(
            std::pair<int, int>(spawnCoordinates.first + this->length - 1, spawnCoordinates.second), Direction::Right);
    bodyParts.push_back(bodyPart);
}

Snake::~Snake() = default;

BodyPart Snake::getHeadPart() const {
    return bodyParts.back();
}

std::vector<BodyPart> Snake::getBodyParts() const {
    return bodyParts;
}

void Snake::move() {
    std::pair<int, int> headCoordinates = getHeadPart().getCoordinates();
    Direction headDirection = getHeadPart().getDirection();

    switch (headDirection) {
        case Direction::Right:
            // move right
            bodyParts.push_back(
                    BodyPart(std::pair<int, int>(headCoordinates.first + 1, headCoordinates.second), Direction::Right));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Left:
            // move left
            bodyParts.push_back(
                    BodyPart(std::pair<int, int>(headCoordinates.first - 1, headCoordinates.second), Direction::Left));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Up:
            // move up
            bodyParts.push_back(
                    BodyPart(std::pair<int, int>(headCoordinates.first, headCoordinates.second - 1), Direction::Up));
            if (!hasApple()) {
                previousTailCoordinates = bodyParts.front().getCoordinates();
                bodyParts.erase(bodyParts.begin());
            }
            setApple(false);
            break;
        case Direction::Down:
            // move down
            bodyParts.push_back(
                    BodyPart(std::pair<int, int>(headCoordinates.first, headCoordinates.second + 1), Direction::Down));
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

std::pair<int, int> Snake::getPreviousTailCoordinates() const {
    return previousTailCoordinates;
}

bool Snake::CanMove() const {
    return movable;
}

void Snake::setCanMove(bool canMove) {
    movable = canMove;
}

bool Snake::hasApple() const {
    return apple;
}

void Snake::setApple(bool hasApple) {
    apple = hasApple;
}

void Snake::changeHeadDirection(Direction newDirection) {
    bodyParts.back().setDirection(newDirection);
}