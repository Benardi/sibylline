/**
 * @file stack.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 1 Jan 2020
 * @brief Header file for Stack module.
 *
 * Defines the constant MAX number of elements, the struct Stack and the
 * prototypes for the subroutines of the Stack module.
 */
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
/* #include <register.h>
 */
typedef struct
{
  void* key;
  void* data;
} Register;

#define MAX 20

typedef struct
{
  Register A[MAX];
  int top;
} Stack;

/** @brief Initializes Stack to have 0 elements.
 *
 * Sets the attribute top to -1. Existing elements are ignored.
 *
 * @param stk Pointer to Stack
 * @return Void
 */
void init_stack(Stack* stk);

/** @brief Checks whether the stack is empty.
 *
 * If any element has been added to the stack returns true. If no element has
 * been added or the stack has just been initialized returns false.
 *
 * @param stk Pointer to Stack
 * @return Whether stack is empty
 */
bool stack_empty(Stack* stk);

/** @brief Checks whether the stack is full.
 *
 * If all available positions are occupied returns true. If there's at least
 * one available position or the stack has just been initialized returns
 * false.
 *
 * @param stk Pointer to Stack
 * @return Whether stack is empty
 */
bool stack_full(Stack* stk);

/** @brief Pushes element on top of stack.
 *
 * If there's an available position pushes element on top of stack and returns
 * true. Else does not change stack and returns false.
 *
 * @param stk Pointer to Stack
 * @return Whether element could be pushed
 */
bool push(Stack* stk, Register reg);

/** @brief Removes element from stack and returns it.
 *
 * If there's at least one element in stack removes it, puts its value into
 * given pointer and returns true. Otherwise doesn't update pointer and
 * returns false.
 *
 * @param stk Pointer to Stack
 * @param removed Pointer to hold value of removed element
 * @return Whether an element could be popped
 */
bool pop(Stack* stk, Register* removed);

#endif
