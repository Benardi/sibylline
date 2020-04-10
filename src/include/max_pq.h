/**
 * @file max_pq.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 19 Mar 2020
 * @brief Header file for Max Priority Queue module.
 *
 * Defines the prototypes for the routines of the Max Priority Queue module.
 */
#ifndef MAX_PQ_H
#define MAX_PQ_H

#include <register.h>
#include <stdbool.h>

/** @brief Extracts maximum value from Max Priority Queue (max-heap).
 *
 * Extracts maximum value from max-heap if heap contains at least one element.
 * Reorganizes heap to maintain heap property and decreases heap size. Returns
 * a boolean value to denote whether extraction was successful. If extraction
 * was successful given pointer is set to maximum value.
 *
 * @param array Array of Registers containing heap elements.
 * @param heap_size Pointer that contains number of elements in heap.
 * @param extracted Pointer where to store Register containing maximum value.
 * @param compare Pointer to function that compares two void pointers.
 * @return Whether extraction was successful.
 */
bool heap_extract_max(Register array[], int* heap_size, Register* extracted, int (*compare)(void*, void*));

/** @brief Gets maximum value / priority in Max Priority Queue (max-heap).
 *
 * If there's at least one element in heap returns its maximum value.
 * Otherwise, its behavior is undefined.
 *
 * @param array Array of Registers containing heap elements.
 * @return Register containing maximum value in max-heap.
 */
Register heap_maximum(Register array[]);

/** @brief Increases key/priority of element in Max Priority Queue (max-heap).
 *
 * Increases key (priority) of element in max-heap to given value. Reorganizes
 * heap to maintain the heap property. The value can only be increased, and a
 * decrease is invalid. Returns a boolean value to denote whether key update
 * was successful.
 *
 * @param array Array of Registers containing heap elements.
 * @param i Index of element whose priority is to be increased.
 * @param key New priority value as void pointer.
 * @param compare Pointer to function that compares two void pointers.
 * @return Whether key increase was successful.
 */
bool heap_increase_key(Register array[], int i, void* key, int (*compare)(void*, void*));

/** @brief Inserts element of given key into Max Priority Queue (max-heap).
 *
 * Inserts element of given key into max-heap. Reorganizes max-heap to
 * maintain heap property and updates heap size.
 *
 * @param array Array of Registers containing heap elements.
 * @param key Key (Priority) of element to be inserted as void pointer.
 * @param heap_size Pointer to number of elements in heap.
 * @param compare Pointer to function that compares two void pointers.
 * @return Void.
 */
void max_heap_insert(Register array[], void* key, int* heap_size, int (*compare)(void*, void*));

#endif
