#include <queue.h>

void init_queue(Queue* q)
{
  q->head = 0;
  q->tail = 0;
}

bool queue_empty(Queue* q)
{
  return q->head == q->tail;
}

bool queue_full(Queue* q)
{
  return q->head == ((q->tail + 1) % (MAX));
}

bool enqueue(Queue* q, Register reg)
{
  if (queue_full(q)) {
    return false;
  }
  else {
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
}

bool dequeue(Queue* q, Register* removed)
{
  if (queue_empty(q))
  {
    return false;
  }
  else
  {
    *removed = q->A[q->head];
    if (q->head == (MAX - 1))
    {
      q->head = 0;
    }
    else
    {
      q->head++;
    }
    return true;
  }
}