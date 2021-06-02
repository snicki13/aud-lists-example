//
// Created by Dominik Kröll on 02.06.21.
//

#ifndef AUD_LISTEN_LINKEDLIST_H
#define AUD_LISTEN_LINKEDLIST_H

/**
 * Typ eines Listenelements mit int als Wert und Zeigern auf weitere Elemente.
 */
typedef struct ListElement {
    int value;
    struct ListElement *prev;
    struct ListElement *next;
} ListElement;

/**
 * Typ einer LinkedList mit size = anzahl Elemente und Zeigern auf first und last.
 */
typedef struct LinkedList {
    int size;
    struct ListElement *first;
    struct ListElement *last;
} LinkedList;

void printList(LinkedList *list);

void addElement(LinkedList* list, int value);

void addFirstElement(LinkedList* list, int value);

LinkedList newList();

void printLinkedList(LinkedList* list);

#endif //AUD_LISTEN_LINKEDLIST_H
