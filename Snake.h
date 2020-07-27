//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <utility>
#include <vector>


class Snake {
private:
    int length;
    char body;
    std::vector<std::pair<int, int>> snakeCoordinates;

public:
    Snake(std::pair<int, int> spawnCoordinates);

    ~Snake();

    std::pair<int, int> getHeadCoordinates() const;


};


#endif //SNAKE_SNAKE_H
