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
  int k1;
  DoublyLinkedList* node1;

  k1 = -150;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);

  ck_assert_int_eq(*((int*)node1->data.key), -150);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->prev == NULL, true);
  ck_assert_int_eq(node1->next == NULL, true);

  ck_assert_int_eq(*((int*)(*head)->data.key), -150);
  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_dll_insert_2)
{
  int k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1 = 10;
  k2 = 30;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);

  /* Test collateral effect */
  ck_assert_int_eq(*((int*)(*head)->data.key), 30);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);

  ck_assert_int_eq(*((int*)(*head)->next->data.key), 10);
  ck_assert_int_eq((*head)->next->next == NULL, true);
  ck_assert_int_eq((*head)->next->prev == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->prev->data.key), 30);

  /* Test function return */
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(*((int*)node1->prev->next->data.key), 10);

  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(*((int*)node2->data.key), 30);
  ck_assert_int_eq(*((int*)node2->next->prev->data.key), 30);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_insert_3)
{
  int k1, k2, k3, k4;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1 = -67;
  k2 = 30;
  k3 = -12;
  k4 = 0;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);
  reg->key = &k4;
  node4 = dll_insert(head, *reg);

  /* Test collateral effect */
  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);

  ck_assert_int_eq(*((int*)(*head)->next->data.key), -12);
  ck_assert_int_eq((*head)->next->next == NULL, false);
  ck_assert_int_eq((*head)->next->prev == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->prev->data.key), 0);

  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 30);
  ck_assert_int_eq((*head)->next->next->next == NULL, false);
  ck_assert_int_eq((*head)->next->next->prev == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->next->prev->data.key), -12);

  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -67);
  ck_assert_int_eq((*head)->next->next->next->next == NULL, true);
  ck_assert_int_eq((*head)->next->next->next->prev == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->prev->data.key), 30);

  /* Test function return */
  ck_assert_int_eq(*((int*)node1->data.key), -67);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(*((int*)node1->prev->data.key), 30);

  ck_assert_int_eq(*((int*)node2->data.key), 30);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(*((int*)node2->prev->data.key), -12);

  ck_assert_int_eq(*((int*)node3->data.key), -12);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(node3->prev == NULL, false);
  ck_assert_int_eq(*((int*)node3->prev->data.key), 0);

  ck_assert_int_eq(*((int*)node4->data.key), 0);
  ck_assert_int_eq(node4->prev == NULL, true);
  ck_assert_int_eq(node4->next == NULL, false);
  ck_assert_int_eq(*((int*)node4->next->data.key), -12);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_1)
{
  int k1, k2, k3, k4, k5;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1 = -67;
  k2 = 30;
  k3 = -12;
  k4 = 0;
  k5 = 30;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);
  reg->key = &k4;
  node4 = dll_insert(head, *reg);
  retrieved = dll_search(head, &k5, compare);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(*((int*)retrieved->data.key), 30);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(*((int*)retrieved->next->data.key), -67);
  ck_assert_int_eq(*((int*)retrieved->prev->data.key), -12);
  ck_assert_int_eq(*((int*)retrieved->prev->prev->data.key), 0);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_2)
{
  int k1, k2, k3, k4, k5;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;

  k1 = 23;
  k2 = 5;
  k3 = -17;
  k4 = -10;
  k5 = 25;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);
  reg->key = &k4;
  node4 = dll_insert(head, *reg);
  retrieved = dll_search(head, &k5, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_search_3)
{
  int k1, k2, k3, k4, k5, k6, k7;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;

  k1 = -67;
  k2 = 30;
  k3 = -12;
  k4 = 0;
  k5 = 20;
  k6 = -189;
  k7 = -67;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);
  reg->key = &k4;
  node4 = dll_insert(head, *reg);
  reg->key = &k5;
  node5 = dll_insert(head, *reg);
  reg->key = &k6;
  node6 = dll_insert(head, *reg);
  retrieved = dll_search(head, &k7, compare);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(*((int*)retrieved->data.key), -67);
  ck_assert_int_eq(retrieved->next == NULL, true);
  ck_assert_int_eq(retrieved->prev == NULL, false);
  ck_assert_int_eq(*((int*)retrieved->prev->data.key), 30);
  ck_assert_int_eq(*((int*)retrieved->prev->prev->data.key), -12);
  ck_assert_int_eq(*((int*)retrieved->prev->prev->prev->data.key), 0);
  ck_assert_int_eq(*((int*)retrieved->prev->prev->prev->prev->data.key), 20);
  ck_assert_int_eq(*((int*)retrieved->prev->prev->prev->prev->prev->data.key),
                   -189);

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
  int k1, k2, k3, k4, k5, k6, k7;
  DoublyLinkedList* retrieved;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;

  k1 = -67;
  k2 = 30;
  k3 = -12;
  k4 = 0;
  k5 = 20;
  k6 = -189;
  k7 = -189;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);
  reg->key = &k4;
  node4 = dll_insert(head, *reg);
  reg->key = &k5;
  node5 = dll_insert(head, *reg);
  reg->key = &k6;
  node6 = dll_insert(head, *reg);
  retrieved = dll_search(head, &k7, compare);

  ck_assert_int_eq(retrieved == NULL, false);
  ck_assert_int_eq(*((int*)retrieved->data.key), -189);
  ck_assert_int_eq(retrieved->next == NULL, false);
  ck_assert_int_eq(retrieved->prev == NULL, true);
  ck_assert_int_eq(*((int*)retrieved->next->data.key), 20);
  ck_assert_int_eq(*((int*)retrieved->next->next->data.key), 0);
  ck_assert_int_eq(*((int*)retrieved->next->next->next->data.key), -12);
  ck_assert_int_eq(*((int*)retrieved->next->next->next->next->data.key), 30);
  ck_assert_int_eq(*((int*)retrieved->next->next->next->next->next->data.key),
                   -67);

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
  int k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1 = -67;
  k2 = 30;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(*((int*)node1->data.key), -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(*((int*)node1->prev->next->data.key), -67);

  ck_assert_int_eq(*((int*)node2->data.key), 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(*((int*)node2->next->prev->data.key), 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq(*((int*)(*head)->data.key), 30);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -67);
  ck_assert_int_eq(*((int*)(*head)->next->prev->data.key), 30);

  dll_delete(head, node1);

  ck_assert_int_eq(*((int*)(*head)->data.key), 30);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_2)
{
  int k1, k2;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;

  k1 = -67;
  k2 = 30;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);

  ck_assert_int_eq(*((int*)node1->data.key), -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(*((int*)node1->prev->next->data.key), -67);

  ck_assert_int_eq(*((int*)node2->data.key), 30);
  ck_assert_int_eq(node2 == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(node2->prev == NULL, true);
  ck_assert_int_eq(*((int*)node2->next->prev->data.key), 30);

  ck_assert_int_eq((*head) == NULL, false);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq(*((int*)(*head)->data.key), 30);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -67);
  ck_assert_int_eq(*((int*)(*head)->next->prev->data.key), 30);

  dll_delete(head, node2);

  ck_assert_int_eq(*((int*)(*head)->data.key), -67);
  ck_assert_int_eq((*head)->next == NULL, true);
  ck_assert_int_eq((*head)->prev == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_3)
{
  int k1;
  DoublyLinkedList* node1;

  k1 = -67;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);

  ck_assert_int_eq(*((int*)(*head)->data.key), -67);

  ck_assert_int_eq(*((int*)node1->data.key), -67);
  ck_assert_int_eq(node1 == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(node1->prev == NULL, true);

  ck_assert_int_eq(*((int*)(*head)->data.key), -67);
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
  int k1, k2, k3;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;

  k1 = 25;
  k2 = 75;
  k3 = 150;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  node2 = dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);

  ck_assert_int_eq(*((int*)(*head)->data.key), 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 75);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 25);

  ck_assert_int_eq(*((int*)node3->data.key), 150);
  ck_assert_int_eq(node3->prev == NULL, true);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(*((int*)node3->next->data.key), 75);
  ck_assert_int_eq(*((int*)node3->next->next->data.key), 25);

  ck_assert_int_eq(*((int*)node2->data.key), 75);
  ck_assert_int_eq(node2->prev == NULL, false);
  ck_assert_int_eq(node2->next == NULL, false);
  ck_assert_int_eq(*((int*)node2->prev->data.key), 150);
  ck_assert_int_eq(*((int*)node2->next->data.key), 25);

  ck_assert_int_eq(*((int*)node1->data.key), 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(*((int*)node1->prev->data.key), 75);
  ck_assert_int_eq(*((int*)node1->prev->prev->data.key), 150);

  dll_delete(head, node2);

  ck_assert_int_eq(*((int*)(*head)->data.key), 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 25);

  ck_assert_int_eq(*((int*)node3->data.key), 150);
  ck_assert_int_eq(node3->prev == NULL, true);
  ck_assert_int_eq(node3->next == NULL, false);
  ck_assert_int_eq(*((int*)node3->next->data.key), 25);

  ck_assert_int_eq(*((int*)node1->data.key), 25);
  ck_assert_int_eq(node1->prev == NULL, false);
  ck_assert_int_eq(node1->next == NULL, true);
  ck_assert_int_eq(*((int*)node1->prev->data.key), 150);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_dll_delete_5)
{
  int k1, k2, k3, k4;
  DoublyLinkedList* node;
  DoublyLinkedList* node1;
  DoublyLinkedList* node3;

  k1 = 25;
  k2 = 75;
  k3 = 150;
  k4 = 75;

  *head = NULL;
  reg->key = &k1;
  node1 = dll_insert(head, *reg);
  reg->key = &k2;
  dll_insert(head, *reg);
  reg->key = &k3;
  node3 = dll_insert(head, *reg);

  node = dll_search(head, &k4, compare);

  ck_assert_int_eq(*((int*)(*head)->data.key), 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 75);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 25);

  dll_delete(head, node);

  ck_assert_int_eq(*((int*)(*head)->data.key), 150);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, false);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 25);

  free(node);
  free(node1);
  free(node3);
}
END_TEST

START_TEST(test_dll_delete_6)
{
  int k1, k2, k3, k4, k5;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;

  k1 = 25;
  k2 = 75;
  k3 = 150;
  k4 = 150;
  k5 = 25;

  *head = NULL;
  reg->key = &k1;
  dll_insert(head, *reg);
  reg->key = &k2;
  node3 = dll_insert(head, *reg);
  reg->key = &k3;
  dll_insert(head, *reg);

  node1 = dll_search(head, &k4, compare);
  dll_delete(head, node1);
  node2 = dll_search(head, &k5, compare);
  dll_delete(head, node2);

  ck_assert_int_eq(*((int*)(*head)->data.key), 75);
  ck_assert_int_eq((*head)->prev == NULL, true);
  ck_assert_int_eq((*head)->next == NULL, true);

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
