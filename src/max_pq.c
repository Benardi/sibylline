#include <heap.h>
#include <max_pq.h>
#include <utils.h>

Register heap_maximum(Register array[])
{
  return array[0];
}

bool heap_extract_max(Register array[], int* heap_size, Register* extracted,
                      int (*compare)(union Key, union Key))
{
  Register max;

  if ((*heap_size) < 1)
    {
      return false;
    }
  else
    {
      max = array[0];
      array[0] = array[(*heap_size) - 1];
      (*heap_size) = (*heap_size) - 1;
      max_heapify(array, (*heap_size), 0, compare);
      (*extracted) = max;

      return true;
    }
}

bool heap_increase_key(Register array[], int i, union Key key,
                       int (*compare)(union Key, union Key))
{
  if (compare(key, array[i].key) == -1)
    {
      return false;
    }
  else
    {
      array[i].key = key;
      while ((i > 0) && compare(array[(int)parent(i)].key, array[i].key) == -1)
        {
          swap_reg(array, i, parent(i));
          i = parent(i);
        }

      return true;
    }
}

void max_heap_insert(Register array[], union Key key, int* heap_size,
                     int (*compare)(union Key, union Key))
{
  int inf = MINUS_INF;
  (*heap_size) = (*heap_size) + 1;
  array[(*heap_size) - 1].key.i = inf;
  heap_increase_key(array, (*heap_size) - 1, key, compare);
}
