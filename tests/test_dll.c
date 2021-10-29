#include <check.h>
#include <dll.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
DoublyLinkedList** head;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

static int compare_int(union Key k1, union Key k2)
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

static int compare_float(union Key k1, union Key k2)
{
  int result;

  if (k1.f > k2.f)
    {
      result = 1;
    }
  else if (k1.f < k2.f)
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
  head = malloc(sizeof(DoublyLinkedList*));
}

void teardown(void)
{
  free(reg);
  free(head);
}

START_TEST(test_dll_insert_1)
{
  union Key k1;
  DoublyLinkedList* node1;

  k1.i = -150;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -150);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->prev == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq((*head)->data.key.i, -150);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_dll_insert_2)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1.i = 10;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  /* Test collateral effect */
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);

  ck_assert_int_eq((*head)->next->data.key.i, 10);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->next->prev == NULL, false);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  /* Test function return */
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);
  ck_assert_int_eq(node1->prev->next->data.key.i, 10);

  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_insert_3)
{
  union Key k1, k2, k3, k4;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);

  /* Test collateral effect */
  ck_assert_int_eq((*head)->data.key.i, 0);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);

  ck_assert_int_eq((*head)->next->data.key.i, -12);
  ck_assert_int_eq((*head)->next->next == NULL, false);
  ck_assert_int_eq((*head)->next->prev == NULL, false);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 0);

  ck_assert_int_eq((*head)->next->next->data.key.i, 30);
  ck_assert_int_eq((*head)->next->next->next == NULL, false);
  ck_assert_int_eq((*head)->next->next->prev == NULL, false);
  ck_assert_int_eq((*head)->next->next->prev->data.key.i, -12);

  ck_assert_int_eq((*head)->next->next->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);
  ck_assert_int_eq((*head)->next->next->next->prev == NULL, false);
  ck_assert_int_eq((*head)->next->next->next->prev->data.key.i, 30);

  /* Test function return */
  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->data.key.i, 30);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->prev->data.key.i, -12);

  ck_assert_int_eq(node3->data.key.i, -12);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(node3->prev->data.key.i, 0);

  ck_assert_int_eq(node4->data.key.i, 0);
  ck_assert_int_eq(node4->prev == NULL, true);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(node4->next->data.key.i, -12);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_1)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;
  k5.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  retrieved = dll_search(head, k5, compare_int);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 30);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->next->data.key.i, -67);
  ck_assert_int_eq(retrieved->prev->data.key.i, -12);
  ck_assert_int_eq(retrieved->prev->prev->data.key.i, 0);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_2)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1.i = 23;
  k2.i = 5;
  k3.i = -17;
  k4.i = -10;
  k5.i = 25;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  retrieved = dll_search(head, k5, compare_int);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_3)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;
  k5.i = 20;
  k6.i = -189;
  k7.i = -67;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);
  reg->key = k6;
  node6 = dll_insert(head, *reg);
  retrieved = dll_search(head, k7, compare_int);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -67);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->prev->data.key.i, 30);
  ck_assert_int_eq(retrieved->prev->prev->data.key.i, -12);
  ck_assert_int_eq(retrieved->prev->prev->prev->data.key.i, 0);
  ck_assert_int_eq(retrieved->prev->prev->prev->prev->data.key.i, 20);
  ck_assert_int_eq(retrieved->prev->prev->prev->prev->prev->data.key.i, -189);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_4)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;
  k5.i = 20;
  k6.i = -189;
  k7.i = -189;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);
  reg->key = k6;
  node6 = dll_insert(head, *reg);
  retrieved = dll_search(head, k7, compare_int);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -189);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->next->data.key.i, 20);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 0);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, -12);
  ck_assert_int_eq(retrieved->next->next->next->next->data.key.i, 30);
  ck_assert_int_eq(retrieved->next->next->next->next->next->data.key.i, -67);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_1)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  dll_delete(head, node1);

  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_2)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  dll_delete(head, node2);

  ck_assert_int_eq((*head)->data.key.i, -67);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_3)
{
  union Key k1;
  DoublyLinkedList* node1;

  k1.i = -67;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, -67);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, true);

  ck_assert_int_eq((*head)->data.key.i, -67);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  dll_delete(head, node1);

  ck_assert_int_eq((*head) == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_dll_delete_4)
{
  union Key k1, k2, k3;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->data.key.i, 25);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, true);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->data.key.i, 75);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);

  dll_delete(head, node2);

  ck_assert_int_eq((*head)->data.key.i, 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 25);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, true);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->data.key.i, 150);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_5)
{
  union Key k1, k2, k3, k4;
  DoublyLinkedList* node;
  DoublyLinkedList* node1;
  DoublyLinkedList* node3;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 75;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);

  node = dll_search(head, k4, compare_int);

  ck_assert_int_eq((*head)->data.key.i, 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->data.key.i, 25);

  dll_delete(head, node);

  ck_assert_int_eq((*head)->data.key.i, 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 25);

  free(node);
  free(node1);
  free(node3);
}
END_TEST

START_TEST(test_dll_delete_6)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 150;
  k5.i = 25;

  *head = NULL;
  reg->key = k1;
  dll_insert(head, *reg);
  reg->key = k2;
  node3 = dll_insert(head, *reg);
  reg->key = k3;
  dll_insert(head, *reg);

  node1 = dll_search(head, k4, compare_int);
  dll_delete(head, node1);
  node2 = dll_search(head, k5, compare_int);
  dll_delete(head, node2);

  ck_assert_int_eq((*head)->data.key.i, 75);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_1)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_nth(head, 0);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 30);
  ck_assert_int_eq(retrieved->next->data.key.i, -67);
  ck_assert_int_eq(retrieved->next->prev->data.key.i, 30);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_2)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_nth(head, 1);

  ck_assert_int_eq(retrieved->data.key.i, -67);
  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->prev->next->data.key.i, -67);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_3)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_nth(head, -1);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_4)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_nth(head, 2);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_5)
{
  union Key k1;
  DoublyLinkedList* node1;
  DoublyLinkedList* retrieved;

  k1.i = -67;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, -67);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, true);

  ck_assert_int_eq((*head)->data.key.i, -67);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  dll_delete(head, node1);

  ck_assert_int_eq((*head) == NULL, true);

  retrieved = dll_get_nth(head, 0);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_6)
{
  union Key k1, k2, k3;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* retrieved;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->data.key.i, 25);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, true);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->data.key.i, 75);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);

  retrieved = dll_get_nth(head, 2);

  ck_assert_int_eq(retrieved->data.key.i, 25);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev->data.key.i, 75);
  ck_assert_int_eq(retrieved->prev->prev->data.key.i, 150);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_nth_7)
{
  union Key k1, k2, k3, k4;
  DoublyLinkedList* node;
  DoublyLinkedList* node1;
  DoublyLinkedList* node3;
  DoublyLinkedList* retrieved;

  k1.f = 25.7;
  k2.f = 75.123;
  k3.f = 150.211;
  k4.f = 75.123;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);

  node = dll_search(head, k4, compare_float);

  ck_assert_float_eq((*head)->data.key.f, 150.211);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_float_eq((*head)->next->data.key.f, 75.123);
  ck_assert_float_eq((*head)->next->next->data.key.f, 25.7);

  dll_delete(head, node);

  ck_assert_float_eq((*head)->data.key.f, 150.211);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_float_eq((*head)->next->data.key.f, 25.7);

  retrieved = dll_get_nth(head, 1);

  ck_assert_float_eq(retrieved->data.key.f, 25.7);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_float_eq(retrieved->prev->data.key.f, 150.211);

  free(node);
  free(node1);
  free(node3);
}
END_TEST

START_TEST(test_dll_get_by_idx_1)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node2, 0, 1);

  ck_assert_int_eq(retrieved->data.key.i, -67);
  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->prev->next->data.key.i, -67);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_2)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node1, 1, 0);

  ck_assert_int_eq(retrieved->data.key.i, 30);
  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->next->prev->data.key.i, 30);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_3)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node1, 1, -1);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_4)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node2, 0, 2);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_5)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node1, 1, 1);

  ck_assert_int_eq(retrieved->data.key.i, -67);
  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->prev->next->data.key.i, -67);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_6)
{
  union Key k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* retrieved;

  k1.i = -67;
  k2.i = 30;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(node1->data.key.i, -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->prev->next->data.key.i, -67);

  ck_assert_int_eq(node2->data.key.i, 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next->prev->data.key.i, 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->data.key.i, 30);
  ck_assert_int_eq((*head)->next->data.key.i, -67);
  ck_assert_int_eq((*head)->next->prev->data.key.i, 30);

  retrieved = dll_get_by_idx(node2, 0, 0);

  ck_assert_int_eq(retrieved->data.key.i, 30);
  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->next->prev->data.key.i, 30);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_7)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* retrieved;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 12;
  k5.i = 34;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 34);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 12);
  ck_assert_int_eq((*head)->next->next->data.key.i, 150);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node5->data.key.i, 34);
  ck_assert_int_eq(node5->prev == NULL, true);
  ck_assert_int_eq(node5->next == NULL, false);
  ck_assert_int_eq(node5->next->data.key.i, 12);
  ck_assert_int_eq(node5->next->next->data.key.i, 150);
  ck_assert_int_eq(node5->next->next->next->data.key.i, 75);
  ck_assert_int_eq(node5->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node4->data.key.i, 12);
  ck_assert_int_eq(node4->prev == NULL, false);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(node4->prev->data.key.i, 34);
  ck_assert_int_eq(node4->next->data.key.i, 150);
  ck_assert_int_eq(node4->next->next->data.key.i, 75);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node3->prev->data.key.i, 12);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node2->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node1->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);
  ck_assert_int_eq(node1->prev->data.key.i, 75);

  retrieved = dll_get_by_idx(node3, 2, 0);

  ck_assert_int_eq(retrieved->data.key.i, 34);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->next->data.key.i, 12);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 150);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 75);
  ck_assert_int_eq(retrieved->next->next->next->next->data.key.i, 25);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_8)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* retrieved;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 12;
  k5.i = 34;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 34);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 12);
  ck_assert_int_eq((*head)->next->next->data.key.i, 150);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node5->data.key.i, 34);
  ck_assert_int_eq(node5->prev == NULL, true);
  ck_assert_int_eq(node5->next == NULL, false);
  ck_assert_int_eq(node5->next->data.key.i, 12);
  ck_assert_int_eq(node5->next->next->data.key.i, 150);
  ck_assert_int_eq(node5->next->next->next->data.key.i, 75);
  ck_assert_int_eq(node5->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node4->data.key.i, 12);
  ck_assert_int_eq(node4->prev == NULL, false);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(node4->prev->data.key.i, 34);
  ck_assert_int_eq(node4->next->data.key.i, 150);
  ck_assert_int_eq(node4->next->next->data.key.i, 75);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node3->prev->data.key.i, 12);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node2->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node1->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);
  ck_assert_int_eq(node1->prev->data.key.i, 75);

  retrieved = dll_get_by_idx(node3, 2, 4);

  ck_assert_int_eq(retrieved->data.key.i, 25);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(retrieved->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(retrieved->prev->prev->data.key.i, 150);
  ck_assert_int_eq(retrieved->prev->data.key.i, 75);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_9)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* retrieved;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 12;
  k5.i = 34;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 34);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 12);
  ck_assert_int_eq((*head)->next->next->data.key.i, 150);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node5->data.key.i, 34);
  ck_assert_int_eq(node5->prev == NULL, true);
  ck_assert_int_eq(node5->next == NULL, false);
  ck_assert_int_eq(node5->next->data.key.i, 12);
  ck_assert_int_eq(node5->next->next->data.key.i, 150);
  ck_assert_int_eq(node5->next->next->next->data.key.i, 75);
  ck_assert_int_eq(node5->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node4->data.key.i, 12);
  ck_assert_int_eq(node4->prev == NULL, false);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(node4->prev->data.key.i, 34);
  ck_assert_int_eq(node4->next->data.key.i, 150);
  ck_assert_int_eq(node4->next->next->data.key.i, 75);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node3->prev->data.key.i, 12);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node2->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node1->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);
  ck_assert_int_eq(node1->prev->data.key.i, 75);

  retrieved = dll_get_by_idx(node5, 0, 4);

  ck_assert_int_eq(retrieved->data.key.i, 25);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(retrieved->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(retrieved->prev->prev->data.key.i, 150);
  ck_assert_int_eq(retrieved->prev->data.key.i, 75);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_get_by_idx_10)
{
  union Key k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* retrieved;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 12;
  k5.i = 34;

  *head = NULL;
  reg->key = k1;
  node1 = dll_insert(head, *reg);
  reg->key = k2;
  node2 = dll_insert(head, *reg);
  reg->key = k3;
  node3 = dll_insert(head, *reg);
  reg->key = k4;
  node4 = dll_insert(head, *reg);
  reg->key = k5;
  node5 = dll_insert(head, *reg);

  ck_assert_int_eq((*head)->data.key.i, 34);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->next->data.key.i, 12);
  ck_assert_int_eq((*head)->next->next->data.key.i, 150);
  ck_assert_int_eq((*head)->next->next->next->data.key.i, 75);
  ck_assert_int_eq((*head)->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node5->data.key.i, 34);
  ck_assert_int_eq(node5->prev == NULL, true);
  ck_assert_int_eq(node5->next == NULL, false);
  ck_assert_int_eq(node5->next->data.key.i, 12);
  ck_assert_int_eq(node5->next->next->data.key.i, 150);
  ck_assert_int_eq(node5->next->next->next->data.key.i, 75);
  ck_assert_int_eq(node5->next->next->next->next->data.key.i, 25);

  ck_assert_int_eq(node4->data.key.i, 12);
  ck_assert_int_eq(node4->prev == NULL, false);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(node4->prev->data.key.i, 34);
  ck_assert_int_eq(node4->next->data.key.i, 150);
  ck_assert_int_eq(node4->next->next->data.key.i, 75);

  ck_assert_int_eq(node3->data.key.i, 150);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node3->prev->data.key.i, 12);
  ck_assert_int_eq(node3->next->data.key.i, 75);
  ck_assert_int_eq(node3->next->next->data.key.i, 25);

  ck_assert_int_eq(node2->data.key.i, 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node2->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node2->prev->data.key.i, 150);
  ck_assert_int_eq(node2->next->data.key.i, 25);

  ck_assert_int_eq(node1->data.key.i, 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev->prev->prev->prev->data.key.i, 34);
  ck_assert_int_eq(node1->prev->prev->prev->data.key.i, 12);
  ck_assert_int_eq(node1->prev->prev->data.key.i, 150);
  ck_assert_int_eq(node1->prev->data.key.i, 75);

  retrieved = dll_get_by_idx(node1, 4, 0);

  ck_assert_int_eq(retrieved->data.key.i, 34);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->next->data.key.i, 12);
  ck_assert_int_eq(retrieved->next->next->data.key.i, 150);
  ck_assert_int_eq(retrieved->next->next->next->data.key.i, 75);
  ck_assert_int_eq(retrieved->next->next->next->next->data.key.i, 25);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_free_list_1)
{
  union Key k1, k2, k3, k4, k5, k6;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;
  k5.i = 20;
  k6.i = -189;

  *head = NULL;
  reg->key = k1;
  dll_insert(head, *reg);
  reg->key = k2;
  dll_insert(head, *reg);
  reg->key = k3;
  dll_insert(head, *reg);
  reg->key = k4;
  dll_insert(head, *reg);
  reg->key = k5;
  dll_insert(head, *reg);
  reg->key = k6;
  dll_insert(head, *reg);

  dll_free_list(head);
}
END_TEST

START_TEST(test_dll_free_list_2)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 25;
  k2.i = 75;
  k3.i = 150;
  k4.i = 12;
  k5.i = 34;

  *head = NULL;
  reg->key = k1;
  dll_insert(head, *reg);
  reg->key = k2;
  dll_insert(head, *reg);
  reg->key = k3;
  dll_insert(head, *reg);
  reg->key = k4;
  dll_insert(head, *reg);
  reg->key = k5;
  dll_insert(head, *reg);

  dll_free_list(head);
}
END_TEST

START_TEST(test_dll_free_list_3)
{
  union Key k1, k2, k3, k4;

  k1.i = -67;
  k2.i = 30;
  k3.i = -12;
  k4.i = 0;

  *head = NULL;
  reg->key = k1;
  dll_insert(head, *reg);
  reg->key = k2;
  dll_insert(head, *reg);
  reg->key = k3;
  dll_insert(head, *reg);
  reg->key = k4;
  dll_insert(head, *reg);

  dll_free_list(head);
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

  tcase_add_test(tc_core, test_dll_insert_1);
  tcase_add_test(tc_core, test_dll_insert_2);
  tcase_add_test(tc_core, test_dll_insert_3);

  tcase_add_test(tc_core, test_dll_search_1);
  tcase_add_test(tc_core, test_dll_search_2);
  tcase_add_test(tc_core, test_dll_search_3);
  tcase_add_test(tc_core, test_dll_search_4);

  tcase_add_test(tc_core, test_dll_delete_1);
  tcase_add_test(tc_core, test_dll_delete_2);
  tcase_add_test(tc_core, test_dll_delete_3);
  tcase_add_test(tc_core, test_dll_delete_4);
  tcase_add_test(tc_core, test_dll_delete_5);
  tcase_add_test(tc_core, test_dll_delete_6);

  tcase_add_test(tc_core, test_dll_get_nth_1);
  tcase_add_test(tc_core, test_dll_get_nth_2);
  tcase_add_test(tc_core, test_dll_get_nth_3);
  tcase_add_test(tc_core, test_dll_get_nth_4);
  tcase_add_test(tc_core, test_dll_get_nth_5);
  tcase_add_test(tc_core, test_dll_get_nth_6);
  tcase_add_test(tc_core, test_dll_get_nth_7);

  tcase_add_test(tc_core, test_dll_get_by_idx_1);
  tcase_add_test(tc_core, test_dll_get_by_idx_2);
  tcase_add_test(tc_core, test_dll_get_by_idx_3);
  tcase_add_test(tc_core, test_dll_get_by_idx_4);
  tcase_add_test(tc_core, test_dll_get_by_idx_5);
  tcase_add_test(tc_core, test_dll_get_by_idx_6);
  tcase_add_test(tc_core, test_dll_get_by_idx_7);
  tcase_add_test(tc_core, test_dll_get_by_idx_8);
  tcase_add_test(tc_core, test_dll_get_by_idx_9);
  tcase_add_test(tc_core, test_dll_get_by_idx_10);

  tcase_add_test(tc_core, test_dll_free_list_1);
  tcase_add_test(tc_core, test_dll_free_list_2);
  tcase_add_test(tc_core, test_dll_free_list_3);

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
