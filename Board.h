//
// Created by Daniel Eidlin on 17/07/2020.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <curses.h>
#include "Snake.h"
#include "Item.h"
#include "SoundController.h"

class Board {

private:
    int height;
    int width;
    char border_sign;
    WINDOW* fieldWin;
    WINDOW* scoreWin;
    Snake snake;
    Item apple;
    Item dioItem;
    int score;
    static const int SNAKE_PAIR, APPLE_PAIR;
    SoundController appleSoundController = SoundController("../sound/apple.wav");
    SoundController dioSoundController = SoundController("../sound/dio.wav");
    bool playAppleSound;
    bool playDioSound;
    bool dioEffect;

public:

    Board(int height, int width, char border_sign = '*');

    ~Board();

    void draw();

    int getHeight() const;

    int getWidth() const;

    void getInput();

    Snake& getSnake();

    bool snakeCollided() const;

    void checkAppleEngage();

    void endGame();

    void spawnDioItem();

    void checkDioEngage();

};


#endif //SNAKE_BOARD_H
