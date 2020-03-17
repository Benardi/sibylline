
#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <limits.h>
#include <math.h>

# define MINUS_INF INT_MIN

#define parent(i)(floor((i - 1) / 2))
#define left(i)(2 * i + 1)
#define right(i)(2 * i + 2)

void max_heapify(int array[], int heap_size, int i);
void build_max_heap(int array[], int length);

#endif