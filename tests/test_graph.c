#include <assert.h>
#include <check.h>
#include <dll.h>
#include <graph.h>
#include <limits.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

Suite* make_test_suite(void);

START_TEST(test_build_adj_list_1)
{
  int i, length;
  union Key k0, k1, k2, k3, k4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  k0.i = 0;
  k1.i = 1;
  k2.i = 2;
  k3.i = 3;
  k4.i = 4;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = k4;
  dll_insert(adj_list[0], reg);
  reg.key = k1;
  dll_insert(adj_list[0], reg);

  reg.key = k3;
  dll_insert(adj_list[1], reg);
  reg.key = k2;
  dll_insert(adj_list[1], reg);
  reg.key = k4;
  dll_insert(adj_list[1], reg);
  reg.key = k0;
  dll_insert(adj_list[1], reg);

  reg.key = k3;
  dll_insert(adj_list[2], reg);
  reg.key = k1;
  dll_insert(adj_list[2], reg);

  reg.key = k2;
  dll_insert(adj_list[3], reg);
  reg.key = k4;
  dll_insert(adj_list[3], reg);
  reg.key = k1;
  dll_insert(adj_list[3], reg);

  reg.key = k1;
  dll_insert(adj_list[4], reg);
  reg.key = k0;
  dll_insert(adj_list[4], reg);
  reg.key = k3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq((*adj_list[0])->data.key.i, 1);
  ck_assert_int_eq((*adj_list[0])->next->data.key.i, 4);

  ck_assert_int_eq((*adj_list[1])->data.key.i, 0);
  ck_assert_int_eq((*adj_list[1])->next->data.key.i, 4);
  ck_assert_int_eq((*adj_list[1])->next->next->data.key.i, 2);
  ck_assert_int_eq((*adj_list[1])->next->next->next->data.key.i, 3);

  ck_assert_int_eq((*adj_list[2])->data.key.i, 1);
  ck_assert_int_eq((*adj_list[2])->next->data.key.i, 3);

  ck_assert_int_eq((*adj_list[3])->data.key.i, 1);
  ck_assert_int_eq((*adj_list[3])->next->data.key.i, 4);
  ck_assert_int_eq((*adj_list[3])->next->next->data.key.i, 2);

  ck_assert_int_eq((*adj_list[4])->data.key.i, 3);
  ck_assert_int_eq((*adj_list[4])->next->data.key.i, 0);
  ck_assert_int_eq((*adj_list[4])->next->next->data.key.i, 1);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(adj_list);
}
END_TEST

START_TEST(test_build_adj_list_2)
{
  int i, length;
  union Key k1, k3, k4, k5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  k1.i = 1;
  k3.i = 3;
  k4.i = 4;
  k5.i = 5;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = k3;
  dll_insert(adj_list[0], reg);
  reg.key = k1;
  dll_insert(adj_list[0], reg);

  reg.key = k4;
  dll_insert(adj_list[1], reg);

  reg.key = k4;
  dll_insert(adj_list[2], reg);
  reg.key = k5;
  dll_insert(adj_list[2], reg);

  reg.key = k1;
  dll_insert(adj_list[3], reg);

  reg.key = k3;
  dll_insert(adj_list[4], reg);

  reg.key = k5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq((*adj_list[0])->data.key.i, 1);
  ck_assert_int_eq((*adj_list[0])->next->data.key.i, 3);

  ck_assert_int_eq((*adj_list[1])->data.key.i, 4);

  ck_assert_int_eq((*adj_list[2])->data.key.i, 5);
  ck_assert_int_eq((*adj_list[2])->next->data.key.i, 4);

  ck_assert_int_eq((*adj_list[3])->data.key.i, 1);

  ck_assert_int_eq((*adj_list[4])->data.key.i, 3);

  ck_assert_int_eq((*adj_list[5])->data.key.i, 5);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(adj_list);
}
END_TEST

START_TEST(test_build_adj_list_3)
{
  int i, length;
  ColoredNode node1, node3, node4, node5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  node1.id = 1;
  node1.color = WHITE;
  node3.id = 3;
  node3.color = GRAY;
  node4.id = 4;
  node4.color = BLACK;
  node5.id = 5;
  node5.color = WHITE;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node3;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);

  reg.value = &node4;
  dll_insert(adj_list[2], reg);
  reg.value = &node5;
  dll_insert(adj_list[2], reg);

  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node3;
  dll_insert(adj_list[4], reg);

  reg.value = &node5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.value)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.value)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->data.value)->id, 5);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(adj_list);
}
END_TEST

START_TEST(test_build_adj_mtx_1)
{
  int row = 5;
  int col = 5;

  int* adj_mtx = malloc(row * col * sizeof(int));

  adj_mtx[row * 0 + 0] = 0;
  adj_mtx[row * 0 + 1] = 1;
  adj_mtx[row * 0 + 2] = 0;
  adj_mtx[row * 0 + 3] = 0;
  adj_mtx[row * 0 + 4] = 1;

  adj_mtx[row * 1 + 0] = 1;
  adj_mtx[row * 1 + 1] = 0;
  adj_mtx[row * 1 + 2] = 1;
  adj_mtx[row * 1 + 3] = 1;
  adj_mtx[row * 1 + 4] = 1;

  adj_mtx[row * 2 + 0] = 0;
  adj_mtx[row * 2 + 1] = 1;
  adj_mtx[row * 2 + 2] = 0;
  adj_mtx[row * 2 + 3] = 1;
  adj_mtx[row * 2 + 4] = 0;

  adj_mtx[row * 3 + 0] = 0;
  adj_mtx[row * 3 + 1] = 1;
  adj_mtx[row * 3 + 2] = 1;
  adj_mtx[row * 3 + 3] = 0;
  adj_mtx[row * 3 + 4] = 1;

  adj_mtx[row * 4 + 0] = 1;
  adj_mtx[row * 4 + 1] = 1;
  adj_mtx[row * 4 + 2] = 0;
  adj_mtx[row * 4 + 3] = 1;
  adj_mtx[row * 4 + 4] = 0;

  ck_assert_int_eq(adj_mtx[row * 0 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 0 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 4], 1);

  ck_assert_int_eq(adj_mtx[row * 1 + 0], 1);
  ck_assert_int_eq(adj_mtx[row * 1 + 1], 0);
  ck_assert_int_eq(adj_mtx[row * 1 + 2], 1);
  ck_assert_int_eq(adj_mtx[row * 1 + 3], 1);
  ck_assert_int_eq(adj_mtx[row * 1 + 4], 1);

  ck_assert_int_eq(adj_mtx[row * 2 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 2 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 3], 1);
  ck_assert_int_eq(adj_mtx[row * 2 + 4], 0);

  ck_assert_int_eq(adj_mtx[row * 3 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 3 + 2], 1);
  ck_assert_int_eq(adj_mtx[row * 3 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 4], 1);

  ck_assert_int_eq(adj_mtx[row * 4 + 0], 1);
  ck_assert_int_eq(adj_mtx[row * 4 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 4 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 4 + 3], 1);
  ck_assert_int_eq(adj_mtx[row * 4 + 4], 0);

  free(adj_mtx);
}
END_TEST

START_TEST(test_build_adj_mtx_2)
{
  int row = 6;
  int col = 6;

  int* adj_mtx = malloc(row * col * sizeof(int));

  adj_mtx[row * 0 + 0] = 0;
  adj_mtx[row * 0 + 1] = 1;
  adj_mtx[row * 0 + 2] = 0;
  adj_mtx[row * 0 + 3] = 1;
  adj_mtx[row * 0 + 4] = 0;
  adj_mtx[row * 0 + 5] = 0;

  adj_mtx[row * 1 + 0] = 0;
  adj_mtx[row * 1 + 1] = 0;
  adj_mtx[row * 1 + 2] = 0;
  adj_mtx[row * 1 + 3] = 0;
  adj_mtx[row * 1 + 4] = 1;
  adj_mtx[row * 1 + 5] = 0;

  adj_mtx[row * 2 + 0] = 0;
  adj_mtx[row * 2 + 1] = 0;
  adj_mtx[row * 2 + 2] = 0;
  adj_mtx[row * 2 + 3] = 0;
  adj_mtx[row * 2 + 4] = 1;
  adj_mtx[row * 2 + 5] = 1;

  adj_mtx[row * 3 + 0] = 0;
  adj_mtx[row * 3 + 1] = 1;
  adj_mtx[row * 3 + 2] = 0;
  adj_mtx[row * 3 + 3] = 0;
  adj_mtx[row * 3 + 4] = 0;
  adj_mtx[row * 3 + 5] = 0;

  adj_mtx[row * 4 + 0] = 0;
  adj_mtx[row * 4 + 1] = 0;
  adj_mtx[row * 4 + 2] = 0;
  adj_mtx[row * 4 + 3] = 1;
  adj_mtx[row * 4 + 4] = 0;
  adj_mtx[row * 4 + 5] = 0;

  adj_mtx[row * 5 + 0] = 0;
  adj_mtx[row * 5 + 1] = 0;
  adj_mtx[row * 5 + 2] = 0;
  adj_mtx[row * 5 + 3] = 0;
  adj_mtx[row * 5 + 4] = 0;
  adj_mtx[row * 5 + 5] = 1;

  ck_assert_int_eq(adj_mtx[row * 0 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 0 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 3], 1);
  ck_assert_int_eq(adj_mtx[row * 0 + 4], 0);
  ck_assert_int_eq(adj_mtx[row * 0 + 5], 0);

  ck_assert_int_eq(adj_mtx[row * 1 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 1 + 1], 0);
  ck_assert_int_eq(adj_mtx[row * 1 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 1 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 1 + 4], 1);
  ck_assert_int_eq(adj_mtx[row * 1 + 5], 0);

  ck_assert_int_eq(adj_mtx[row * 2 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 1], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 2 + 4], 1);
  ck_assert_int_eq(adj_mtx[row * 2 + 5], 1);

  ck_assert_int_eq(adj_mtx[row * 3 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 1], 1);
  ck_assert_int_eq(adj_mtx[row * 3 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 4], 0);
  ck_assert_int_eq(adj_mtx[row * 3 + 5], 0);

  ck_assert_int_eq(adj_mtx[row * 4 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 4 + 1], 0);
  ck_assert_int_eq(adj_mtx[row * 4 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 4 + 3], 1);
  ck_assert_int_eq(adj_mtx[row * 4 + 4], 0);
  ck_assert_int_eq(adj_mtx[row * 4 + 5], 0);

  ck_assert_int_eq(adj_mtx[row * 5 + 0], 0);
  ck_assert_int_eq(adj_mtx[row * 5 + 1], 0);
  ck_assert_int_eq(adj_mtx[row * 5 + 2], 0);
  ck_assert_int_eq(adj_mtx[row * 5 + 3], 0);
  ck_assert_int_eq(adj_mtx[row * 5 + 4], 0);
  ck_assert_int_eq(adj_mtx[row * 5 + 5], 1);

  free(adj_mtx);
}
END_TEST

START_TEST(test_bfs_1)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0, node1, node2, node3, node4, node5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;
  node5.id = 5;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;
  vrtxs[5] = &node5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node3;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);

  reg.value = &node4;
  dll_insert(adj_list[2], reg);
  reg.value = &node5;
  dll_insert(adj_list[2], reg);

  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node3;
  dll_insert(adj_list[4], reg);

  reg.value = &node5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.value)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.value)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.value)->id, 3);

  bfs(adj_list, vrtxs, length, &node2);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);
  ck_assert_int_eq(node5.id, 5);

  ck_assert_int_eq(node0.color, WHITE);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);
  ck_assert_int_eq(node5.color, BLACK);

  ck_assert_int_eq(node0.dist, INF);
  ck_assert_int_eq(node1.dist, 3);
  ck_assert_int_eq(node2.dist, 0);
  ck_assert_int_eq(node3.dist, 2);
  ck_assert_int_eq(node4.dist, 1);
  ck_assert_int_eq(node5.dist, 1);

  ck_assert_ptr_eq(node0.p, NULL);
  ck_assert_ptr_eq(node1.p, &node3);
  ck_assert_ptr_eq(node2.p, NULL);
  ck_assert_ptr_eq(node3.p, &node4);
  ck_assert_ptr_eq(node4.p, &node2);
  ck_assert_ptr_eq(node5.p, &node2);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_bfs_2)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0, node1, node2, node3, node4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node4;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node3;
  dll_insert(adj_list[1], reg);
  reg.value = &node2;
  dll_insert(adj_list[1], reg);
  reg.value = &node4;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node3;
  dll_insert(adj_list[2], reg);
  reg.value = &node1;
  dll_insert(adj_list[2], reg);

  reg.value = &node2;
  dll_insert(adj_list[3], reg);
  reg.value = &node4;
  dll_insert(adj_list[3], reg);
  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node1;
  dll_insert(adj_list[4], reg);
  reg.value = &node0;
  dll_insert(adj_list[4], reg);
  reg.value = &node3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.value)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.value)->id, 4);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->next->data.value)->id,
                   2);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[1])->next->next->next->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.value)->id, 4);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.value)->id,
                   2);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.value)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->data.value)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->next->data.value)->id,
                   1);

  bfs(adj_list, vrtxs, length, &node0);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);

  ck_assert_int_eq(node0.dist, 0);
  ck_assert_int_eq(node1.dist, 1);
  ck_assert_int_eq(node2.dist, 2);
  ck_assert_int_eq(node3.dist, 2);
  ck_assert_int_eq(node4.dist, 1);

  ck_assert_ptr_eq(node0.p, NULL);
  ck_assert_ptr_eq(node1.p, &node0);
  ck_assert_ptr_eq(node2.p, &node1);
  ck_assert_ptr_eq(node3.p, &node1);
  ck_assert_ptr_eq(node4.p, &node0);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_bfs_3)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0, node1, node2, node3, node4, node5, node6, node7;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 8;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;
  node5.id = 5;
  node6.id = 6;
  node7.id = 7;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;
  vrtxs[5] = &node5;
  vrtxs[6] = &node6;
  vrtxs[7] = &node7;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node4;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node5;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node6;
  dll_insert(adj_list[2], reg);
  reg.value = &node5;
  dll_insert(adj_list[2], reg);
  reg.value = &node3;
  dll_insert(adj_list[2], reg);

  reg.value = &node7;
  dll_insert(adj_list[3], reg);
  reg.value = &node6;
  dll_insert(adj_list[3], reg);
  reg.value = &node2;
  dll_insert(adj_list[3], reg);

  reg.value = &node0;
  dll_insert(adj_list[4], reg);

  reg.value = &node6;
  dll_insert(adj_list[5], reg);
  reg.value = &node2;
  dll_insert(adj_list[5], reg);
  reg.value = &node1;
  dll_insert(adj_list[5], reg);

  reg.value = &node7;
  dll_insert(adj_list[6], reg);
  reg.value = &node5;
  dll_insert(adj_list[6], reg);
  reg.value = &node3;
  dll_insert(adj_list[6], reg);
  reg.value = &node2;
  dll_insert(adj_list[6], reg);

  reg.value = &node6;
  dll_insert(adj_list[7], reg);
  reg.value = &node3;
  dll_insert(adj_list[7], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.value)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.value)->id, 5);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.value)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.value)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->next->data.value)->id,
                   6);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.value)->id, 6);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.value)->id,
                   7);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.value)->id, 0);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->next->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->next->next->data.value)->id,
                   6);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->next->data.value)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->next->next->data.value)->id,
                   5);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[6])->next->next->next->data.value)->id, 7);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[7])->data.value)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[7])->next->data.value)->id, 6);

  bfs(adj_list, vrtxs, length, &node1);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);
  ck_assert_int_eq(node5.id, 5);
  ck_assert_int_eq(node6.id, 6);
  ck_assert_int_eq(node7.id, 7);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);
  ck_assert_int_eq(node5.color, BLACK);
  ck_assert_int_eq(node6.color, BLACK);
  ck_assert_int_eq(node7.color, BLACK);

  ck_assert_int_eq(node0.dist, 1);
  ck_assert_int_eq(node1.dist, 0);
  ck_assert_int_eq(node2.dist, 2);
  ck_assert_int_eq(node3.dist, 3);
  ck_assert_int_eq(node4.dist, 2);
  ck_assert_int_eq(node5.dist, 1);
  ck_assert_int_eq(node6.dist, 2);
  ck_assert_int_eq(node7.dist, 3);

  ck_assert_ptr_eq(node0.p, &node1);
  ck_assert_ptr_eq(node1.p, NULL);
  ck_assert_ptr_eq(node2.p, &node5);
  ck_assert_ptr_eq(node3.p, &node2);
  ck_assert_ptr_eq(node4.p, &node0);
  ck_assert_ptr_eq(node5.p, &node1);
  ck_assert_ptr_eq(node6.p, &node5);
  ck_assert_ptr_eq(node7.p, &node6);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_bfs_4)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0;
  DoublyLinkedList*** adj_list;

  length = 1;
  node0.id = 0;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  bfs(adj_list, vrtxs, length, &node0);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node0.dist, 0);
  ck_assert_ptr_eq(node0.p, NULL);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_bfs_5)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0, node1, node2, node3, node4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node4;
  dll_insert(adj_list[0], reg);
  reg.value = &node3;
  dll_insert(adj_list[0], reg);
  reg.value = &node2;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);
  reg.value = &node3;
  dll_insert(adj_list[1], reg);
  reg.value = &node2;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node4;
  dll_insert(adj_list[2], reg);
  reg.value = &node3;
  dll_insert(adj_list[2], reg);
  reg.value = &node1;
  dll_insert(adj_list[2], reg);
  reg.value = &node0;
  dll_insert(adj_list[2], reg);

  reg.value = &node4;
  dll_insert(adj_list[3], reg);
  reg.value = &node2;
  dll_insert(adj_list[3], reg);
  reg.value = &node1;
  dll_insert(adj_list[3], reg);
  reg.value = &node0;
  dll_insert(adj_list[3], reg);

  reg.value = &node3;
  dll_insert(adj_list[4], reg);
  reg.value = &node2;
  dll_insert(adj_list[4], reg);
  reg.value = &node1;
  dll_insert(adj_list[4], reg);
  reg.value = &node0;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->next->data.value)->id,
                   3);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[0])->next->next->next->data.value)->id, 4);

  bfs(adj_list, vrtxs, length, &node4);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);

  ck_assert_int_eq(node0.dist, 1);
  ck_assert_int_eq(node1.dist, 1);
  ck_assert_int_eq(node2.dist, 1);
  ck_assert_int_eq(node3.dist, 1);
  ck_assert_int_eq(node4.dist, 0);

  ck_assert_ptr_eq(node0.p, &node4);
  ck_assert_ptr_eq(node1.p, &node4);
  ck_assert_ptr_eq(node2.p, &node4);
  ck_assert_ptr_eq(node3.p, &node4);
  ck_assert_ptr_eq(node4.p, NULL);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_bfs_6)
{
  int i, length;
  ColoredNode** vrtxs;
  ColoredNode node0, node1, node2, node3, node4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);
  reg.value = &node3;
  dll_insert(adj_list[1], reg);
  reg.value = &node2;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node3;
  dll_insert(adj_list[2], reg);
  reg.value = &node1;
  dll_insert(adj_list[2], reg);

  reg.value = &node4;
  dll_insert(adj_list[3], reg);
  reg.value = &node2;
  dll_insert(adj_list[3], reg);
  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node3;
  dll_insert(adj_list[4], reg);
  reg.value = &node1;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.value)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.value)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->next->data.value)->id,
                   3);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[1])->next->next->next->data.value)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.value)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.value)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.value)->id,
                   4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.value)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->data.value)->id, 3);

  bfs(adj_list, vrtxs, length, &node2);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);

  ck_assert_int_eq(node0.dist, 2);
  ck_assert_int_eq(node1.dist, 1);
  ck_assert_int_eq(node2.dist, 0);
  ck_assert_int_eq(node3.dist, 1);
  ck_assert_int_eq(node4.dist, 2);

  ck_assert_ptr_eq(node0.p, &node1);
  ck_assert_ptr_eq(node1.p, &node2);
  ck_assert_ptr_eq(node2.p, NULL);
  ck_assert_ptr_eq(node3.p, &node2);
  ck_assert_ptr_eq(node4.p, &node1);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_dfs_1)
{
  int i, length;
  TimedNode** vrtxs;
  TimedNode node0, node1, node2, node3, node4, node5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;
  node5.id = 5;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;
  vrtxs[5] = &node5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node3;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);

  reg.value = &node4;
  dll_insert(adj_list[2], reg);
  reg.value = &node5;
  dll_insert(adj_list[2], reg);

  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node3;
  dll_insert(adj_list[4], reg);

  reg.value = &node5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.value)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.value)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.value)->id, 5);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.value)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.value)->id, 1);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.value)->id, 3);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);
  ck_assert_int_eq(node5.id, 5);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);
  ck_assert_int_eq(node5.color, BLACK);

  ck_assert_ptr_eq(node0.p, NULL);
  ck_assert_ptr_eq(node1.p, &node0);
  ck_assert_ptr_eq(node2.p, NULL);
  ck_assert_ptr_eq(node5.p, &node2);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_dfs_2)
{
  int i, length;
  TimedNode** vrtxs;
  TimedNode node0, node1, node2, node3, node4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node4;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node3;
  dll_insert(adj_list[1], reg);
  reg.value = &node2;
  dll_insert(adj_list[1], reg);
  reg.value = &node4;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node3;
  dll_insert(adj_list[2], reg);
  reg.value = &node1;
  dll_insert(adj_list[2], reg);

  reg.value = &node2;
  dll_insert(adj_list[3], reg);
  reg.value = &node4;
  dll_insert(adj_list[3], reg);
  reg.value = &node1;
  dll_insert(adj_list[3], reg);

  reg.value = &node1;
  dll_insert(adj_list[4], reg);
  reg.value = &node0;
  dll_insert(adj_list[4], reg);
  reg.value = &node3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.value)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.value)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->data.value)->id, 4);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->next->data.value)->id, 2);
  ck_assert_int_eq(
      ((TimedNode*)(*adj_list[1])->next->next->next->data.value)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.value)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->data.value)->id, 4);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->next->data.value)->id, 2);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.value)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->next->data.value)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->next->next->data.value)->id, 1);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_dfs_3)
{
  int i, length;
  TimedNode** vrtxs;
  TimedNode node0, node1, node2, node3, node4, node5, node6, node7;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 8;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;
  node5.id = 5;
  node6.id = 6;
  node7.id = 7;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;
  vrtxs[5] = &node5;
  vrtxs[6] = &node6;
  vrtxs[7] = &node7;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node4;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node5;
  dll_insert(adj_list[1], reg);
  reg.value = &node0;
  dll_insert(adj_list[1], reg);

  reg.value = &node6;
  dll_insert(adj_list[2], reg);
  reg.value = &node5;
  dll_insert(adj_list[2], reg);
  reg.value = &node3;
  dll_insert(adj_list[2], reg);

  reg.value = &node7;
  dll_insert(adj_list[3], reg);
  reg.value = &node6;
  dll_insert(adj_list[3], reg);
  reg.value = &node2;
  dll_insert(adj_list[3], reg);

  reg.value = &node0;
  dll_insert(adj_list[4], reg);

  reg.value = &node6;
  dll_insert(adj_list[5], reg);
  reg.value = &node2;
  dll_insert(adj_list[5], reg);
  reg.value = &node1;
  dll_insert(adj_list[5], reg);

  reg.value = &node7;
  dll_insert(adj_list[6], reg);
  reg.value = &node5;
  dll_insert(adj_list[6], reg);
  reg.value = &node3;
  dll_insert(adj_list[6], reg);
  reg.value = &node2;
  dll_insert(adj_list[6], reg);

  reg.value = &node6;
  dll_insert(adj_list[7], reg);
  reg.value = &node3;
  dll_insert(adj_list[7], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.value)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.value)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->data.value)->id, 5);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.value)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.value)->id, 5);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->next->data.value)->id, 6);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.value)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->data.value)->id, 6);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->next->data.value)->id, 7);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.value)->id, 0);

  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->next->data.value)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->next->next->data.value)->id, 6);

  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->data.value)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->next->data.value)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->next->next->data.value)->id, 5);
  ck_assert_int_eq(
      ((TimedNode*)(*adj_list[6])->next->next->next->data.value)->id, 7);

  ck_assert_int_eq(((TimedNode*)(*adj_list[7])->data.value)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[7])->next->data.value)->id, 6);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);
  ck_assert_int_eq(node5.id, 5);
  ck_assert_int_eq(node6.id, 6);
  ck_assert_int_eq(node7.id, 7);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);
  ck_assert_int_eq(node5.color, BLACK);
  ck_assert_int_eq(node6.color, BLACK);
  ck_assert_int_eq(node7.color, BLACK);

  ck_assert_ptr_eq(node0.p, NULL);
  ck_assert_ptr_eq(node4.p, &node0);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_dfs_4)
{
  int i, length;
  TimedNode** vrtxs;
  TimedNode node0;
  DoublyLinkedList*** adj_list;

  length = 1;
  node0.id = 0;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_ptr_eq(node0.p, NULL);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

START_TEST(test_dfs_5)
{
  int i, length;
  TimedNode** vrtxs;
  TimedNode node0, node1, node2, node3, node4, node5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  node0.id = 0;
  node1.id = 1;
  node2.id = 2;
  node3.id = 3;
  node4.id = 4;
  node5.id = 5;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &node0;
  vrtxs[1] = &node1;
  vrtxs[2] = &node2;
  vrtxs[3] = &node3;
  vrtxs[4] = &node4;
  vrtxs[5] = &node5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.value = &node3;
  dll_insert(adj_list[0], reg);
  reg.value = &node2;
  dll_insert(adj_list[0], reg);
  reg.value = &node1;
  dll_insert(adj_list[0], reg);

  reg.value = &node4;
  dll_insert(adj_list[1], reg);

  reg.value = &node5;
  dll_insert(adj_list[2], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.value)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.value)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->next->data.value)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.value)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.value)->id, 5);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(node0.id, 0);
  ck_assert_int_eq(node1.id, 1);
  ck_assert_int_eq(node2.id, 2);
  ck_assert_int_eq(node3.id, 3);
  ck_assert_int_eq(node4.id, 4);

  ck_assert_int_eq(node0.color, BLACK);
  ck_assert_int_eq(node1.color, BLACK);
  ck_assert_int_eq(node2.color, BLACK);
  ck_assert_int_eq(node3.color, BLACK);
  ck_assert_int_eq(node4.color, BLACK);

  ck_assert_ptr_eq(node0.p, NULL);
  ck_assert_ptr_eq(node1.p, &node0);
  ck_assert_ptr_eq(node2.p, &node0);
  ck_assert_ptr_eq(node3.p, &node0);
  ck_assert_ptr_eq(node4.p, &node1);
  ck_assert_ptr_eq(node5.p, &node2);

  for (i = 0; i < length; i++)
    {
      dll_free_list(adj_list[i]);
      free(adj_list[i]);
    }

  free(vrtxs);
  free(adj_list);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Graph Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_test(tc_core, test_build_adj_list_1);
  tcase_add_test(tc_core, test_build_adj_list_2);
  tcase_add_test(tc_core, test_build_adj_list_3);

  tcase_add_test(tc_core, test_build_adj_mtx_1);
  tcase_add_test(tc_core, test_build_adj_mtx_2);

  tcase_add_test(tc_core, test_bfs_1);
  tcase_add_test(tc_core, test_bfs_2);
  tcase_add_test(tc_core, test_bfs_3);
  tcase_add_test(tc_core, test_bfs_4);
  tcase_add_test(tc_core, test_bfs_5);
  tcase_add_test(tc_core, test_bfs_6);

  tcase_add_test(tc_core, test_dfs_1);
  tcase_add_test(tc_core, test_dfs_2);
  tcase_add_test(tc_core, test_dfs_3);
  tcase_add_test(tc_core, test_dfs_4);
  tcase_add_test(tc_core, test_dfs_5);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
  int number_failed;
  SRunner* sr;

  sr = srunner_create(make_test_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "test.log");
  srunner_set_xml(sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
