#ifndef CDLL_H
#define CDLL_H

#include <stddef.h>

typedef int Key;

typedef struct
{
  Key key; /* Key that maps the register */
}
Register;

typedef struct CircularDoublyLinkedList
{
  struct CircularDoublyLinkedList *prev;
  struct CircularDoublyLinkedList *next;
  Register data;
}
CircularDoublyLinkedList;

void cddl_init(CircularDoublyLinkedList* nil);
CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil, Key k);
CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil, Key k);
void cdll_delete(CircularDoublyLinkedList* to_remove);

#endif