//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <curses.h>

class Board {

private:
    int height;
    int width;
    char border_sign;
    WINDOW* win;

public:
    Board(int height, int width, char border_sign = '*');

    ~Board();

    void draw() const ;

    int getHeight() const;

    int getWidth() const;

    void getInput() const;

};


#endif //SNAKE_BOARD_H
