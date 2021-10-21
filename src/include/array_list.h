#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <register.h>
#include <stdbool.h>

typedef struct
{
  int size;
  int capacity;
  Register* array;
} ArrayList;

void init_list(ArrayList* list, int capacity);
void insert(ArrayList* list, Register element);
bool set(ArrayList* list, Register element, int position);
Register* get(ArrayList* list, int position);
bool contains(ArrayList* list, void* identifier,
              int (*compare_to)(void*, void*));
bool shift_left(ArrayList* list, int index);
bool discard(ArrayList* list, int index);
int index_of(ArrayList* list, void* identifier,
             int (*compare_to)(void*, void*));

#endif
