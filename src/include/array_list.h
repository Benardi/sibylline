/**
 * @file array_list.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 24 Oct 2021
 * @brief Header file for ArrayList module.
 *
 * Defines the the struct ArrayList and the prototypes for the routines of the
 * ArrayList module.
 */
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <register.h>
#include <stdbool.h>

const int INCREASE_FACTOR = 2;

typedef struct
{
  int size;
  int capacity;
  Register* array;
} ArrayList;

/** @brief Initializes ArrayList with 0 elements and given capacity.
 *
 * Sets attribute size to 0, and capacity to given parameter. Allocates array
 * attribute with array of Register as long as the capacity attribute.
 *
 * @param list Pointer to ArrayList.
 * @param capacity Number of elements the ArrayList can fit initially.
 * @return Void
 */
void init_list(ArrayList* list, int capacity);

/** @brief Adds given element to the end of ArrayList.
 *
 * Adds given element to the end of ArrayList. If there's no available index
 * the ArrayList's capacity is doubled over. In case of capacity increase a new
 * longer array is allocated, elements are copied over and older array is freed.
 *
 * @param list Pointer to ArrayList.
 * @param element New element to be inserted in the ArrayList
 * @return Void
 */
void insert(ArrayList* list, Register element);

/** @brief Adds element at given index in ArrayList.
 *
 * Adds given element at index in ArrayList. If position was already occupied
 * function performs a shift to the right. If there's no available capacity the
 * ArrayList's capacity is doubled over. In case of capacity increase a new
 * longer array is allocated, elements are copied over and older array is freed.
 *
 * @param list Pointer to ArrayList.
 * @param index Position for new element.
 * @return Whether element could be inserted
 */
bool insert_at(ArrayList* list, Register element, int index);

/*
 * @brief Sets element at index within ArrayList.
 *
 * Sets element at given index, if index is occupied existing element
 * is overwritten. Valid index must be within ArrayList's capacity, above -1
 * and below attribute capacity. If invalid index is provided the function
 * makes no work and returns false, otherwise functions inserts element and
 * returns true.
 *
 * @param list Pointer to ArrayList.
 * @param element New element to be inserted in the ArrayList.
 * @param index Position to be set with new element.
 * @return Whether element could be set at given index.
 */
bool set(ArrayList* list, Register element, int index);

/*
 * @brief Retrieves element from given index in ArrayList.
 *
 * Retrieves element from given index in ArrayList. Valid index refers to
 * the index of an existing element, which must be above -1 and below
 * ArrayList's size. If invalid index is provided the function NULL.
 *
 * @param list Pointer to ArrayList.
 * @param index Position of element to be retrieved.
 * @return Returns Pointer to retrieved element.
 */
Register* get(ArrayList* list, int index);

/*
 * @brief Returns boolean saying if element is in ArrayList.
 *
 * Returns boolean value to represent whether element matching given identifier
 * is in ArrayList.
 *
 * @param list Pointer to ArrayList.
 * @param identifier Point to identifier of element to be found.
 * @param compare Pointer to function that compares two void pointers.
 * @return Whether element is in ArrayList.
 */
bool contains(ArrayList* list, void* identifier,
              int (*compare_to)(void*, void*));

/*
 * @brief Moves elements to the left starting at given index.
 *
 * Moves elements in ArrayList to the left starting at given index, and
 * returns true. Valid index must be above -1 and less than ArrayList's size.
 * In other words index must have an element to its right so something can be
 * shifter to the left. If invalid index is provided no change takes effect,
 * and function returns false.
 *
 * @param list Pointer to ArrayList.
 * @param index Position from which to start shifting elements to the left.
 * @return Whether shift left could be performed.
 */
bool shift_left(ArrayList* list, int index);

/*
 * @brief Moves elements to the right down to given index.
 *
 * Moves elements in ArrayList to the right. Starting from the last existing
 * element down to the given index each element is moved to the right. If list
 * is fully occupied its capacity is doubled before shift is performed.
 *
 * @param list Pointer to ArrayList.
 * @param index Position from down to which the shift right will be performed.
 * @return Whether shift right could be performed.
 */
void shift_right(ArrayList* list, int index);

/*
 * @brief Removes element from given index from ArrayList.
 *
 * Removes element at given index from ArrayList, and returns true. If there
 * are elements to the right of the one removed a gap is formed. This function
 * shifts to the left the aforementioned element so no gaps persists in the
 * ArrayList. ArrayList's size is updated. Valid index must be above -1 and
 * less than ArrayList's size. If invalid index is provided no change takes
 * effect, and function returns false.
 *
 * @param list Pointer to ArrayList.
 * @param index Position of element to be removed.
 * @return Whether element could be discarded.
 */
bool discard(ArrayList* list, int index);

/*
 * @brief Retrieves index of element in ArrayList with given identifier.
 *
 * Finds the index of first element in Array that matches given identifier.
 * If there's no match in the ArrayList the function returns -1.
 *
 * @param list Pointer to ArrayList.
 * @param identifier Point to identifier of element to be found.
 * @param compare Pointer to function that compares two void pointers.
 * @return Index of match in ArrayList.
 */
int index_of(ArrayList* list, void* identifier,
             int (*compare_to)(void*, void*));

#endif
