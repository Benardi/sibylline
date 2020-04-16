#include <assert.h>
#include <check.h>
#include <dll.h>
#include <graph.h>
#include <limits.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

Suite* make_test_suite(void);
int compare(void* key1, void* key2);

int compare(void* key1, void* key2)
{
  int result;
  int k1 = *((int*)key1);
  int k2 = *((int*)key2);

  if (k1 > k2)
    {
      result = 1;
    }
  else if (k1 < k2)
    {
      result = -1;
    }
  else
    {
      result = 0;
    }
  return result;
}

START_TEST(test_build_adj_list_1)
{
  int i, length;
  int u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  u0 = 0;
  u1 = 1;
  u2 = 2;
  u3 = 3;
  u4 = 4;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u3;
  dll_insert(adj_list[1], reg);
  reg.key = &u2;
  dll_insert(adj_list[1], reg);
  reg.key = &u4;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u3;
  dll_insert(adj_list[2], reg);
  reg.key = &u1;
  dll_insert(adj_list[2], reg);

  reg.key = &u2;
  dll_insert(adj_list[3], reg);
  reg.key = &u4;
  dll_insert(adj_list[3], reg);
  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u1;
  dll_insert(adj_list[4], reg);
  reg.key = &u0;
  dll_insert(adj_list[4], reg);
  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(*((int*)(*adj_list[0])->data.key), 1);
  ck_assert_int_eq(*((int*)(*adj_list[0])->next->data.key), 4);

  ck_assert_int_eq(*((int*)(*adj_list[1])->data.key), 0);
  ck_assert_int_eq(*((int*)(*adj_list[1])->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*adj_list[1])->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*adj_list[1])->next->next->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*adj_list[2])->data.key), 1);
  ck_assert_int_eq(*((int*)(*adj_list[2])->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*adj_list[3])->data.key), 1);
  ck_assert_int_eq(*((int*)(*adj_list[3])->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*adj_list[3])->next->next->data.key), 2);

  ck_assert_int_eq(*((int*)(*adj_list[4])->data.key), 3);
  ck_assert_int_eq(*((int*)(*adj_list[4])->next->data.key), 0);
  ck_assert_int_eq(*((int*)(*adj_list[4])->next->next->data.key), 1);

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
  int u1, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  u1 = 1;
  u3 = 3;
  u4 = 4;
  u5 = 5;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);

  reg.key = &u4;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);

  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  reg.key = &u5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(*((int*)(*adj_list[0])->data.key), 1);
  ck_assert_int_eq(*((int*)(*adj_list[0])->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*adj_list[1])->data.key), 4);

  ck_assert_int_eq(*((int*)(*adj_list[2])->data.key), 5);
  ck_assert_int_eq(*((int*)(*adj_list[2])->next->data.key), 4);

  ck_assert_int_eq(*((int*)(*adj_list[3])->data.key), 1);

  ck_assert_int_eq(*((int*)(*adj_list[4])->data.key), 3);

  ck_assert_int_eq(*((int*)(*adj_list[5])->data.key), 5);

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
  ColoredNode u1, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  u1.id = 1;
  u1.color = WHITE;
  u3.id = 3;
  u3.color = GRAY;
  u4.id = 4;
  u4.color = BLACK;
  u5.id = 5;
  u5.color = WHITE;

  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);

  reg.key = &u4;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);

  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  reg.key = &u5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.key)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.key)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->data.key)->id, 5);

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
  ColoredNode u0, u1, u2, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;
  u5.id = 5;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;
  vrtxs[5] = &u5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);

  reg.key = &u4;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);

  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  reg.key = &u5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.key)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.key)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.key)->id, 3);

  bfs(adj_list, vrtxs, length, &u2);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);
  ck_assert_int_eq(u5.id, 5);

  ck_assert_int_eq(u0.color, WHITE);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);
  ck_assert_int_eq(u5.color, BLACK);

  ck_assert_int_eq(u0.dist, INF);
  ck_assert_int_eq(u1.dist, 3);
  ck_assert_int_eq(u2.dist, 0);
  ck_assert_int_eq(u3.dist, 2);
  ck_assert_int_eq(u4.dist, 1);
  ck_assert_int_eq(u5.dist, 1);

  ck_assert_ptr_eq(u0.p, NULL);
  ck_assert_ptr_eq(u1.p, &u3);
  ck_assert_ptr_eq(u2.p, NULL);
  ck_assert_ptr_eq(u3.p, &u4);
  ck_assert_ptr_eq(u4.p, &u2);
  ck_assert_ptr_eq(u5.p, &u2);

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
  ColoredNode u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u3;
  dll_insert(adj_list[1], reg);
  reg.key = &u2;
  dll_insert(adj_list[1], reg);
  reg.key = &u4;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u3;
  dll_insert(adj_list[2], reg);
  reg.key = &u1;
  dll_insert(adj_list[2], reg);

  reg.key = &u2;
  dll_insert(adj_list[3], reg);
  reg.key = &u4;
  dll_insert(adj_list[3], reg);
  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u1;
  dll_insert(adj_list[4], reg);
  reg.key = &u0;
  dll_insert(adj_list[4], reg);
  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.key)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.key)->id, 4);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->next->data.key)->id, 2);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[1])->next->next->next->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.key)->id, 4);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.key)->id, 2);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.key)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->data.key)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->next->data.key)->id, 1);

  bfs(adj_list, vrtxs, length, &u0);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);

  ck_assert_int_eq(u0.dist, 0);
  ck_assert_int_eq(u1.dist, 1);
  ck_assert_int_eq(u2.dist, 2);
  ck_assert_int_eq(u3.dist, 2);
  ck_assert_int_eq(u4.dist, 1);

  ck_assert_ptr_eq(u0.p, NULL);
  ck_assert_ptr_eq(u1.p, &u0);
  ck_assert_ptr_eq(u2.p, &u1);
  ck_assert_ptr_eq(u3.p, &u1);
  ck_assert_ptr_eq(u4.p, &u0);

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
  ColoredNode u0, u1, u2, u3, u4, u5, u6, u7;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 8;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;
  u5.id = 5;
  u6.id = 6;
  u7.id = 7;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;
  vrtxs[5] = &u5;
  vrtxs[6] = &u6;
  vrtxs[7] = &u7;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u5;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u6;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);
  reg.key = &u3;
  dll_insert(adj_list[2], reg);

  reg.key = &u7;
  dll_insert(adj_list[3], reg);
  reg.key = &u6;
  dll_insert(adj_list[3], reg);
  reg.key = &u2;
  dll_insert(adj_list[3], reg);

  reg.key = &u0;
  dll_insert(adj_list[4], reg);

  reg.key = &u6;
  dll_insert(adj_list[5], reg);
  reg.key = &u2;
  dll_insert(adj_list[5], reg);
  reg.key = &u1;
  dll_insert(adj_list[5], reg);

  reg.key = &u7;
  dll_insert(adj_list[6], reg);
  reg.key = &u5;
  dll_insert(adj_list[6], reg);
  reg.key = &u3;
  dll_insert(adj_list[6], reg);
  reg.key = &u2;
  dll_insert(adj_list[6], reg);

  reg.key = &u6;
  dll_insert(adj_list[7], reg);
  reg.key = &u3;
  dll_insert(adj_list[7], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.key)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.key)->id, 5);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.key)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.key)->id, 5);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->next->data.key)->id, 6);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.key)->id, 6);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.key)->id, 7);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.key)->id, 0);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->next->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[5])->next->next->data.key)->id, 6);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->next->data.key)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[6])->next->next->data.key)->id, 5);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[6])->next->next->next->data.key)->id, 7);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[7])->data.key)->id, 3);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[7])->next->data.key)->id, 6);

  bfs(adj_list, vrtxs, length, &u1);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);
  ck_assert_int_eq(u5.id, 5);
  ck_assert_int_eq(u6.id, 6);
  ck_assert_int_eq(u7.id, 7);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);
  ck_assert_int_eq(u5.color, BLACK);
  ck_assert_int_eq(u6.color, BLACK);
  ck_assert_int_eq(u7.color, BLACK);

  ck_assert_int_eq(u0.dist, 1);
  ck_assert_int_eq(u1.dist, 0);
  ck_assert_int_eq(u2.dist, 2);
  ck_assert_int_eq(u3.dist, 3);
  ck_assert_int_eq(u4.dist, 2);
  ck_assert_int_eq(u5.dist, 1);
  ck_assert_int_eq(u6.dist, 2);
  ck_assert_int_eq(u7.dist, 3);

  ck_assert_ptr_eq(u0.p, &u1);
  ck_assert_ptr_eq(u1.p, NULL);
  ck_assert_ptr_eq(u2.p, &u5);
  ck_assert_ptr_eq(u3.p, &u2);
  ck_assert_ptr_eq(u4.p, &u0);
  ck_assert_ptr_eq(u5.p, &u1);
  ck_assert_ptr_eq(u6.p, &u5);
  ck_assert_ptr_eq(u7.p, &u6);

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
  ColoredNode u0;
  DoublyLinkedList*** adj_list;

  length = 1;
  u0.id = 0;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  bfs(adj_list, vrtxs, length, &u0);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u0.dist, 0);
  ck_assert_ptr_eq(u0.p, NULL);

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
  ColoredNode u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u2;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);
  reg.key = &u3;
  dll_insert(adj_list[1], reg);
  reg.key = &u2;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u4;
  dll_insert(adj_list[2], reg);
  reg.key = &u3;
  dll_insert(adj_list[2], reg);
  reg.key = &u1;
  dll_insert(adj_list[2], reg);
  reg.key = &u0;
  dll_insert(adj_list[2], reg);

  reg.key = &u4;
  dll_insert(adj_list[3], reg);
  reg.key = &u2;
  dll_insert(adj_list[3], reg);
  reg.key = &u1;
  dll_insert(adj_list[3], reg);
  reg.key = &u0;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);
  reg.key = &u2;
  dll_insert(adj_list[4], reg);
  reg.key = &u1;
  dll_insert(adj_list[4], reg);
  reg.key = &u0;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->next->next->data.key)->id, 3);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[0])->next->next->next->data.key)->id, 4);

  bfs(adj_list, vrtxs, length, &u4);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);

  ck_assert_int_eq(u0.dist, 1);
  ck_assert_int_eq(u1.dist, 1);
  ck_assert_int_eq(u2.dist, 1);
  ck_assert_int_eq(u3.dist, 1);
  ck_assert_int_eq(u4.dist, 0);

  ck_assert_ptr_eq(u0.p, &u4);
  ck_assert_ptr_eq(u1.p, &u4);
  ck_assert_ptr_eq(u2.p, &u4);
  ck_assert_ptr_eq(u3.p, &u4);
  ck_assert_ptr_eq(u4.p, NULL);

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
  ColoredNode u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;

  vrtxs = malloc(length * sizeof(ColoredNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);
  reg.key = &u3;
  dll_insert(adj_list[1], reg);
  reg.key = &u2;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u3;
  dll_insert(adj_list[2], reg);
  reg.key = &u1;
  dll_insert(adj_list[2], reg);

  reg.key = &u4;
  dll_insert(adj_list[3], reg);
  reg.key = &u2;
  dll_insert(adj_list[3], reg);
  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);
  reg.key = &u1;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[0])->data.key)->id, 1);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->data.key)->id, 0);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[1])->next->next->data.key)->id, 3);
  ck_assert_int_eq(
      ((ColoredNode*)(*adj_list[1])->next->next->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[2])->next->data.key)->id, 3);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->data.key)->id, 2);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[3])->next->next->data.key)->id, 4);

  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->data.key)->id, 1);
  ck_assert_int_eq(((ColoredNode*)(*adj_list[4])->next->data.key)->id, 3);

  bfs(adj_list, vrtxs, length, &u2);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);

  ck_assert_int_eq(u0.dist, 2);
  ck_assert_int_eq(u1.dist, 1);
  ck_assert_int_eq(u2.dist, 0);
  ck_assert_int_eq(u3.dist, 1);
  ck_assert_int_eq(u4.dist, 2);

  ck_assert_ptr_eq(u0.p, &u1);
  ck_assert_ptr_eq(u1.p, &u2);
  ck_assert_ptr_eq(u2.p, NULL);
  ck_assert_ptr_eq(u3.p, &u2);
  ck_assert_ptr_eq(u4.p, &u1);

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
  TimedNode u0, u1, u2, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;
  u5.id = 5;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;
  vrtxs[5] = &u5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);

  reg.key = &u4;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);

  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  reg.key = &u5;
  dll_insert(adj_list[5], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.key)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.key)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.key)->id, 5);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.key)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.key)->id, 1);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.key)->id, 3);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);
  ck_assert_int_eq(u5.id, 5);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);
  ck_assert_int_eq(u5.color, BLACK);

  ck_assert_ptr_eq(u0.p, NULL);
  ck_assert_ptr_eq(u1.p, &u0);
  ck_assert_ptr_eq(u2.p, NULL);
  ck_assert_ptr_eq(u5.p, &u2);

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
  TimedNode u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 5;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u3;
  dll_insert(adj_list[1], reg);
  reg.key = &u2;
  dll_insert(adj_list[1], reg);
  reg.key = &u4;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u3;
  dll_insert(adj_list[2], reg);
  reg.key = &u1;
  dll_insert(adj_list[2], reg);

  reg.key = &u2;
  dll_insert(adj_list[3], reg);
  reg.key = &u4;
  dll_insert(adj_list[3], reg);
  reg.key = &u1;
  dll_insert(adj_list[3], reg);

  reg.key = &u1;
  dll_insert(adj_list[4], reg);
  reg.key = &u0;
  dll_insert(adj_list[4], reg);
  reg.key = &u3;
  dll_insert(adj_list[4], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.key)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.key)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->data.key)->id, 4);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->next->data.key)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->next->next->data.key)->id,
                   3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.key)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->data.key)->id, 4);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->next->data.key)->id, 2);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.key)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->next->data.key)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->next->next->data.key)->id, 1);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);

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
  TimedNode u0, u1, u2, u3, u4, u5, u6, u7;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 8;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;
  u5.id = 5;
  u6.id = 6;
  u7.id = 7;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;
  vrtxs[5] = &u5;
  vrtxs[6] = &u6;
  vrtxs[7] = &u7;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u5;
  dll_insert(adj_list[1], reg);
  reg.key = &u0;
  dll_insert(adj_list[1], reg);

  reg.key = &u6;
  dll_insert(adj_list[2], reg);
  reg.key = &u5;
  dll_insert(adj_list[2], reg);
  reg.key = &u3;
  dll_insert(adj_list[2], reg);

  reg.key = &u7;
  dll_insert(adj_list[3], reg);
  reg.key = &u6;
  dll_insert(adj_list[3], reg);
  reg.key = &u2;
  dll_insert(adj_list[3], reg);

  reg.key = &u0;
  dll_insert(adj_list[4], reg);

  reg.key = &u6;
  dll_insert(adj_list[5], reg);
  reg.key = &u2;
  dll_insert(adj_list[5], reg);
  reg.key = &u1;
  dll_insert(adj_list[5], reg);

  reg.key = &u7;
  dll_insert(adj_list[6], reg);
  reg.key = &u5;
  dll_insert(adj_list[6], reg);
  reg.key = &u3;
  dll_insert(adj_list[6], reg);
  reg.key = &u2;
  dll_insert(adj_list[6], reg);

  reg.key = &u6;
  dll_insert(adj_list[7], reg);
  reg.key = &u3;
  dll_insert(adj_list[7], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.key)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.key)->id, 0);
  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->next->data.key)->id, 5);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.key)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->data.key)->id, 5);
  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->next->next->data.key)->id, 6);

  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->data.key)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->data.key)->id, 6);
  ck_assert_int_eq(((TimedNode*)(*adj_list[3])->next->next->data.key)->id, 7);

  ck_assert_int_eq(((TimedNode*)(*adj_list[4])->data.key)->id, 0);

  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->next->data.key)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[5])->next->next->data.key)->id, 6);

  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->data.key)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->next->data.key)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->next->next->data.key)->id, 5);
  ck_assert_int_eq(((TimedNode*)(*adj_list[6])->next->next->next->data.key)->id,
                   7);

  ck_assert_int_eq(((TimedNode*)(*adj_list[7])->data.key)->id, 3);
  ck_assert_int_eq(((TimedNode*)(*adj_list[7])->next->data.key)->id, 6);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);
  ck_assert_int_eq(u5.id, 5);
  ck_assert_int_eq(u6.id, 6);
  ck_assert_int_eq(u7.id, 7);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);
  ck_assert_int_eq(u5.color, BLACK);
  ck_assert_int_eq(u6.color, BLACK);
  ck_assert_int_eq(u7.color, BLACK);

  ck_assert_ptr_eq(u0.p, NULL);
  ck_assert_ptr_eq(u4.p, &u0);

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
  TimedNode u0;
  DoublyLinkedList*** adj_list;

  length = 1;
  u0.id = 0;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_ptr_eq(u0.p, NULL);

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
  TimedNode u0, u1, u2, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** adj_list;

  length = 6;
  u0.id = 0;
  u1.id = 1;
  u2.id = 2;
  u3.id = 3;
  u4.id = 4;
  u5.id = 5;

  vrtxs = malloc(length * sizeof(TimedNode*));
  adj_list = malloc(length * sizeof(DoublyLinkedList**));

  vrtxs[0] = &u0;
  vrtxs[1] = &u1;
  vrtxs[2] = &u2;
  vrtxs[3] = &u3;
  vrtxs[4] = &u4;
  vrtxs[5] = &u5;

  for (i = 0; i < length; i++)
    {
      adj_list[i] = malloc(sizeof(DoublyLinkedList*));
      *adj_list[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(adj_list[0], reg);
  reg.key = &u2;
  dll_insert(adj_list[0], reg);
  reg.key = &u1;
  dll_insert(adj_list[0], reg);

  reg.key = &u4;
  dll_insert(adj_list[1], reg);

  reg.key = &u5;
  dll_insert(adj_list[2], reg);

  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->data.key)->id, 1);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->data.key)->id, 2);
  ck_assert_int_eq(((TimedNode*)(*adj_list[0])->next->next->data.key)->id, 3);

  ck_assert_int_eq(((TimedNode*)(*adj_list[1])->data.key)->id, 4);

  ck_assert_int_eq(((TimedNode*)(*adj_list[2])->data.key)->id, 5);

  dfs(adj_list, vrtxs, length);

  ck_assert_int_eq(u0.id, 0);
  ck_assert_int_eq(u1.id, 1);
  ck_assert_int_eq(u2.id, 2);
  ck_assert_int_eq(u3.id, 3);
  ck_assert_int_eq(u4.id, 4);

  ck_assert_int_eq(u0.color, BLACK);
  ck_assert_int_eq(u1.color, BLACK);
  ck_assert_int_eq(u2.color, BLACK);
  ck_assert_int_eq(u3.color, BLACK);
  ck_assert_int_eq(u4.color, BLACK);

  ck_assert_ptr_eq(u0.p, NULL);
  ck_assert_ptr_eq(u1.p, &u0);
  ck_assert_ptr_eq(u2.p, &u0);
  ck_assert_ptr_eq(u3.p, &u0);
  ck_assert_ptr_eq(u4.p, &u1);
  ck_assert_ptr_eq(u5.p, &u2);

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
