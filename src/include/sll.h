/**
 * @file dll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 7 Jan 2020
 * @brief Header file for Singly Linked List module.
 *
 * Defines the constant MAX number of elements, the structs Key, Register
 * and SinglyLinkedList and the prototypes for the subroutines of the
 * SinglyLinkedList module.
 */
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

/** @brief Inserts node at front of Linked List.
 *  
 * Inserts node at front of Linked List. If other nodes already exist in list
 * new node becomes new head and existing nodes are linked to new one. Returns
 * pointer to added node and updates double pointer with new head of the
 * linked list.
 *
 * @param head Double pointer to head of linked list. 
 * @param k Key for Register of inserted node.
 * @return Pointer to inserted node.
 */
SinglyLinkedList* sll_insert(SinglyLinkedList** head, Key k);

/** @brief Retrieves node from linked list via key. 
 *
 * Iterates sequentially over linked list. If node with given key exists
 * returns pointer to it, otherwise returns @c NULL.
 *
 * @param head Double pointer to head of linked list. 
 * @param k Key for Register of inserted node.
 * @return Pointer to retrieved node.
 */
SinglyLinkedList* sll_search(SinglyLinkedList** head, Key k);

/** @brief Deletes given node from linked list. 
 *
 * Removes a node given via pointer from linked list. List is amended to make
 * up for absence of removed node. Allocated memory for node pointer is not
 * freed. It's up to the user to free memory allocated to pointer.
 *
 * @param head Double pointer to head of linked list. 
 * @param k Key for Register of inserted node.
 * @return Void
 */
void sll_delete(SinglyLinkedList** head, SinglyLinkedList* to_remove);

#endif