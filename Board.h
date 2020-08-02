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
    WINDOW* fieldWin;
    WINDOW* scoreWin;
    Snake snake;
    Apple apple;
    int score;

public:
    Board(int height, int width, char border_sign = '*');

    ~Board();

    void draw() const ;

    int getHeight() const;

    int getWidth() const;

    void getInput();

    Snake& getSnake();

    bool snakeCollided() const;

    void spawnApple();

    void checkAppleEngage();

};


#endif //SNAKE_BOARD_H
