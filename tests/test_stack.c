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
int compare(void* key1, void* key2);

int compare(void* key1, void* key2)
{
  int result;
  int k1 = *((int*)key1);
  int k2 = *((int*)key2);

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
  stk = malloc(sizeof(Stack));
}

void teardown(void)
{
  free(reg);
  free(stk);
}

START_TEST(test_init_stack_1)
{
  init_stack(stk);
  ck_assert_int_eq(stk->top, -1);
}
END_TEST

START_TEST(test_init_stack_2)
{
  init_stack(stk);
  init_stack(stk);
  ck_assert_int_eq(stk->top, -1);
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
  init_stack(stk);
  ck_assert_int_eq(stack_empty(stk), true);
}
END_TEST

START_TEST(test_stack_empty_3)
{
  int k1 = 10;

  reg->key = &k1;
  init_stack(stk);
  stk->A[0] = *reg;
  stk->top = 0;
  ck_assert_int_eq(stack_empty(stk), false);
}
END_TEST

START_TEST(test_stack_empty_4)
{
  int k1 = 10;

  reg->key = &k1;
  init_stack(stk);
  stk->A[0] = *reg;
  stk->top = 0;
  init_stack(stk);
  ck_assert_int_eq(stack_empty(stk), true);
}
END_TEST

START_TEST(test_stack_full_1)
{
  init_stack(stk);
  ck_assert_int_eq(stack_full(stk), false);
}
END_TEST

START_TEST(test_stack_full_2)
{
  int k1 = -10;

  reg->key = &k1;
  init_stack(stk);
  push(stk, *reg);
  ck_assert_int_eq(stack_full(stk), false);
}
END_TEST

START_TEST(test_stack_full_3)
{
  int k1 = -10;
  bool result = true;

  reg->key = &k1;
  init_stack(stk);

  /* Filling up the stack */
  for (i = 0; i < MAX - 1; i++)
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
}
END_TEST

START_TEST(test_stack_pop_1)
{
  bool result;

  init_stack(stk);
  result = pop(stk, reg);

  ck_assert_int_eq(result, false);
}
END_TEST

START_TEST(test_stack_pop_2)
{
  int k1;
  bool result1, result2, result3;

  k1 = 7;

  init_stack(stk);
  result1 = pop(stk, reg); /* Doesn't write to pointer address*/
  reg->key = &k1;
  push(stk, *reg);
  result2 = pop(stk, reg); /* Writes to pointer address*/
  result3 = pop(stk, reg); /* Doesn't write to pointer address*/

  ck_assert_int_eq(result1, false);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, false);

  ck_assert_int_eq(*((int*)reg->key), 7);
}
END_TEST

START_TEST(test_stack_pop_3)
{
  int k1, k2;
  bool result1, result2, result3;
  Register* el1;
  Register* el2;

  k1 = 7;
  k2 = -5;

  el1 = malloc(sizeof(Register));
  el2 = malloc(sizeof(Register));

  init_stack(stk);
  reg->key = &k1;
  push(stk, *reg);
  reg->key = &k2;
  push(stk, *reg);

  result1 = pop(stk, el1);
  result2 = pop(stk, el2);
  result3 = pop(stk, el2);

  ck_assert_int_eq(result1, true);
  ck_assert_int_eq(result2, true);
  ck_assert_int_eq(result3, false);

  ck_assert_int_eq(*((int*)el1->key), -5);
  ck_assert_int_eq(*((int*)el2->key), 7);

  free(el1);
  free(el2);
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
