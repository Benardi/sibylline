#include <check.h>
#include <malloc.h>
#include <seq_list.h>
#include <stdint.h>
#include <stdlib.h>

SeqList *sl;
Register *reg;

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
  init_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_init_seq_list_2)
{
  sl->nElem = 0;
  init_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_init_seq_list_3)
{
  sl->nElem = 127;
  init_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_init_seq_list_4)
{
  sl->nElem = -127;
  init_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_size_1)
{
  sl->nElem = 0;
  ck_assert_int_eq(size(sl), 0);
}
END_TEST

START_TEST(test_size_2)
{
  sl->nElem = 10;
  ck_assert_int_eq(size(sl), 10);
}
END_TEST

START_TEST(test_size_3)
{
  sl->nElem = -10;
  ck_assert_int_eq(size(sl), -10);
}
END_TEST

START_TEST(test_reinit_seq_list_1)
{
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_2)
{
  sl->nElem = 0;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_3)
{
  sl->nElem = 24;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_reinit_seq_list_4)
{
  sl->nElem = -24;
  reinit_seq_list(sl);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_insert_elem_1)
{
  int k1;
  bool result;

  k1 = 13;

  init_seq_list(sl);

  reg->key = &k1;
  result = insert_elem(sl, *reg, 0);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(*((int *)sl->A[0].key), 13);
}
END_TEST

START_TEST(test_insert_elem_2)
{
  int k1, k2;
  bool result1;
  bool result2;

  k1 = -8;
  k2 = 7;

  init_seq_list(sl);

  reg->key = &k1;
  result1 = insert_elem(sl, *reg, 0);

  reg->key = &k2;
  result2 = insert_elem(sl, *reg, 1);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(*((int *)sl->A[0].key), -8);
  ck_assert_int_eq(*((int *)sl->A[1].key), 7);
}
END_TEST

START_TEST(test_insert_elem_3)
{
  int k1, k2;
  bool result1;
  bool result2;

  k1 = -8;
  k2 = 7;

  init_seq_list(sl);

  reg->key = &k1;
  result1 = insert_elem(sl, *reg, 0);

  reg->key = &k2;
  result2 = insert_elem(sl, *reg, 2);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, false);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(*((int *)sl->A[0].key), -8);
}
END_TEST

START_TEST(test_insert_elem_4)
{
  int k1;
  bool result;

  k1 = -8;

  init_seq_list(sl);

  reg->key = &k1;
  result = insert_elem(sl, *reg, -1);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_insert_sorted_1)
{
  int k1;
  bool result;

  k1 = 13;

  init_seq_list(sl);

  reg->key = &k1;
  result = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(*((int *)sl->A[0].key), 13);
}
END_TEST

START_TEST(test_insert_sorted_2)
{
  int k1, k2;
  bool result1;
  bool result2;

  init_seq_list(sl);

  k1 = 7;
  k2 = -8;

  reg->key = &k1;
  result2 = insert_sorted(sl, *reg, compare);

  reg->key = &k2;
  result1 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(*((int *)sl->A[0].key), -8);
  ck_assert_int_eq(*((int *)sl->A[1].key), 7);
}
END_TEST

START_TEST(test_insert_sorted_3)
{
  int k1, k2;
  bool result1;
  bool result2;

  k1 = -8;
  k2 = -10;

  init_seq_list(sl);

  reg->key = &k1;
  result1 = insert_sorted(sl, *reg, compare);

  reg->key = &k2;
  result2 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(*((int *)sl->A[0].key), -10);
  ck_assert_int_eq(*((int *)sl->A[1].key), -8);
}
END_TEST

START_TEST(test_insert_sorted_4)
{
  int k1, k2, k3;
  bool result1;
  bool result2;
  bool result3;

  k1 = 10;
  k2 = -8;
  k3 = 0;

  init_seq_list(sl);

  reg->key = &k1;
  result1 = insert_sorted(sl, *reg, compare);

  reg->key = &k2;
  result2 = insert_sorted(sl, *reg, compare);

  reg->key = &k3;
  result3 = insert_sorted(sl, *reg, compare);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(*((int *)sl->A[0].key), -8);
  ck_assert_int_eq(*((int *)sl->A[1].key), 0);
  ck_assert_int_eq(*((int *)sl->A[2].key), 10);
}
END_TEST

START_TEST(test_seq_search_1)
{
  int k1 = 10;

  init_seq_list(sl);
  ck_assert_int_eq(seq_search(sl, &k1, compare), -1);
}
END_TEST

START_TEST(test_seq_search_2)
{
  int k1 = 3;
  int k2 = 3;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->nElem = 1;
  ck_assert_int_eq(seq_search(sl, &k2, compare), 0);
}
END_TEST

START_TEST(test_seq_search_3)
{
  int k1 = 0;
  int k2 = -5;
  int k3 = 4;
  int k4 = 4;
  int k5 = 4;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(seq_search(sl, &k5, compare), 2);
}
END_TEST

START_TEST(test_seq_search_4)
{
  int k1 = 0;
  int k2 = -1;
  int k3 = 2;
  int k4 = -3;
  int k5 = 5;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(seq_search(sl, &k5, compare), -1);
}
END_TEST

START_TEST(test_sentinel_search_1)
{
  int k1 = 10;

  init_seq_list(sl);
  ck_assert_int_eq(sentinel_search(sl, &k1, compare), -1);
}
END_TEST

START_TEST(test_sentinel_search_2)
{
  int k1 = 3;
  int k2 = 3;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->nElem = 1;
  ck_assert_int_eq(sentinel_search(sl, &k2, compare), 0);
}
END_TEST

START_TEST(test_sentinel_search_3)
{
  int k1 = 0;
  int k2 = -5;
  int k3 = 4;
  int k4 = 4;
  int k5 = 4;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(sentinel_search(sl, &k5, compare), 2);
}
END_TEST

START_TEST(test_sentinel_search_4)
{
  int k1 = 0;
  int k2 = -1;
  int k3 = 2;
  int k4 = -3;
  int k5 = 5;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(sentinel_search(sl, &k5, compare), -1);
}
END_TEST

START_TEST(test_binary_search_1)
{
  int k1 = 10;

  init_seq_list(sl);

  ck_assert_int_eq(binary_search(sl, &k1, compare), -1);
}
END_TEST

START_TEST(test_binary_search_2)
{
  int k1 = 3;
  int k2 = 3;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->nElem = 1;
  ck_assert_int_eq(binary_search(sl, &k2, compare), 0);
}
END_TEST

START_TEST(test_binary_search_3)
{
  int k1 = 5;
  int k2 = 0;
  int k3 = 4;
  int k4 = 4;
  int k5 = 4;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(binary_search(sl, &k5, compare), 2);
}
END_TEST

START_TEST(test_binary_search_4)
{
  int k1 = -3;
  int k2 = -1;
  int k3 = 0;
  int k4 = 2;
  int k5 = 5;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  ck_assert_int_eq(binary_search(sl, &k5, compare), -1);
}
END_TEST

START_TEST(test_remove_elem_1)
{
  int k1, k2;
  bool result;

  k1 = 20;
  k2 = 20;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->nElem = 1;

  result = remove_elem(sl, &k2, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_remove_elem_2)
{
  int k1, k2, k3;
  bool result;

  k1 = 0;
  k2 = 1;
  k3 = 2;

  init_seq_list(sl);

  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->nElem = 2;

  result = remove_elem(sl, &k3, compare);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_remove_elem_3)
{
  bool result;

  int k1 = 0;
  int k2 = -1;
  int k3 = 2;
  int k4 = -3;
  int k5 = 2;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  result = remove_elem(sl, &k5, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(*((int *)sl->A[0].key), 0);
  ck_assert_int_eq(*((int *)sl->A[1].key), -1);
  ck_assert_int_eq(*((int *)sl->A[2].key), -3);
}
END_TEST

START_TEST(test_remove_elem_4)
{
  bool result;

  int k1 = 7;
  int k2 = 1;
  int k3 = 7;
  int k4 = -2;
  int k5 = 7;

  init_seq_list(sl);
  sl->A[0].key = &k1;
  sl->A[1].key = &k2;
  sl->A[2].key = &k3;
  sl->A[3].key = &k4;
  sl->nElem = 4;

  result = remove_elem(sl, &k5, compare);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(*((int *)sl->A[0].key), 1);
  ck_assert_int_eq(*((int *)sl->A[1].key), 7);
  ck_assert_int_eq(*((int *)sl->A[2].key), -2);
}
END_TEST

Suite *make_test_suite(void)
{
  Suite *s;
  TCase *tc_core;

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
