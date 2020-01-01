#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#define MAX 20

typedef int Key;

typedef struct
{
  Key key;  /* Key that maps the register */
} Register;

typedef struct
{
    Register A[MAX];
    int top;
} Stack;

void init_stack(Stack* stk);
bool stack_empty(Stack* stk);
bool stack_full(Stack* stk);
bool push(Stack* stk, Register reg);
Register* pop(Stack* stk);

#endif /* STACK_H */