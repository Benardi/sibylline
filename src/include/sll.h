/**
 * @file sll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 7 Jan 2020
 * @brief Header file for Singly Linked List module.
 *
 * Defines the struct SinglyLinkedList and the prototypes for the
 * routines of the SinglyLinkedList module.
 */
#ifndef SLL_H
#define SLL_H

#include <register.h>
#include <stddef.h>

typedef struct SinglyLinkedList
{
  struct SinglyLinkedList* next;
  Register data;
} SinglyLinkedList;

/** @brief Inserts node at front of Singly Linked List.
 *
 * Inserts node at front of Singly Linked List. If other nodes already exist
 * in list new node becomes new head and existing nodes are linked to new one.
 * Returns pointer to added node and updates double pointer with new head of
 * the Singly Linked List.
 *
 * @param head Double pointer to head of Singly Linked List.
 * @param reg Register of inserted node.
 * @return Pointer to inserted node.
 */
SinglyLinkedList* sll_insert(SinglyLinkedList** head, Register reg);

/** @brief Retrieves node from Singly Linked List via key.
 *
 * Iterates sequentially over Singly Linked List. If node with given key
 * exists returns pointer to it, otherwise returns @c NULL. The employed
 * compare function must receive two union Keys as parameters and return
 * an integer as result. If first parameter is bigger it should return 1, if
 * first parameter is smaller it should return -1, if it's the same as the
 * second parameter it should return 0.
 *
 * @param head Double pointer to head of Singly Linked List.
 * @param key Key for Register of inserted node.
 * @param compare Pointer to function that compares two union Keys.
 * @return Pointer to retrieved node.
 */
SinglyLinkedList* sll_search(SinglyLinkedList** head, union Key key,
                             int (*compare)(union Key, union Key));

/** @brief Deletes given node from Singly Linked List.
 *
 * Removes a node given via pointer from Singly Linked List. List is amended
 * to make up for absence of removed node. Allocated memory for node pointer
 * is not freed. It's up to the user to free memory allocated to pointer.
 *
 * @param head Double pointer to head of Singly Linked List.
 * @param to_remove Pointer to node to be removed.
 * @return Void
 */
void sll_delete(SinglyLinkedList** head, SinglyLinkedList* to_remove);

#endif
