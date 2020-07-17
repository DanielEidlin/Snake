//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H


class Board {

private:
    int height;
    int width;
    char border_sign;

public:
    Board(int height, int width, char border_sign = '*');

    ~Board();

    void draw();

};


#endif //SNAKE_BOARD_H
