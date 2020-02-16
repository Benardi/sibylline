#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <heap.h>

void setup(void);
void teardown(void);
Suite *make_stack_suite(void);

void setup(void)
{
}

void teardown(void)
{
}

START_TEST(test_max_heapify_1)
{
    int heap_size, i; 
    int array[] = {10, 5, 7, -9, 200};

    heap_size = 3;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 10);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
    ck_assert_int_eq(array[3], -9);
    ck_assert_int_eq(array[4], 200);
}
END_TEST

START_TEST(test_max_heapify_2)
{
    int heap_size, i; 
    int array[] = {10, 5, 7, -9, 200};

    heap_size = 3;
    i = 1; /* left child */

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 10);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
    ck_assert_int_eq(array[3], -9);
    ck_assert_int_eq(array[4], 200);
}
END_TEST

START_TEST(test_max_heapify_3)
{
    int heap_size, i; 
    int array[] = {10, 5, 7, -9, 200};

    heap_size = 3;
    i = 2; /* right child */

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 10);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
    ck_assert_int_eq(array[3], -9);
    ck_assert_int_eq(array[4], 200);
}
END_TEST

START_TEST(test_max_heapify_4)
{
    int heap_size, i; 
    int array[] = {3, 10, 8, 90, -1500};

    heap_size = 3;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 10);
    ck_assert_int_eq(array[1], 3);
    ck_assert_int_eq(array[2], 8);
    ck_assert_int_eq(array[3], 90);
    ck_assert_int_eq(array[4], -1500);
}
END_TEST

START_TEST(test_max_heapify_5)
{
    int heap_size, i; 
    int array[] = {3, 8, 10, 90, -1500};

    heap_size = 3;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 10);
    ck_assert_int_eq(array[1], 8);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 90);
    ck_assert_int_eq(array[4], -1500);
}
END_TEST

START_TEST(test_max_heapify_6)
{
    int heap_size, i; 
    int array[] = {3, 9, 8, 7, 6, 4, 5};

    heap_size = 7;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 9);
    ck_assert_int_eq(array[1], 7);
    ck_assert_int_eq(array[2], 8);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 6);
    ck_assert_int_eq(array[5], 4);
    ck_assert_int_eq(array[6], 5);
}
END_TEST

START_TEST(test_max_heapify_7)
{
    int heap_size, i; 
    int array[] = {3, 9, 8, 6, 7, 4, 5};

    heap_size = 7;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 9);
    ck_assert_int_eq(array[1], 7);
    ck_assert_int_eq(array[2], 8);
    ck_assert_int_eq(array[3], 6);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 4);
    ck_assert_int_eq(array[6], 5);
}
END_TEST

START_TEST(test_max_heapify_8)
{
    int heap_size, i; 
    int array[] = {3, 8, 9, 6, 7, 5, 4};

    heap_size = 7;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 9);
    ck_assert_int_eq(array[1], 8);
    ck_assert_int_eq(array[2], 5);
    ck_assert_int_eq(array[3], 6);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 3);
    ck_assert_int_eq(array[6], 4);
}
END_TEST

START_TEST(test_max_heapify_9)
{
    int heap_size, i; 
    int array[] = {3, 8, 9, 6, 7, 4, 5};

    heap_size = 7;
    i = 0;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 9);
    ck_assert_int_eq(array[1], 8);
    ck_assert_int_eq(array[2], 5);
    ck_assert_int_eq(array[3], 6);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 4);
    ck_assert_int_eq(array[6], 3);
}
END_TEST

START_TEST(test_max_heapify_10)
{
    int heap_size, i; 
    int array[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    heap_size = 10;
    i = 1;

    max_heapify(array, heap_size, i);

    ck_assert_int_eq(array[0], 16);
    ck_assert_int_eq(array[1], 14);
    ck_assert_int_eq(array[2], 10);
    ck_assert_int_eq(array[3], 8);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 9);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 2);
    ck_assert_int_eq(array[8], 4);
    ck_assert_int_eq(array[9], 1);
}
END_TEST

Suite *make_stack_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack Creation Test Suite");

    /* Creation test case */
    tc_core = tcase_create("Test Cases with Setup and Teardown");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_max_heapify_1);
    tcase_add_test(tc_core, test_max_heapify_2);
    tcase_add_test(tc_core, test_max_heapify_3);
    tcase_add_test(tc_core, test_max_heapify_4);
    tcase_add_test(tc_core, test_max_heapify_5);
    tcase_add_test(tc_core, test_max_heapify_6);
    tcase_add_test(tc_core, test_max_heapify_7);
    tcase_add_test(tc_core, test_max_heapify_8);
    tcase_add_test(tc_core, test_max_heapify_9);
    tcase_add_test(tc_core, test_max_heapify_10);

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
