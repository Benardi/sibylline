#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <utils.h>

Suite *make_stack_suite(void);

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
}END_TEST

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
}END_TEST

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
}END_TEST

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
}END_TEST

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
}END_TEST

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

}END_TEST

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

}END_TEST

START_TEST(test_max_1)
{   int max_idx;

    int array[] = {5, 2, 4, 6, 1, 3};
    max_idx = max(array, 0, 5);

    ck_assert_int_eq(max_idx, 3);
    ck_assert_int_eq(array[max_idx], 6);

}END_TEST

START_TEST(test_max_2)
{   int max_idx;

    int array[] = {5, 2, 4, 6, 1, 3};
    max_idx = max(array, 0, 2);

    ck_assert_int_eq(max_idx, 0);
    ck_assert_int_eq(array[max_idx], 5);

}END_TEST

START_TEST(test_max_3)
{   int max_idx;

    int array[] = {5, 2, 4, 6, 1, 3};
    max_idx = max(array, 4, 4);

    ck_assert_int_eq(max_idx, 4);
    ck_assert_int_eq(array[max_idx], 1);

}END_TEST

START_TEST(test_max_4)
{   int max_idx;

    int array[] = {5, 2, 4, 6, 1, 3};
    max_idx = max(array, 4, 4);

    ck_assert_int_eq(max_idx, 4);
    ck_assert_int_eq(array[max_idx], 1);

}END_TEST

START_TEST(test_max_5)
{   int max_idx;

    int array[] = {5, 2, 4, 6, 1, 3};
    max_idx = max(array, 3, 2);

    ck_assert_int_eq(max_idx, -1);

}END_TEST

START_TEST(test_max_6)
{   int max_idx;

    int array[] = {-200, -50, -150, -25, -175, -300, -275, -33};
    max_idx = max(array, 0, 7);

    ck_assert_int_eq(max_idx, 3);
    ck_assert_int_eq(array[max_idx], -25);

}END_TEST

START_TEST(test_max_7)
{   int max_idx;

    int array[] = {-200, -50, -150, -25, -175, -300, -275, -33};
    max_idx = max(array, 4, 6);

    ck_assert_int_eq(max_idx, 4);
    ck_assert_int_eq(array[max_idx], -175);

}END_TEST

START_TEST(test_max_8)
{   int max_idx;

    int array[] = {-30, -20, -10, 0, 10, 15, 30, 50, 60, 66, 90, 93, 127};
    max_idx = max(array, 0, 12);

    ck_assert_int_eq(max_idx, 12);
    ck_assert_int_eq(array[max_idx], 127);

}END_TEST

START_TEST(test_max_9)
{   int max_idx;

    int array[] = {-30, -20, -10, 0, 10, 15, 30, 50, 60, 66, 90, 93, 127};
    max_idx = max(array, 2, 9);

    ck_assert_int_eq(max_idx, 9);
    ck_assert_int_eq(array[max_idx], 66);

}END_TEST

START_TEST(test_max_10)
{   int max_idx;

    int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
    max_idx = max(array, 3, 9);

    ck_assert_int_eq(max_idx, 3);
    ck_assert_int_eq(array[max_idx], 0);

}END_TEST

START_TEST(test_max_11)
{   int max_idx;

    int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
    max_idx = max(array, 0, 12);

    ck_assert_int_eq(max_idx, 0);
    ck_assert_int_eq(array[max_idx], 33);

}END_TEST

START_TEST(test_max_12)
{   int max_idx;

    int array[] = {33, 20, 7, 0, -10, -19, -30, -41, -54, -68, -90, -93, -98};
    max_idx = max(array, 4, 9);

    ck_assert_int_eq(max_idx, 4);
    ck_assert_int_eq(array[max_idx], -10);

}END_TEST

START_TEST(test_sample_1)
{   int sampled_num, lower, upper;

    lower = -100;
    upper = 100;

    sampled_num = sample(lower, upper);

   
    ck_assert_int_ge(sampled_num, lower);
    ck_assert_int_le(sampled_num, upper);

}END_TEST

START_TEST(test_sample_2)
{   int sampled_num, lower, upper;

    lower = -100;
    upper = -95;

    sampled_num = sample(lower, upper);

   
    ck_assert_int_ge(sampled_num, lower);
    ck_assert_int_le(sampled_num, upper);

}END_TEST

START_TEST(test_sample_3)
{   int sampled_num, lower, upper;

    lower = 73;
    upper = 76;

    sampled_num = sample(lower, upper);

   
    ck_assert_int_ge(sampled_num, lower);
    ck_assert_int_le(sampled_num, upper);

}END_TEST

START_TEST(test_sample_4)
{   int sampled_num, lower, upper;

    lower = 100;
    upper = 120;

    sampled_num = sample(lower, upper);

   
    ck_assert_int_ge(sampled_num, lower);
    ck_assert_int_le(sampled_num, upper);

}END_TEST

START_TEST(test_sample_5)
{   int sampled_num, lower, upper;

    lower = 77;
    upper = 78;

    sampled_num = sample(lower, upper);

   
    ck_assert_int_ge(sampled_num, lower);
    ck_assert_int_le(sampled_num, upper);

}END_TEST

Suite *make_stack_suite(void)
{
    Suite *s;
    TCase *tc_core;

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

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(make_stack_suite());
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "test.log");
    srunner_set_xml(sr, "test.xml");
    srunner_run_all(sr, CK_VERBOSE);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}