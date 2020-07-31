//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <curses.h>
#include "Snake.h"
#include "Apple.h"

class Board {

private:
    int height;
    int width;
    char border_sign;
    WINDOW* win;
    Snake snake;
    Apple apple;

public:
    Board(int height, int width, char border_sign = '*');

    ~Board();

    void draw() const ;

    int getHeight() const;

    int getWidth() const;

    void getInput();

    Snake& getSnake();

    bool snakeCollided() const;

};


#endif //SNAKE_BOARD_H
