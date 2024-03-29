/**
 * @file csll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 9 Jan 2020
 * @brief Header file for Circular Singly Linked List module.
 *
 * Defines the structDoublyLinkedList and the prototypes for the routines of
 * the CircularSinglyLinkedList module.
 */
#ifndef CSLL_H
#define CSLL_H

#include <register.h>
#include <stddef.h>

typedef struct CircularSinglyLinkedList
{
  struct CircularSinglyLinkedList* next;
  Register data;
} CircularSinglyLinkedList;

/** @brief Inserts node at front of Circular Singly Linked List.
 *
 * Inserts node at front of Circular Singly Linked List. If other nodes
 * already exist in list existing nodes are linked to new one. Returns
 * pointer to added node.
 *
 * @param tail Double pointer to tail of Circular Singly Linked List.
 * @param reg Register of inserted node.
 * @return Pointer to inserted node.
 */
CircularSinglyLinkedList* csll_insert_begin(CircularSinglyLinkedList** tail,
                                            Register reg);

/** @brief Inserts node at end of Circular Singly Linked List.
 *
 * Inserts node at end of Circular Singly Linked List. If other nodes
 * already exist in list new node becomes new tail and existing nodes are
 * linked to new one. Returns pointer to added node and updates double
 * pointer with new tail of the linked list.
 *
 * @param tail Double pointer to tail of Circular Singly Linked List.
 * @param reg Register of inserted node.
 * @return Pointer to inserted node.
 */
CircularSinglyLinkedList* csll_insert_end(CircularSinglyLinkedList** tail,
                                          Register reg);

/** @brief Retrieves node from Circular Singly Linked List via key.
 *
 * Iterates sequentially over Circular Singly Linked List. If node with given
 * key exists returns pointer to it, otherwise returns @c NULL. The employed
 * compare function must receive two union Keys as parameters and return
 * an integer as result. If first parameter is bigger it should return 1, if
 * first parameter is smaller it should return -1, if it's the same as the
 * second parameter it should return 0.
 *
 * @param tail Double pointer to tail of Circular Singly Linked List.
 * @param key Key for Register of inserted node.
 * @param compare Pointer to function that compares two union Keys.
 * @return Pointer to retrieved node.
 */
CircularSinglyLinkedList* csll_search(CircularSinglyLinkedList** tail,
                                      union Key key,
                                      int (*compare)(union Key, union Key));

/** @brief Deletes given node from Circular Singly Linked List.
 *
 * Removes a node given via pointer from Circular Singly Linked List. List is
 * amended to make up for absence of removed node. Allocated memory for node
 * pointer is not freed. It's up to the user to free memory allocated
 * to pointer.
 *
 * @param tail Double pointer to tail of Circular Singly Linked List.
 * @param to_remove pointer to node to be removed.
 * @return Void
 */
void csll_delete(CircularSinglyLinkedList** tail,
                 CircularSinglyLinkedList* to_remove);

#endif
