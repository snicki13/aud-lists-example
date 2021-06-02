//
// Created by Dominik Kröll on 02.06.21.
//

#include "lib/ArrayList.h"

/**
 * Entfernt das i-te Element aus einer ArrayList. Implementierung von Matthias G.
 * @param i
 */
void delete(ArrayList* a, int i) {
    a->size = a->size - 1;
    for(int j = i; j < a->size; j++) {
        a->data[j] = a->data[j+1];
    }
    // added by Dominik
    // a->data[a->size] = 0;
}

int main() {
    ArrayList a = newArrayList();
    // &list = Zeiger auf Liste.
    // Äquivalent zu address(list) im Pseudocode.
    pushBack(&a, 7);
    pushBack(&a, 23);
    printMemory(a.data, a.size, a.capacity);
    pushBack(&a, 42);
    pushBack(&a, 66);
//    pushBack(&a, 79);
//    pushBack(&a, 96);
//    pushBack(&a, 102);
//    pushBack(&a, 432);
//    pushBack(&a, 666);

    printMemory(a.data, a.size, a.capacity);

    delete(&a, 2);

    printMemory(a.data, a.size, a.capacity);

    return 0;
}