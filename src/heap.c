#include <heap.h>
#include <utils.h>

void max_heapify(Register array[], int heap_size, int i,
                 int (*compare)(void*, void*))
{
  int left, right, largest;
  left = left(i);
  right = right(i);

  if (left < heap_size && compare(array[left].key, array[i].key) == 1)
    {
      largest = left;
    }
  else
    {
      largest = i;
    }
  if (right < heap_size && compare(array[right].key, array[largest].key) == 1)
    {
      largest = right;
    }
  if (largest != i)
    {
      swap_reg(array, i, largest);
      max_heapify(array, heap_size, largest, compare);
    }
}

void build_max_heap(Register array[], int length, int (*compare)(void*, void*))
{
  int heap_size, i;

  heap_size = length;
  for (i = parent(length - 1); i > -1; i--)
    {
      max_heapify(array, heap_size, i, compare);
    }
}
