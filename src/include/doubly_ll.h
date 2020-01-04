/**
 * @file doubly_ll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 2 Jan 2020
 * @brief Header file for Doubly Linked List module.
 *
 * Defines the constant MAX number of elements, the structs Key, Register 
 * and DoublyLinkedList and the prototypes for the subroutines of the DoublyLinkedList module.
 */
#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <stddef.h>
#include <stdbool.h>

typedef int Key;

typedef struct
{
  Key key; /* Key that maps the register */
}
Register;

typedef struct DoublyLinkedList
{
  struct DoublyLinkedList *prev;
  struct DoublyLinkedList *next;
  Register data;
}
DoublyLinkedList;

DoublyLinkedList* list_insert(DoublyLinkedList** head, Key k);
DoublyLinkedList* list_search(DoublyLinkedList** head, Key k);
void list_delete(DoublyLinkedList** dll, DoublyLinkedList* to_remove);

#endif