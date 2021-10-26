#include <check.h>
#include <malloc.h>
#include <sll.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
SinglyLinkedList** head;

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
  head = malloc(sizeof(SinglyLinkedList*));
}

void teardown(void)
{
  free(reg);
  free(head);
}

START_TEST(test_sll_insert_1)
{
  union Key k1;
  SinglyLinkedList* node1;

  k1.i = 200;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node1, true);

  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 200);
  ck_assert_int_eq(node1->data.key.i, 200);

  free(node1);
}
END_TEST

START_TEST(test_sll_insert_2)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_insert_3)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_search_1)
{
  union Key k1;
  SinglyLinkedList* node1;

  k1.i = 100;

  *head = NULL;
  node1 = sll_search(head, k1, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, true);
  ck_assert_int_eq(node1 == NULL, true);
  ck_assert_int_eq(node1 == (*head), true);

  free(node1);
}
END_TEST

START_TEST(test_sll_search_2)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = 200;
  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  retrieved = sll_search(head, k2, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node1, true);

  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 200);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head) == retrieved, true);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 200);
  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
}
END_TEST

START_TEST(test_sll_search_3)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = -35;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  node2 = sll_search(head, k2, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node1, true);

  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 200);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq(node2 == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_search_4)
{
  union Key k1, k2, k3;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = 250;
  k3.i = 200;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  retrieved = sll_search(head, k3, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  ck_assert_int_eq((*head)->next == retrieved, true);
  ck_assert_int_eq(node2->next == retrieved, true);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 200);
  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_search_5)
{
  union Key k1, k2, k3;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = 250;
  k3.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  retrieved = sll_search(head, k3, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  ck_assert_int_eq((*head) == retrieved, true);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(retrieved->data.key.i, 250);
  ck_assert_int_eq(retrieved == node2, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_search_6)
{
  union Key k1, k2, k3;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = 250;
  k3.i = 0;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  retrieved = sll_search(head, k3, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_search_7)
{
  union Key k1, k2, k3, k4, k5;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;
  k5.i = 10;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);
  retrieved = sll_search(head, k5, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_search_8)
{
  union Key k1, k2, k3, k4, k5;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;
  k5.i = 33;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);
  retrieved = sll_search(head, k5, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  ck_assert_int_eq(node4->next == retrieved, true);
  ck_assert_int_eq(retrieved->next == node2, true);
  ck_assert_int_eq((*head)->next == retrieved, true);
  ck_assert_int_eq(retrieved->data.key.i, 33);
  ck_assert_int_eq(retrieved == node3, true);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_search_9)
{
  union Key k1, k2, k3, k4, k5;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;
  SinglyLinkedList* retrieved;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;
  k5.i = 200;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);
  retrieved = sll_search(head, k5, compare);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  ck_assert_int_eq(node2->next == retrieved, true);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 200);
  ck_assert_int_eq((*head)->next->next->next == retrieved, true);
  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_1)
{
  union Key k1;
  SinglyLinkedList* node1;

  k1.i = 200;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node1, true);

  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 200);
  ck_assert_int_eq(node1->data.key.i, 200);

  sll_delete(head, node1);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_sll_delete_2)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  sll_delete(head, node2);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node1, true);
  ck_assert_int_eq((*head)->data.key.i, 200);
  ck_assert_int_eq(node1->next == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_delete_3)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  sll_delete(head, node1);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq(node1->next == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_delete_4)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  sll_delete(head, node1);
  sll_delete(head, node2);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_delete_5)
{
  union Key k1, k2;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;

  k1.i = 200;
  k2.i = 250;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 200);
  ck_assert_int_eq(node2->data.key.i, 250);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 250);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  sll_delete(head, node2);
  sll_delete(head, node1);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, true);

  free(node1);
  free(node2);
}
END_TEST

START_TEST(test_sll_delete_6)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node2);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_7)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node3);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node2, true);
  ck_assert_int_eq((*head)->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_8)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node4);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node2, true);
  ck_assert_int_eq((*head)->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, 33);
  ck_assert_int_eq((*head)->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_9)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node1);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_10)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node1);
  sll_delete(head, node4);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == NULL, true);

  ck_assert_int_eq((*head)->next == node2, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, 33);
  ck_assert_int_eq((*head)->next->data.key.i, -80);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_11)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node2);
  sll_delete(head, node3);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node1, true);
  ck_assert_int_eq((*head)->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

START_TEST(test_sll_delete_12)
{
  union Key k1, k2, k3, k4;
  SinglyLinkedList* node1;
  SinglyLinkedList* node2;
  SinglyLinkedList* node3;
  SinglyLinkedList* node4;

  k1.i = 200;
  k2.i = -80;
  k3.i = 33;
  k4.i = -730;

  *head = NULL;
  reg->key = k1;
  node1 = sll_insert(head, *reg);
  reg->key = k2;
  node2 = sll_insert(head, *reg);
  reg->key = k3;
  node3 = sll_insert(head, *reg);
  reg->key = k4;
  node4 = sll_insert(head, *reg);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head) == node4, true);

  ck_assert_int_eq(node4->next == node3, true);
  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->next == node3, true);
  ck_assert_int_eq((*head)->next->next == node2, true);
  ck_assert_int_eq((*head)->next->next->next == node1, true);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  ck_assert_int_eq((*head)->data.key.i, -730);
  ck_assert_int_eq((*head)->next->data.key.i, 33);
  ck_assert_int_eq((*head)->next->next->data.key.i, -80);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 200);

  sll_delete(head, node3);
  sll_delete(head, node1);
  sll_delete(head, node4);
  sll_delete(head, node2);

  ck_assert_int_eq(head == NULL, false);
  ck_assert_int_eq((*head) == NULL, true);

  ck_assert_int_eq(node4->data.key.i, -730);
  ck_assert_int_eq(node3->data.key.i, 33);
  ck_assert_int_eq(node2->data.key.i, -80);
  ck_assert_int_eq(node1->data.key.i, 200);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("DoublyLinkedList Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with no Setup/Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_sll_insert_1);
  tcase_add_test(tc_core, test_sll_insert_2);
  tcase_add_test(tc_core, test_sll_insert_3);

  tcase_add_test(tc_core, test_sll_search_1);
  tcase_add_test(tc_core, test_sll_search_2);
  tcase_add_test(tc_core, test_sll_search_3);
  tcase_add_test(tc_core, test_sll_search_4);
  tcase_add_test(tc_core, test_sll_search_5);
  tcase_add_test(tc_core, test_sll_search_6);
  tcase_add_test(tc_core, test_sll_search_7);
  tcase_add_test(tc_core, test_sll_search_8);
  tcase_add_test(tc_core, test_sll_search_9);

  tcase_add_test(tc_core, test_sll_delete_1);
  tcase_add_test(tc_core, test_sll_delete_2);
  tcase_add_test(tc_core, test_sll_delete_3);
  tcase_add_test(tc_core, test_sll_delete_4);
  tcase_add_test(tc_core, test_sll_delete_5);
  tcase_add_test(tc_core, test_sll_delete_6);
  tcase_add_test(tc_core, test_sll_delete_7);
  tcase_add_test(tc_core, test_sll_delete_8);
  tcase_add_test(tc_core, test_sll_delete_9);
  tcase_add_test(tc_core, test_sll_delete_10);
  tcase_add_test(tc_core, test_sll_delete_11);
  tcase_add_test(tc_core, test_sll_delete_12);

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
