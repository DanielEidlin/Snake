//
// Created by Daniel Eidlin on 17/07/2020.
//

#include "Board.h"
#include <iostream>
#include <string>

Board::Board(int height, int width, char border_sign) : height(height / 2 - 1), width(width),
                                                        border_sign(border_sign) {}

Board::~Board() {
    std::cout << "Destructing Board" << std::endl;
}

void Board::draw() {
    std::cout << std::string(width, border_sign) << std::endl;
    for (int i = 0; i < height; i++) {
        std::cout << border_sign << std::string(width - 2, ' ') << border_sign << std::endl;
    }
    std::cout << std::string(width, border_sign) << std::endl;
}

int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
}