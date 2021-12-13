#include <check.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <str_builder.h>

START_TEST(test_init_success)
{
  bool result;
  int capacity = 30;
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  result = init_str_builder(str_bldr, capacity);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(str_bldr->size, 0);
  ck_assert_int_eq(str_bldr->capacity, capacity);

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_init_fail)
{
  bool result;
  int capacity = 0;
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  result = init_str_builder(str_bldr, capacity);

  ck_assert_int_eq(result, false);

  free(str_bldr);
}
END_TEST

START_TEST(test_append_str_1)
{
  int capacity = 30;
  char expected[] = "Vae Victis!";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae");
  append_str(str_bldr, " Victis!");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

/* The expected string has exactly 20 chars, so due to the null byte we are
 * forced to expand the array once more so it has 40 chars. */
START_TEST(test_append_str_2)
{
  int capacity = 5;
  char expected[] = "Carthago delenda est";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Carthago");
  append_str(str_bldr, " delenda");
  append_str(str_bldr, " est");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 40);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_start)
{
  int capacity = 30;
  char expected[] = "Furius|Camillus";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Marcus|Furius|Camillus");

  del_str(str_bldr, "Marcus|");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 30);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_mid)
{
  int capacity = 30;
  char expected[] = "Marcus|Camillus";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Marcus|Furius|Camillus");

  del_str(str_bldr, "|Furius");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 30);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_end)
{
  int capacity = 30;
  char expected[] = "Marcus|Furius";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Marcus|Furius|Camillus");

  del_str(str_bldr, "|Camillus");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 30);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_fail)
{
  int capacity = 30;
  char expected[] = "Marcus|Furius|Camillus";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, expected);

  del_str(str_bldr, "Apollo's beloved");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 30);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

/* Check whether del_str's leftover null byte ruins append_str */
START_TEST(test_append_str_after_del_str)
{
  int capacity = 30;
  char expected[] = "Marcus|Camillus|Veii's ruin";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Marcus|Furius|Camillus");

  del_str(str_bldr, "|Furius");
  append_str(str_bldr, "|Veii's ruin");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 30);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_ensure_capacity_needed)
{
  int initial_capacity = 5;
  int new_capacity = 10;
  char expected[] = "123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, initial_capacity);
  ensure_capacity(str_bldr, new_capacity);
  /* Would fail unles we ensured capacity*/
  append_str(str_bldr, "123456789");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, new_capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_ensure_capacity_pointless)
{
  int initial_capacity = 10;
  int new_capacity = 5;
  char expected[] = "123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, initial_capacity);
  /* As new capacity is smaller ensure_capacity is skipped */
  ensure_capacity(str_bldr, new_capacity);
  append_str(str_bldr, "123456789");

  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, initial_capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_at_head)
{
  bool success;
  int capacity = 30;
  char expected[] = "No more Vae Victis";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, 0, "No more ");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_at_middle)
{
  bool success;
  int capacity = 30;
  char expected[] = "Vae no more Victis";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, 3, " no more");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_at_end)
{
  bool success;
  int capacity = 30;
  char expected[] = "Vae Victis no more";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, str_bldr->size, " no more");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_too_large)
{
  bool success;
  int capacity = 11;
  char expected[] = "Vae no more Victis";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, 3, " no more");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 22);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_idx_too_big)
{
  bool success;
  int capacity = 30;
  char expected[] = "Vae Victis";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, str_bldr->size + 1, " no more");

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_insert_str_idx_too_small)
{
  bool success;
  int capacity = 30;
  char expected[] = "Vae Victis";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "Vae Victis");
  success = insert_str(str_bldr, -1, " no more");

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_head)
{
  bool success;
  int capacity = 20;
  char expected[] = "89";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 0, 7);

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_mid)
{
  bool success;
  int capacity = 20;
  char expected[] = "0126789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 3, 5);

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_end)
{
  bool success;
  int capacity = 20;
  char expected[] = "01234";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 5, 9);

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_entire)
{
  bool success;
  int capacity = 20;
  char expected[] = "";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 0, str_bldr->size - 1);

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_digit)
{
  bool success;
  int capacity = 20;
  char expected[] = "012356789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 4, 4);

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_invalid_start)
{
  bool success;
  int capacity = 20;
  char expected[] = "0123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, -1, 6);

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_del_str_range_invalid_end)
{
  bool success;
  int capacity = 20;
  char expected[] = "0123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = del_str_range(str_bldr, 3, str_bldr->size);

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_head)
{
  bool success;
  int capacity = 20;
  char expected[] = "abc3456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, 0, 2, "abc");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_mid)
{
  bool success;
  int capacity = 20;
  char expected[] = "012abcd789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, 3, 6, "abcd");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_end)
{
  bool success;
  int capacity = 20;
  char expected[] = "012345aeio";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, 6, 9, "aeio");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_invalid_start)
{
  bool success;
  int capacity = 20;
  char expected[] = "0123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, -1, 9, "aeio");

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_invalid_end)
{
  bool success;
  int capacity = 20;
  char expected[] = "0123456789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, 6, 12, "aeio");

  ck_assert_int_eq(success, false);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, capacity);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

START_TEST(test_replace_str_too_big)
{
  bool success;
  int capacity = 20;
  char expected[] = "012abcdefghijklmnop789";
  StringBuilder* str_bldr = malloc(sizeof(StringBuilder));

  init_str_builder(str_bldr, capacity);
  append_str(str_bldr, "0123456789");
  success = replace_str(str_bldr, 3, 6, "abcdefghijklmnop");

  ck_assert_int_eq(success, true);
  ck_assert_str_eq(str_bldr->array, expected);
  ck_assert_int_eq(str_bldr->capacity, 40);
  ck_assert_int_eq(str_bldr->size, strlen(expected));

  free(str_bldr->array);
  free(str_bldr);
}
END_TEST

static Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Queue Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_test(tc_core, test_init_success);
  tcase_add_test(tc_core, test_init_fail);

  tcase_add_test(tc_core, test_append_str_1);
  tcase_add_test(tc_core, test_append_str_2);

  tcase_add_test(tc_core, test_del_str_start);
  tcase_add_test(tc_core, test_del_str_mid);
  tcase_add_test(tc_core, test_del_str_end);
  tcase_add_test(tc_core, test_del_str_fail);

  tcase_add_test(tc_core, test_append_str_after_del_str);
  tcase_add_test(tc_core, test_ensure_capacity_needed);
  tcase_add_test(tc_core, test_ensure_capacity_pointless);

  tcase_add_test(tc_core, test_insert_str_at_head);
  tcase_add_test(tc_core, test_insert_str_at_middle);
  tcase_add_test(tc_core, test_insert_str_at_end);
  tcase_add_test(tc_core, test_insert_str_too_large);
  tcase_add_test(tc_core, test_insert_str_idx_too_big);
  tcase_add_test(tc_core, test_insert_str_idx_too_small);

  tcase_add_test(tc_core, test_del_str_range_head);
  tcase_add_test(tc_core, test_del_str_range_mid);
  tcase_add_test(tc_core, test_del_str_range_end);
  tcase_add_test(tc_core, test_del_str_range_entire);
  tcase_add_test(tc_core, test_del_str_range_invalid_start);
  tcase_add_test(tc_core, test_del_str_range_invalid_end);
  tcase_add_test(tc_core, test_del_str_range_digit);

  tcase_add_test(tc_core, test_replace_str_head);
  tcase_add_test(tc_core, test_replace_str_mid);
  tcase_add_test(tc_core, test_replace_str_end);
  tcase_add_test(tc_core, test_replace_str_invalid_start);
  tcase_add_test(tc_core, test_replace_str_invalid_end);
  tcase_add_test(tc_core, test_replace_str_too_big);

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
