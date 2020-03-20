#include <heap.h>
#include <max_pq.h>
#include <utils.h>

int heap_maximum(int array[])
{
  return array[0];
}

bool heap_extract_max(int array[], int* heap_size, int* extracted)
{
  int max;

  if ((*heap_size) < 1)
    {
      return false;
    }
  else
    {
      max = array[0];
      array[0] = array[(*heap_size) - 1];
      (*heap_size) = (*heap_size) - 1;
      max_heapify(array, (*heap_size), 0);
      (*extracted) = max;

      return true;
    }
}

bool heap_increase_key(int array[], int i, int key)
{
  if (key < array[i])
    {
      return false;
    }
  else
    {
      array[i] = key;
      while ((i > 0) && array[(int)parent(i)] < array[i])
        {
          swap(array, i, parent(i));
          i = parent(i);
        }

      return true;
    }
}

void max_heap_insert(int array[], int key, int* heap_size)
{
  (*heap_size) = (*heap_size) + 1;
  array[(*heap_size) - 1] = MINUS_INF;
  heap_increase_key(array, (*heap_size) - 1, key);
}