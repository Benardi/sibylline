#include <str_builder.h>

bool init_str_builder(StringBuilder* str_bldr, int capacity)
{
  bool result = false;

  if (capacity > 0)
    {
      result = true;
      str_bldr->size = 0;
      str_bldr->capacity = capacity;

      str_bldr->array = malloc(capacity * sizeof(char));
      str_bldr->array[0] = '\0';
    }

  return result;
}

static void expand_array(StringBuilder* str_bldr, int increase_factor)
{
  char* new_array;
  char* old_array;

  old_array = str_bldr->array;
  new_array = malloc(str_bldr->capacity * increase_factor * sizeof(char));

  /* +1 to include null byte */
  memmove(new_array, str_bldr->array, str_bldr->size + 1);
  str_bldr->array = new_array;
  str_bldr->capacity = str_bldr->capacity * increase_factor;
  free(old_array);
}

void append_str(StringBuilder* str_bldr, char str[])
{
  int length = strlen(str);

  /* We add 1 to acknowledge the null byte */
  while ((str_bldr->size + length + 1) > str_bldr->capacity)
    {
      expand_array(str_bldr, STR_BUILDER_INCREASE_FACTOR);
    }

  str_bldr->size = str_bldr->size + strlen(str);
  strcat(str_bldr->array, str);
}

bool del_str(StringBuilder* str_bldr, char target[])
{
  char* tail;
  char* to_delete;
  bool result = false;
  int length = strlen(target);

  to_delete = strstr(str_bldr->array, target);
  if (to_delete != NULL)
    {
      result = true;
      str_bldr->size = str_bldr->size - length;
      tail = to_delete + length;
      /* +1 to include null byte */
      memmove(to_delete, tail, strlen(tail) + 1);
    }

  return result;
}

void ensure_capacity(StringBuilder* str_bldr, int capacity)
{
  char* new_array;
  char* old_array;

  if (capacity > str_bldr->capacity)
    {
      old_array = str_bldr->array;
      new_array = malloc(capacity * sizeof(char));

      /* +1 to include null byte */
      memmove(new_array, str_bldr->array, str_bldr->size + 1);
      str_bldr->array = new_array;
      str_bldr->capacity = capacity;
      free(old_array);
    }
}

bool insert_str(StringBuilder* str_bldr, int index, char str[])
{
  char* tail; /* What's after index */
  char* new_array;
  char* old_array;
  bool success = false;
  int length = strlen(str);

  if ((index > -1) && (index <= str_bldr->size))
    {
      /* We add 1 to acknowledge the null byte */
      while ((str_bldr->size + length + 1) > str_bldr->capacity)
        {
          expand_array(str_bldr, STR_BUILDER_INCREASE_FACTOR);
        }

      new_array = malloc(str_bldr->capacity * sizeof(char));

      /* Copy over right until before index */
      strncpy(new_array, str_bldr->array, index);
      new_array[index] = '\0';

      strcat(new_array, str);

      tail = str_bldr->array;
      tail = tail + index;
      strcat(new_array, tail);

      str_bldr->size = str_bldr->size + length;

      old_array = str_bldr->array;
      str_bldr->array = new_array;
      free(old_array);
      success = true;
    }

  return success;
}

bool del_str_range(StringBuilder* str_bldr, int start, int end)
{
  char* tail;
  char* new_array;
  char* old_array;
  bool result = false;

  if ((start > -1) && (end < str_bldr->size) && (end >= start))
    {
      new_array = malloc(str_bldr->capacity * sizeof(char));
      /* Copy over right until before index */
      strncpy(new_array, str_bldr->array, start);

      tail = str_bldr->array + end + 1;
      new_array[start] = '\0';
      strcat(new_array, tail);

      str_bldr->size = str_bldr->size - (1 + end - start);
      old_array = str_bldr->array;
      str_bldr->array = new_array;
      free(old_array);

      result = true;
    }

  return result;
}

bool replace_str(StringBuilder* str_bldr, int start, int end, char str[])
{
  char* tail;
  char* new_array;
  char* old_array;
  bool result = false;
  int length = strlen(str);

  if ((start > -1) && (end < str_bldr->size) && (end >= start))
    {
      /* We add 1 to acknowledge the null byte */
      while ((str_bldr->size + length + 1) > str_bldr->capacity)
        {
          expand_array(str_bldr, STR_BUILDER_INCREASE_FACTOR);
        }

      new_array = malloc(str_bldr->capacity * sizeof(char));
      /* Copy over right until before index */
      strncpy(new_array, str_bldr->array, start);

      tail = str_bldr->array + end + 1;
      new_array[start] = '\0';
      strcat(new_array, str);
      strcat(new_array, tail);

      str_bldr->size = str_bldr->size + length - (1 + end - start);
      old_array = str_bldr->array;
      str_bldr->array = new_array;
      free(old_array);

      result = true;
    }

  return result;
}
