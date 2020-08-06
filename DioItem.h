//
// Created by Daniel Eidlin on 05/08/2020.
//

#ifndef SNAKE_DIOITEM_H
#define SNAKE_DIOITEM_H


#include "Item.h"

class DioItem : public Item {
private:
    bool active;
    int counter;

public:
    DioItem();

    DioItem(std::pair<int, int> spawnCoordinates, char itemChar);

    bool isActive() const;

    void setActive(bool active);

    int getCounter() const;

    void setCounter(int counter);

};


#endif //SNAKE_DIOITEM_H
