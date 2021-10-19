/**
 * @file graph.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 15 Apr 2020
 * @brief Header file for Graph module.
 *
 * Defines the prototypes for the routines of the Graph module.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <dll.h>
#include <limits.h>
#include <stddef.h>

#define INF INT_MAX

typedef enum NodeColor
{
  WHITE = 0,
  GRAY = 1,
  BLACK = 2
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

typedef struct WeightedNode
{
  int id;
  int dist;
  int weight;
  struct WeightedNode* p;
} WeightedNode;

typedef struct WeightedEdge
{
  int weight;
  struct WeightedNode* node;
} WeightedEdge;

/** @brief Applies Breadth First Search on given graph.
 *
 * Applies Breadth First Search on given graph. Graph is provided in the
 * form of adjanceny list. Adjacency list is an array containing a Doubly
 * Linked List (its head) at each index. The nth linked list (at nth index)
 * keeps the vertices adjacent to the the nth vertex. The BFS algorithm
 * colors nodes to keep track of the visited ones. Nodes that are not reached
 * from root node are kept WHITE. For each node in the graph the algorithm
 * calculates the distance to root node and its 'parent' node. A node's
 * parent is the node that links it to the root node.
 *
 * @param adj_list List contains the vertices adjacent each vertex.
 * @param vertices Array with all vertices in array.
 * @param length Number of vertices in graph.
 * @param root Vertex used as root for BFS algorithm.
 * @return Void.
 */
void bfs(DoublyLinkedList*** adj_list, ColoredNode* vertices[], int length,
         ColoredNode* root);

/** @brief Applies Depth First Search on given graph.
 *
 * Applies Depth First Search on given graph. Graph is provided in the
 * form of adjanceny list. Adjacency list is an array containing a Doubly
 * Linked List (its head) at each index. The nth linked list (at nth index)
 * keeps the vertices adjacent to the the nth vertex. The DFS algorithm
 * colors nodes to keep track of the visited ones. For each node in the
 * graph the algorithm calculates its discovery time (iterations for it to
 * be found the distance), finish time (iterations for it and its adjacent
 * vertices to be processed) and its 'parent' node. A node's parent is the
 * node that links it to the root of its tree (DFS produces disjoint trees
 * that together make up the entire graph).
 *
 * @param adj_list List contains the vertices adjacent each vertex.
 * @param vertices Array with all vertices in array.
 * @param length Number of vertices in graph.
 * @return Void.
 */
void dfs(DoublyLinkedList*** adj_list, TimedNode* vrtxs[], int length);

void init_sgl_src(WeightedNode vrtxs[], int length, WeightedNode* root);

void relax(WeightedNode vrtxs[], int length, WeightedNode* u, WeightedNode* v);

void bellman_ford(DoublyLinkedList*** adj_list, WeightedNode vrtxs[], int length);

#endif
