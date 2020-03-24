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
 * Applies Insertion Sort procedure to sort array elements
 * in ascending order.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void insertion_sort(int array[], int start, int end);

/** @brief Combines two sorted sequences into a sorted one.
 *
 * The procedure assumes that the subarrays array[start, middle] and
 * array[middle + 1, end] are in sorted order. It merges them to form
 * a single sorted subarray that replaces the current subarray
 * A[start, end]. This version makes use of auxiliary structures.
 *
 * @param array Array of integer containing two sequences.
 * @param start Position of first element of first sequence.
 * @param middle Position of last element of first sequence.
 * @param end Position of last element of second sequence.
 * @return Void
 */
void merge(int array[], int start, int middle, int end);

/** @brief Sorts given array via Merge Sort procedure.
 *
 * Applies Merge Sort procedure to sort array elements
 * in ascending order. Merge Sort makes use of the procedure
 * 'merge' to successfully sort the array.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void merge_sort(int array[], int start, int end);

/** @brief Combines two sorted sequences into a sorted one in-place.
 *
 * The procedure assumes that the subarrays array[start, middle] and
 * array[middle + 1, end] are in sorted order. It merges them to form
 * a single sorted subarray that replaces the current subarray
 * A[start, end]. This version makes no use of auxiliary structures.
 *
 * @param array Array of integer containing two sequences.
 * @param start Position of first element of first sequence.
 * @param middle Position of last element of first sequence.
 * @param end Position of last element of second sequence.
 * @return Void
 */
void inplace_merge(int array[], int start, int middle, int end);

/** @brief Sorts given array via in place Merge Sort procedure.
 *
 * Applies the in place Merge Sort procedure to sort array
 * elements in ascending order. Merge Sort makes use of the
 * procedure 'in place merge' to successfully sort the array.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void inplace_merge_sort(int array[], int start, int end);

/** @brief Reorders array elements around elected pivot (last element).
 *
 * Elects last element as pivot. Moves elements around to ensure that
 * elements smaller than the pivot are to its left and that elements
 * bigger than the pivot are to its right.
 *
 * @param array Array of integer numbers to be partitioned around pivot.
 * @param start Position of first array element to be partitioned.
 * @param end Position of last array element to be partitioned.
 * @return New position of the elected pivot
 */
int partition(int array[], int start, int end);

/** @brief Sorts given array via Quick Sort procedure.
 *
 * Applies the Quick Sort procedure to sort array
 * elements in ascending order. Quick Sort makes use of the
 * procedure 'partition' to successfully sort array.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void quick_sort(int array[], int start, int end);

/** @brief Reorders array elements around randomly elected pivot.
 *
 * Randomly elects element as pivot. Moves elements around to ensure that
 * elements smaller than the pivot are to its left and that elements
 * bigger than the pivot are to its right.
 *
 * @param array Array of integer numbers to be partitioned around pivot.
 * @param start Position of first array element to be partitioned.
 * @param end Position of last array element to be partitioned.
 * @return New position of the elected pivot
 */
int rand_partition(int array[], int start, int end);

/** @brief Sorts given array via Random Quick Sort procedure.
 *
 * Applies the Random Quick Sort procedure to sort array
 * elements in ascending order. Random Quick Sort makes use of the
 * procedure 'random partition' to successfully sort the array.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @param seed Value used to ensure procedure is reproducible.
 * @return Void
 */
void rand_quick_sort(int array[], int start, int end, unsigned int seed);

/** @brief Sorts given array via Selection Sort procedure.
 *
 * Applies the Selection Sort procedure to sort array
 * elements in ascending order.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void selection_sort(int array[], int start, int end);

/** @brief Sorts given array via Bubble Sort procedure.
 *
 * Applies the Bubble Sort procedure to sort array
 * elements in ascending order.
 *
 * @param array Array of integer numbers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @return Void
 */
void bubble_sort(int array[], int start, int end);

/** @brief Sorts given array via Heap Sort procedure.
 *
 * Applies the Heap Sort procedure to sort all elements
 * in array in ascending order.
 *
 * @param array Array of integer numbers to be sorted
 * @param length Number of elements in array.
 * @return Void
 */
void heap_sort(int array[], int length);

void counting_sort(int array[], int* out, int length, int upper_limit);
void counting_sort_by_nth_digit(int array[], int* out, int length, int n);
void radix_sort(int array[], int* out, int length, int max_decimal_place);
void bucket_sort(int array[], int length);
#endif