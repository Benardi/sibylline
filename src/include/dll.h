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

#include <register.h>
#include <stdbool.h>
#include <stddef.h>

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
 * returns pointer to it, otherwise returns @c NULL. The employed compare
 * function must receive two union Keys as parameters and return an integer
 * as result. If first parameter is bigger it should return 1, if first
 * parameter is smaller it should return -1, if it's the same as the second
 * parameter it should return 0.
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @param key Key for Register of inserted node.
 * @param compare_to Pointer to comparator for union Keys.
 * @return Pointer to retrieved node.
 */
DoublyLinkedList* dll_search(DoublyLinkedList** head, union Key search_key,
                             int (*compare)(union Key, union Key));

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

/** @brief Retrieves nth node in Doubly Linked List.
 *
 * Searchs for element in Doubly Linked List by index. Starts search from
 * Doubly Linked List's head. If nth element exists returns pointer to it
 * if it doesn't exist returns @c NULL
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @param n Index of node to be retrieved.
 * @return Pointer to retrieved node.
 */
DoublyLinkedList* dll_get_nth(DoublyLinkedList** head, int n);

/** @brief Retrieves nth node in Doubly Linked List using a starting point.
 *
 * Searchs for element in Doubly Linked List by index. Starts search from
 * Doubly Linked List's head. If nth element exists returns pointer to it
 * if it doesn't exist returns @c NULL
 *
 * @param curt Pointer to node in Linked List used as search's starting point.
 * @param curt_idx Index of node used as search's starting point.
 * @param end Index of node to be retrieved.
 * @return Pointer to retrieved node.
 */
DoublyLinkedList* dll_get_by_idx(DoublyLinkedList* curt, int curt_idx, int end);

/** @brief Frees memory allocated for nodes in Doubly Linked List.
 *
 * Iterates over elements in Doubly Linked List and frees memory allocated
 * for them. It's up to the user to free memory allocated to the double
 * pointer (head).
 *
 * @param head Double pointer to head of Doubly Linked List.
 * @return Void.
 */
void dll_free_list(DoublyLinkedList** head);

#endif
