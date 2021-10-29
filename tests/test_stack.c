#include <check.h>
#include <malloc.h>
#include <stack.h>
#include <stdint.h>
#include <stdlib.h>

Stack* stk;
Register* reg;

int i;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

void setup(void)
{
  reg = malloc(sizeof(Register));
  stk = malloc(sizeof(Stack));
}

void teardown(void)
{
  free(reg);
  free(stk);
}

START_TEST(test_init_stack_1)
{
  int length = 10;
  init_stack(stk, length);
  ck_assert_int_eq(stk->top, -1);

  free(stk->array);
}
END_TEST

START_TEST(test_init_stack_2)
{
  int length = 10;
  init_stack(stk, length);
  reinit_stack(stk);
  ck_assert_int_eq(stk->top, -1);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_empty_1)
{
  stk->top = 0;

  ck_assert_int_eq(stack_empty(stk), false);
}
END_TEST

START_TEST(test_stack_empty_2)
{
  int length = 5;
  init_stack(stk, length);
  ck_assert_int_eq(stack_empty(stk), true);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_empty_3)
{
  union Key k1;
  int length = 5;

  k1.i = 10;
  reg->key = k1;
  init_stack(stk, length);
  stk->array[0] = *reg;
  stk->top = 0;
  ck_assert_int_eq(stack_empty(stk), false);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_empty_4)
{
  union Key k1;
  int length = 10;

  k1.i = 10;
  reg->key = k1;
  init_stack(stk, length);
  stk->array[0] = *reg;
  stk->top = 0;
  reinit_stack(stk);
  ck_assert_int_eq(stack_empty(stk), true);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_full_1)
{
  int length = 10;

  init_stack(stk, length);
  ck_assert_int_eq(stack_full(stk), false);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_full_2)
{
  union Key k1;
  int length = 10;

  k1.i = -10;
  reg->key = k1;
  init_stack(stk, length);
  push(stk, *reg);
  ck_assert_int_eq(stack_full(stk), false);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_full_3)
{
  union Key k1;
  int length = 20;
  bool result = true;

  k1.i = -10;
  reg->key = k1;
  init_stack(stk, length);

  /* Filling up the stack */
  for (i = 0; i < stk->length - 1; i++)
    {
      result = result && push(stk, *reg);
    }

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(stack_full(stk), false);

  /* Last available position */
  result = push(stk, *reg);
  ck_assert_int_eq(result, true);
  ck_assert_int_eq(stack_full(stk), true);

  /* Stack overflow */
  result = push(stk, *reg);
  ck_assert_int_eq(result, false);
  ck_assert_int_eq(stack_full(stk), true);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_pop_1)
{
  bool result;
  int length = 5;

  init_stack(stk, length);
  result = pop(stk, reg);

  ck_assert_int_eq(result, false);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_pop_2)
{
  union Key k1;
  bool result1, result2, result3;
  int length = 20;

  k1.i = 7;

  init_stack(stk, length);
  result1 = pop(stk, reg); /* Doesn't write to pointer address*/
  reg->key = k1;
  push(stk, *reg);
  result2 = pop(stk, reg); /* Writes to pointer address*/
  result3 = pop(stk, reg); /* Doesn't write to pointer address*/

  ck_assert_int_eq(result1, false);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, false);

  ck_assert_int_eq(reg->key.i, 7);

  free(stk->array);
}
END_TEST

START_TEST(test_stack_pop_3)
{
  union Key k1, k2;
  bool result1, result2, result3;
  Register* el1;
  Register* el2;
  int length = 20;

  k1.i = 7;
  k2.i = -5;

  el1 = malloc(sizeof(Register));
  el2 = malloc(sizeof(Register));

  init_stack(stk, length);
  reg->key = k1;
  push(stk, *reg);
  reg->key = k2;
  push(stk, *reg);

  result1 = pop(stk, el1);
  result2 = pop(stk, el2);
  result3 = pop(stk, el2);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, false);

  ck_assert_int_eq(el1->key.i, -5);
  ck_assert_int_eq(el2->key.i, 7);

  free(el1);
  free(el2);

  free(stk->array);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Stack Creation Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_init_stack_1);
  tcase_add_test(tc_core, test_init_stack_2);

  tcase_add_test(tc_core, test_stack_empty_1);
  tcase_add_test(tc_core, test_stack_empty_2);
  tcase_add_test(tc_core, test_stack_empty_3);
  tcase_add_test(tc_core, test_stack_empty_4);

  tcase_add_test(tc_core, test_stack_full_1);
  tcase_add_test(tc_core, test_stack_full_2);
  tcase_add_test(tc_core, test_stack_full_3);

  tcase_add_test(tc_core, test_stack_pop_1);
  tcase_add_test(tc_core, test_stack_pop_2);
  tcase_add_test(tc_core, test_stack_pop_3);

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
