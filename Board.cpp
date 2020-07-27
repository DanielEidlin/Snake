//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"
#include <curses.h>

Board::Board(int height, int width, char border_sign) : height(height / 2 - 1), width(width), border_sign(border_sign) {
    initscr();  // ncurses initializer
    noecho();   // disable echo
    cbreak();   // read one char at a time
    keypad(win, TRUE);  // allow input of special keys
    win = newwin(this->height, this->width, 0, 0);  // create new window
    box(win, 0, 0); // create border
}

Board::~Board() {
    endwin();   // ncurses reset function
}

void Board::draw() const {
    wrefresh(win);  // refresh window
}

int Board::getHeight() const {
    return height;
}

int Board::getWidth() const {
    return width;
}

void Board::getInput() const {
    int ch = wgetch(win);

    switch (ch) {
        case KEY_RIGHT:
            // move right
            break;
        case KEY_LEFT:
            // move left
            break;
        case KEY_UP:
            // move up
            break;
        case KEY_DOWN:
            // move down
            break;
        default:
            // do nothing
            break;

    }
}