//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"
#include <curses.h>
#include <iostream>

Board::Board(int height, int width, char border_sign) : height(height), width(width), border_sign(border_sign) {
    srand((unsigned) time(0));  // reset seed
    int randomXCoordinate = 1 + (rand() % (this->width - 2));    // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % (this->height - 2));   // Random y coordinate in the board's range
    std::pair<int, int> spawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    snake = Snake(spawnCoordinates);
    initscr();  // ncurses initializer
    noecho();   // disable echo
    cbreak();   // read one char at a time
    win = newwin(this->height, this->width, 0, 0);  // create new window
    keypad(win, TRUE);  // allow input of special keys
    box(win, 0, 0); // create border
}

Board::~Board() {
    endwin();   // ncurses reset function
}

void Board::draw() const {
    std::vector<std::pair<int, int>> snakeCoordinates = snake.getSnakeCoordinates();
    for (int i = 0; i < snakeCoordinates.size(); i++) {
        mvwaddch(win, snakeCoordinates[i].second, snakeCoordinates[i].first, '$');
    }
    wrefresh(win);  // refresh window
}

int Board::getHeight() const {
    return height;
}

int Board::getWidth() const {
    return width;
}

void Board::getInput() {
    int ch = wgetch(win);
    std::pair<int, int> snakeHeadCoordinates = snake.getHeadCoordinates();
    mvwaddch(win, snakeHeadCoordinates.second, snakeHeadCoordinates.first, ' ');

    switch (ch) {
        case KEY_RIGHT:
            // move right
            snake.move(0);
            break;
        case KEY_LEFT:
            // move left
            snake.move(1);
            break;
        case KEY_UP:
            // move up
            snake.move(2);
            break;
        case KEY_DOWN:
            // move down
            snake.move(3);
            break;
        default:
            // do nothing
            break;

    }
}