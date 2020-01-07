/**
 * @file cdll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 6 Jan 2020
 * @brief Header file for Circular Doubly Linked List module.
 *
 * Defines the constant MAX number of elements, the structs Key, Register
 * and CircularDoublyLinkedList and the prototypes for the subroutines of the
 * CircularDoublyLinkedList module.
 */
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

/** @brief Inits nil node to create valid linked list.
 *  
 * Sets nil node as its own next and previous node to create valid linked
 * list. If nodes have already been inserted they lose their link to nil node
 * but the memory allocated to them is not freed.
 *
 * @param nil Pointer to nil node. 
 * @return Void.
 */
void cddl_init(CircularDoublyLinkedList* nil);

/** @brief Inserts node to front of Linked List, as 'next' for nil node.
 *  
 * Inserts node to front of Linked List, being a circular list node is
 * put after nil node. New node becomes new 'next' of the nil node and
 * existing node if they existed are linked to the new one. Returns 
 * pointer to inserted node.
 *
 * @param nil Pointer to nil node. 
 * @param k Key for Register of inserted node.
 * @return Pointer to inserted node.
 */
CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil, Key k);

/** @brief Retrieves node in linked list via key. 
 *
 * Iterates sequentially over linked list. If node with given key exists
 * returns pointer to it, otherwise returns pointer to nil node.
 *
 * @param nil Pointer to nil node. 
 * @param k Key for Register of inserted node.
 * @return Pointer to retrieved node.
 */
CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil, Key k);

/** @brief Deletes given node from linked list. 
 *
 * Removes a node given via pointer from linked list. List is amended to make
 * up for absence of removed node. Allocated memory for node pointer is not
 * freed. It's up to user to free memory allocated to pointer.
 *
 * @param nil Pointer to nil node. 
 * @param k Key for Register of inserted node.
 * @return Void
 */
void cdll_delete(CircularDoublyLinkedList* to_remove);

#endif