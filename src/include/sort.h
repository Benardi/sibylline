#ifndef SORT_H
#define SORT_H

void insertion_sort(int array[], int length);

void merge(int array[], int start, int middle, int end);
void merge_sort(int array[], int start, int end);

void inplace_merge(int array[], int start, int middle, int end);
void inplace_merge_sort(int array[], int start, int end);

int partition( int array[], int start, int end);
void quick_sort(int array[], int start, int end);

int rand_partition(int array[], int start, int end);
void rand_quick_sort(int array[], int start, int end, unsigned int seed);

void selection_sort(int array[], int start, int end);
void bubble_sort(int array[], int start, int end);

#endif