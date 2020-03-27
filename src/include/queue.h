/**
 * @file queue.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 2 Jan 2020
 * @brief Header file for Queue module.
 *
 * Defines the constant MAX number of elements, the struct Queue and the
 * prototypes for the routines of the Queue module.
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <register.h>
#include <stdbool.h>

#define MAX 20

typedef struct
{
  Register A[MAX];
  int head;
  int tail;
} Queue;

/** @brief Initializes Queue to have 0 elements.
 *
 * Sets the attribute head and tail to 0. Existing elements are ignored.
 *
 * @param q Pointer to Queue
 * @return Void
 */
void init_queue(Queue* q);

/** @brief Checks whether the queue is empty.
 *
 * If any element has been added to the queue returns true. If no element has
 * been added or the queue has just been initialized returns false.
 *
 * @param q Pointer to Queue
 * @return Whether queue is empty
 */
bool queue_empty(Queue* q);

/** @brief Checks whether the queue is full.
 *
 * If all available positions are occupied returns true. A queue can
 * hold n - 1 elements, so if MAX - 1 elements have been enqueued the queue is
 * full. If there's at least one available position besides the one reserved
 * to the tail or the queue has just been initialized returns false.
 *
 * @param q Queue as a pointer
 * @return Whether queue is empty
 */
bool queue_full(Queue* q);

/** @brief Adds element to tail of queue.
 *
 * If there's an available position plus the position reserved for the tail of
 * the queue adds element to tail of queue and returns true. Else doesn't
 * change queue and returns false.
 *
 * @param q Queue as a pointer
 * @return Whether element could be enqueued
 */
bool enqueue(Queue* q, Register reg);

/** @brief Removes head of queue and returns it.
 *
 * If there's at least one element in queue removes head of queue, puts its
 * value into given pointer and returns true. Otherwise doesn't update pointer
 * and returns false.
 *
 * @param q Queue as a pointer
 * @param removed Pointer to hold value of removed element
 * @return Whether an element could be dequeued
 */
bool dequeue(Queue* q, Register* removed);

#endif
