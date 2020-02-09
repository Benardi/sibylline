#ifndef SORT_H
#define SORT_H

void insertion_sort(int array[], int length);

void merge(int array[], int p, int q, int r);
void merge_sort(int array[], int p, int r);

void inplace_merge(int array[], int p, int q, int r);
void inplace_merge_sort(int array[], int p, int r);

int partition( int array[], int start, int end);
void quick_sort(int array[], int start, int end);

#endif