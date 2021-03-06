//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"

const int Board::SNAKE_PAIR = 1;
const int Board::APPLE_PAIR = 2;

Board::Board(int height, int width, char border_sign) : height(height), width(width), border_sign(border_sign),
                                                        score(0), playAppleSound(false), playDioSound(false),
                                                        dioEffect(false) {
    initializeSnake();
    initializeApple();
    initializeDioItem();
    initializeWindows();
    initializeColors();
}

Board::~Board() {}

std::pair<int, int> Board::generateRandomCoordinates() const {
    srand((unsigned) time(0));
    int randomXCoordinate = 1 + (rand() % (this->width - 2));    // Random x coordinate in the board's range
    int randomYCoordinate = 1 + (rand() % (this->height - 2));   // Random y coordinate in the board's range
    std::pair<int, int> randomCoordinates = std::pair<int, int>(randomXCoordinate, randomYCoordinate);
    return randomCoordinates;
}

void Board::initializeSnake() {
    // Initialize Snake
    int xCoordinate = this->width / 2;
    int yCoordinate = this->height / 2;
    std::pair<int, int> snakeSpawnCoordinates = std::pair<int, int>(xCoordinate, yCoordinate);
    snake = Snake(3, snakeSpawnCoordinates);
}

void Board::initializeApple() {
    // Initialize Apple
    std::pair<int, int> appleSpawnCoordinates = generateRandomCoordinates();
    apple = Item(appleSpawnCoordinates, '@');
}

void Board::initializeDioItem() {
    // Initialize Dio item
    std::pair<int, int> dioSpawnCoordinates = generateRandomCoordinates();
    dioItem = DioItem(dioSpawnCoordinates, '?');
}

void Board::initializeWindows() {
    // Initialize windows
    initscr();  // ncurses initializer
    curs_set(0);    // hide cursor
    noecho();   // disable echo
    cbreak();   // read one char at a time
    fieldWin = newwin(this->height, this->width, 1, 0);  // create new window
    nodelay(fieldWin, TRUE); // make wgetch non-blocking
    keypad(fieldWin, TRUE);  // allow input of special keys
    box(fieldWin, 0, 0); // create border
    scoreWin = newwin(1, this->width, 0, 0);    // create score window
}

void Board::initializeColors() const {
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }

    // Initialize colors
    start_color();
    init_pair(SNAKE_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(APPLE_PAIR, COLOR_RED, COLOR_BLACK);
}

void Board::eraseLastDrawings() const {
    // Erase previous drawings of the snake and/or the apple and Dio item
    std::pair<int, int> previousTailCoordinates = snake.getPreviousTailCoordinates();
    mvwaddch(fieldWin, previousTailCoordinates.second, previousTailCoordinates.first, ' ');
    std::pair<int, int> previousAppleCoordinates = apple.getPreviousCoordinates();
    mvwaddch(fieldWin, previousAppleCoordinates.second, previousAppleCoordinates.first, ' ');
    std::pair<int, int> previousDioCoordinates = dioItem.getPreviousCoordinates();
    mvwaddch(fieldWin, previousDioCoordinates.second, previousDioCoordinates.first, ' ');
}

void Board::drawSnakeBody() const {
    // Draw snake body parts
    std::vector<BodyPart> snakeBodyParts = snake.getBodyParts();
    wattron(fieldWin, COLOR_PAIR(SNAKE_PAIR));
    for (int i = 0; i < snakeBodyParts.size() - 1; i++) {
        BodyPart currentBodyPart = snakeBodyParts[i];
        std::pair<int, int> bodyPartCoordinates = currentBodyPart.getCoordinates();
        char bodyPartSymbol = BodyPart::directionSymbols[currentBodyPart.getDirection()];
        mvwaddch(fieldWin, bodyPartCoordinates.second, bodyPartCoordinates.first, bodyPartSymbol);
    }
    wattroff(fieldWin, COLOR_PAIR(SNAKE_PAIR));
}

void Board::drawSnakeHead() const {
    // Draw snake head part
    wattron(fieldWin, COLOR_PAIR(SNAKE_PAIR));
    BodyPart headPart = snake.getHeadPart();
    std::pair<int, int> headPartCoordinates = headPart.getCoordinates();
    char headPartSymbol = BodyPart::directionSymbols[headPart.getDirection()];
    mvwaddch(fieldWin, headPartCoordinates.second, headPartCoordinates.first, headPartSymbol);
    wattroff(fieldWin, COLOR_PAIR(SNAKE_PAIR));
}

void Board::drawApple() const {
    // draw apple
    std::pair<int, int> appleCoordinates = apple.getCoordinates();
    wattron(fieldWin, COLOR_PAIR(APPLE_PAIR));
    mvwaddch(fieldWin, appleCoordinates.second, appleCoordinates.first, apple.getItemChar());
    wattroff(fieldWin, COLOR_PAIR(APPLE_PAIR));
}

void Board::drawDioItem() const {
    if (dioItem.isActive()) {
        // draw Dio item if active
        std::pair<int, int> dioCoordinates = dioItem.getCoordinates();
        mvwaddch(fieldWin, dioCoordinates.second, dioCoordinates.first, dioItem.getItemChar());
    }
}

void Board::playSounds() {
    if (playAppleSound) {
        appleSoundController.playSound();   // play apple sound if needed
        playAppleSound = false;
    }
    if (playDioSound) {
        dioSoundController.playSound();   // play Dio sound if needed
        playDioSound = false;
    }
}

void Board::draw() {
    eraseLastDrawings();
    drawSnakeBody();
    drawSnakeHead();
    drawApple();
    drawDioItem();
    wrefresh(fieldWin);  // refresh field window
    playSounds();
    mvwprintw(scoreWin, 0, 0, "Score: %d", score);  // print score
    wrefresh(scoreWin); // refresh score window
}

void Board::getInput() {
    int ch = wgetch(fieldWin);

    switch (ch) {
        case KEY_RIGHT:
            if (snake.getHeadPart().getDirection() != Direction::Left) {
                // move right
                snake.setCanMove(true);
                snake.changeHeadDirection(Direction::Right);
            }
            break;
        case KEY_LEFT:
            if (snake.getHeadPart().getDirection() != Direction::Right) {
                // move left
                snake.setCanMove(true);
                snake.changeHeadDirection(Direction::Left);
            }
            break;
        case KEY_UP:
            if (snake.getHeadPart().getDirection() != Direction::Down) {
                // move up
                snake.setCanMove(true);
                snake.changeHeadDirection(Direction::Up);
            }
            break;
        case KEY_DOWN:
            if (snake.getHeadPart().getDirection() != Direction::Up) {
                // move down
                snake.setCanMove(true);
                snake.changeHeadDirection(Direction::Down);
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

void Board::checkAppleEngage() {
    std::pair<int, int> headCoordinates = snake.getHeadPart().getCoordinates();
    std::pair<int, int> appleCoordinates = apple.getCoordinates();
    if (headCoordinates == appleCoordinates) {
        snake.setApple(true);
        playAppleSound = true;
        score++;
        apple.spawn(width, height);
    }
}

void Board::endGame() {
    endwin();   // ncurses reset function
}

void Board::activateDioItem() {
    if (!dioItem.isActive() && !dioItem.getCounter()) {
        dioEffect = false;
        int activationCondition = (int) (rand() % 400);
        if (activationCondition == 0) {
            dioItem.setActive(true);
        }
    } else if (!dioItem.isActive() && dioItem.getCounter()) {
        int dioCounter = dioItem.getCounter();
        dioItem.setCounter(dioCounter - 1);
    }
}

void Board::checkDioEngage() {
    if (dioItem.isActive()) {
        std::pair<int, int> headCoordinates = snake.getHeadPart().getCoordinates();
        std::pair<int, int> dioCoordinates = dioItem.getCoordinates();
        if (headCoordinates == dioCoordinates) {
            playDioSound = true;
            dioItem.spawn(width, height);
            dioItem.setActive(false);
            dioEffect = true;
            dioItem.setCounter(17);
        }
    }
}

bool Board::isDioEffect() const {
    return dioEffect;
}
