//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <utility>


class Snake {
private:
    int length;
    char body;
    std::pair<int, int> headCoordinates;

public:
    Snake(std::pair<int, int> spawnCoordinates);

    ~Snake();

    std::pair<int, int> getHeadCoordinates() const;

    void setHeadCoordinates(std::pair<int, int> const& newCoordinates);

};


#endif //SNAKE_SNAKE_H
