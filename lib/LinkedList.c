#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/**
 * Erzeugt eine neue Liste ohne Werte
 * @return die neue Liste
 */
LinkedList newList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return *list;
}

/**
 * Erzeugt ein neues Listenelement mit gegebenem Wert und initialisiert die Pointer mit NULL
 * @param value der Wert
 * @return das Listenelement
 */
ListElement* newListElement(int value) {
    // malloc = reserviere Speicherplatz
    // Das * am Typen sagt, dass hier ein Zeiger auf ein ListElement gespeichert wird.
    ListElement* listElement = malloc(sizeof(ListElement));
    // -> : Dereferenzierungsoperator. Äquivalent zu object(listElement).value im Pseudocode
    // Alternativ: *listElement.value
    listElement->value = value;
    listElement->next = NULL;
    listElement->prev = NULL;
    return listElement;
}

/**
 * Erzeugt ein neues Element mit dem gegeben Wert und haengt es hinten an die Liste an.
 * @param list die Liste
 * @param value der Wert
 */
void addElement(LinkedList* list, int value) {
    ListElement* listElement = newListElement(value);
    if (list->size > 0) { // Hat die Liste schon Elemente?
        listElement->prev = list->last; // Letztes Element der Liste ist Vorgänger des neuen Elements.
        list->last->next = listElement; // Nachfolger des bisher letzten Elements ist das neue Element.
        list->last = listElement;       // Das neue Element ist das neue letzte der Liste.
    } else {
        // Neues Element ist first und last.
        list->first = listElement;
        list->last = listElement;
    }
    list->size += 1;
}

/**
 * Erzeugt ein neues Element mit dem gegeben Wert und haengt es vorne an die Liste an.
 * @param list die Liste
 * @param value der Wert
 */
void addFirstElement(LinkedList* list, int value) {
    ListElement* listElement = newListElement(value);
    if (list->size > 0) { // Hat die Liste schon Elemente?
        listElement->next = list->first; // Erstes Element der Liste ist Nachfolger des neuen Elements.
        list->first->prev = listElement; // Vorgänger des bisher ersten Elements ist das neue Element.
        list->first = listElement;       // Das neue Element ist das neue erste der Liste.
    } else {
        // Neues Element ist first und last.
        list->first = listElement;
        list->last = listElement;
    }
    list->size += 1;
}

/**
 * Prints a LinkedList to stdout
 * @param list LinkedList
 */
void printList(LinkedList *list) {
    ListElement* next = list->first;
    printf("[");
    while (next != NULL) {
        printf("%3d", next->value);
        if (next->next != NULL) { // Kein baumelndes Komma :)
            printf(", ");
        }
        next = next->next;
    }
    printf("]\n");
}

void printLinkedList(LinkedList* list) {
    ListElement* it = list->first;
    while (it != NULL) {
        printf("%16s————————————————————————————————————————————————————————————\n", "");
        printf("%14p: | value: %3d | ", it, it->value);
        if (it->next == NULL) {
            printf("\033[0;31mnext: %14p\033[0m | ", it->next);
        } else {
            printf("next: %14p | ", it->next);
        }
        if (it->prev == NULL) {
            printf("\033[0;31mprev: %14p\033[0m |\n", it->prev);
        } else {
            printf("prev: %14p |\n", it->prev);
        }
        printf("%16s————————————————————————————————————————————————————————————\n", "");
        if (it->next != NULL) {
            printf("                                 ↓                      ↑\n");
        }
        printf("\n");
        it = it->next;
    }
}
