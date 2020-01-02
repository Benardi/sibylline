#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 20

typedef int Key;

typedef struct
{
  Key key;  /* Key that maps the register */
} Register;

typedef struct 
{
    Register A[MAX];
    int head;
    int tail;
} Queue;

void init_queue(Queue *q);
bool enqueue(Queue* q, Register reg);
bool dequeue(Queue *q);
#endif