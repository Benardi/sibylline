/**
 * @file heap.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 17 Mar 2020
 * @brief Header file for Heap module.
 *
 * Defines the constant MINUS_INF, the parent, left and right MACROS and
 * the prototypes for the routines of the Heap module.
 */
#ifndef HEAP_H
#define HEAP_H

#include <limits.h>
#include <math.h>
#include <register.h>
#include <stdbool.h>

#define MINUS_INF INT_MIN

#define parent(i) (floor((i - 1) / 2))
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

/** @brief Rotates i-th element to ensure max-heap property.
 *
 * This procedure assumes that i's left and right  are max heaps. Rotates
 * given element with one of its children to remove a violation to the
 * max-heap property. This function receives  a compare function that takes
 * two union Keys as parameters and return an integer as result.
 * If first parameter is bigger it should return 1, if first
 * parameter is smaller it should return -1, if it's the same as the second
 * parameter it should return 0.
 *
 * @param array Array of Registers containing heap elements.
 * @param heap_size Number of elements considered to be in the heap.
 * @param i Index in array for given heap element
 * @param compare Pointer to function that compares two union Keys.
 * @return Void.
 */
void max_heapify(Register array[], int heap_size, int i,
                 int (*compare)(union Key, union Key));

/** @brief Produces a max-heap from an unordered input array.
 *
 * Swaps elements in given array to produce a max-heap encompassing
 * all elements in array. This function receives  a compare function that takes
 * two union Keys as parameters and return an integer as result.
 * If first parameter is bigger it should return 1, if first
 * parameter is smaller it should return -1, if it's the same as the second
 * parameter it should return 0.
 *
 * @param array Array of Registers containing heap elements.
 * @param length Number of elements in given array.
 * @param compare Pointer to function that compares two union Keys.
 * @return Void.
 */
void build_max_heap(Register array[], int length,
                    int (*compare)(union Key, union Key));

#endif
