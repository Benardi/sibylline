#include <array_list.h>
#include <malloc.h>

void init_list(ArrayList* list, int capacity)
{
  list->size = 0;
  list->capacity = capacity;
  list->array = malloc(capacity * sizeof(Register));
}

void insert(ArrayList* list, Register element)
{
  Register* new_array;
  Register* old_array;
  int i;

  if (list->size == list->capacity)
    {
      old_array = list->array;
      new_array = malloc(2 * list->capacity * sizeof(Register));

      for (i = 0; i < list->capacity; i++)
        {
          new_array[i] = old_array[i];
        }
      list->array = new_array;
      list->capacity = 2 * list->capacity;
      free(old_array);
    }

  list->array[list->size] = element;
  list->size = list->size + 1;
}
bool set(ArrayList* list, Register element, int position)
{
  bool result;
  if ((position > -1) && (position < list->capacity))
    {
      list->array[position] = element;
      result = true;
    }
  else
    {
      result = false;
    }
  return result;
}

Register* get(ArrayList* list, int position)
{
  Register* target;
  if ((position > -1) && (position < list->capacity))
    {
      target = &(list->array[position]);
    }
  else
    {
      target = NULL;
    }
  return target;
}

bool contains(ArrayList* list, void* identifier,
              int (*compare_to)(void*, void*))
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

int index_of(ArrayList* list, void* identifier, int (*compare_to)(void*, void*))
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
