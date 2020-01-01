#include <stack.h>

void init_stack(Stack* stk)
{
  stk->top = -1;
}

bool stack_empty(Stack* stk)
{
  if (stk->top == -1) {
      return true;
  }
  else {
      return false;
  }
}


bool stack_full(Stack* stk)
{
  if (stk->top == (MAX - 1)) {
      return true;
  }
  else {
      return false;
  }
}


bool push(Stack* stk, Register reg)
{
  if (stack_full(stk)) {
    return false;
  }
  else {
    stk->top = stk->top + 1;
    stk->A[stk->top] = reg;
    return true;
  }
}


Register* pop(Stack* stk)
{
  if (stack_empty(stk)) {
    return NULL;
  }
  else {
    stk->top = stk->top - 1;
    return &(stk->A[stk->top + 1]); /* pointer to position */
  }
}