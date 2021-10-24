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
int compare_to(void* key1, void* key2);

void setup(void)
{
  list = malloc(sizeof(ArrayList));
}

void teardown(void)
{
  free(list->array);
  free(list);
}

int compare_to(void* key1, void* key2)
{
  int result;
  double k1 = *((int*)key1);
  double k2 = *((int*)key2);

  if (k1 == k2)
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
  int capacity = 1;
  int k = 5;

  init_list(list, capacity);

  el.key = &k;
  insert(list, el);

  ck_assert_int_eq(list->size, 1);
  ck_assert_int_eq(list->capacity, 1);
  ck_assert_int_eq(*((int*)list->array[0].key), 5);
}
END_TEST

START_TEST(test_insert3_capacity1)
{
  Register el;
  int capacity = 1;
  int k1, k2, k3;

  init_list(list, capacity);

  k1 = 5;
  el.key = &k1;
  insert(list, el);

  k2 = 15;
  el.key = &k2;
  insert(list, el);

  k3 = -10;
  el.key = &k3;
  insert(list, el);

  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(list->capacity, 4);
  ck_assert_int_eq(*((int*)list->array[0].key), 5);
  ck_assert_int_eq(*((int*)list->array[1].key), 15);
  ck_assert_int_eq(*((int*)list->array[2].key), -10);
}
END_TEST

START_TEST(test_insert4_capacity5)
{
  Register el;
  int capacity = 5;
  int k1, k2, k3, k4;

  init_list(list, capacity);

  k1 = 5;
  el.key = &k1;
  insert(list, el);

  k2 = 15;
  el.key = &k2;
  insert(list, el);

  k3 = -10;
  el.key = &k3;
  insert(list, el);

  k4 = -15;
  el.key = &k4;
  insert(list, el);

  ck_assert_int_eq(list->size, 4);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 5);
  ck_assert_int_eq(*((int*)list->array[1].key), 15);
  ck_assert_int_eq(*((int*)list->array[2].key), -10);
  ck_assert_int_eq(*((int*)list->array[3].key), -15);
}
END_TEST

START_TEST(test_insert_at_capacity1)
{
  Register el;
  int capacity = 1;
  int k = 5;

  init_list(list, capacity);

  el.key = &k;
  insert_at(list, el, 0);

  ck_assert_int_eq(list->size, 1);
  ck_assert_int_eq(list->capacity, 1);
  ck_assert_int_eq(*((int*)list->array[0].key), 5);
}
END_TEST

START_TEST(test_insert_twice_at_capacity1)
{
  Register el;
  int capacity = 1;
  int k1, k2;
  k1 = 5;
  k2 = 20;

  init_list(list, capacity);

  el.key = &k1;
  insert_at(list, el, 0);

  el.key = &k2;
  insert_at(list, el, 0);

  ck_assert_int_eq(list->size, 2);
  ck_assert_int_eq(list->capacity, 2);
  ck_assert_int_eq(*((int*)list->array[0].key), 20);
  ck_assert_int_eq(*((int*)list->array[1].key), 5);
}
END_TEST

START_TEST(test_insert_at_capacity5)
{
  Register el;
  int capacity = 5;
  int k, k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 3;
  el.key = &k2;
  list->array[1] = el;

  k3 = 4;
  el.key = &k3;
  list->array[2] = el;

  k4 = 5;
  el.key = &k4;
  list->array[3] = el;

  k = 2;
  el.key = &k;
  insert_at(list, el, 1);

  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
  ck_assert_int_eq(*((int*)list->array[2].key), 3);
  ck_assert_int_eq(*((int*)list->array[3].key), 4);
  ck_assert_int_eq(*((int*)list->array[4].key), 5);
}
END_TEST

START_TEST(test_insert_at_last_index)
{
  Register el;
  int capacity = 5;
  int k, k1, k2, k3, k4;
  int index = 4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 3;
  el.key = &k2;
  list->array[1] = el;

  k3 = 4;
  el.key = &k3;
  list->array[2] = el;

  k4 = 5;
  el.key = &k4;
  list->array[3] = el;

  k = 12;
  el.key = &k;
  insert_at(list, el, index);

  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 3);
  ck_assert_int_eq(*((int*)list->array[2].key), 4);
  ck_assert_int_eq(*((int*)list->array[3].key), 5);
  ck_assert_int_eq(*((int*)list->array[4].key), 12);
}
END_TEST

START_TEST(test_set_success)
{
  Register el;
  int capacity = 4;
  int k1, k2, k3, k4;
  bool result;

  init_list(list, capacity);
  list->size = 4;

  k1 = 5;
  el.key = &k1;
  list->array[0] = el;

  k2 = 15;
  el.key = &k2;
  list->array[1] = el;

  k3 = -10;
  el.key = &k3;
  list->array[2] = el;

  k4 = 25;
  el.key = &k4;
  list->array[3] = el;

  result = set(list, el, 3);

  ck_assert_int_eq(*((int*)list->array[3].key), 25);
  ck_assert_int_eq(result, true);
}
END_TEST

START_TEST(test_set_head_fail)
{
  Register el;
  int capacity = 4;
  int k1, k2, k3;
  bool result;

  init_list(list, capacity);
  list->size = 3;

  k1 = 5;
  el.key = &k1;
  list->array[0] = el;

  k2 = 15;
  el.key = &k2;
  list->array[1] = el;

  k3 = -10;
  el.key = &k3;
  list->array[2] = el;

  result = set(list, el, -1);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_set_tail_fail)
{
  Register el;
  int capacity = 4;
  int k1, k2, k3;
  bool result;

  init_list(list, capacity);
  list->size = 3;

  k1 = 5;
  el.key = &k1;
  list->array[0] = el;

  k2 = 15;
  el.key = &k2;
  list->array[1] = el;

  k3 = -10;
  el.key = &k3;
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
  int k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 25;
  el.key = &k1;
  list->array[0] = el;

  k2 = 35;
  el.key = &k2;
  list->array[1] = el;

  k3 = -20;
  el.key = &k3;
  list->array[2] = el;

  k4 = 58;
  el.key = &k4;
  list->array[3] = el;

  result = get(list, 1);

  ck_assert_int_eq(result == &list->array[1], true);
  ck_assert_int_eq(*((int*)result->key), 35);
}
END_TEST

START_TEST(test_get_head_fail)
{
  Register el;
  Register* result;
  int capacity = 4;
  int k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 25;
  el.key = &k1;
  list->array[0] = el;

  k2 = 35;
  el.key = &k2;
  list->array[1] = el;

  k3 = -20;
  el.key = &k3;
  list->array[2] = el;

  k4 = 58;
  el.key = &k4;
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
  int k1, k2, k3, k4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 25;
  el.key = &k1;
  list->array[0] = el;

  k2 = 35;
  el.key = &k2;
  list->array[1] = el;

  k3 = -20;
  el.key = &k3;
  list->array[2] = el;

  k4 = 58;
  el.key = &k4;
  list->array[3] = el;

  result = get(list, 4);

  ck_assert_int_eq(result == NULL, true);
}
END_TEST

START_TEST(test_contains_success)
{
  Register el;
  int capacity = 10;
  int k1, k2, k3, k4, k5;
  int k;
  bool result;
  void* identifier;

  init_list(list, capacity);
  list->size = 5;

  k1 = 5;
  el.key = &k1;
  list->array[0] = el;

  k2 = 15;
  el.key = &k2;
  list->array[1] = el;

  k3 = -10;
  el.key = &k3;
  list->array[2] = el;

  k4 = 25;
  el.key = &k4;
  list->array[3] = el;

  k5 = 32;
  el.key = &k5;
  list->array[4] = el;

  k = -10;
  identifier = (void*)&k;

  result = contains(list, identifier, compare_to);

  ck_assert_int_eq(result, true);
}
END_TEST

START_TEST(test_contains_fail)
{
  Register el;
  int capacity = 10;
  int k1, k2, k3, k4, k5;
  int k;
  bool result;
  void* identifier;

  init_list(list, capacity);
  list->size = 5;

  k1 = 5;
  el.key = &k1;
  list->array[0] = el;

  k2 = 15;
  el.key = &k2;
  list->array[1] = el;

  k3 = -10;
  el.key = &k3;
  list->array[2] = el;

  k4 = 25;
  el.key = &k4;
  list->array[3] = el;

  k5 = 32;
  el.key = &k5;
  list->array[4] = el;

  k = 48;
  identifier = (void*)&k;

  result = contains(list, identifier, compare_to);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_shift_left_2el_array)
{
  Register el;
  bool result;
  int k1, k2;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 2;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)list->array[0].key), 2);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
}
END_TEST

START_TEST(test_shift_left_2nd_el_in_4_el_array)
{
  Register el;
  bool result;
  int k1, k2, k3, k4;
  int index = 1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 3);
  ck_assert_int_eq(*((int*)list->array[2].key), 4);
  ck_assert_int_eq(*((int*)list->array[3].key), 4);
}
END_TEST

START_TEST(test_shift_left_fail_head)
{
  Register el;
  bool result;
  int k1, k2, k3, k4;
  int index = -1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
  ck_assert_int_eq(*((int*)list->array[2].key), 3);
  ck_assert_int_eq(*((int*)list->array[3].key), 4);
}
END_TEST

START_TEST(test_shift_left_fail_tail)
{
  Register el;
  bool result;
  int k1, k2, k3, k4;
  int index = 4;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  result = shift_left(list, index);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
  ck_assert_int_eq(*((int*)list->array[2].key), 3);
  ck_assert_int_eq(*((int*)list->array[3].key), 4);
}
END_TEST

START_TEST(test_shift_right_2nd_el_in_4_el_array)
{
  Register el;
  int k1, k2, k3, k4;
  int index = 1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  shift_right(list, index);

  ck_assert_int_eq(list->capacity, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
  ck_assert_int_eq(*((int*)list->array[2].key), 2);
  ck_assert_int_eq(*((int*)list->array[3].key), 3);
  ck_assert_int_eq(*((int*)list->array[4].key), 4);
}
END_TEST

START_TEST(test_shift_right_1st_el_in_4_el_filled_array)
{
  Register el;
  int k1, k2, k3, k4;
  int index = 0;
  int capacity = 4;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  shift_right(list, index);

  ck_assert_int_eq(list->capacity, 8);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 1);
  ck_assert_int_eq(*((int*)list->array[2].key), 2);
  ck_assert_int_eq(*((int*)list->array[3].key), 3);
  ck_assert_int_eq(*((int*)list->array[4].key), 4);
}
END_TEST

START_TEST(test_discard_head_4_el)
{
  Register el;
  bool result;
  int k1, k2, k3, k4;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  result = discard(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(*((int*)list->array[0].key), 2);
  ck_assert_int_eq(*((int*)list->array[1].key), 3);
  ck_assert_int_eq(*((int*)list->array[2].key), 4);
}
END_TEST

START_TEST(test_discard_tail_1_el)
{
  Register el;
  bool result;
  int k1;
  int index = 0;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 1;

  k1 = 15;
  el.key = &k1;
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
  int k1, k2, k3, k4;
  int index = 3;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 4;

  k1 = 1;
  el.key = &k1;
  list->array[0] = el;

  k2 = 2;
  el.key = &k2;
  list->array[1] = el;

  k3 = 3;
  el.key = &k3;
  list->array[2] = el;

  k4 = 4;
  el.key = &k4;
  list->array[3] = el;

  result = discard(list, index);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(*((int*)list->array[0].key), 1);
  ck_assert_int_eq(*((int*)list->array[1].key), 2);
  ck_assert_int_eq(*((int*)list->array[2].key), 3);
}
END_TEST

START_TEST(test_discard_idx_1_twice_5_el)
{
  Register el;
  bool result_1, result_2;
  int k1, k2, k3, k4, k5;
  int index = 1;
  int capacity = 5;

  init_list(list, capacity);
  list->size = 5;

  k1 = 10;
  el.key = &k1;
  list->array[0] = el;

  k2 = 20;
  el.key = &k2;
  list->array[1] = el;

  k3 = 30;
  el.key = &k3;
  list->array[2] = el;

  k4 = 1;
  el.key = &k4;
  list->array[3] = el;

  k5 = 2;
  el.key = &k5;
  list->array[4] = el;

  result_1 = discard(list, index);
  result_2 = discard(list, index);

  ck_assert_int_eq(result_1, true);
  ck_assert_int_eq(result_2, true);
  ck_assert_int_eq(list->size, 3);
  ck_assert_int_eq(*((int*)list->array[0].key), 10);
  ck_assert_int_eq(*((int*)list->array[1].key), 1);
  ck_assert_int_eq(*((int*)list->array[2].key), 2);
}
END_TEST

START_TEST(test_index_of_success)
{
  Register el;
  void* identifier;
  int result, value, capacity, k1, k2, k3, k4, k5;

  capacity = 7;
  init_list(list, capacity);
  list->size = 5;

  k1 = 10;
  el.key = &k1;
  list->array[0] = el;

  k2 = 20;
  el.key = &k2;
  list->array[1] = el;

  k3 = 30;
  el.key = &k3;
  list->array[2] = el;

  k4 = 1;
  el.key = &k4;
  list->array[3] = el;

  k5 = 2;
  el.key = &k5;
  list->array[4] = el;

  value = 30;
  identifier = &value;
  result = index_of(list, identifier, compare_to);

  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 10);
  ck_assert_int_eq(*((int*)list->array[1].key), 20);
  ck_assert_int_eq(*((int*)list->array[2].key), 30);
  ck_assert_int_eq(*((int*)list->array[3].key), 1);
  ck_assert_int_eq(*((int*)list->array[4].key), 2);
}
END_TEST

START_TEST(test_index_of_failure)
{
  Register el;
  void* identifier;
  int result, value, capacity, k1, k2, k3, k4, k5;

  capacity = 7;
  init_list(list, capacity);
  list->size = 5;

  k1 = 10;
  el.key = &k1;
  list->array[0] = el;

  k2 = 20;
  el.key = &k2;
  list->array[1] = el;

  k3 = 30;
  el.key = &k3;
  list->array[2] = el;

  k4 = 1;
  el.key = &k4;
  list->array[3] = el;

  k5 = 2;
  el.key = &k5;
  list->array[4] = el;

  value = 100;
  identifier = &value;
  result = index_of(list, identifier, compare_to);

  ck_assert_int_eq(result, -1);
  ck_assert_int_eq(list->size, 5);
  ck_assert_int_eq(*((int*)list->array[0].key), 10);
  ck_assert_int_eq(*((int*)list->array[1].key), 20);
  ck_assert_int_eq(*((int*)list->array[2].key), 30);
  ck_assert_int_eq(*((int*)list->array[3].key), 1);
  ck_assert_int_eq(*((int*)list->array[4].key), 2);
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
