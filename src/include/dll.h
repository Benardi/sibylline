/**
 * @file dll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 2 Jan 2020
 * @brief Header file for Doubly Linked List module.
 *
 * Defines the struct DoublyLinkedList and the prototypes for the routines of
 * the DoublyLinkedList module.
 */
#ifndef DLL_H
#define DLL_H

#include <stdbool.h>
#include <stddef.h>
/* #include <register.h>
 */
typedef struct
{
  void* key;
  void* data;
} Register;

typedef struct DoublyLinkedList
{
  struct DoublyLinkedList* prev;
  struct DoublyLinkedList* next;
  Register data;
} DoublyLinkedList;

/** @brief Inserts node at front of Doubly Linked List.
 *
 * Inserts node at front of Doubly Linked List. If other nodes already exist
 * in list new node becomes new head and existing nodes are linked to new one.
 * Returns pointer to added node and updates double pointer with new head of
 * the linked list.
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @param reg Register of inserted node.
 * @return Pointer to inserted node.
 */
DoublyLinkedList* dll_insert(DoublyLinkedList** head, Register reg);

/** @brief Retrieves node from Doubly Linked List via key.
 *
 * Iterates sequentially over Doubly Linked List. If node with given key exists
 * returns pointer to it, otherwise returns @c NULL.
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @param k Key for Register of inserted node.
 * @return Pointer to retrieved node.
 */
DoublyLinkedList* dll_search(DoublyLinkedList** head, void* key,
                             int (*compare)(void*, void*));

/** @brief Deletes given node from Doubly Linked List.
 *
 * Removes a node given via pointer from Doubly Linked List. List is amended
 * to make up for absence of removed node. Allocated memory for node pointer
 * is not freed. It's up to the user to free memory allocated to pointer.
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @param to_remove Pointer to node to be removed.
 * @return Void
 */
void dll_delete(DoublyLinkedList** head, DoublyLinkedList* to_remove);

#endif
