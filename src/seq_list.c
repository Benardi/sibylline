#include <malloc.h>
#include <seq_list.h>
#include <stdio.h>

void init_seq_list(SeqList* sl, int max_n_elems)
{
  sl->n_elems = 0;
  sl->max_n_elems = max_n_elems;
  sl->array = malloc((max_n_elems + 1) * sizeof(Register));
}

void reinit_seq_list(SeqList* sl)
{
  sl->n_elems = 0;
}

int size(SeqList* sl)
{
  return sl->n_elems;
}

int seq_search(SeqList* sl, void* key, int (*compare)(void*, void*))
{
  int i = 0;
  while (i < sl->n_elems)
    {
      if (compare(key, sl->array[i].key) == 0)
        {
          return i;
        }
      else
        {
          i++;
        }
    }
  return -1;
}

int sentinel_search(SeqList* sl, void* k, int (*compare)(void*, void*))
{
  int i = 0;
  sl->array[sl->n_elems].key = k;

  while (compare(sl->array[i].key, k) != 0)
    {
      i++;
    }
  if (i == sl->n_elems)
    {
      return -1;
    }
  else
    {
      return i;
    }
}

bool insert_sorted(SeqList* sl, Register reg, int (*compare)(void*, void*))
{
  int pos;

  if (sl->n_elems >= sl->max_n_elems)
    {
      return false;
    }

  pos = sl->n_elems;

  while (pos > 0 && compare(sl->array[pos - 1].key, reg.key) == 1)
    {
      sl->array[pos] = sl->array[pos - 1];
      pos--;
    }

  sl->array[pos] = reg;
  sl->n_elems++;

  return true;
}

int binary_search(SeqList* sl, void* k, int (*compare)(void*, void*))
{
  int left, right, middle;
  left = 0;
  right = sl->n_elems - 1;

  while (left <= right)
    {
      middle = (left + right) / 2;
      if (compare(sl->array[middle].key, k) == 0)
        {
          return middle;
        }
      else
        {
          if (compare(sl->array[middle].key, k) == -1)
            {
              left = middle + 1;
            }
          else
            {
              right = middle - 1;
            }
        }
    }

  return -1;
}

bool insert_elem(SeqList* sl, Register reg, int i)
{
  int j;
  if (sl->n_elems == sl->max_n_elems || i < 0 || i > sl->n_elems)
    {
      return false;
    }
  else
    {
      for (j = sl->n_elems; j > i; j--)
        {
          sl->array[j] = sl->array[j - 1];
        }
      sl->array[i] = reg;
      sl->n_elems++;
      return true;
    }
}

bool remove_elem(SeqList* sl, void* key, int (*compare)(void*, void*))
{
  int pos, j;
  pos = seq_search(sl, key, compare);
  if (pos == -1)
    {
      return false;
    }
  else
    {
      for (j = pos; j < sl->n_elems - 1; j++)
        {
          sl->array[j] = sl->array[j + 1];
        }
      sl->n_elems--;
      return true;
    }
}

void show_list(SeqList* sl)
{
  int i;
  printf("List: \"");

  for (i = 0; i < sl->n_elems - 1; i++)
    printf("%i ", *((int*)sl->array[i].key));

  /* Last element isn't followed by blank space */
  printf("%i", *((int*)sl->array[sl->n_elems - 1].key));
  printf("\"\n");
}
