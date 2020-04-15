#ifndef GRAPH_H
#define GRAPH_H

#include <dll.h>
#include <limits.h>
#include <stddef.h>

#define INF INT_MAX

typedef enum NodeColor
{
  WHITE = 0, GRAY = 1, BLACK = 2
} NodeColor;

typedef struct ColoredNode
{
  int id;
  int dist;
  NodeColor color;
  struct ColoredNode* p;
} ColoredNode;

typedef struct TimedNode
{
  int id;
  int d_time;
  int f_time;
  NodeColor color;
  struct TimedNode* p;
} TimedNode;

void bfs(DoublyLinkedList*** adj_list, ColoredNode* vertices[], int length, ColoredNode* root);
void dfs(DoublyLinkedList*** adj_list, TimedNode* vrtxs[], int length);
void dfs_visit(DoublyLinkedList*** adj_list, TimedNode* vrtxs[], int length, TimedNode* start_vrtx, int* time);

#endif
