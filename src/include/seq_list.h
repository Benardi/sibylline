/**
 * @file seq_list.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 12 Oct 2019
 * @brief Header file for Sequential List module.
 *
 * Defines the constant MAX number of elements, the struct SeqList and the
 * prototypes for the routines of the Sequential List module.
 */
#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <register.h>
#include <stdbool.h>

#define MAX 20

typedef struct
{
  Register A[MAX + 1]; /* Array that stores the elements */
  int nElem;           /* Current number of elements in Sequential List */
} SeqList;

/** @brief Initializes Sequential List with 0 elements.
 *
 * Sets the attribute nElems of a Sequential List given as a pointer to 0.
 *
 * @param sl Sequential List as pointer
 * @return Void
 */
void init_seq_list(SeqList* sl);

/** @brief Reinitializes Sequential List with 0 elements.
 *
 * Sets the attribute nElems of a Sequential List (that has been used before)
 * given as a pointer to 0.
 *
 * @param sl Sequential List as pointer
 * @return Void
 */
void reinit_seq_list(SeqList* sl);

/** @brief Calculates the size of a Sequential List.
 *
 * Calculates the size of a initialized Sequential List, undefined behavior if
 * not properly initialized
 *
 * @param sl Sequential List as pointer
 * @return The size of the Sequential List
 */
int size(SeqList* sl);

/** @brief Inserts register in Sequential List at given position.
 *
 * If given position is invalid (bigger than MAX/nElems or less than zero) the
 * Sequential List is kept unchanged and false is returned. Else, the element
 * is inserted and true returned.
 *
 * @param sl Pointer to Sequential List.
 * @param reg Element that contains key.
 * @param i Position where to insert
 * @return Whether element could be inserted
 */
bool insert_elem(SeqList* sl, Register reg, int i);

/** @brief Inserts register in Sequential List whilst ensuring the List stays
 * sorted.
 *
 * If the Sequential List is already filled up it is kept unchanged and false
 * is returned. Else, the element is inserted and true returned. The employed
 * compare function must receive two void pointers as parameters and return
 * an integer as result. If first parameter is bigger it should return 1, if
 * first parameter is smaller it should return -1, if it's the same as the
 * second parameter it should return 0.
 *
 * @param sl Sequential List as pointer
 * @param reg Element that contains key
 * @param compare Pointer to function that compares two void pointers.
 * @return Whether element could be inserted
 */
bool insert_sorted(SeqList* sl, Register reg, int (*compare)(void*, void*));

/** @brief Sequentially searchs a Sequential List and returns
 * index of first occurrence.
 *
 * Sequentially iterates over Sequential List in ascending order of index.
 * Returns index of first occurrence that matches given Register key, else
 * returns -1. The employed compare function must receive two void pointers
 * as parameters and return an integer as result. If first parameter is
 * bigger it should return 1, if first parameter is smaller it should
 * return -1, if it's the same as the second parameter it should return 0.
 *
 * @param sl Sequential List as pointer
 * @param key Key to be found
 * @param compare Pointer to function that compares two void pointers.
 * @return Index of first match
 */
int seq_search(SeqList* sl, void* key, int (*compare)(void*, void*));

/** @brief Performs binary search on a Sequential List under the assumption it
 * is sorted.
 *
 * Performs binary search on a sorted Sequential List. Returns index of first
 * matched occurrence of given Register key, else returns -1. The employed
 * compare function must receive two void pointers as parameters and return
 * an integer as result. If first parameter is bigger it should return 1,
 * if first parameter is smaller it should return -1, if it's the same as the
 * second parameter it should return 0.
 *
 * @param sl Sequential List as pointer
 * @param key Key to be found
 * @param compare Pointer to function that compares two void pointers.
 * @return Index of first match
 */
int binary_search(SeqList* sl, void* k, int (*compare)(void*, void*));

/** @brief Sequentially searchs a Sequential List and returns index of first
 * occurrence.
 *
 * Sequentially iterates over Sequential List in ascending order of index.
 * Sentinel is appended to List to allow a more efficient search. Returns
 * index of first occurrence that matches given Register key, else returns -1.
 * The employed compare function must receive two void pointers as parameters
 * and return an integer as result. If first parameter is bigger it should
 * return 1, if first parameter is smaller it should return -1, if it's the
 * same as the second parameter it should return 0.
 *
 * @param sl Sequential List as pointer
 * @param key Key to be found
 * @param compare Pointer to function that compares two void pointers.
 * @return Index of first match
 */
int sentinel_search(SeqList* sl, void* k, int (*compare)(void*, void*));

/** @brief Sequentially searchs a Sequential List and removes first
 * occurrence.
 *
 * Sequentially iterates over Sequential List in ascending order of index.
 * Removes first occurrence that matches given Register key and shifts
 * remaining elements to the right to keep Sequential List contiguous.
 * Else, keeps Sequential List untouched. The employed compare function must
 * receive two void pointers as parameters and return an integer as result.
 * If first parameter is bigger it should return 1, if first parameter is
 * smaller it should return -1, if it's the same as the second parameter
 * it should return 0.
 *
 * @param sl Sequential List as pointer
 * @param key Key to be found
 * @param compare Pointer to function that compares two void pointers.
 * @return Wheter element could be removed
 */
bool remove_elem(SeqList* sl, void* key, int (*compare)(void*, void*));

/** @brief Prints elements in Sequential List
 *
 * Sequentially iterates over Sequential List in ascending order of index,
 * printing the key of each existing element separated by a blank space.
 *
 * @param sl Sequential List as pointer
 * @return Void
 */
void show_list(SeqList* sl);

#endif
