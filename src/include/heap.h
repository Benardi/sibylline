
#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MINUS_INF INT_MIN

#define parent(i)(floor((i - 1) / 2))
#define left(i)(2 * i + 1)
#define right(i)(2 * i + 2)

/** @brief Rotates i-th element to ensure max-heap property.
 * 
 * This procedure assumes that i's left and right  are max heaps. Rotates
 * given element with one of its children to remove a violation to the
 * max-heap property.
 *
 * @param array Array of integers containing heap elements. 
 * @param heap_size Number of elements considered to be in the heap.
 * @param i Index in array for given heap element
 * @return Void.
 */
void max_heapify(int array[], int heap_size, int i);

/** @brief Produces a max-heap from an unordered input array.
 * 
 * Swaps elements in given array to produce a max-heap encompassing
 * all elements in array.
 *
 * @param array Array of integers containing heap elements. 
 * @param length Number of elements in given array. 
 * @return Void.
 */
void build_max_heap(int array[], int length);

#endif