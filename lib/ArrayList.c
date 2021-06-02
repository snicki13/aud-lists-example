//
// Created by Dominik Kröll on 02.06.21.
//

#include <stdlib.h>
#include <printf.h>
#include "ArrayList.h"

ArrayList newArrayList() {
    ArrayList* a = malloc(sizeof(ArrayList));
    a->size = 0;
    a->capacity = 2;
    a->data = calloc(a->capacity, sizeof(int));
    return *a;
}

int get(ArrayList* a, int i) {
    if (a->size < i) {
        return 0;
    } else {
        return a->data[i];
    }
}


int count(ArrayList* a) {
    return a->size;
}

void pushBack(ArrayList* a, int y) {
    if (a->capacity == a->size) {
        printf("pushBack! Old capacity: %d, new capacity: %d\n", a->capacity, a->capacity * 2);
        a->capacity = 2 * a->capacity;
        int* newarr = calloc(a->capacity, sizeof(int));
        for (int i = 0; i < a->size; i++) {
            newarr[i] = a->data[i];
        }
        //printf("a->data: \n");
        //printMemory(a->data, a->capacity / 2);
        //printf("Newarr: \n");
        //printMemory(newarr, a->capacity);
        free(a->data);
        a->data = newarr;
    }
    a->size += 1;
    a->data[a->size - 1] = y;
}

int popBack(ArrayList* a) {
    int y = a->data[a->size - 1];
    a->size = a->size - 1;
    return y;
}

void printArrayList(ArrayList* a) {
    printf("[");
    for (int i = 0; i < a->size; i++) {
        printf("%3d", a->data[i]);
        if (i+1 != a->size) { // Kein baumelndes Komma :)
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Prints the memory structure of the ArrayList.
 * @param a
 * @param capacity
 */
void printMemory(int* a, int size, int capacity) {
    for (int i = 0; i < capacity; i++) {
        printf("| %-2d", i);
    }
    printf("|\n");
    for (int i = 0; i < capacity; i++) {
        printf("|———");
    }
    printf("|\n");
    for (int i = 0; i < capacity; i++) {
        if(i >= size) {
            printf("|\033[0;31m%3d\033[0m", a[i]);
        } else {
            printf("|%3d", a[i]);
        }
    }
    printf("|\n\n");
}
