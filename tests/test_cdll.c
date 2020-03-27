#include <cdll.h>
#include <check.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
CircularDoublyLinkedList* nil;

void setup(void);
void teardown(void);
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

void setup(void)
{
  nil = malloc(sizeof(CircularDoublyLinkedList));
  reg = malloc(sizeof(Register));
}

void teardown(void)
{
  free(reg);
  free(nil);
}

START_TEST(test_cdll_init_1)
{
  cdll_init(nil);
  ck_assert_int_eq(nil->next == nil, true);
  ck_assert_int_eq(nil->prev == nil, true);
}
END_TEST

START_TEST(test_cdll_insert_1)
{
  int k1;
  CircularDoublyLinkedList* node1;

  k1 = 17;
  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->prev == node1, true);
  ck_assert_int_eq(nil->next == node1, true);
  ck_assert_int_eq(node1->prev == nil, true);
  ck_assert_int_eq(node1->next == nil, true);

  ck_assert_int_eq(*((int*)nil->prev->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), 17);
  ck_assert_int_eq(*((int*)node1->data.key), 17);

  free(node1);
}
END_TEST

START_TEST(test_cdll_insert_2)
{
  int k1, k2;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;

  k1 = 17;
  k2 = -9;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_insert_3)
{
  int k1, k2, k3;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* node3;

  k1 = -2;
  k2 = 5;
  k3 = 0;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  reg->key = &k3;
  node3 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node2, true);
  ck_assert_int_eq(nil->next->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)nil->next->next->next->data.key), -2);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_1)
{
  int k1;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* retrieved;

  k1 = 17;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k1, compare);

  ck_assert_int_eq(nil->prev == node1, true);
  ck_assert_int_eq(nil->next == node1, true);
  ck_assert_int_eq(node1->prev == nil, true);
  ck_assert_int_eq(node1->next == nil, true);

  ck_assert_int_eq(*((int*)nil->prev->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), 17);
  ck_assert_int_eq(*((int*)node1->data.key), 17);

  ck_assert_int_eq(retrieved->prev == nil, true);
  ck_assert_int_eq(retrieved->next == nil, true);
  ck_assert_int_eq(*((int*)retrieved->data.key), 17);

  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
}
END_TEST

START_TEST(test_cdll_search_2)
{
  int k1, k2;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* retrieved;

  k1 = 17;
  k2 = 25;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k2, compare);

  ck_assert_int_eq(nil->prev == node1, true);
  ck_assert_int_eq(nil->next == node1, true);
  ck_assert_int_eq(node1->prev == nil, true);
  ck_assert_int_eq(node1->next == nil, true);

  ck_assert_int_eq(*((int*)nil->prev->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), 17);
  ck_assert_int_eq(*((int*)node1->data.key), 17);

  ck_assert_int_eq(retrieved->prev == node1, true);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(retrieved == nil, true);

  free(node1);
}
END_TEST

START_TEST(test_cdll_search_3)
{
  int k1, k2, k3;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* retrieved;

  k1 = 17;
  k2 = -9;
  k3 = -9;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k3, compare);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  ck_assert_int_eq(*((int*)retrieved->data.key), -9);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(retrieved->prev == nil, true);
  ck_assert_int_eq(nil->next == retrieved, true);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(nil->prev->prev == retrieved, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_4)
{
  int k1, k2, k3;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* retrieved;

  k1 = 17;
  k2 = -9;
  k3 = 17;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k3, compare);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  ck_assert_int_eq(*((int*)retrieved->data.key), 17);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved->next == nil, true);
  ck_assert_int_eq(nil->prev == retrieved, true);
  ck_assert_int_eq(node2->next == retrieved, true);
  ck_assert_int_eq(retrieved->prev == node2, true);
  ck_assert_int_eq(nil->next->next == retrieved, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_5)
{
  int k1, k2, k3;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* retrieved;

  k1 = 17;
  k2 = -9;
  k3 = -22;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k3, compare);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  ck_assert_int_eq(*((int*)retrieved->next->data.key), -9);
  ck_assert_int_eq(*((int*)retrieved->next->next->data.key), 17);
  ck_assert_int_eq(node2->prev == retrieved, true);
  ck_assert_int_eq(node1->next == retrieved, true);
  ck_assert_int_eq(retrieved->next->next == node1, true);
  ck_assert_int_eq(retrieved->prev->prev == node2, true);
  ck_assert_int_eq(retrieved->next->next->next == retrieved, true);
  ck_assert_int_eq(retrieved->prev->prev->prev == retrieved, true);
  ck_assert_int_eq(retrieved == nil, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_6)
{
  int k1, k2, k3, k4;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* node3;
  CircularDoublyLinkedList* retrieved;

  k1 = -2;
  k2 = 5;
  k3 = 0;
  k4 = 0;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  reg->key = &k3;
  node3 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k4, compare);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node2, true);
  ck_assert_int_eq(nil->next->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)nil->next->next->next->data.key), -2);

  ck_assert_int_eq(nil->prev->prev->prev == retrieved, true);
  ck_assert_int_eq(retrieved->next == node2, true);
  ck_assert_int_eq(retrieved->prev == nil, true);
  ck_assert_int_eq(nil->next == retrieved, true);
  ck_assert_int_eq(retrieved == node3, true);
  ck_assert_int_eq(*((int*)retrieved->data.key), 0);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_7)
{
  int k1, k2, k3, k4;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* node3;
  CircularDoublyLinkedList* retrieved;

  k1 = -2;
  k2 = 5;
  k3 = 0;
  k4 = 214350;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  reg->key = &k3;
  node3 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k4, compare);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node2, true);
  ck_assert_int_eq(nil->next->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)nil->next->next->next->data.key), -2);

  ck_assert_int_eq(retrieved == nil, true);
  ck_assert_int_eq(*((int*)retrieved->next->data.key), 0);
  ck_assert_int_eq(retrieved->next == node3, true);
  ck_assert_int_eq(retrieved->prev == node1, true);
  ck_assert_int_eq(*((int*)retrieved->next->next->data.key), 5);
  ck_assert_int_eq(retrieved->prev->prev == node2, true);
  ck_assert_int_eq(retrieved->next->next == node2, true);
  ck_assert_int_eq(*((int*)retrieved->next->next->next->data.key), -2);
  ck_assert_int_eq(retrieved->next->next->next == node1, true);
  ck_assert_int_eq(retrieved->prev->prev->prev == node3, true);
  ck_assert_int_eq(retrieved->next->next->next->next == nil, true);
  ck_assert_int_eq(retrieved->prev->prev->prev->prev == retrieved, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_search_8)
{
  int k1, k2, k3, k4;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* node3;
  CircularDoublyLinkedList* retrieved;

  k1 = -2;
  k2 = 5;
  k3 = 0;
  k4 = 5;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  reg->key = &k3;
  node3 = cdll_insert(nil, *reg);
  retrieved = cdll_search(nil, &k4, compare);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node2, true);
  ck_assert_int_eq(nil->next->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)nil->next->next->next->data.key), -2);

  ck_assert_int_eq(*((int*)retrieved->data.key), 5);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(node1->prev == retrieved, true);
  ck_assert_int_eq(retrieved->next == node1, true);
  ck_assert_int_eq(retrieved->prev == node3, true);
  ck_assert_int_eq(nil->next->next == retrieved, true);
  ck_assert_int_eq(nil->prev->prev == retrieved, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_delete_1)
{
  int k1;
  CircularDoublyLinkedList* node1;

  k1 = 17;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->prev == node1, true);
  ck_assert_int_eq(nil->next == node1, true);
  ck_assert_int_eq(node1->prev == nil, true);
  ck_assert_int_eq(node1->next == nil, true);

  ck_assert_int_eq(*((int*)nil->prev->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), 17);
  ck_assert_int_eq(*((int*)node1->data.key), 17);

  cdll_delete(node1);

  ck_assert_int_eq(nil->prev == nil, true);
  ck_assert_int_eq(nil->next == nil, true);
  ck_assert_int_eq(*((int*)node1->data.key), 17);

  free(node1);
}
END_TEST

START_TEST(test_cdll_delete_2)
{
  int k1, k2;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;

  k1 = 17;
  k2 = -9;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  cdll_delete(node1);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node2, true);

  ck_assert_int_eq(node2->next == nil, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(nil->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_delete_3)
{
  int k1, k2;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;

  k1 = 17;
  k2 = -9;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->next == node2, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == nil, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), -9);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 17);

  cdll_delete(node2);

  ck_assert_int_eq(nil->next == node1, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == nil, true);

  ck_assert_int_eq(nil->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -9);
  ck_assert_int_eq(*((int*)node1->data.key), 17);
  ck_assert_int_eq(*((int*)nil->next->data.key), 17);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_cdll_delete_4)
{
  int k1, k2, k3;
  CircularDoublyLinkedList* node1;
  CircularDoublyLinkedList* node2;
  CircularDoublyLinkedList* node3;

  k1 = -2;
  k2 = 5;
  k3 = 0;

  cdll_init(nil);
  reg->key = &k1;
  node1 = cdll_insert(nil, *reg);
  reg->key = &k2;
  node2 = cdll_insert(nil, *reg);
  reg->key = &k3;
  node3 = cdll_insert(nil, *reg);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node2, true);

  ck_assert_int_eq(node2->next == node1, true);
  ck_assert_int_eq(node2->prev == node3, true);

  ck_assert_int_eq(node3->next == node2, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node2, true);
  ck_assert_int_eq(nil->next->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node2, true);
  ck_assert_int_eq(nil->prev->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)nil->next->next->next->data.key), -2);

  cdll_delete(node2);

  ck_assert_int_eq(nil->next == node3, true);
  ck_assert_int_eq(nil->prev == node1, true);

  ck_assert_int_eq(node1->next == nil, true);
  ck_assert_int_eq(node1->prev == node3, true);

  ck_assert_int_eq(node3->next == node1, true);
  ck_assert_int_eq(node3->prev == nil, true);

  ck_assert_int_eq(nil->next->next == node1, true);
  ck_assert_int_eq(nil->next->next->next == nil, true);
  ck_assert_int_eq(nil->prev->prev == node3, true);
  ck_assert_int_eq(nil->prev->prev->prev == nil, true);

  ck_assert_int_eq(*((int*)node1->data.key), -2);
  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(*((int*)node3->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->data.key), 0);
  ck_assert_int_eq(*((int*)nil->next->next->data.key), -2);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("DoublyLinkedList Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup/Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_cdll_init_1);

  tcase_add_test(tc_core, test_cdll_insert_1);
  tcase_add_test(tc_core, test_cdll_insert_2);
  tcase_add_test(tc_core, test_cdll_insert_3);

  tcase_add_test(tc_core, test_cdll_search_1);
  tcase_add_test(tc_core, test_cdll_search_2);
  tcase_add_test(tc_core, test_cdll_search_3);
  tcase_add_test(tc_core, test_cdll_search_4);
  tcase_add_test(tc_core, test_cdll_search_5);
  tcase_add_test(tc_core, test_cdll_search_6);
  tcase_add_test(tc_core, test_cdll_search_7);
  tcase_add_test(tc_core, test_cdll_search_8);

  tcase_add_test(tc_core, test_cdll_delete_1);
  tcase_add_test(tc_core, test_cdll_delete_2);
  tcase_add_test(tc_core, test_cdll_delete_3);
  tcase_add_test(tc_core, test_cdll_delete_4);

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
