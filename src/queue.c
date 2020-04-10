#include <queue.h>
#include <malloc.h>

void init_queue(Queue* q, int length)
{
  q->head = 0;
  q->tail = 0;
  q->length = length;
  q->array = malloc(length * sizeof(Register)); 
}

void reinit_queue(Queue* q)
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
  return q->head == ((q->tail + 1) % (q->length));
}

bool enqueue(Queue* q, Register reg)
{
  if (queue_full(q))
    {
      return false;
    }
  else
    {
      q->array[q->tail] = reg;

      if (q->tail == (q->length - 1))
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
      *removed = q->array[q->head];
      if (q->head == (q->length - 1))
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
