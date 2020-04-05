#include <check.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <utils.h>

Suite* make_test_suite(void);

START_TEST(test_swap_1)
{
  int array[] = {5, 2, 4, 6, 1, 3};
  swap(array, 0, 1);

  ck_assert_int_eq(array[0], 2);
  ck_assert_int_eq(array[1], 5);
  ck_assert_int_eq(array[2], 4);
  ck_assert_int_eq(array[3], 6);
  ck_assert_int_eq(array[4], 1);
  ck_assert_int_eq(array[5], 3);
}
END_TEST

START_TEST(test_swap_2)
{
  int array[] = {5, 2, 4, 6, 1, 3};
  swap(array, 3, 3);

  ck_assert_int_eq(array[0], 5);
  ck_assert_int_eq(array[1], 2);
  ck_assert_int_eq(array[2], 4);
  ck_assert_int_eq(array[3], 6);
  ck_assert_int_eq(array[4], 1);
  ck_assert_int_eq(array[5], 3);
}
END_TEST

START_TEST(test_swap_3)
{
  int array[] = {5, 2, 4, 6, 1, 3};
  swap(array, 0, 0);

  ck_assert_int_eq(array[0], 5);
  ck_assert_int_eq(array[1], 2);
  ck_assert_int_eq(array[2], 4);
  ck_assert_int_eq(array[3], 6);
  ck_assert_int_eq(array[4], 1);
  ck_assert_int_eq(array[5], 3);
}
END_TEST

START_TEST(test_swap_4)
{
  int array[] = {5, 2, 4, 6, 1, 3};
  swap(array, 5, 5);

  ck_assert_int_eq(array[0], 5);
  ck_assert_int_eq(array[1], 2);
  ck_assert_int_eq(array[2], 4);
  ck_assert_int_eq(array[3], 6);
  ck_assert_int_eq(array[4], 1);
  ck_assert_int_eq(array[5], 3);
}
END_TEST

START_TEST(test_swap_5)
{
  int array[] = {5, -10, 4, -20, 1, 0};
  swap(array, 4, 1);

  ck_assert_int_eq(array[0], 5);
  ck_assert_int_eq(array[1], 1);
  ck_assert_int_eq(array[2], 4);
  ck_assert_int_eq(array[3], -20);
  ck_assert_int_eq(array[4], -10);
  ck_assert_int_eq(array[5], 0);
}
END_TEST

START_TEST(test_swap_6)
{
  int array[] = {5, -10, 4, -20, 1, 0};
  swap(array, 5, 2);

  ck_assert_int_eq(array[0], 5);
  ck_assert_int_eq(array[1], -10);
  ck_assert_int_eq(array[2], 0);
  ck_assert_int_eq(array[3], -20);
  ck_assert_int_eq(array[4], 1);
  ck_assert_int_eq(array[5], 4);
}
END_TEST

START_TEST(test_swap_7)
{
  int array[] = {-50, 0, 25, -33, 245, -535, 0, -67, 200, 300, -20};
  swap(array, 7, 3);

  ck_assert_int_eq(array[0], -50);
  ck_assert_int_eq(array[1], 0);
  ck_assert_int_eq(array[2], 25);
  ck_assert_int_eq(array[3], -67);
  ck_assert_int_eq(array[4], 245);
  ck_assert_int_eq(array[5], -535);
  ck_assert_int_eq(array[6], 0);
  ck_assert_int_eq(array[7], -33);
  ck_assert_int_eq(array[8], 200);
  ck_assert_int_eq(array[9], 300);
  ck_assert_int_eq(array[10], -20);
}
END_TEST

START_TEST(test_max_1)
{
  int max_idx;

  int array[] = {5, 2, 4, 6, 1, 3};
  max_idx = max(array, 0, 5);

  ck_assert_int_eq(max_idx, 3);
  ck_assert_int_eq(array[max_idx], 6);
}
END_TEST

START_TEST(test_max_2)
{
  int max_idx;

  int array[] = {5, 2, 4, 6, 1, 3};
  max_idx = max(array, 0, 2);

  ck_assert_int_eq(max_idx, 0);
  ck_assert_int_eq(array[max_idx], 5);
}
END_TEST

START_TEST(test_max_3)
{
  int max_idx;

  int array[] = {5, 2, 4, 6, 1, 3};
  max_idx = max(array, 4, 4);

  ck_assert_int_eq(max_idx, 4);
  ck_assert_int_eq(array[max_idx], 1);
}
END_TEST

START_TEST(test_max_4)
{
  int max_idx;

  int array[] = {5, 2, 4, 6, 1, 3};
  max_idx = max(array, 4, 4);

  ck_assert_int_eq(max_idx, 4);
  ck_assert_int_eq(array[max_idx], 1);
}
END_TEST

START_TEST(test_max_5)
{
  int max_idx;

  int array[] = {5, 2, 4, 6, 1, 3};
  max_idx = max(array, 3, 2);

  ck_assert_int_eq(max_idx, -1);
}
END_TEST

START_TEST(test_max_6)
{
  int max_idx;

  int array[] = {-200, -50, -150, -25, -175, -300, -275, -33};
  max_idx = max(array, 0, 7);

  ck_assert_int_eq(max_idx, 3);
  ck_assert_int_eq(array[max_idx], -25);
}
END_TEST

START_TEST(test_max_7)
{
  int max_idx;

  int array[] = {-200, -50, -150, -25, -175, -300, -275, -33};
  max_idx = max(array, 4, 6);

  ck_assert_int_eq(max_idx, 4);
  ck_assert_int_eq(array[max_idx], -175);
}
END_TEST

START_TEST(test_max_8)
{
  int max_idx;

  int array[] = {-30, -20, -10, 0, 10, 15, 30, 50, 60, 66, 90, 93, 127};
  max_idx = max(array, 0, 12);

  ck_assert_int_eq(max_idx, 12);
  ck_assert_int_eq(array[max_idx], 127);
}
END_TEST

START_TEST(test_max_9)
{
  int max_idx;

  int array[] = {-30, -20, -10, 0, 10, 15, 30, 50, 60, 66, 90, 93, 127};
  max_idx = max(array, 2, 9);

  ck_assert_int_eq(max_idx, 9);
  ck_assert_int_eq(array[max_idx], 66);
}
END_TEST

START_TEST(test_max_10)
{
  int max_idx;

  int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
  max_idx = max(array, 3, 9);

  ck_assert_int_eq(max_idx, 3);
  ck_assert_int_eq(array[max_idx], 0);
}
END_TEST

START_TEST(test_max_11)
{
  int max_idx;

  int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
  max_idx = max(array, 0, 12);

  ck_assert_int_eq(max_idx, 0);
  ck_assert_int_eq(array[max_idx], 33);
}
END_TEST

START_TEST(test_max_12)
{
  int max_idx;

  int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
  max_idx = max(array, 4, 9);

  ck_assert_int_eq(max_idx, 4);
  ck_assert_int_eq(array[max_idx], -10);
}
END_TEST

START_TEST(test_sample_1)
{
  int sampled_num, lower, upper;

  lower = -100;
  upper = 100;

  sampled_num = sample(lower, upper);

  ck_assert_int_ge(sampled_num, lower);
  ck_assert_int_le(sampled_num, upper);
}
END_TEST

START_TEST(test_sample_2)
{
  int sampled_num, lower, upper;

  lower = -100;
  upper = -95;

  sampled_num = sample(lower, upper);

  ck_assert_int_ge(sampled_num, lower);
  ck_assert_int_le(sampled_num, upper);
}
END_TEST

START_TEST(test_sample_3)
{
  int sampled_num, lower, upper;

  lower = 73;
  upper = 76;

  sampled_num = sample(lower, upper);

  ck_assert_int_ge(sampled_num, lower);
  ck_assert_int_le(sampled_num, upper);
}
END_TEST

START_TEST(test_sample_4)
{
  int sampled_num, lower, upper;

  lower = 100;
  upper = 120;

  sampled_num = sample(lower, upper);

  ck_assert_int_ge(sampled_num, lower);
  ck_assert_int_le(sampled_num, upper);
}
END_TEST

START_TEST(test_sample_5)
{
  int sampled_num, lower, upper;

  lower = 77;
  upper = 78;

  sampled_num = sample(lower, upper);

  ck_assert_int_ge(sampled_num, lower);
  ck_assert_int_le(sampled_num, upper);
}
END_TEST

START_TEST(test_ipow_1)
{
  int base, exp, result;

  base = 3;
  exp = 9;

  result = ipow(base, exp);

  ck_assert_int_eq(result, 19683);
}
END_TEST

START_TEST(test_ipow_2)
{
  int base, exp, result;

  base = 27;
  exp = 0;

  result = ipow(base, exp);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_ipow_3)
{
  int base, exp, result;

  base = 0;
  exp = 0;

  result = ipow(base, exp);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_ipow_4)
{
  int base, exp, result;

  base = 0;
  exp = 10;

  result = ipow(base, exp);

  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_ipow_5)
{
  int base, exp, result;

  base = 12;
  exp = 4;

  result = ipow(base, exp);

  ck_assert_int_eq(result, 20736);
}
END_TEST

START_TEST(test_nth_digit_1)
{
  int number, nth, base, value;

  number = 19324;
  nth = 1;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 4);
}
END_TEST

START_TEST(test_nth_digit_2)
{
  int number, nth, base, value;

  number = 19324;
  nth = 2;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 2);
}
END_TEST

START_TEST(test_nth_digit_3)
{
  int number, nth, base, value;

  number = 19324;
  nth = 3;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 3);
}
END_TEST

START_TEST(test_nth_digit_4)
{
  int number, nth, base, value;

  number = 19324;
  nth = 4;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 9);
}
END_TEST

START_TEST(test_nth_digit_5)
{
  int number, nth, base, value;

  number = 19324;
  nth = 5;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 1);
}
END_TEST

START_TEST(test_nth_digit_6)
{
  int number, nth, base, value;

  number = 19324;
  nth = 10;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 0);
}
END_TEST

START_TEST(test_nth_digit_7)
{
  int number, nth, base, value;

  number = 19324;
  nth = 7;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 0);
}
END_TEST

START_TEST(test_nth_digit_8)
{
  int number, nth, base, value;

  number = -52918;
  nth = 1;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, -8);
}
END_TEST

START_TEST(test_nth_digit_9)
{
  int number, nth, base, value;

  number = -52918;
  nth = 2;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, -1);
}
END_TEST

START_TEST(test_nth_digit_10)
{
  int number, nth, base, value;

  number = -52918;
  nth = 3;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, -9);
}
END_TEST

START_TEST(test_nth_digit_11)
{
  int number, nth, base, value;

  number = -52918;
  nth = 4;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, -2);
}
END_TEST

START_TEST(test_nth_digit_12)
{
  int number, nth, base, value;

  number = -52918;
  nth = 5;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, -5);
}
END_TEST

START_TEST(test_nth_digit_13)
{
  int number, nth, base, value;

  number = -52918;
  nth = 10;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 0);
}
END_TEST

START_TEST(test_nth_digit_14)
{
  int number, nth, base, value;

  number = -52918;
  nth = 7;
  base = 10;

  value = nth_digit(number, nth, base);

  ck_assert_int_eq(value, 0);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Utils Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_test(tc_core, test_swap_1);
  tcase_add_test(tc_core, test_swap_2);
  tcase_add_test(tc_core, test_swap_3);
  tcase_add_test(tc_core, test_swap_4);
  tcase_add_test(tc_core, test_swap_5);
  tcase_add_test(tc_core, test_swap_6);
  tcase_add_test(tc_core, test_swap_7);

  tcase_add_test(tc_core, test_max_1);
  tcase_add_test(tc_core, test_max_2);
  tcase_add_test(tc_core, test_max_3);
  tcase_add_test(tc_core, test_max_4);
  tcase_add_test(tc_core, test_max_5);
  tcase_add_test(tc_core, test_max_6);
  tcase_add_test(tc_core, test_max_7);
  tcase_add_test(tc_core, test_max_8);
  tcase_add_test(tc_core, test_max_9);
  tcase_add_test(tc_core, test_max_10);
  tcase_add_test(tc_core, test_max_11);
  tcase_add_test(tc_core, test_max_12);

  tcase_add_test(tc_core, test_sample_1);
  tcase_add_test(tc_core, test_sample_2);
  tcase_add_test(tc_core, test_sample_3);
  tcase_add_test(tc_core, test_sample_4);
  tcase_add_test(tc_core, test_sample_5);

  tcase_add_test(tc_core, test_ipow_1);
  tcase_add_test(tc_core, test_ipow_2);
  tcase_add_test(tc_core, test_ipow_3);
  tcase_add_test(tc_core, test_ipow_4);
  tcase_add_test(tc_core, test_ipow_5);

  tcase_add_test(tc_core, test_nth_digit_1);
  tcase_add_test(tc_core, test_nth_digit_2);
  tcase_add_test(tc_core, test_nth_digit_3);
  tcase_add_test(tc_core, test_nth_digit_4);
  tcase_add_test(tc_core, test_nth_digit_5);
  tcase_add_test(tc_core, test_nth_digit_6);
  tcase_add_test(tc_core, test_nth_digit_7);
  tcase_add_test(tc_core, test_nth_digit_8);
  tcase_add_test(tc_core, test_nth_digit_9);
  tcase_add_test(tc_core, test_nth_digit_10);
  tcase_add_test(tc_core, test_nth_digit_11);
  tcase_add_test(tc_core, test_nth_digit_12);
  tcase_add_test(tc_core, test_nth_digit_13);
  tcase_add_test(tc_core, test_nth_digit_14);

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
