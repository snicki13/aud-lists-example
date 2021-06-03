//
// Created by Dominik Kröll on 02.06.21.
//

#include <math.h>
#include <printf.h>
#include "lib/LinkedList.h"

/**
 * Kehrt die Liste um. Algorithmus von Anne-Kristin W.
 * @param list die Liste
 */
void reverseListValue(LinkedList *list) {
    ListElement* f = list->first;
    ListElement* l = list->last;

    // (int) ceil(list->size / 2.0) => size / 2 aufgerundet
    for (int i = 1; i <= (int) ceil(list->size / 2.0); i++) {
        int swap = f->value;
        f->value = l->value;
        l->value = swap;
        l = l->prev;
        f = f->next;
    }
}

/**
 * Kehrt die Liste um. Algorithmus von Daniel G.
 * @param list
 */
void reverseListPointer(LinkedList* list) {
    ListElement* it = list->first;
    list->first = list->last;
    list->last = it;
    for (int i = 1; i <= list->size; i++) {
        ListElement* temp = it->next;
        it->next = it->prev;
        it->prev = temp;
        it = temp;
    }
}

void reverseRek(ListElement* elem) {
    ListElement* temp = elem->next;
    elem->next = elem->prev;
    elem->prev = temp;
    if (elem->prev == NULL) {
        return;
    } else {
        reverseRek(elem->prev);
    }
}

void reverseListRecursive(LinkedList* list) {
    reverseRek(list->first);
    ListElement* temp = list->first;
    list->first = list->last;
    list->last = temp;
}

int main() {
    LinkedList list = newList();
    // &list = Zeiger auf Liste.
    // Äquivalent zu address(list) im Pseudocode.
    addElement(&list, 7);
    addElement(&list, 23);
    addElement(&list, 42);
    //addElement(&list, 66);
    //addElement(&list, 79);
    //addElement(&list, 96);
    //addFirstElement(&list, 1);

    printf("Pre reverse: \n");
    printLinkedList(&list);
    reverseListRecursive(&list);
    //reverseListPointer(&list);
    //reverseListValue(&list);
    printf("Post reverse: \n");
    printLinkedList(&list);

    return 0;
}
