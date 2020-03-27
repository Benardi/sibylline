#include <seq_list.h>
#include <stdio.h>

void init_seq_list(SeqList* sl)
{
  sl->nElem = 0;
}

void reinit_seq_list(SeqList* sl)
{
  sl->nElem = 0;
}

int size(SeqList* sl)
{
  return sl->nElem;
}

int seq_search(SeqList* sl, void* key, int (*compare)(void*, void*))
{
  int i = 0;
  while (i < sl->nElem)
    {
      if (compare(key, sl->A[i].key) == 0)
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
  sl->A[sl->nElem].key = k;

  while (compare(sl->A[i].key, k) != 0)
    {
      i++;
    }
  if (i == sl->nElem)
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

  if (sl->nElem >= MAX)
    {
      return false;
    }

  pos = sl->nElem;

  while (pos > 0 && compare(sl->A[pos - 1].key, reg.key) == 1)
    {
      sl->A[pos] = sl->A[pos - 1];
      pos--;
    }

  sl->A[pos] = reg;
  sl->nElem++;

  return true;
}

int binary_search(SeqList* sl, void* k, int (*compare)(void*, void*))
{
  int left, right, middle;
  left = 0;
  right = sl->nElem - 1;

  while (left <= right)
    {
      middle = (left + right) / 2;
      if (compare(sl->A[middle].key, k) == 0)
        {
          return middle;
        }
      else
        {
          if (compare(sl->A[middle].key, k) == -1)
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
  if (sl->nElem == MAX || i < 0 || i > sl->nElem)
    {
      return false;
    }
  else
    {
      for (j = sl->nElem; j > i; j--)
        {
          sl->A[j] = sl->A[j - 1];
        }
      sl->A[i] = reg;
      sl->nElem++;
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
      for (j = pos; j < sl->nElem - 1; j++)
        {
          sl->A[j] = sl->A[j + 1];
        }
      sl->nElem--;
      return true;
    }
}

void show_list(SeqList* sl)
{
  int i;
  printf("List: \"");

  for (i = 0; i < sl->nElem - 1; i++)
    printf("%i ", *((int*)sl->A[i].key));

  /* Last element isn't followed by blank space */
  printf("%i", *((int*)sl->A[sl->nElem - 1].key));
  printf("\"\n");
}
