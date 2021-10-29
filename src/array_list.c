#include <array_list.h>
#include <malloc.h>

void init_list(ArrayList* list, int capacity)
{
  list->size = 0;
  list->capacity = capacity;
  list->array = malloc(capacity * sizeof(Register));
}

static void increase_capacity(ArrayList* list, int factor)
{
  int i;
  Register* new_array;
  Register* old_array;

  old_array = list->array;
  new_array = malloc(factor * list->capacity * sizeof(Register));

  for (i = 0; i < list->capacity; i++)
    {
      new_array[i] = old_array[i];
    }
  list->array = new_array;
  list->capacity = factor * list->capacity;
  free(old_array);
}

void insert(ArrayList* list, Register element)
{
  if (list->size == list->capacity)
    {
      increase_capacity(list, INCREASE_FACTOR);
    }

  list->array[list->size] = element;
  list->size = list->size + 1;
}

bool insert_at(ArrayList* list, Register element, int index)
{
  bool result;

  if ((index > -1) && (index < list->capacity))
    {
      if (index < list->size)
        {
          shift_right(list, index);
        }
      list->array[index] = element;
      list->size = list->size + 1;
      result = true;
    }
  else
    {
      result = false;
    }

  return result;
}

bool set(ArrayList* list, Register element, int index)
{
  bool result;
  if ((index > -1) && (index < list->capacity))
    {
      list->array[index] = element;
      result = true;
    }
  else
    {
      result = false;
    }
  return result;
}

Register* get(ArrayList* list, int index)
{
  Register* target;
  if ((index > -1) && (index < list->capacity))
    {
      target = &(list->array[index]);
    }
  else
    {
      target = NULL;
    }
  return target;
}

bool contains(ArrayList* list, union Key identifier,
              int (*compare_to)(union Key, union Key))
{
  int i;
  bool result = false;

  for (i = 0; i < list->size; i++)
    {
      if (compare_to(list->array[i].key, identifier) == true)
        {
          result = true;
          break;
        }
    }
  return result;
}

bool shift_left(ArrayList* list, int index)
{
  int i;
  bool result;

  if ((index < 0) || (index >= list->size))
    {
      result = false;
    }
  else
    {
      for (i = index; i < list->size - 1; i++)
        {
          list->array[i] = list->array[i + 1];
        }
      result = true;
    }

  return result;
}

void shift_right(ArrayList* list, int index)
{
  int i;

  if (list->size == list->capacity)
    {
      increase_capacity(list, INCREASE_FACTOR);
    }

  for (i = list->size - 1; i >= index; i--)
    {
      list->array[i + 1] = list->array[i];
    }
}

bool discard(ArrayList* list, int index)
{
  bool result = true;

  if (index == list->size - 1)
    {
      list->size = list->size - 1;
    }
  else if ((index >= 0) && (index < list->size - 2))
    {
      shift_left(list, index);
      list->size = list->size - 1;
    }
  else
    {
      result = false;
    }

  return result;
}

int index_of(ArrayList* list, union Key identifier,
             int (*compare_to)(union Key, union Key))
{
  int index = -1;
  int i;

  for (i = 0; i < list->size; i++)
    {
      if (compare_to(list->array[i].key, identifier) == true)
        {
          index = i;
          break;
        }
    }
  return index;
}
