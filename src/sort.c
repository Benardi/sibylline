#include <heap.h>
#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <sort.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#define INFINITY INT_MAX

void insertion_sort(int array[], int start, int end)
{
  int j, i, key;

  for (j = start + 1; j <= end; j++)
    {
      key = array[j];
      i = j - 1; /* last element of sorted deck */
      while (i > (start - 1) && array[i] > key)
        {
          array[i + 1] = array[i];
          i = i - 1;
        }
      array[i + 1] = key;
    }
}

void merge(int array[], int start, int middle, int end)
{
  int* left;
  int* right;
  int n1, n2;
  int i, j, k;

  n1 = middle - start + 1;
  n2 = end - middle;

  left = malloc((n1 + 1) * sizeof(int));
  right = malloc((n2 + 1) * sizeof(int));

  /* populate left array */
  for (i = 0; i < n1; i++)
    {
      left[i] = array[start + i];
    }

  /* populate right array */
  for (j = 0; j < n2; j++)
    {
      right[j] = array[middle + j + 1];
    }

  left[n1] = INFINITY;
  right[n2] = INFINITY;

  i = j = 0;

  /* transfer values to array in correct order */
  for (k = start; k <= end; k++)
    {
      if (left[i] <= right[j])
        {
          array[k] = left[i];
          i++;
        }
      else
        {
          array[k] = right[j];
          j++;
        }
    }

  free(left);
  free(right);
}

void merge_sort(int array[], int start, int end)
{
  int middle;

  if (start < end)
    {
      middle = floor((start + end) / 2);
      merge_sort(array, start, middle);
      merge_sort(array, middle + 1, end);
      merge(array, start, middle, end);
    }
}

static void shift_right_array(int array[], int start, int end)
{
  int i;

  for (i = end; i > start; i--)
    {
      array[i] = array[i - 1];
    }
}

void inplace_merge(int array[], int start, int middle, int end)
{
  int start1, start2, moved;

  start1 = start;
  start2 = middle + 1;

  while (start1 <= middle && start2 <= end)
    {
      if (array[start1] < array[start2])
        {
          start1++;
        }
      else
        {
          moved = array[start2];
          shift_right_array(array, start1, start2);
          array[start1] = moved;
          start2++;
          start1++;
          middle++;
        }
    }
}

void inplace_merge_sort(int array[], int start, int end)
{
  int middle;

  if (start < end)
    {
      middle = floor((start + end) / 2);
      inplace_merge_sort(array, start, middle);
      inplace_merge_sort(array, middle + 1, end);
      inplace_merge(array, start, middle, end);
    }
}

int partition(int array[], int start, int end)
{
  int i, j, pivot;

  pivot = array[end];
  i = start - 1;

  for (j = start; j < end; j++)
    {
      if (array[j] <= pivot)
        {
          i++;
          swap(array, i, j);
        }
    }
  swap(array, i + 1, end);

  return i + 1;
}

void quick_sort(int array[], int start, int end)
{
  int middle;

  if (start < end)
    {
      middle = partition(array, start, end);
      quick_sort(array, start, middle - 1);
      quick_sort(array, middle + 1, end);
    }
}

int rand_partition(int array[], int start, int end)
{
  int i;
  i = sample(start, end);
  swap(array, end, i);
  return partition(array, start, end);
}

static void random_quick_sort(int array[], int start, int end)
{
  int middle;

  if (start < end)
    {
      middle = rand_partition(array, start, end);
      random_quick_sort(array, start, middle - 1);
      random_quick_sort(array, middle + 1, end);
    }
}

void rand_quick_sort(int array[], int start, int end, unsigned int seed)
{
  srand(seed);
  random_quick_sort(array, start, end);
}

void selection_sort(int array[], int start, int end)
{
  int i;
  int max_idx;

  for (i = 0; i < (end - start); i++)
    {
      max_idx = max(array, start, end - i);
      swap(array, max_idx, end - i);
    }
}

void bubble_sort(int array[], int start, int end)
{
  int i, j;

  for (i = start; i < end; i++)
    {
      for (j = end; j > i; j--)
        {
          if (array[j] < array[j - 1])
            {
              swap(array, j, j - 1);
            }
        }
    }
}

void heap_sort(int array[], int length)
{
  int i, heap_size;

  build_max_heap(array, length);

  heap_size = length;
  for (i = length - 1; i > 0; i--)
    {
      swap(array, 0, i);
      heap_size--;
      max_heapify(array, heap_size, 0);
    }
}

/* will go from 0 to upper_limit (inclusive) */
void counting_sort(int array[], int* out, int length, int upper_limit)
{
  int i;
  int* occ;

  occ = malloc((upper_limit + 1) * sizeof(int));

  for (i = 0; i <= upper_limit; i++)
    {
      occ[i] = 0;
    }

  for (i = 0; i < length; i++)
    {
      occ[array[i]] = occ[array[i]] + 1;
    }
  /* occ[0] contains how many times 0 occurs in array */

  for (i = 1; i <= upper_limit; i++)
    {
      occ[i] = occ[i] + occ[i - 1];
    }
  /* occ[1] contains number of elements less than or equal to 1 in array */
  /* occ[1] then represents where 1 should be at a sorted array */

  for (i = length - 1; i > -1; i--)
    {
      out[occ[array[i]] - 1] = array[i];
      occ[array[i]] = occ[array[i]] - 1;
    }

  free(occ);
}

/* will go from 0 to upper_limit (inclusive) */
/* n: which of n digits to consider */
void counting_sort_by_nth_digit(int array[], int* out, int length, int n)
{
  int* occ;
  int i, digit;
  int upper_limit = 9;

  occ = malloc((upper_limit + 1) * sizeof(int));

  for (i = 0; i <= upper_limit; i++)
    {
      occ[i] = 0;
    }

  for (i = 0; i < length; i++)
    {
      digit = nth_digit(array[i], n, 10);
      occ[digit] = occ[digit] + 1;
    }
  /* occ[0] contains how many times 0 occurs in array */

  for (i = 1; i <= upper_limit; i++)
    {
      occ[i] = occ[i] + occ[i - 1];
    }
  /* occ[1] contains number of elements less than or equal to 1 in array */
  /* occ[1] then represents where 1 should be at a sorted array */

  for (i = length - 1; i > -1; i--)
    {
      digit = nth_digit(array[i], n, 10);
      out[occ[digit] - 1] = array[i];
      occ[digit] = occ[digit] - 1;
    }

  free(occ);
}

void radix_sort(int array[], int* out, int length, int max_decimal_place)
{
  int i, size;
  int* temp;

  size = length * sizeof(int);
  temp = malloc(size);

  memcpy(temp, array, size);

  for (i = 1; i <= max_decimal_place; i++)
    {
      counting_sort_by_nth_digit(temp, out, length, i);
      memcpy(temp, out, size);
    }

  free(temp);
}