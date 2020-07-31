//
// Created by Daniel Eidlin on 31/07/2020.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H


#include <utility>

class Apple {
private:
    std::pair<int, int> coordinates;
    char appleChar;

public:
    Apple();

    Apple(std::pair<int, int> spawnCoordinates, char appleChar = '@');

    ~Apple();

    std::pair<int, int> getCoordinates() const;

    void setCoordinates(std::pair<int, int> newCoordinates);

    char getAppleChar() const;
};


#endif //SNAKE_APPLE_H
