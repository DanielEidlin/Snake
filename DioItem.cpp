//
// Created by Daniel Eidlin on 05/08/2020.
//

#include "DioItem.h"

DioItem::DioItem() {}

DioItem::DioItem(std::pair<int, int> spawnCoordinates, char itemChar) : Item(spawnCoordinates, itemChar), active(false),
                                                                        counter(0) {}

bool DioItem::isActive() const {
    return active;
}

void DioItem::setActive(bool active) {
    DioItem::active = active;
}

int DioItem::getCounter() const {
    return counter;
}

void DioItem::setCounter(int counter) {
    DioItem::counter = counter;
}
