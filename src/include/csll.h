#ifndef CSLL_H
#define CSLL_H

#include <stddef.h>

typedef int Key;

typedef struct
{
  Key key; /* Key that maps the register */
}
Register;

typedef struct CircularSinglyLinkedList
{
  struct CircularSinglyLinkedList *next;
  Register data;
}
CircularSinglyLinkedList;

CircularSinglyLinkedList* csll_insert_begin(CircularSinglyLinkedList** tail, Key k);
CircularSinglyLinkedList* csll_insert_end(CircularSinglyLinkedList** tail, Key k);
CircularSinglyLinkedList* csll_search(CircularSinglyLinkedList** tail, Key k);
void csll_delete(CircularSinglyLinkedList** tail,
                 CircularSinglyLinkedList* to_remove);

#endif