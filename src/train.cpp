// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    Cage *first = nullptr;
    countOp = 0;
    FirstCount = 0;
    ThirdCount = 0;
    CountForCage = 0;
}
void Train::addCage(bool light) {
    Cage *item = new Cage;
    item->next = nullptr;
    item->prev = nullptr;
    item->light = light;
    if (first == nullptr) {
        first = item;
    } else {
        if (first->next == nullptr) {
            first->next = item;
            first->prev = item;
            item->prev = first;
            item->next = first;
        } else {
            Cage *temp = first;
            while (temp->next != first) {
                temp = temp->next;
            }
            temp->next = item;
            item->prev = temp;
            item->next = first;
            first->prev = item;
        }
    }
}
int Train::getLength() {
    Cage *item = first;
    if (item->light == false) {
        item->light = true;
    }
    int result = 0;
    while (1) {
        item = item->next;
        countOp += 1;
        FirstCount += 1;
        while (item->light != true) {
            item = item->next;
            countOp += 1;
            FirstCount += 1;
        }
        item->light = false;
        result = FirstCount;
        while (FirstCount != 0) {
            countOp += 1;
            FirstCount -= 1;
            item = item->prev;
        }
        if (item->light == false) {
            return result;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
