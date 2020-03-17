
#ifndef MAX_PQ_H
#define MAX_PQ_H

#include <stdbool.h>

bool heap_extract_max(int array[], int heap_size, int* extracted);
int heap_maximum(int array[]);
bool heap_increase_key(int array[], int i, int key);
void max_heap_insert(int array[], int key, int* heap_size);

#endif