#include <check.h>
#include <csll.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
CircularSinglyLinkedList** tail;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

static int compare(union Key k1, union Key k2)
{
  int result;

  if (k1.i > k2.i)
    {
      result = 1;
    }
  else if (k1.i < k2.i)
    {
      result = -1;
    }
  else
    {
      result = 0;
    }
  return result;
}

void setup(void)
{
  reg = malloc(sizeof(Register));
  tail = malloc(sizeof(CircularSinglyLinkedList*));
}

void teardown(void)
{
  free(reg);
  free(tail);
}

START_TEST(test_csll_insert_begin_1)
{
  union Key k1;
  CircularSinglyLinkedList* node1;

  k1.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail)->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == (*tail), true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node1->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  free(node1);
}
END_TEST

START_TEST(test_csll_insert_begin_2)
{
  union Key k1, k2;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;

  k1.i = 15;
  k2.i = -25;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node2, true);
  ck_assert_int_eq((*tail)->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == (*tail), true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node1 == (*tail), true);
  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next->next == node1, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);

  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node2 == (*tail), false);
  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next->next == node2, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_csll_insert_begin_3)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_insert_end_1)
{
  union Key k1;
  CircularSinglyLinkedList* node1;

  k1.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail)->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == (*tail), true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node1->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  free(node1);
}
END_TEST

START_TEST(test_csll_insert_end_2)
{
  union Key k1, k2;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;

  k1.i = 15;
  k2.i = -25;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node2, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq((*tail)->data.key.i, -25);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next == (*tail), true);
  ck_assert_int_eq(node1->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node2, true);
  ck_assert_int_eq(node2->next->next == (*tail), true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_csll_insert_end_3)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_1)
{
  union Key k1;
  CircularSinglyLinkedList* retrieved;

  k1.i = 10;
  *tail = NULL;
  retrieved = csll_search(tail, k1, compare);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);
  ck_assert_int_eq(retrieved == NULL, true);
}
END_TEST

START_TEST(test_csll_search_2)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next == node3, true);
  ck_assert_int_eq(retrieved->next->next == node2, true);
  ck_assert_int_eq(retrieved->next->next->next == node1, true);
  ck_assert_int_eq(retrieved->next->next->next == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_3)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = -25;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(retrieved->next->next == node3, true);
  ck_assert_int_eq(retrieved->next->next->next == node2, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_4)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = -15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_5)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next == node2, true);
  ck_assert_int_eq(retrieved->next->next == node1, true);
  ck_assert_int_eq(retrieved->next->next->next == node3, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_6)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved->data.key.i, 0);
  ck_assert_int_eq((*tail) == retrieved, true);
  ck_assert_int_eq(retrieved->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(retrieved->next->next == node2, true);
  ck_assert_int_eq(retrieved->next->next->next == node3, true);
  ck_assert_int_eq(retrieved->next->next->next == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_7)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = -25;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved->data.key.i, -25);
  ck_assert_int_eq(retrieved->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next == node3, true);
  ck_assert_int_eq(retrieved->next == (*tail), true);
  ck_assert_int_eq(retrieved->next->next == node1, true);
  ck_assert_int_eq(retrieved->next->next->next == node2, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_8)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved->data.key.i, 15);
  ck_assert_int_eq(retrieved->next->data.key.i, -25);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 15);
  ck_assert_int_eq(retrieved->next == node2, true);
  ck_assert_int_eq(retrieved->next->next == node3, true);
  ck_assert_int_eq(retrieved->next->next == (*tail), true);
  ck_assert_int_eq(retrieved->next->next->next == node1, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_search_9)
{
  union Key k1, k2, k3, k4;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;
  CircularSinglyLinkedList* retrieved;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;
  k4.i = 5;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next == (*tail), true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  retrieved = csll_search(tail, k4, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_1)
{
  union Key k1;
  CircularSinglyLinkedList* node1;

  k1.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail)->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == (*tail), true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node1->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_csll_delete_2)
{
  union Key k1;
  CircularSinglyLinkedList* node1;

  k1.i = 15;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail)->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == (*tail), true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node1->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_csll_delete_3)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node2, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, -25);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node3, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_4)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node2);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node1, true);
  ck_assert_int_eq(node1->next->next == (*tail), true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next == (*tail), true);
  ck_assert_int_eq(node3->next->next == node3, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_5)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node3);
  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node2, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, -25);

  ck_assert_int_eq((*tail)->next->data.key.i, -25);
  ck_assert_int_eq(node2->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node2, true);
  ck_assert_int_eq(node2->next == node2, true);
  ck_assert_int_eq(node2 == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_6)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node1);
  csll_delete(tail, node3);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node2, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, -25);

  ck_assert_int_eq((*tail)->next->data.key.i, -25);
  ck_assert_int_eq(node2->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node2, true);
  ck_assert_int_eq(node2->next == node2, true);
  ck_assert_int_eq(node2 == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_7)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node2);
  csll_delete(tail, node3);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_8)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node3);
  csll_delete(tail, node2);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node1, true);
  ck_assert_int_eq(node1->next == node1, true);
  ck_assert_int_eq(node1 == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_9)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node3);
  csll_delete(tail, node2);
  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_10)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node1);
  csll_delete(tail, node2);
  csll_delete(tail, node3);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_11)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node3);
  csll_delete(tail, node2);
  csll_delete(tail, node1);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_12)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node3);
  csll_delete(tail, node1);
  csll_delete(tail, node2);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_delete_13)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node1, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 15);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);
  ck_assert_int_eq(node1->next->next->next == (*tail), true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  csll_delete(tail, node2);
  csll_delete(tail, node1);
  csll_delete(tail, node3);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_insert_begin_end_1)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_begin(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_end(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_begin(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node2, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, -25);

  ck_assert_int_eq((*tail)->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next == node3, true);
  ck_assert_int_eq((*tail)->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == node2, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->data.key.i, 0);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node2, true);
  ck_assert_int_eq(node1->next == (*tail), true);
  ck_assert_int_eq(node1->next->next == node3, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node3, true);
  ck_assert_int_eq(node2->next->next == node1, true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->next->next == node2, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

START_TEST(test_csll_insert_begin_end_2)
{
  union Key k1, k2, k3;
  CircularSinglyLinkedList* node1;
  CircularSinglyLinkedList* node2;
  CircularSinglyLinkedList* node3;

  k1.i = 15;
  k2.i = -25;
  k3.i = 0;

  *tail = NULL;
  reg->key = k1;
  node1 = csll_insert_end(tail, *reg);
  reg->key = k2;
  node2 = csll_insert_begin(tail, *reg);
  reg->key = k3;
  node3 = csll_insert_end(tail, *reg);

  ck_assert_int_eq(tail == NULL, false);
  ck_assert_int_eq((*tail) == NULL, false);
  ck_assert_int_eq((*tail) == node3, true);

  ck_assert_int_eq(node1->data.key.i, 15);
  ck_assert_int_eq(node2->data.key.i, -25);
  ck_assert_int_eq(node3->data.key.i, 0);
  ck_assert_int_eq((*tail)->data.key.i, 0);

  ck_assert_int_eq((*tail)->next->data.key.i, -25);
  ck_assert_int_eq((*tail)->next->next->data.key.i, 15);
  ck_assert_int_eq((*tail)->next->next->next->data.key.i, 0);
  ck_assert_int_eq((*tail)->next == node2, true);
  ck_assert_int_eq((*tail)->next->next == node1, true);
  ck_assert_int_eq((*tail)->next->next->next == node3, true);
  ck_assert_int_eq((*tail)->next->next->next == (*tail), true);

  ck_assert_int_eq(node1->next->data.key.i, -0);
  ck_assert_int_eq(node1->next->next->data.key.i, -25);
  ck_assert_int_eq(node1->next->next->next->data.key.i, 15);
  ck_assert_int_eq(node1->next == node3, true);
  ck_assert_int_eq(node1->next == (*tail), true);
  ck_assert_int_eq(node1->next->next == node2, true);
  ck_assert_int_eq(node1->next->next->next == node1, true);

  ck_assert_int_eq(node2->next->data.key.i, 15);
  ck_assert_int_eq(node2->next->next->data.key.i, 0);
  ck_assert_int_eq(node2->next->next->next->data.key.i, -25);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->next->next == node3, true);
  ck_assert_int_eq(node2->next->next == (*tail), true);
  ck_assert_int_eq(node2->next->next->next == node2, true);

  ck_assert_int_eq(node3->next->data.key.i, -25);
  ck_assert_int_eq(node3->next->next->data.key.i, 15);
  ck_assert_int_eq(node3->next->next->next->data.key.i, 0);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->next->next == node1, true);
  ck_assert_int_eq(node3->next->next->next == node3, true);
  ck_assert_int_eq(node3->next->next->next == (*tail), true);

  free(node1);
  free(node2);
  free(node3);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("DoublyLinkedList Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_csll_insert_begin_1);
  tcase_add_test(tc_core, test_csll_insert_begin_2);
  tcase_add_test(tc_core, test_csll_insert_begin_3);

  tcase_add_test(tc_core, test_csll_insert_end_1);
  tcase_add_test(tc_core, test_csll_insert_end_2);
  tcase_add_test(tc_core, test_csll_insert_end_3);

  tcase_add_test(tc_core, test_csll_search_1);
  tcase_add_test(tc_core, test_csll_search_2);
  tcase_add_test(tc_core, test_csll_search_3);
  tcase_add_test(tc_core, test_csll_search_4);
  tcase_add_test(tc_core, test_csll_search_5);
  tcase_add_test(tc_core, test_csll_search_6);
  tcase_add_test(tc_core, test_csll_search_7);
  tcase_add_test(tc_core, test_csll_search_8);
  tcase_add_test(tc_core, test_csll_search_9);

  tcase_add_test(tc_core, test_csll_delete_1);
  tcase_add_test(tc_core, test_csll_delete_2);
  tcase_add_test(tc_core, test_csll_delete_3);
  tcase_add_test(tc_core, test_csll_delete_4);
  tcase_add_test(tc_core, test_csll_delete_5);
  tcase_add_test(tc_core, test_csll_delete_6);
  tcase_add_test(tc_core, test_csll_delete_7);
  tcase_add_test(tc_core, test_csll_delete_8);
  tcase_add_test(tc_core, test_csll_delete_9);
  tcase_add_test(tc_core, test_csll_delete_10);
  tcase_add_test(tc_core, test_csll_delete_11);
  tcase_add_test(tc_core, test_csll_delete_12);
  tcase_add_test(tc_core, test_csll_delete_13);

  tcase_add_test(tc_core, test_csll_insert_begin_end_1);
  tcase_add_test(tc_core, test_csll_insert_begin_end_2);

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
