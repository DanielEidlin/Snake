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
    Snake();

    Snake(std::pair<int, int> spawnCoordinates);

    ~Snake();

    std::pair<int, int> getHeadCoordinates() const;

    std::vector<std::pair<int, int>> getSnakeCoordinates() const;

    void move(int direction);

};


#endif //SNAKE_SNAKE_H
