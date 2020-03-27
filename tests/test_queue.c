#include <check.h>
#include <malloc.h>
#include <queue.h>
#include <stdint.h>
#include <stdlib.h>

Queue *q;
Register *el;
int i;

void setup(void);
void teardown(void);
Suite *make_test_suite(void);
int compare(void *key1, void *key2);

int compare(void *key1, void *key2)
{
  int result;
  int k1 = *((int *)key1);
  int k2 = *((int *)key2);

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
  q = malloc(sizeof(Queue));
  el = malloc(sizeof(Register));
}

void teardown(void)
{
  free(el);
  free(q);
}

START_TEST(test_init_queue_1)
{
  init_queue(q);
  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);
}
END_TEST

START_TEST(test_init_queue_2)
{
  int k;

  k = 10;

  el->key = &k;
  init_queue(q);
  enqueue(q, *el);
  init_queue(q);

  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);
}
END_TEST

START_TEST(test_init_queue_3)
{
  init_queue(q);
  dequeue(q, el);

  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);
}
END_TEST

START_TEST(test_queue_empty_1)
{
  init_queue(q);

  ck_assert_int_eq(queue_empty(q), true);
}
END_TEST

START_TEST(test_queue_empty_2)
{
  bool result;

  init_queue(q);
  result = enqueue(q, *el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_empty(q), false);
}
END_TEST

START_TEST(test_queue_empty_3)
{
  bool result1, result2;

  init_queue(q);

  ck_assert_int_eq(queue_empty(q), true);

  result1 = enqueue(q, *el);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(queue_empty(q), false);

  result2 = dequeue(q, el);

  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(queue_empty(q), true);
}
END_TEST

START_TEST(test_queue_full_1)
{
  init_queue(q);
  ck_assert_int_eq(queue_full(q), false);
}
END_TEST

START_TEST(test_queue_full_2)
{
  int k;
  bool result = true;

  k = -10;

  el->key = &k;
  init_queue(q);

  for (i = 0; i < (MAX - 2); i++)
    {
      result = result && enqueue(q, *el);
    }

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_full(q), false);
}
END_TEST

START_TEST(test_queue_full_3)
{
  int k;
  bool result = true;

  k = -10;

  el->key = &k;
  init_queue(q);

  /* Filling up the queue */
  for (i = 0; i < (MAX - 1); i++)
    {
      result = result && enqueue(q, *el);
    }

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_full(q), true);

  /* Queue overflow */
  result = enqueue(q, *el);
  ck_assert_int_eq(result, false);
  ck_assert_int_eq(queue_full(q), true);
}
END_TEST

START_TEST(test_enqueue_1)
{
  int k;
  bool result;

  k = 8;

  init_queue(q);
  el->key = &k;
  result = enqueue(q, *el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(q->tail, 1);
  ck_assert_int_eq(*((int *)q->A[(q->head)].key), 8);
}
END_TEST

START_TEST(test_enqueue_2)
{
  int k1, k2;
  bool result1, result2;

  k1 = 8;
  k2 = -15;

  init_queue(q);
  el->key = &k1;
  result1 = enqueue(q, *el);
  el->key = &k2;
  result2 = enqueue(q, *el);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);

  ck_assert_int_eq(q->tail, 2);
  ck_assert_int_eq(*((int *)q->A[(q->tail - 1)].key), -15);
  ck_assert_int_eq(*((int *)q->A[(q->head)].key), 8);
}
END_TEST

START_TEST(test_dequeue_1)
{
  bool result;
  init_queue(q);
  result = dequeue(q, el);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_dequeue_2)
{
  int k;
  bool result;

  k = -247;

  init_queue(q);

  el->key = &k;
  enqueue(q, *el);
  result = dequeue(q, el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int *)el->key), -247);
}
END_TEST

START_TEST(test_dequeue_3)
{
  int k;
  bool result;

  k = -247;
  init_queue(q);

  el->key = &k;
  enqueue(q, *el);
  dequeue(q, el);
  result = dequeue(q, el); /* el is not overwritten */

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int *)el->key), -247);
}
END_TEST

START_TEST(test_recreate_1)
{
  int k1, k2, k3, k4, k5;

  k1 = 15;
  k2 = 6;
  k3 = 9;
  k4 = 8;
  k5 = 4;

  init_queue(q);

  for (i = 0; i < 14; i++)
    {
      enqueue(q, *el);
    }

  el->key = &k1;
  enqueue(q, *el);
  el->key = &k2;
  enqueue(q, *el);
  el->key = &k3;
  enqueue(q, *el);
  el->key = &k4;
  enqueue(q, *el);
  el->key = &k5;
  enqueue(q, *el);

  for (i = 0; i < 14; i++)
    {
      dequeue(q, el);
    }

  ck_assert_int_eq(*((int *)q->A[14].key), 15);
  ck_assert_int_eq(*((int *)q->A[15].key), 6);
  ck_assert_int_eq(*((int *)q->A[16].key), 9);
  ck_assert_int_eq(*((int *)q->A[17].key), 8);
  ck_assert_int_eq(*((int *)q->A[18].key), 4);

  ck_assert_int_eq(q->tail, 19);
  ck_assert_int_eq(q->head, 14);
}
END_TEST

START_TEST(test_recreate_2)
{
  int k1, k2, k3, k4, k5, k6, k7, k8;

  k1 = 15;
  k2 = 6;
  k3 = 9;
  k4 = 8;
  k5 = 4;
  k6 = 17;
  k7 = 3;
  k8 = 5;
  init_queue(q);

  for (i = 0; i < 14; i++)
    {
      enqueue(q, *el);
    }

  el->key = &k1;
  enqueue(q, *el);
  el->key = &k2;
  enqueue(q, *el);
  el->key = &k3;
  enqueue(q, *el);
  el->key = &k4;
  enqueue(q, *el);
  el->key = &k5;
  enqueue(q, *el);

  for (i = 0; i < 14; i++)
    {
      dequeue(q, el);
    }

  el->key = &k6;
  enqueue(q, *el);
  el->key = &k7;
  enqueue(q, *el);
  el->key = &k8;
  enqueue(q, *el);
  dequeue(q, el);

  ck_assert_int_eq(*((int *)q->A[14].key), 15); /* Has been removed */
  ck_assert_int_eq(*((int *)q->A[15].key), 6);
  ck_assert_int_eq(*((int *)q->A[16].key), 9);
  ck_assert_int_eq(*((int *)q->A[17].key), 8);
  ck_assert_int_eq(*((int *)q->A[18].key), 4);
  ck_assert_int_eq(*((int *)q->A[19].key), 17);
  ck_assert_int_eq(*((int *)q->A[0].key), 3);
  ck_assert_int_eq(*((int *)q->A[1].key), 5);

  ck_assert_int_eq(q->tail, 2);
  ck_assert_int_eq(q->head, 15);

  ck_assert_int_eq(*((int *)q->A[q->head].key), 6);
  ck_assert_int_eq(*((int *)q->A[q->tail - 1].key), 5);
}
END_TEST

Suite *make_test_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Queue Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_init_queue_1);
  tcase_add_test(tc_core, test_init_queue_2);
  tcase_add_test(tc_core, test_init_queue_3);

  tcase_add_test(tc_core, test_queue_empty_1);
  tcase_add_test(tc_core, test_queue_empty_2);
  tcase_add_test(tc_core, test_queue_empty_3);

  tcase_add_test(tc_core, test_queue_full_1);
  tcase_add_test(tc_core, test_queue_full_2);
  tcase_add_test(tc_core, test_queue_full_3);

  tcase_add_test(tc_core, test_enqueue_1);
  tcase_add_test(tc_core, test_enqueue_2);

  tcase_add_test(tc_core, test_dequeue_1);
  tcase_add_test(tc_core, test_dequeue_2);
  tcase_add_test(tc_core, test_dequeue_3);

  tcase_add_test(tc_core, test_recreate_1);
  tcase_add_test(tc_core, test_recreate_2);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
  int number_failed;
  SRunner *sr;

  sr = srunner_create(make_test_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "test.log");
  srunner_set_xml(sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
