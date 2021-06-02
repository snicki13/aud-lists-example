//
// Created by Dominik Kröll on 02.06.21.
//

#ifndef AUD_LISTEN_ARRAYLIST_H
#define AUD_LISTEN_ARRAYLIST_H

typedef struct ArrayList {
    int* data;
    int size;
    int capacity;
} ArrayList;

ArrayList newArrayList();

int get(ArrayList* a, int i);

int count(ArrayList* a);

void pushBack(ArrayList* a, int y);

int popBack(ArrayList* a);

void printArrayList(ArrayList* a);

void printMemory(int* a, int size, int capacity);

#endif //AUD_LISTEN_ARRAYLIST_H
