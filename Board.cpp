//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"
#include <curses.h>

Board::Board(int height, int width, char border_sign) : height(height), width(width), border_sign(border_sign) {
    int xCoordinate = this->width / 2;
    int yCoordinate = this->height / 2;
    std::pair<int, int> spawnCoordinates = std::pair<int, int>(xCoordinate, yCoordinate);
    snake = Snake(3, spawnCoordinates);
    initscr();  // ncurses initializer
    curs_set(0);    // hide cursor
    noecho();   // disable echo
    cbreak();   // read one char at a time
    win = newwin(this->height, this->width, 0, 0);  // create new window
    nodelay(win, TRUE); // make wgetch non-blocking
    keypad(win, TRUE);  // allow input of special keys
    box(win, 0, 0); // create border
}

Board::~Board() {
    endwin();   // ncurses reset function
}

void Board::draw() const {
    std::vector<std::pair<int, int>> snakeCoordinates = snake.getSnakeCoordinates();
    std::pair<int, int> previousTailCoordinates = snake.getPreviousTailCoordinates();
    mvwaddch(win, previousTailCoordinates.second, previousTailCoordinates.first, ' ');

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

    switch (ch) {
        case KEY_RIGHT:
            if (snake.getDirection() != Direction::Left) {
                // move right
                snake.setCanMove(true);
                snake.setDirection(Direction::Right);
            }
            break;
        case KEY_LEFT:
            if (snake.getDirection() != Direction::Right) {
                // move left
                snake.setCanMove(true);
                snake.setDirection(Direction::Left);
            }
            break;
        case KEY_UP:
            if (snake.getDirection() != Direction::Down) {
                // move up
                snake.setCanMove(true);
                snake.setDirection(Direction::Up);
            }
            break;
        case KEY_DOWN:
            if (snake.getDirection() != Direction::Up) {
                // move down
                snake.setCanMove(true);
                snake.setDirection(Direction::Down);
            }
            break;
        default:
            // do nothing
            break;

    }
}

Snake &Board::getSnake() {
    return snake;
}

bool Board::snakeCollided() const {
    int xSnakeHeadCoordinates = snake.getHeadCoordinates().first;
    int ySnakeHeadCoordinates = snake.getHeadCoordinates().second;

    return xSnakeHeadCoordinates == 0 || xSnakeHeadCoordinates == width - 1 || ySnakeHeadCoordinates == 0 ||
           ySnakeHeadCoordinates == height - 1;
}