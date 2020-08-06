//
// Created by Daniel Eidlin on 05/08/2020.
//

#ifndef SNAKE_ITEM_H
#define SNAKE_ITEM_H
#include <utility>


class Item {
protected:
    std::pair<int, int> coordinates;
    std::pair<int, int> previousCoordinates;
    char itemChar;

public:
    Item();

    Item(std::pair<int, int> spawnCoordinates, char itemChar);

    ~Item();

    std::pair<int, int> getCoordinates() const;

    void setCoordinates(std::pair<int, int> newCoordinates);

    char getItemChar() const;

    void setItemChar(char newItemChar);

    std::pair<int, int> getPreviousCoordinates() const;

    void setPreviousCoordinates(std::pair<int, int> newCoordinates);

    void spawn(int width, int height);

};


#endif //SNAKE_ITEM_H
