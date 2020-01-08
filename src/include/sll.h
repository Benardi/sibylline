#ifndef SLL_H
#define SLL_H

#include <stddef.h>

typedef int Key;

typedef struct
{
  Key key; /* Key that maps the register */
}
Register;

typedef struct SinglyLinkedList
{
  struct SinglyLinkedList *next;
  Register data;
}
SinglyLinkedList;

SinglyLinkedList* sll_search(SinglyLinkedList** head, Key k);
SinglyLinkedList* sll_insert(SinglyLinkedList** head, Key k);
void sll_delete(SinglyLinkedList** head, SinglyLinkedList* to_remove);

#endif