//
// Created by Dominik Kröll on 07.06.21.
//

#include <printf.h>
#include <stdlib.h>
#include "lib/LinkedList.h"

void delete(LinkedList* list, ListElement* it) {
    if (list->size == 1) {
        free(it);
        list->first = NULL;
        list->last = NULL;
    } else if (it->next == NULL) {
        // ODER: it == list.last
        it->prev->next = NULL;
        list->last = it->prev;
        free(it);
    } else if (it->prev == NULL) {
        it->next->prev = NULL;
        list->first = it->next;
        free(it);
    } else {
        ListElement* p1 = it->next;
        ListElement* p2 = it->prev;
        it->prev->next = p1;
        it->next->prev = p2;
        free(it);
    }
    list->size -= 1;
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

    printf("Pre delete: \n");
    printLinkedList(&list);

    delete(&list, list.first);
    delete(&list, list.first);
    delete(&list, list.first);

    printf("Post delete: \n");
    printLinkedList(&list);

    return 0;
}