#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <seq_list.h>

SeqList *sl;
Register reg;

void setup(void);
void teardown(void);
Suite *make_seq_list_suite(void);

void setup(void)
{
  sl = (SeqList *)malloc(sizeof(SeqList));
}

void teardown(void)
{
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
  init_seq_list(sl);

  reg.key = 13;
  bool result = insert_elem(sl, reg, 0);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(sl->A[0].key, 13);
}
END_TEST

START_TEST(test_insert_elem_2)
{
  init_seq_list(sl);

  reg.key = -8;
  bool result1 = insert_elem(sl, reg, 0);

  reg.key = 7;
  bool result2 = insert_elem(sl, reg, 1);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(sl->A[0].key, -8);
  ck_assert_int_eq(sl->A[1].key, 7);
}
END_TEST

START_TEST(test_insert_elem_3)
{
  init_seq_list(sl);

  reg.key = -8;
  bool result1 = insert_elem(sl, reg, 0);

  reg.key = 7;
  bool result2 = insert_elem(sl, reg, 2);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, false);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(sl->A[0].key, -8);
}
END_TEST

START_TEST(test_insert_elem_4)
{
  init_seq_list(sl);

  reg.key = -8;
  bool result = insert_elem(sl, reg, -1);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_insert_sorted_1)
{
  init_seq_list(sl);

  reg.key = 13;
  bool result = insert_sorted(sl, reg);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 1);
  ck_assert_int_eq(sl->A[0].key, 13);
}
END_TEST

START_TEST(test_insert_sorted_2)
{
  init_seq_list(sl);

  reg.key = 7;
  bool result2 = insert_sorted(sl, reg);

  reg.key = -8;
  bool result1 = insert_sorted(sl, reg);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(sl->A[0].key, -8);
  ck_assert_int_eq(sl->A[1].key, 7);
}
END_TEST

START_TEST(test_insert_sorted_3)
{
  init_seq_list(sl);

  reg.key = -8;
  bool result1 = insert_sorted(sl, reg);

  reg.key = -10;
  bool result2 = insert_sorted(sl, reg);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(sl->nElem, 2);
  ck_assert_int_eq(sl->A[0].key, -10);
  ck_assert_int_eq(sl->A[1].key, -8);
}
END_TEST

START_TEST(test_insert_sorted_4)
{
  reg.key = 10;
  bool result1 = insert_sorted(sl, reg);

  reg.key = -8;
  bool result2 = insert_sorted(sl, reg);

  reg.key = 0;
  bool result3 = insert_sorted(sl, reg);


  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(sl->A[0].key, -8);
  ck_assert_int_eq(sl->A[1].key, 0);
  ck_assert_int_eq(sl->A[2].key, 10);
}
END_TEST

START_TEST(test_seq_search_1)
{
  init_seq_list(sl);
  ck_assert_int_eq(seq_search(sl, 10), -1);
}
END_TEST

START_TEST(test_seq_search_2)
{
  init_seq_list(sl);
  sl->A[0].key = 3;
  sl->nElem = 1;
  ck_assert_int_eq(seq_search(sl, 3), 0);
}
END_TEST

START_TEST(test_seq_search_3)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = -5;
  sl->A[2].key = 4;
  sl->A[3].key = 4;
  sl->nElem = 4;

  ck_assert_int_eq(seq_search(sl, 4), 2);
}
END_TEST

START_TEST(test_seq_search_4)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = -1;
  sl->A[2].key = 2;
  sl->A[3].key = -3;
  sl->nElem = 4;

  ck_assert_int_eq(seq_search(sl, 5), -1);
}
END_TEST

START_TEST(test_sentinel_search_1)
{
  init_seq_list(sl);
  ck_assert_int_eq(sentinel_search(sl, 10), -1);
}
END_TEST

START_TEST(test_sentinel_search_2)
{
  init_seq_list(sl);
  sl->A[0].key = 3;
  sl->nElem = 1;
  ck_assert_int_eq(sentinel_search(sl, 3), 0);
}
END_TEST

START_TEST(test_sentinel_search_3)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = -5;
  sl->A[2].key = 4;
  sl->A[3].key = 4;
  sl->nElem = 4;

  ck_assert_int_eq(sentinel_search(sl, 4), 2);
}
END_TEST

START_TEST(test_sentinel_search_4)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = -1;
  sl->A[2].key = 2;
  sl->A[3].key = -3;
  sl->nElem = 4;

  ck_assert_int_eq(sentinel_search(sl, 5), -1);
}
END_TEST

START_TEST(test_binary_search_1)
{
  init_seq_list(sl);
  ck_assert_int_eq(binary_search(sl, 10), -1);
}
END_TEST

START_TEST(test_binary_search_2)
{
  init_seq_list(sl);
  sl->A[0].key = 3;
  sl->nElem = 1;
  ck_assert_int_eq(binary_search(sl, 3), 0);
}
END_TEST

START_TEST(test_binary_search_3)
{
  init_seq_list(sl);
  sl->A[0].key = -5;
  sl->A[1].key = 0;
  sl->A[2].key = 4;
  sl->A[3].key = 4;
  sl->nElem = 4;

  ck_assert_int_eq(binary_search(sl, 4), 2);
}
END_TEST

START_TEST(test_binary_search_4)
{
  init_seq_list(sl);
  sl->A[0].key = -3;
  sl->A[1].key = -1;
  sl->A[2].key = 0;
  sl->A[3].key = 2;
  sl->nElem = 4;

  ck_assert_int_eq(binary_search(sl, 5), -1);
}
END_TEST

START_TEST(test_remove_elem_1)
{
  init_seq_list(sl);
  sl->A[0].key = 20;
  sl->nElem = 1;

  bool result = remove_elem(20, sl);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 0);
}
END_TEST

START_TEST(test_remove_elem_2)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = 1;
  sl->nElem = 2;

  bool result = remove_elem(2, sl);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_remove_elem_3)
{
  init_seq_list(sl);
  sl->A[0].key = 0;
  sl->A[1].key = -1;
  sl->A[2].key = 2;
  sl->A[3].key = -3;
  sl->nElem = 4;

  bool result = remove_elem(2, sl);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(sl->A[0].key, 0);
  ck_assert_int_eq(sl->A[1].key, -1);
  ck_assert_int_eq(sl->A[2].key, -3);
}
END_TEST

START_TEST(test_remove_elem_4)
{
  init_seq_list(sl);
  sl->A[0].key = 7;
  sl->A[1].key = 1;
  sl->A[2].key = 7;
  sl->A[3].key = -2;
  sl->nElem = 4;

  bool result = remove_elem(7, sl);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(sl->nElem, 3);
  ck_assert_int_eq(sl->A[0].key, 1);
  ck_assert_int_eq(sl->A[1].key, 7);
  ck_assert_int_eq(sl->A[2].key, -2);
}
END_TEST

Suite *make_seq_list_suite(void)
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

  sr = srunner_create(make_seq_list_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "test.log");
  srunner_set_xml(sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
