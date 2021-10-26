#include <array_list.h>
#include <check.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

ArrayList* list;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

void setup(void)
{
  list = malloc(sizeof(ArrayList));
}

void teardown(void)
{
  free(list->array);
  free(list);
}

static int compare_to(union Key k1, union Key k2)
{
  int result;

  if (k1.i == k2.i)
    {
      result = 1;
    }
  else
    {
      result = 0;
    }
  return result;
}

START_TEST(test_init_list)
{
  int capacity = 1;

  init_list(list, capacity);

  ck_assert_int_eq(list->size, 0);
  ck_assert_int_eq(list->capacity, 1);
}
END_TEST

START_TEST(test_insert1_capacity1)
{
  Register el;
  union Key k;
  int capacity = 1;

  k.i = 5;

  init_list(list, capacity);

  el.key = k;
  insert(list, el);

  ck_assert_int_eq(list->size, 1);
  ck_assert_int_eq(list->capacity, 1);
  ck_assert_int_eq(list->array[0].key.i, 5);
}
END_TEST

START_TEST(test_insert3_capacity1)
{
  Register el;
  int capacity = 1;
  union Key k1, k2, k3;

  init_list(list, capacity);

  k1.i = 5;
  el.key = k1;
  insert(list, el);

  k2.i = 15;
  el.key = k2;
  insert(list, el);

  k3.i = -10;
  el.key = k3;
  insert(list, el);

  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(list->capacity, 4);
  ck_assert_int_eq(list->array[0].key.i, 5);
  ck_assert_int_eq(list->array[1].key.i, 15);
  ck_assert_int_eq(list->array[2].key.i, -10);
}
END_TEST

START_TEST(test_insert4_capacity5)
{
  Register el;
  int capacity = 5;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);

  k1.i = 5;
  el.key = k1;
  insert(list, el);

  k2.i = 15;
  el.key = k2;
  insert(list, el);

  k3.i = -10;
  el.key = k3;
  insert(list, el);

  k4.i = -15;
  el.key = k4;
  insert(list, el);

  ck_assert_int_eq(list->size, 4);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(list->array[0].key.i, 5);
  ck_assert_int_eq(list->array[1].key.i, 15);
  ck_assert_int_eq(list->array[2].key.i, -10);
  ck_assert_int_eq(list->array[3].key.i, -15);
}
END_TEST

START_TEST(test_insert_at_capacity1)
{
  Register el;
  int capacity = 1;
  union Key k;
  k.i = 5;

  init_list(list, capacity);

  el.key = k;
  insert_at(list, el, 0);

  ck_assert_int_eq(list->size, 1);
  ck_assert_int_eq(list->capacity, 1);
  ck_assert_int_eq(list->array[0].key.i, 5);
}
END_TEST

START_TEST(test_insert_twice_at_capacity1)
{
  Register el;
  int capacity = 1;
  union Key k1, k2;
  k1.i = 5;
  k2.i = 20;

  init_list(list, capacity);

  el.key = k1;
  insert_at(list, el, 0);

  el.key = k2;
  insert_at(list, el, 0);

  ck_assert_int_eq(list->size, 2);
  ck_assert_int_eq(list->capacity, 2);
  ck_assert_int_eq(list->array[0].key.i, 20);
  ck_assert_int_eq(list->array[1].key.i, 5);
}
END_TEST

START_TEST(test_insert_at_capacity5)
{
  Register el;
  int capacity = 5;
  union Key k, k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 3;
  el.key = k2;
  list->array[1] = el;

  k3.i = 4;
  el.key = k3;
  list->array[2] = el;

  k4.i = 5;
  el.key = k4;
  list->array[3] = el;

  k.i = 2;
  el.key = k;
  insert_at(list, el, 1);

  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 2);
  ck_assert_int_eq(list->array[2].key.i, 3);
  ck_assert_int_eq(list->array[3].key.i, 4);
  ck_assert_int_eq(list->array[4].key.i, 5);
}
END_TEST

START_TEST(test_insert_at_last_index)
{
  Register el;
  int capacity = 5;
  union Key k, k1, k2, k3, k4;
  int index = 4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 3;
  el.key = k2;
  list->array[1] = el;

  k3.i = 4;
  el.key = k3;
  list->array[2] = el;

  k4.i = 5;
  el.key = k4;
  list->array[3] = el;

  k.i = 12;
  el.key = k;
  insert_at(list, el, index);

  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 3);
  ck_assert_int_eq(list->array[2].key.i, 4);
  ck_assert_int_eq(list->array[3].key.i, 5);
  ck_assert_int_eq(list->array[4].key.i, 12);
}
END_TEST

START_TEST(test_set_success)
{
  Register el;
  int capacity = 4;
  union Key k1, k2, k3, k4;
  bool result;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 5;
  el.key = k1;
  list->array[0] = el;

  k2.i = 15;
  el.key = k2;
  list->array[1] = el;

  k3.i = -10;
  el.key = k3;
  list->array[2] = el;

  k4.i = 25;
  el.key = k4;
  list->array[3] = el;

  result = set(list, el, 3);

  ck_assert_int_eq(list->array[3].key.i, 25);
  ck_assert_int_eq(result, true);
}
END_TEST

START_TEST(test_set_head_fail)
{
  Register el;
  int capacity = 4;
  union Key k1, k2, k3;
  bool result;

  init_list(list, capacity);
  list->size = 3;

  k1.i = 5;
  el.key = k1;
  list->array[0] = el;

  k2.i = 15;
  el.key = k2;
  list->array[1] = el;

  k3.i = -10;
  el.key = k3;
  list->array[2] = el;

  result = set(list, el, -1);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_set_tail_fail)
{
  Register el;
  int capacity = 4;
  union Key k1, k2, k3;
  bool result;

  init_list(list, capacity);
  list->size = 3;

  k1.i = 5;
  el.key = k1;
  list->array[0] = el;

  k2.i = 15;
  el.key = k2;
  list->array[1] = el;

  k3.i = -10;
  el.key = k3;
  list->array[2] = el;

  result = set(list, el, 4);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_get_success)
{
  Register el;
  Register* result;
  int capacity = 4;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 25;
  el.key = k1;
  list->array[0] = el;

  k2.i = 35;
  el.key = k2;
  list->array[1] = el;

  k3.i = -20;
  el.key = k3;
  list->array[2] = el;

  k4.i = 58;
  el.key = k4;
  list->array[3] = el;

  result = get(list, 1);

  ck_assert_int_eq(result == &list->array[1], true);
  ck_assert_int_eq(result->key.i, 35);
}
END_TEST

START_TEST(test_get_head_fail)
{
  Register el;
  Register* result;
  int capacity = 4;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 25;
  el.key = k1;
  list->array[0] = el;

  k2.i = 35;
  el.key = k2;
  list->array[1] = el;

  k3.i = -20;
  el.key = k3;
  list->array[2] = el;

  k4.i = 58;
  el.key = k4;
  list->array[3] = el;

  result = get(list, -1);

  ck_assert_int_eq(result == NULL, true);
}
END_TEST

START_TEST(test_get_tail_fail)
{
  Register el;
  Register* result;
  int capacity = 4;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 25;
  el.key = k1;
  list->array[0] = el;

  k2.i = 35;
  el.key = k2;
  list->array[1] = el;

  k3.i = -20;
  el.key = k3;
  list->array[2] = el;

  k4.i = 58;
  el.key = k4;
  list->array[3] = el;

  result = get(list, 4);

  ck_assert_int_eq(result == NULL, true);
}
END_TEST

START_TEST(test_contains_success)
{
  Register el;
  bool result;
  int capacity = 10;
  union Key identifier;
  union Key k1, k2, k3, k4, k5;

  init_list(list, capacity);
  list->size = 5;

  k1.i = 5;
  el.key = k1;
  list->array[0] = el;

  k2.i = 15;
  el.key = k2;
  list->array[1] = el;

  k3.i = -10;
  el.key = k3;
  list->array[2] = el;

  k4.i = 25;
  el.key = k4;
  list->array[3] = el;

  k5.i = 32;
  el.key = k5;
  list->array[4] = el;

  identifier.i = -10;

  result = contains(list, identifier, compare_to);

  ck_assert_int_eq(result, true);
}
END_TEST

START_TEST(test_contains_fail)
{
  Register el;
  int capacity = 10;
  bool result;
  union Key identifier;
  union Key k1, k2, k3, k4, k5;

  init_list(list, capacity);
  list->size = 5;

  k1.i = 5;
  el.key = k1;
  list->array[0] = el;

  k2.i = 15;
  el.key = k2;
  list->array[1] = el;

  k3.i = -10;
  el.key = k3;
  list->array[2] = el;

  k4.i = 25;
  el.key = k4;
  list->array[3] = el;

  k5.i = 32;
  el.key = k5;
  list->array[4] = el;

  identifier.i = 48;

  result = contains(list, identifier, compare_to);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_shift_left_2el_array)
{
  Register el;
  bool result;
  union Key k1, k2;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 2;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->array[0].key.i, 2);
  ck_assert_int_eq(list->array[1].key.i, 2);
}
END_TEST

START_TEST(test_shift_left_2nd_el_in_4_el_array)
{
  Register el;
  bool result;
  int index = 1;
  int capacity = 5;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 3);
  ck_assert_int_eq(list->array[2].key.i, 4);
  ck_assert_int_eq(list->array[3].key.i, 4);
}
END_TEST

START_TEST(test_shift_left_fail_head)
{
  Register el;
  bool result;
  int index = -1;
  int capacity = 5;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 2);
  ck_assert_int_eq(list->array[2].key.i, 3);
  ck_assert_int_eq(list->array[3].key.i, 4);
}
END_TEST

START_TEST(test_shift_left_fail_tail)
{
  Register el;
  bool result;
  int index = 4;
  int capacity = 5;
  union Key k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 2);
  ck_assert_int_eq(list->array[2].key.i, 3);
  ck_assert_int_eq(list->array[3].key.i, 4);
}
END_TEST

START_TEST(test_shift_right_2nd_el_in_4_el_array)
{
  Register el;
  union Key k1, k2, k3, k4;
  int index = 1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  shift_right(list, index);

  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 2);
  ck_assert_int_eq(list->array[2].key.i, 2);
  ck_assert_int_eq(list->array[3].key.i, 3);
  ck_assert_int_eq(list->array[4].key.i, 4);
}
END_TEST

START_TEST(test_shift_right_1st_el_in_4_el_filled_array)
{
  Register el;
  union Key k1, k2, k3, k4;
  int index = 0;
  int capacity = 4;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  shift_right(list, index);

  ck_assert_int_eq(list->capacity, 8);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 1);
  ck_assert_int_eq(list->array[2].key.i, 2);
  ck_assert_int_eq(list->array[3].key.i, 3);
  ck_assert_int_eq(list->array[4].key.i, 4);
}
END_TEST

START_TEST(test_discard_head_4_el)
{
  Register el;
  bool result;
  union Key k1, k2, k3, k4;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  result = discard(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(list->array[0].key.i, 2);
  ck_assert_int_eq(list->array[1].key.i, 3);
  ck_assert_int_eq(list->array[2].key.i, 4);
}
END_TEST

START_TEST(test_discard_tail_1_el)
{
  Register el;
  bool result;
  union Key k1;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 1;

  k1.i = 15;
  el.key = k1;
  list->array[0] = el;

  result = discard(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->size, 0);
}
END_TEST

START_TEST(test_discard_tail_4_el)
{
  Register el;
  bool result;
  union Key k1, k2, k3, k4;
  int index = 3;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1.i = 1;
  el.key = k1;
  list->array[0] = el;

  k2.i = 2;
  el.key = k2;
  list->array[1] = el;

  k3.i = 3;
  el.key = k3;
  list->array[2] = el;

  k4.i = 4;
  el.key = k4;
  list->array[3] = el;

  result = discard(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(list->array[0].key.i, 1);
  ck_assert_int_eq(list->array[1].key.i, 2);
  ck_assert_int_eq(list->array[2].key.i, 3);
}
END_TEST

START_TEST(test_discard_idx_1_twice_5_el)
{
  Register el;
  bool result_1, result_2;
  union Key k1, k2, k3, k4, k5;
  int index = 1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 5;

  k1.i = 10;
  el.key = k1;
  list->array[0] = el;

  k2.i = 20;
  el.key = k2;
  list->array[1] = el;

  k3.i = 30;
  el.key = k3;
  list->array[2] = el;

  k4.i = 1;
  el.key = k4;
  list->array[3] = el;

  k5.i = 2;
  el.key = k5;
  list->array[4] = el;

  result_1 = discard(list, index);
  result_2 = discard(list, index);

  ck_assert_int_eq(result_1, true);
  ck_assert_int_eq(result_2, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(list->array[0].key.i, 10);
  ck_assert_int_eq(list->array[1].key.i, 1);
  ck_assert_int_eq(list->array[2].key.i, 2);
}
END_TEST

START_TEST(test_index_of_success)
{
  Register el;
  union Key identifier;
  int result, capacity;
  union Key k1, k2, k3, k4, k5;

  capacity = 7;
  init_list(list, capacity);
  list->size = 5;

  k1.i = 10;
  el.key = k1;
  list->array[0] = el;

  k2.i = 20;
  el.key = k2;
  list->array[1] = el;

  k3.i = 30;
  el.key = k3;
  list->array[2] = el;

  k4.i = 1;
  el.key = k4;
  list->array[3] = el;

  k5.i = 2;
  el.key = k5;
  list->array[4] = el;

  identifier.i = 30;
  result = index_of(list, identifier, compare_to);

  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->array[0].key.i, 10);
  ck_assert_int_eq(list->array[1].key.i, 20);
  ck_assert_int_eq(list->array[2].key.i, 30);
  ck_assert_int_eq(list->array[3].key.i, 1);
  ck_assert_int_eq(list->array[4].key.i, 2);
}
END_TEST

START_TEST(test_index_of_failure)
{
  Register el;
  union Key identifier;
  int result, capacity;
  union Key k1, k2, k3, k4, k5;

  capacity = 7;
  init_list(list, capacity);
  list->size = 5;

  k1.i = 10;
  el.key = k1;
  list->array[0] = el;

  k2.i = 20;
  el.key = k2;
  list->array[1] = el;

  k3.i = 30;
  el.key = k3;
  list->array[2] = el;

  k4.i = 1;
  el.key = k4;
  list->array[3] = el;

  k5.i = 2;
  el.key = k5;
  list->array[4] = el;

  identifier.i = 100;
  result = index_of(list, identifier, compare_to);

  ck_assert_int_eq(result, -1);
  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->array[0].key.i, 10);
  ck_assert_int_eq(list->array[1].key.i, 20);
  ck_assert_int_eq(list->array[2].key.i, 30);
  ck_assert_int_eq(list->array[3].key.i, 1);
  ck_assert_int_eq(list->array[4].key.i, 2);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("ArrayList Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");
  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_init_list);

  tcase_add_test(tc_core, test_insert1_capacity1);
  tcase_add_test(tc_core, test_insert3_capacity1);
  tcase_add_test(tc_core, test_insert4_capacity5);

  tcase_add_test(tc_core, test_insert_at_capacity1);
  tcase_add_test(tc_core, test_insert_twice_at_capacity1);
  tcase_add_test(tc_core, test_insert_at_capacity5);
  tcase_add_test(tc_core, test_insert_at_last_index);

  tcase_add_test(tc_core, test_set_success);
  tcase_add_test(tc_core, test_set_head_fail);
  tcase_add_test(tc_core, test_set_tail_fail);

  tcase_add_test(tc_core, test_get_success);
  tcase_add_test(tc_core, test_get_head_fail);
  tcase_add_test(tc_core, test_get_tail_fail);

  tcase_add_test(tc_core, test_contains_success);
  tcase_add_test(tc_core, test_contains_fail);

  tcase_add_test(tc_core, test_shift_left_2el_array);
  tcase_add_test(tc_core, test_shift_left_2nd_el_in_4_el_array);
  tcase_add_test(tc_core, test_shift_left_fail_head);
  tcase_add_test(tc_core, test_shift_left_fail_tail);

  tcase_add_test(tc_core, test_shift_right_2nd_el_in_4_el_array);
  tcase_add_test(tc_core, test_shift_right_1st_el_in_4_el_filled_array);

  tcase_add_test(tc_core, test_discard_tail_1_el);
  tcase_add_test(tc_core, test_discard_tail_4_el);
  tcase_add_test(tc_core, test_discard_head_4_el);
  tcase_add_test(tc_core, test_discard_idx_1_twice_5_el);

  tcase_add_test(tc_core, test_index_of_success);
  tcase_add_test(tc_core, test_index_of_failure);

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
