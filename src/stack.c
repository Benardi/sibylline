#include <stack.h>
#include <stdlib.h>

void init_stack(Stack* stk, int length)
{
  stk->top = -1;
  stk->length = length;
  stk->array = malloc(stk->length * sizeof(Item));
}

void reinit_stack(Stack* stk)
{
  stk->top = -1;
}

bool stack_empty(Stack* stk)
{
  if (stk->top == -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool stack_full(Stack* stk)
{
  if (stk->top == (stk->length - 1))
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool push(Stack* stk, Item item)
{
  if (stack_full(stk))
    {
      return false;
    }
  else
    {
      stk->top = stk->top + 1;
      stk->array[stk->top] = item;
      return true;
    }
}

bool pop(Stack* stk, Item* removed)
{
  if (stack_empty(stk))
    {
      return false;
    }
  else
    {
      stk->top = stk->top - 1;
      *removed = stk->array[stk->top + 1];
      return true;
    }
}
