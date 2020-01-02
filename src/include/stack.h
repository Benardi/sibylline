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

/** @brief Initializes Stack to have 0 elements.
 *
 *  Sets the attribute top to -1. Existing elements are
 *  ignored.
 *
 *  @param pointer Stack to be initialized
 *  @return Void
 */
void init_stack(Stack* stk);

/** @brief Checks whether the stack is empty. 
 *
 *  If any element has been added to the stack 
 *  returns true. If no element has been added 
 *  or the stack has just been initialized returns
 *  false. 
 *
 *  @param stk Stack as a pointer 
 *  @return Whether stack is empty
 */
bool stack_empty(Stack* stk);

/** @brief Checks whether the stack is full. 
 *
 *  If all available positions are occupied returns
 *  true. If there's at least one available position 
 *  or the stack has just been initialized returns
 *  false. 
 *
 *  @param stk Stack as a pointer 
 *  @return Whether stack is empty
 */
bool stack_full(Stack* stk);

/** @brief Pushes element on top of stack. 
 *
 *  If there's an available position pushes 
 *  element on top of stack and returns true.
 *  Else does not change stack and returns false. 
 *
 *  @param stk Stack as a pointer 
 *  @return Whether element could be pushed
 */
bool push(Stack* stk, Register reg);

/** @brief Removes element from stack and returns it. 
 *
 *  If there's at least one element in stack removes it,
 *  puts its value into given point and returns true.
 *  Otherwise doesn't update pointer and returns false. 
 *
 *  @param stk Stack as a pointer 
 *  @param removed pointer to hold value of removed element
 *  @return Whether an element could be popped
 */
bool pop(Stack* stk, Register* removed);

#endif /* STACK_H */