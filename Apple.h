//
// Created by Daniel Eidlin on 31/07/2020.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H


#include <utility>

class Apple {
private:
    std::pair<int, int> coordinates;
    std::pair<int, int> previousCoordinates;
    char appleChar;

public:
    Apple();

    Apple(std::pair<int, int> spawnCoordinates, char appleChar = '@');

    ~Apple();

    std::pair<int, int> getCoordinates() const;

    void setCoordinates(std::pair<int, int> newCoordinates);

    char getAppleChar() const;

    std::pair<int, int> getPreviousCoordinates() const;

    void setPreviousCoordinates(std::pair<int, int> newCoordinates);
};


#endif //SNAKE_APPLE_H
