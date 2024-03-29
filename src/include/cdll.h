/**
 * @file cdll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 6 Jan 2020
 * @brief Header file for Circular Doubly Linked List module.
 *
 * Defines the the CircularDoublyLinkedList and the prototypes for the
 * routines of the CircularDoublyLinkedList module.
 */
#ifndef CDLL_H
#define CDLL_H

#include <register.h>
#include <stddef.h>

typedef struct CircularDoublyLinkedList
{
  struct CircularDoublyLinkedList* prev;
  struct CircularDoublyLinkedList* next;
  Register data;
} CircularDoublyLinkedList;

/** @brief Inits nil node to create valid Circular Doubly Linked List.
 *
 * Sets nil node as its own next and previous node to create valid Circular
 * Doubly Linked List. If nodes have already been inserted they lose their
 * link to nil node but the memory allocated to them is not freed.
 *
 * @param nil Pointer to nil node.
 * @return Void.
 */
void cdll_init(CircularDoublyLinkedList* nil);

/** @brief Inserts node to front of Circular Doubly Linked List, as 'next' for
 * nil node.
 *
 * Inserts node to front of Circular Doubly Linked List, being a circular list
 * node is put after nil node. New node becomes new 'next' of the nil node and
 * existing node if they existed are linked to the new one. Returns
 * pointer to inserted node.
 *
 * @param nil Pointer to nil node.
 * @param reg Register of inserted node.
 * @return Pointer to inserted node.
 */
CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil,
                                      Register reg);

/** @brief Retrieves node in Circular Doubly Linked List via key.
 *
 * Iterates sequentially over Circular Doubly Linked List. If node with given
 * key exists returns pointer to it, otherwise returns pointer to nil node.
 * The employed compare function must receive two union Keys as parameters
 * and return an integer as result. The employed compare function must receive
 * two union Keys as parameter and return an integer as result. If first
 * parameter is bigger it should return 1, if first parameter is smaller it
 * should return -1, if it's the same as the second parameter it should
 * return 0.
 *
 *
 * @param nil Pointer to nil node.
 * @param key Key for Register of inserted node.
 * @param compare Pointer to function that compares two union Keys.
 * @return Pointer to retrieved node.
 */
CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil,
                                      union Key key,
                                      int (*compare)(union Key, union Key));

/** @brief Deletes given node from Circular Doubly Linked List.
 *
 * Removes a node given via pointer from Circular Doubly Linked List. List is
 * amended to make up for absence of removed node. Allocated memory for node
 * pointer is not freed. It's up to user to free memory allocated to pointer.
 *
 * @param to_remove Pointer to node to be removed.
 * @return Void
 */
void cdll_delete(CircularDoublyLinkedList* to_remove);

#endif
