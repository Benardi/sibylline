/**
 * @file sort.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 12 Feb 2020
 * @brief Header file for Sort module.
 * 
 * Defines routines employed to sort an array of numbers.
 */
#ifndef SORT_H
#define SORT_H

/** @brief Sorts given array via Insertion Sort procedure.
 *
 * Applies Insertion Sort procedure to put all array elements
 * in ascending order.
 *
 * @param array array of integer numbers to be sorted
 * @param length number of elements in array parameter.
 * @return Void
 */
void insertion_sort(int array[], int length);

void merge(int array[], int start, int middle, int end);

/** @brief Sorts given array via Merge Sort procedure.
 *
 * Applies Merge Sort procedure to put all array elements
 * in ascending order. Merge Sort makes use of the procedure
 * 'merge' to successfully sort the array.
 *
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @return Void
 */
void merge_sort(int array[], int start, int end);

void inplace_merge(int array[], int start, int middle, int end);

/** @brief Sorts given array via in place Merge Sort procedure.
 *
 * Applies the in place Merge Sort procedure to put all array
 * elements in ascending order. Merge Sort makes use of the
 * procedure 'in place merge' to successfully sort the array.
 *
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @return Void
 */
void inplace_merge_sort(int array[], int start, int end);

int partition(int array[], int start, int end);

/** @brief Sorts given array via Quick Sort procedure.
 *
 * Applies the Quick Sort procedure to put all array
 * elements in ascending order. Quick Sort makes use of the
 * procedure 'partition' to successfully sort array.
 *
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @return Void
 */
void quick_sort(int array[], int start, int end);

int rand_partition(int array[], int start, int end);

/** @brief Sorts given array via Random Quick Sort procedure.
 *
 * Applies the Random Quick Sort procedure to put all array
 * elements in ascending order. Random Quick Sort makes use of the
 * procedure 'random partition' to successfully sort the array.
 *
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @param seed value used to ensure procedure is reproducible.
 * @return Void
 */
void rand_quick_sort(int array[], int start, int end, unsigned int seed);

/** @brief Sorts given array via Selection Sort procedure.
 *
 * Applies the Selection Sort procedure to put all array
 * elements in ascending order.
 * 
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @return Void
 */
void selection_sort(int array[], int start, int end);

/** @brief Sorts given array via Bubble Sort procedure.
 *
 * Applies the Bubble Sort procedure to put all array
 * elements in ascending order.
 *
 * @param array array of integer numbers to be sorted
 * @param start position of first array element to be sorted.
 * @param end position of last array element to be sorted.
 * @return Void
 */
void bubble_sort(int array[], int start, int end);

#endif