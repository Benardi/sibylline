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

#include <dll.h>
#include <register.h>

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

/** @brief Sorts given array via Insertion Sort procedure.
 *
 * Applies Insertion Sort procedure to sort array elements in ascending
 * order. The employed compare function must receive two void pointers
 * as parameters and return an integer as result. If first parameter is
 * bigger it should return 1, if first parameter is smaller it should
 * return -1, if it's the same as the second parameter it should return 0.
 *
 * @param array Array of Registers to be sorted
 * @param start Position of first array element to be sorted.
 * @param end Position of last array element to be sorted.
 * @param compare Pointer to function that compares two void pointers.
 * @return Void
 */
void insertion_sort_gnrc(Register array[], int start, int end,
                         int (*compare)(void*, void*));

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
void heap_sort(Register array[], int length, int (*compare)(void*, void*));

/** @brief Sorts given array via Counting Sort procedure.
 *
 * Applies the Counting Sort procedure to sort all elements in array in
 * ascending order. Counting sort assumes that each element is an integer
 * in the range 0 to @c upper_limit. The employed compare function must
 * receive two void pointers as parameters and return an integer as result.
 * If first parameter is bigger it should return 1, if first parameter is
 * smaller it should return -1, if it's the same as the second parameter
 * it should return 0.
 *
 * @param array Array of integer numbers to be sorted.
 * @param out Output array that will contain the sorted version.
 * @param length Number of elements in array.
 * @param upper_limit Upper bound for values in array.
 * @return Void
 */
void counting_sort(int array[], int* out, int length, int upper_limit);

/** @brief Sorts given array via Counting Sort based on nth decimal place.
 *
 * Applies the Counting Sort procedure to sort all elements in array in
 * ascending order based on the nth decimal place of value of elements.
 * Counting sort assumes that each element is an integer in the range
 * 0 to @c upper_limit. The employed compare function must receive two
 * void pointers as parameters and return an integer as result. If first
 * parameter is bigger it should return 1, if first parameter is smaller
 * it should return -1, if it's the same as the second parameter it should
 * return 0.
 *
 * @param array Array of integer numbers to be sorted.
 * @param out Output array that will contain the sorted version.
 * @param length Number of elements in array.
 * @param n Decimal place to be used by sorting procedure.
 * @return Void
 */
void counting_sort_by_nth_digit(int array[], int* out, int length, int n);

/** @brief Sorts given array via Radix Sort procedure.
 *
 * Applies the Radix Sort procedure to sort all elements in array in
 * ascending order. Radix Sort expects a maximum number of decimal places
 * in the given array elements.
 *
 * @param array Array of integer numbers to be sorted.
 * @param out Output array that will contain the sorted version.
 * @param length Number of elements in array.
 * @param max_decimal_place Maximum number of decimal places in elements.
 * @return Void
 */
void radix_sort(int array[], int* out, int length, int max_decimal_place);

/** @brief Sorts Doubly Linked List via Insertion Sort procedure.
 *
 * Applies Insertion Sort procedure to sort elements in Doubly Linked List
 * in ascending order. The employed compare function must receive two void
 * pointers as parameters and return an integer as result. If first parameter
 * is bigger it should return 1, if first parameter is smaller it should
 * return -1, if it's the same as the second parameter it should return 0.
 *
 * @param head Double pointer to head of existing Doubly Linked List.
 * @param start Position of first element in list to be sorted.
 * @param end Position of last element in list to be sorted.
 * @param compare Pointer to function that compares two void pointers.
 * @return Void
 */
void insertion_sort_dll(DoublyLinkedList** head, int start, int end,
                        int (*compare)(void*, void*));

/** @brief Sorts array of Registers via Bucket Sort procedure.
 *
 * Applies Insertion Sort procedure to sort elements in Doubly Linked List
 * in ascending order. The employed compare function must receive two void
 * pointers as parameters and return an integer as result. If first parameter
 * is bigger it should return 1, if first parameter is smaller it should
 * return -1, if it's the same as the second parameter it should return 0.
 *
 * @param array Array of Registers to be sorted
 * @param length Number of elements in array.
 * @param compare Pointer to function that multiplies the values of two
 *  void pointers then floors the result.
 * @param compare Pointer to function that compares two void pointers.
 * @return Void
 */
void bucket_sort(Register array[], int length,
                 int (*mul_plus_floor)(int, void*),
                 int (*compare)(void*, void*));

#endif
