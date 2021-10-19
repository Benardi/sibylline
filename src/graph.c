#include <dll.h>
#include <graph.h>
#include <malloc.h>
#include <queue.h>
#include <limits.h>

#define INFINITY INT_MAX

void bfs(DoublyLinkedList*** adj_list, ColoredNode* vrtxs[], int length,
         ColoredNode* root)
{
  Queue q;
  int i, inf;
  Register* reg;
  ColoredNode* crt;
  ColoredNode* adj;
  DoublyLinkedList* node;

  inf = INF;
  reg = malloc(sizeof(Register));

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

  reg->key = root;
  enqueue(&q, *reg);

  while (queue_empty(&q) == false)
    {
      dequeue(&q, reg);
      crt = reg->key;

      node = (*adj_list[crt->id]);

      while (node != NULL)
        {
          adj = node->data.key;

          if (adj->color == WHITE)
            {
              adj->color = GRAY;
              adj->dist = crt->dist + 1;
              adj->p = crt;

              reg->key = adj;
              enqueue(&q, *reg);
            }

          node = node->next;
        }

      crt->color = BLACK;
    }

  free(reg);
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
      adj = node->data.key;

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

void init_sgl_src(WeightedNode vrtxs[], int length, WeightedNode* root)
{
  int i;

  for (i  = 0; i < length; i++)
  {
    vrtxs[i]->dist = INFINITY;
    vrtxs[i]->p = NULL;
  }
  root->dist = 0;
}

void relax(DoublyLinkedList*** adj_list, int length, WeightedNode* vrtx1,
	   WeightedNode* vrtx2, int (*compare)(void*, void*))
{
  DoublyLinkedList** head;
  DoublyLinkedList* node;
  WeightedEdge edge;

  head = adj_list[vrtx1->id];
  node = dll_search(head, (void*) vrtx2->id, compare); 

  edge = node->data.key;

  if (vrtx2->dist > (vrtx1->dist + edge.weight))
  {
    vrtx2->dist = vrtx1->dist + edge.weight;
    vrtx2->p = vrtx1->p;   
  }

}

void bellman_ford(DoublyLinkedList*** adj_list, WeightedNode vrtxs[], int length)
{
  init_sgl_src(vrtxs, length, root);
 
}
