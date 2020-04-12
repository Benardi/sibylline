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
  NodeColor color;
  int dist;
  struct ColoredNode* p;
} ColoredNode;

void bfs(DoublyLinkedList*** adj_list, ColoredNode* vertices[], int length, ColoredNode* root);

#endif
