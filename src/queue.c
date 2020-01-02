#include <queue.h>

void init_queue(Queue *q)
{
  q->head = 0;
  q->tail = 0;
}

bool enqueue(Queue *q, Register reg)
{
  q->A[q->tail] = reg;

  if (q->tail == (MAX - 1))
  {
    q->tail = 0;
  }
  else
  {
    q->tail++;
  }
  return true;
}

bool dequeue(Queue *q)
{
  Register removed;
  removed = q->A[q->head];
  if (q->head == (MAX - 1))
  {
    q->head = 0;
  }
  else
  {
    q->head++;
  }
}