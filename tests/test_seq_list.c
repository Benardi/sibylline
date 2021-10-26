#include <check.h>
#include <malloc.h>
#include <seq_list.h>
#include <stdint.h>
#include <stdlib.h>

SeqList* sl;
Register* reg;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

int max_n_elems = 20;

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
  sl = malloc(sizeof(SeqList));
}

void teardown(void)
{
  free(reg);
  free(sl);
}

START_TEST(test_init_seq_list_1)
{
  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_init_seq_list_2)
{
  sl->n_elems = 0;
  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_init_seq_list_3)
{
  sl->n_elems = 127;
  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_init_seq_list_4)
{
  sl->n_elems = -127;
  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_size_1)
{
  sl->n_elems = 0;
  ck_assert_int_eq(size(sl), 0);
}
END_TEST

START_TEST(test_size_2)
{
  sl->n_elems = 10;
  ck_assert_int_eq(size(sl), 10);
}
END_TEST

START_TEST(test_size_3)
{
  sl->n_elems = -10;
  ck_assert_int_eq(size(sl), -10);
}
END_TEST

START_TEST(test_reinit_seq_list_1)
{
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->n_elems, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_2)
{
  sl->n_elems = 0;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->n_elems, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_3)
{
  sl->n_elems = 24;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->n_elems, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_4)
{
  sl->n_elems = -24;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->n_elems, 0);
}
END_TEST

START_TEST(test_insert_elem_1)
{
  union Key k1;
  bool result;

  k1.i = 13;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result = insert_elem(sl, *reg, 0);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->n_elems, 1);
  ck_assert_int_eq(sl->array[0].key.i, 13);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_elem_2)
{
  union Key k1, k2;
  bool result1;
  bool result2;

  k1.i = -8;
  k2.i = 7;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result1 = insert_elem(sl, *reg, 0);

  reg->key = k2;
  result2 = insert_elem(sl, *reg, 1);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->n_elems, 2);
  ck_assert_int_eq(sl->array[0].key.i, -8);
  ck_assert_int_eq(sl->array[1].key.i, 7);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_elem_3)
{
  union Key k1, k2;
  bool result1;
  bool result2;

  k1.i = -8;
  k2.i = 7;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result1 = insert_elem(sl, *reg, 0);

  reg->key = k2;
  result2 = insert_elem(sl, *reg, 2);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, false);
  ck_assert_int_eq(sl->n_elems, 1);
  ck_assert_int_eq(sl->array[0].key.i, -8);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_elem_4)
{
  union Key k1;
  bool result;

  k1.i = -8;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result = insert_elem(sl, *reg, -1);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_sorted_1)
{
  union Key k1;
  bool result;

  k1.i = 13;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->n_elems, 1);
  ck_assert_int_eq(sl->array[0].key.i, 13);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_sorted_2)
{
  union Key k1, k2;
  bool result1;
  bool result2;

  init_seq_list(sl, max_n_elems);

  k1.i = 7;
  k2.i = -8;

  reg->key = k1;
  result2 = insert_sorted(sl, *reg, compare);

  reg->key = k2;
  result1 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->n_elems, 2);
  ck_assert_int_eq(sl->array[0].key.i, -8);
  ck_assert_int_eq(sl->array[1].key.i, 7);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_sorted_3)
{
  union Key k1, k2;
  bool result1;
  bool result2;

  k1.i = -8;
  k2.i = -10;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result1 = insert_sorted(sl, *reg, compare);

  reg->key = k2;
  result2 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->n_elems, 2);
  ck_assert_int_eq(sl->array[0].key.i, -10);
  ck_assert_int_eq(sl->array[1].key.i, -8);

  free(sl->array);
}
END_TEST

START_TEST(test_insert_sorted_4)
{
  union Key k1, k2, k3;
  bool result1;
  bool result2;
  bool result3;

  k1.i = 10;
  k2.i = -8;
  k3.i = 0;

  init_seq_list(sl, max_n_elems);

  reg->key = k1;
  result1 = insert_sorted(sl, *reg, compare);

  reg->key = k2;
  result2 = insert_sorted(sl, *reg, compare);

  reg->key = k3;
  result3 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, true);
  ck_assert_int_eq(sl->n_elems, 3);
  ck_assert_int_eq(sl->array[0].key.i, -8);
  ck_assert_int_eq(sl->array[1].key.i, 0);
  ck_assert_int_eq(sl->array[2].key.i, 10);

  free(sl->array);
}
END_TEST

START_TEST(test_seq_search_1)
{
  union Key k1;
  k1.i = 10;

  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(seq_search(sl, k1, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_seq_search_2)
{
  union Key k1, k2;

  k1.i = 3;
  k2.i = 3;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->n_elems = 1;
  ck_assert_int_eq(seq_search(sl, k2, compare), 0);

  free(sl->array);
}
END_TEST

START_TEST(test_seq_search_3)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 0;
  k2.i = -5;
  k3.i = 4;
  k4.i = 4;
  k5.i = 4;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(seq_search(sl, k5, compare), 2);

  free(sl->array);
}
END_TEST

START_TEST(test_seq_search_4)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 0;
  k2.i = -1;
  k3.i = 2;
  k4.i = -3;
  k5.i = 5;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(seq_search(sl, k5, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_sentinel_search_1)
{
  union Key k1;
  k1.i = 10;

  init_seq_list(sl, max_n_elems);
  ck_assert_int_eq(sentinel_search(sl, k1, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_sentinel_search_2)
{
  union Key k1, k2;

  k1.i = 3;
  k2.i = 3;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->n_elems = 1;
  ck_assert_int_eq(sentinel_search(sl, k2, compare), 0);

  free(sl->array);
}
END_TEST

START_TEST(test_sentinel_search_3)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 0;
  k2.i = -5;
  k3.i = 4;
  k4.i = 4;
  k5.i = 4;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(sentinel_search(sl, k5, compare), 2);

  free(sl->array);
}
END_TEST

START_TEST(test_sentinel_search_4)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 0;
  k2.i = -1;
  k3.i = 2;
  k4.i = -3;
  k5.i = 5;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(sentinel_search(sl, k5, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_binary_search_1)
{
  union Key k1;

  k1.i = 10;

  init_seq_list(sl, max_n_elems);

  ck_assert_int_eq(binary_search(sl, k1, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_binary_search_2)
{
  union Key k1, k2;

  k1.i = 3;
  k2.i = 3;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->n_elems = 1;
  ck_assert_int_eq(binary_search(sl, k2, compare), 0);

  free(sl->array);
}
END_TEST

START_TEST(test_binary_search_3)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = 5;
  k2.i = 0;
  k3.i = 4;
  k4.i = 4;
  k5.i = 4;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(binary_search(sl, k5, compare), 2);

  free(sl->array);
}
END_TEST

START_TEST(test_binary_search_4)
{
  union Key k1, k2, k3, k4, k5;

  k1.i = -3;
  k2.i = -1;
  k3.i = 0;
  k4.i = 2;
  k5.i = 5;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  ck_assert_int_eq(binary_search(sl, k5, compare), -1);

  free(sl->array);
}
END_TEST

START_TEST(test_remove_elem_1)
{
  union Key k1, k2;
  bool result;

  k1.i = 20;
  k2.i = 20;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->n_elems = 1;

  result = remove_elem(sl, k2, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->n_elems, 0);

  free(sl->array);
}
END_TEST

START_TEST(test_remove_elem_2)
{
  union Key k1, k2, k3;
  bool result;

  k1.i = 0;
  k2.i = 1;
  k3.i = 2;

  init_seq_list(sl, max_n_elems);

  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->n_elems = 2;

  result = remove_elem(sl, k3, compare);

  ck_assert_int_eq(result, false);

  free(sl->array);
}
END_TEST

START_TEST(test_remove_elem_3)
{
  bool result;

  union Key k1, k2, k3, k4, k5;

  k1.i = 0;
  k2.i = -1;
  k3.i = 2;
  k4.i = -3;
  k5.i = 2;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  result = remove_elem(sl, k5, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->n_elems, 3);
  ck_assert_int_eq(sl->array[0].key.i, 0);
  ck_assert_int_eq(sl->array[1].key.i, -1);
  ck_assert_int_eq(sl->array[2].key.i, -3);

  free(sl->array);
}
END_TEST

START_TEST(test_remove_elem_4)
{
  bool result;

  union Key k1, k2, k3, k4, k5;

  k1.i = 7;
  k2.i = 1;
  k3.i = 7;
  k4.i = -2;
  k5.i = 7;

  init_seq_list(sl, max_n_elems);
  sl->array[0].key = k1;
  sl->array[1].key = k2;
  sl->array[2].key = k3;
  sl->array[3].key = k4;
  sl->n_elems = 4;

  result = remove_elem(sl, k5, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->n_elems, 3);
  ck_assert_int_eq(sl->array[0].key.i, 1);
  ck_assert_int_eq(sl->array[1].key.i, 7);
  ck_assert_int_eq(sl->array[2].key.i, -2);

  free(sl->array);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("SeqList Creation Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_init_seq_list_1);
  tcase_add_test(tc_core, test_init_seq_list_2);
  tcase_add_test(tc_core, test_init_seq_list_3);
  tcase_add_test(tc_core, test_init_seq_list_4);

  tcase_add_test(tc_core, test_size_1);
  tcase_add_test(tc_core, test_size_2);
  tcase_add_test(tc_core, test_size_3);

  tcase_add_test(tc_core, test_reinit_seq_list_1);
  tcase_add_test(tc_core, test_reinit_seq_list_2);
  tcase_add_test(tc_core, test_reinit_seq_list_3);
  tcase_add_test(tc_core, test_reinit_seq_list_4);

  tcase_add_test(tc_core, test_insert_elem_1);
  tcase_add_test(tc_core, test_insert_elem_2);
  tcase_add_test(tc_core, test_insert_elem_3);
  tcase_add_test(tc_core, test_insert_elem_4);

  tcase_add_test(tc_core, test_insert_sorted_1);
  tcase_add_test(tc_core, test_insert_sorted_2);
  tcase_add_test(tc_core, test_insert_sorted_3);
  tcase_add_test(tc_core, test_insert_sorted_4);

  tcase_add_test(tc_core, test_seq_search_1);
  tcase_add_test(tc_core, test_seq_search_2);
  tcase_add_test(tc_core, test_seq_search_3);
  tcase_add_test(tc_core, test_seq_search_4);

  tcase_add_test(tc_core, test_sentinel_search_1);
  tcase_add_test(tc_core, test_sentinel_search_2);
  tcase_add_test(tc_core, test_sentinel_search_3);
  tcase_add_test(tc_core, test_sentinel_search_4);

  tcase_add_test(tc_core, test_binary_search_1);
  tcase_add_test(tc_core, test_binary_search_2);
  tcase_add_test(tc_core, test_binary_search_3);
  tcase_add_test(tc_core, test_binary_search_4);

  tcase_add_test(tc_core, test_remove_elem_1);
  tcase_add_test(tc_core, test_remove_elem_2);
  tcase_add_test(tc_core, test_remove_elem_3);
  tcase_add_test(tc_core, test_remove_elem_4);

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
