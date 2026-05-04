#include <dll.h>
#include <graph.h>
#include <queue.h>
#include <stdlib.h>

void bfs(DoublyLinkedList*** adj_list, ColoredNode* vrtxs[], int length,
         ColoredNode* root)
{
  Queue q;
  int i, inf;
  Item* item;
  ColoredNode* crt;
  ColoredNode* adj;
  DoublyLinkedList* node;

  inf = INF;
  item = malloc(sizeof(Item));

  for (i = 0; i < length; i++)
    {
      if (vrtxs[i] != root)
        {
          vrtxs[i]->color = WHITE;
          vrtxs[i]->dist = inf;
          vrtxs[i]->p = NULL;
        }
    }

  root->color = GRAY;
  root->dist = 0;
  root->p = NULL;

  init_queue(&q, length + 1);

  item->value = root;
  enqueue(&q, *item);

  while (queue_empty(&q) == false)
    {
      dequeue(&q, item);
      crt = item->value;

      node = (*adj_list[crt->id]);

      while (node != NULL)
        {
          adj = node->data.value;

          if (adj->color == WHITE)
            {
              adj->color = GRAY;
              adj->dist = crt->dist + 1;
              adj->p = crt;

              item->value = adj;
              enqueue(&q, *item);
            }

          node = node->next;
        }

      crt->color = BLACK;
    }

  free(item);
  free(q.array);
}

static void dfs_visit(DoublyLinkedList*** adj_list, TimedNode* vrtxs[],
                      int length, TimedNode* start_vrtx, int* time)
{
  TimedNode* adj;
  DoublyLinkedList* node;

  *time = *time + 1;
  start_vrtx->d_time = *time;
  start_vrtx->color = GRAY;

  node = *(adj_list[start_vrtx->id]);

  while (node != NULL)
    {
      adj = node->data.value;

      if (adj->color == WHITE)
        {
          adj->p = start_vrtx;
          dfs_visit(adj_list, vrtxs, length, adj, time);
        }

      node = node->next;
    }

  start_vrtx->color = BLACK;
  *time = *time + 1;
  start_vrtx->f_time = *time;
}

void dfs(DoublyLinkedList*** adj_list, TimedNode* vrtxs[], int length)
{
  int i;
  int time;

  for (i = 0; i < length; i++)
    {
      vrtxs[i]->color = WHITE;
      vrtxs[i]->p = NULL;
    }

  time = 0;

  for (i = 0; i < length; i++)
    {
      if (vrtxs[i]->color == WHITE)
        {
          dfs_visit(adj_list, vrtxs, length, vrtxs[i], &time);
        }
    }
}
