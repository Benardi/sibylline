#include <check.h>
#include <malloc.h>
#include <queue.h>
#include <stdint.h>
#include <stdlib.h>

Queue* q;
Register* el;
int i;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

int length = 20;

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
  init_queue(q, length);
  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);

  free(q->array);
}
END_TEST

START_TEST(test_init_queue_2)
{
  union Key k;

  k.i = 10;

  el->key = k;
  init_queue(q, length);
  enqueue(q, *el);
  reinit_queue(q);

  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);

  free(q->array);
}
END_TEST

START_TEST(test_init_queue_3)
{
  init_queue(q, length);
  dequeue(q, el);

  ck_assert_int_eq(q->head, 0);
  ck_assert_int_eq(q->tail, 0);

  free(q->array);
}
END_TEST

START_TEST(test_queue_empty_1)
{
  init_queue(q, length);

  ck_assert_int_eq(queue_empty(q), true);

  free(q->array);
}
END_TEST

START_TEST(test_queue_empty_2)
{
  bool result;

  init_queue(q, length);
  result = enqueue(q, *el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_empty(q), false);

  free(q->array);
}
END_TEST

START_TEST(test_queue_empty_3)
{
  bool result1, result2;

  init_queue(q, length);

  ck_assert_int_eq(queue_empty(q), true);

  result1 = enqueue(q, *el);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(queue_empty(q), false);

  result2 = dequeue(q, el);

  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(queue_empty(q), true);

  free(q->array);
}
END_TEST

START_TEST(test_queue_full_1)
{
  init_queue(q, length);
  ck_assert_int_eq(queue_full(q), false);

  free(q->array);
}
END_TEST

START_TEST(test_queue_full_2)
{
  union Key k;
  bool result = true;

  k.i = -10;

  el->key = k;
  init_queue(q, length);

  for (i = 0; i < (q->length - 2); i++)
    {
      result = result && enqueue(q, *el);
    }

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_full(q), false);

  free(q->array);
}
END_TEST

START_TEST(test_queue_full_3)
{
  union Key k;
  bool result = true;

  k.i = -10;

  el->key = k;
  init_queue(q, length);

  /* Filling up the queue */
  for (i = 0; i < (q->length - 1); i++)
    {
      result = result && enqueue(q, *el);
    }

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(queue_full(q), true);

  /* Queue overflow */
  result = enqueue(q, *el);
  ck_assert_int_eq(result, false);
  ck_assert_int_eq(queue_full(q), true);

  free(q->array);
}
END_TEST

START_TEST(test_enqueue_1)
{
  union Key k;
  bool result;

  k.i = 8;

  init_queue(q, length);
  el->key = k;
  result = enqueue(q, *el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(q->tail, 1);
  ck_assert_int_eq(q->array[(q->head)].key.i, 8);

  free(q->array);
}
END_TEST

START_TEST(test_enqueue_2)
{
  union Key k1, k2;
  bool result1, result2;

  k1.i = 8;
  k2.i = -15;

  init_queue(q, length);
  el->key = k1;
  result1 = enqueue(q, *el);
  el->key = k2;
  result2 = enqueue(q, *el);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);

  ck_assert_int_eq(q->tail, 2);
  ck_assert_int_eq(q->array[(q->tail - 1)].key.i, -15);
  ck_assert_int_eq(q->array[(q->head)].key.i, 8);

  free(q->array);
}
END_TEST

START_TEST(test_dequeue_1)
{
  bool result;
  init_queue(q, length);
  result = dequeue(q, el);

  ck_assert_int_eq(result, false);

  free(q->array);
}
END_TEST

START_TEST(test_dequeue_2)
{
  union Key k;
  bool result;

  k.i = -247;

  init_queue(q, length);

  el->key = k;
  enqueue(q, *el);
  result = dequeue(q, el);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(el->key.i, -247);

  free(q->array);
}
END_TEST

START_TEST(test_dequeue_3)
{
  union Key k;
  bool result;

  k.i = -247;

  init_queue(q, length);

  el->key = k;
  enqueue(q, *el);
  dequeue(q, el);
  result = dequeue(q, el); /* el is not overwritten */

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(el->key.i, -247);

  free(q->array);
}
END_TEST

START_TEST(test_recreate_1)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 15;
  k2.i = 6;
  k3.i = 9;
  k4.i = 8;
  k5.i = 4;

  init_queue(q, length);

  for (i = 0; i < 14; i++)
    {
      enqueue(q, *el);
    }

  el->key = k1;
  enqueue(q, *el);
  el->key = k2;
  enqueue(q, *el);
  el->key = k3;
  enqueue(q, *el);
  el->key = k4;
  enqueue(q, *el);
  el->key = k5;
  enqueue(q, *el);

  for (i = 0; i < 14; i++)
    {
      dequeue(q, el);
    }

  ck_assert_int_eq(q->array[14].key.i, 15);
  ck_assert_int_eq(q->array[15].key.i, 6);
  ck_assert_int_eq(q->array[16].key.i, 9);
  ck_assert_int_eq(q->array[17].key.i, 8);
  ck_assert_int_eq(q->array[18].key.i, 4);

  ck_assert_int_eq(q->tail, 19);
  ck_assert_int_eq(q->head, 14);

  free(q->array);
}
END_TEST

START_TEST(test_recreate_2)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;

  k1.i = 15;
  k2.i = 6;
  k3.i = 9;
  k4.i = 8;
  k5.i = 4;
  k6.i = 17;
  k7.i = 3;
  k8.i = 5;

  init_queue(q, length);

  for (i = 0; i < 14; i++)
    {
      enqueue(q, *el);
    }

  el->key = k1;
  enqueue(q, *el);
  el->key = k2;
  enqueue(q, *el);
  el->key = k3;
  enqueue(q, *el);
  el->key = k4;
  enqueue(q, *el);
  el->key = k5;
  enqueue(q, *el);

  for (i = 0; i < 14; i++)
    {
      dequeue(q, el);
    }

  el->key = k6;
  enqueue(q, *el);
  el->key = k7;
  enqueue(q, *el);
  el->key = k8;
  enqueue(q, *el);
  dequeue(q, el);

  ck_assert_int_eq(q->array[14].key.i, 15); /* Has been removed */
  ck_assert_int_eq(q->array[15].key.i, 6);
  ck_assert_int_eq(q->array[16].key.i, 9);
  ck_assert_int_eq(q->array[17].key.i, 8);
  ck_assert_int_eq(q->array[18].key.i, 4);
  ck_assert_int_eq(q->array[19].key.i, 17);
  ck_assert_int_eq(q->array[0].key.i, 3);
  ck_assert_int_eq(q->array[1].key.i, 5);

  ck_assert_int_eq(q->tail, 2);
  ck_assert_int_eq(q->head, 15);

  ck_assert_int_eq(q->array[q->head].key.i, 6);
  ck_assert_int_eq(q->array[q->tail - 1].key.i, 5);

  free(q->array);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

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
