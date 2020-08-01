//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"
#include <curses.h>

Board::Board(int height, int width, char border_sign) : height(height), width(width), border_sign(border_sign) {
    // Initialize Snake ----------------------------------------------------------------------------------------
    int xCoordinate = this->width / 2;
    int yCoordinate = this->height / 2;
    std::pair<int, int> snakeSpawnCoordinates = std::pair<int, int>(xCoordinate, yCoordinate);
    snake = Snake(3, snakeSpawnCoordinates);
    // Initialize Apple ----------------------------------------------------------------------------------------
    srand((unsigned) time(0));
    int randomXCoordinate = 1 + (rand() % (this->width - 2));    // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % (this->height - 2));   // Random y coordinate in the board's range
    std::pair<int, int> appleSpawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    apple = Apple(appleSpawnCoordinates);
    // Initialize window ----------------------------------------------------------------------------------------
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
    std::vector<BodyPart> snakeBodyParts = snake.getBodyParts();
    std::pair<int, int> previousTailCoordinates = snake.getPreviousTailCoordinates();
    mvwaddch(win, previousTailCoordinates.second, previousTailCoordinates.first, ' ');
    std::pair<int, int> appleCoordinates = apple.getCoordinates();
    std::pair<int, int> previousAppleCoordinates = apple.getPreviousCoordinates();
    mvwaddch(win, previousAppleCoordinates.second, previousAppleCoordinates.first, ' ');

    for (int i = 0; i < snakeBodyParts.size(); i++) {
        std::pair<int, int> bodyPartCoordinates = snakeBodyParts[i].getCoordinates();
        mvwaddch(win, bodyPartCoordinates.second, bodyPartCoordinates.first, snake.getBodyChar());
    }

    mvwaddch(win, appleCoordinates.second, appleCoordinates.first, apple.getAppleChar());  // draw apple
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
    std::vector<BodyPart> bodyParts = snake.getBodyParts();
    std::pair<int, int> headCoordinates = snake.getHeadPart().getCoordinates();
    int xSnakeHeadCoordinates = headCoordinates.first;
    int ySnakeHeadCoordinates = headCoordinates.second;

    bool bodyCollision = false;
    bool borderCollision =
            xSnakeHeadCoordinates == 0 || xSnakeHeadCoordinates == width - 1 || ySnakeHeadCoordinates == 0 ||
            ySnakeHeadCoordinates == height - 1;

    for (int i = 0; i < bodyParts.size() - 1; i++) {
        std::pair<int, int> bodyPartCoordinates = bodyParts[i].getCoordinates();
        if (headCoordinates == bodyPartCoordinates) {
            bodyCollision = true;
            break;
        }
    }

    return bodyCollision || borderCollision;

}

void Board::spawnApple() {
    int randomXCoordinate = 1 + (rand() % (this->width - 2));  // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % (this->height - 2));  // Random y coordinate in the board's range
    std::pair<int, int> appleSpawnCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    apple.setPreviousCoordinates(apple.getCoordinates());
    apple.setCoordinates(appleSpawnCoordinates);
}

void Board::checkAppleEngage() {
    std::pair<int, int> headCoordinates = snake.getHeadPart().getCoordinates();
    std::pair<int, int> appleCoordinates = apple.getCoordinates();
    if (headCoordinates == appleCoordinates) {
        snake.setApple(true);
        spawnApple();
    }
}