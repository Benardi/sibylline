#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>
#include <check.h>
#include <sort.h>

Suite *make_rbt_suite(void);

int seed = 23;

START_TEST(test_insertion_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_insertion_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_insertion_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_insertion_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_insertion_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_insertion_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_insertion_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_insertion_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_insertion_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_insertion_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_insertion_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_insertion_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_insertion_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_insertion_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_insertion_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_insertion_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    insertion_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_merge_1)
{
    int array[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int start = 0;
    int middle = 3;
    int end = 7;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_merge_2)
{
    int array[] = {2, -2};
    int start = 0;
    int middle = 0;
    int end = 1;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -2);
    ck_assert_int_eq(array[1], 2);
}
END_TEST

START_TEST(test_merge_3)
{
    int array[] = {-5, 0};
    int start = 0;
    int middle = 0;
    int end = 1;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_merge_4)
{
    int array[] = {-5, 0};
    int start = 0;
    int middle = 0;
    int end = 1;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_merge_5)
{
    int array[] = {5, 3, 7};
    int start = 0;
    int middle = 0;
    int end = 2;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 3);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
}
END_TEST

START_TEST(test_merge_6)
{
    int array[] = {8, -5, -3};
    int start = 0;
    int middle = 0;
    int end = 2;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], -3);
    ck_assert_int_eq(array[2], 8);
}
END_TEST

START_TEST(test_merge_7)
{
    int array[] = {-10, -5, -1};
    int start = 0;
    int middle = 0;
    int end = 2;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -10);
    ck_assert_int_eq(array[1], -5);
    ck_assert_int_eq(array[2], -1);
}
END_TEST

START_TEST(test_merge_8)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int middle = 4;
    int end = 7;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_merge_9)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int middle = 2;
    int end = 5;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_merge_10)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int middle = 3;
    int end = 5;

    merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_merge_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_merge_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_merge_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_merge_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_merge_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_merge_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_merge_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_merge_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_merge_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_merge_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_merge_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_merge_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_merge_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_merge_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_merge_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_merge_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_inplace_merge_1)
{
    int array[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int start = 0;
    int middle = 3;
    int end = 7;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_inplace_merge_2)
{
    int array[] = {2, -2};
    int start = 0;
    int middle = 0;
    int end = 1;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -2);
    ck_assert_int_eq(array[1], 2);
}
END_TEST

START_TEST(test_inplace_merge_3)
{
    int array[] = {-5, 0};
    int start = 0;
    int middle = 0;
    int end = 1;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_inplace_merge_4)
{
    int array[] = {-5, 0};
    int start = 0;
    int middle = 0;
    int end = 1;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_inplace_merge_5)
{
    int array[] = {5, 3, 7};
    int start = 0;
    int middle = 0;
    int end = 2;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 3);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
}
END_TEST

START_TEST(test_inplace_merge_6)
{
    int array[] = {8, -5, -3};
    int start = 0;
    int middle = 0;
    int end = 2;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], -3);
    ck_assert_int_eq(array[2], 8);
}
END_TEST

START_TEST(test_inplace_merge_7)
{
    int array[] = {-10, -5, -1};
    int start = 0;
    int middle = 0;
    int end = 2;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], -10);
    ck_assert_int_eq(array[1], -5);
    ck_assert_int_eq(array[2], -1);
}
END_TEST

START_TEST(test_inplace_merge_8)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int middle = 4;
    int end = 7;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_inplace_merge_9)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int middle = 2;
    int end = 5;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_inplace_merge_10)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int middle = 3;
    int end = 5;

    inplace_merge(array, start, middle, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_inplace_merge_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_inplace_merge_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_inplace_merge_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_inplace_merge_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_inplace_merge_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_inplace_merge_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_inplace_merge_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_inplace_merge_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_inplace_merge_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_inplace_merge_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_inplace_merge_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_inplace_merge_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_inplace_merge_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_inplace_merge_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_inplace_merge_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_inplace_merge_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    inplace_merge_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_partition_1)
{
    int middle;
    int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int start = 0;
    int end = 7;

    middle = partition(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 8);
    ck_assert_int_eq(middle, 3);
}
END_TEST

START_TEST(test_partition_2)
{
    int middle;
    int array[] = {9, 7, 4, 3, 7, 5};
    int start = 0;
    int end = 5;

    middle = partition(array, start, end);

    ck_assert_int_eq(array[0], 4);
    ck_assert_int_eq(array[1], 3);
    ck_assert_int_eq(array[2], 5);
    ck_assert_int_eq(array[3], 7);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 9);
    ck_assert_int_eq(middle, 2);    
}
END_TEST

START_TEST(test_partition_3)
{
    int middle;
    int array[] = {-7, 7, 3, 8, 2, 5, -9, 4};
    int start = 0;
    int end = 7;

    middle = partition(array, start, end);

    ck_assert_int_eq(array[0], -7);
    ck_assert_int_eq(array[1], 3);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], -9);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 8);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(middle, 4);
}
END_TEST

START_TEST(test_partition_4)
{
    int middle;
    int array[] = {-9, -7, -5, -3, -1, 0, 2, 4, 6, 8, 10, 12, 15,
                   20, 25, 30, 50, 100, 200};
    int start = 0;
    int end = 18;

    middle = partition(array, start, end);

    ck_assert_int_eq(array[0], -9);
    ck_assert_int_eq(array[1], -7);
    ck_assert_int_eq(array[2], -5);
    ck_assert_int_eq(array[3], -3);
    ck_assert_int_eq(array[4], -1);
    ck_assert_int_eq(array[5], 0);
    ck_assert_int_eq(array[6], 2);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 6);
    ck_assert_int_eq(array[9], 8);
    ck_assert_int_eq(array[10], 10);
    ck_assert_int_eq(array[11], 12);
    ck_assert_int_eq(array[12], 15);
    ck_assert_int_eq(array[13], 20);
    ck_assert_int_eq(array[14], 25);
    ck_assert_int_eq(array[15], 30);
    ck_assert_int_eq(array[16], 50);
    ck_assert_int_eq(array[17], 100);
    ck_assert_int_eq(array[18], 200);
 
    ck_assert_int_eq(middle, 18);
}
END_TEST

START_TEST(test_partition_5)
{
    int middle;
    int array[] = {8, 6, 4, 2, 0, -2, -4, -6, -8, -10, -12, -14};
    int start = 0;
    int end = 11;

    middle = partition(array, start, end);

    ck_assert_int_eq(array[0], -14);
    ck_assert_int_eq(array[1], 6);
    ck_assert_int_eq(array[2], 4);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], -2);
    ck_assert_int_eq(array[6], -4);
    ck_assert_int_eq(array[7], -6);
    ck_assert_int_eq(array[8], -8);
    ck_assert_int_eq(array[9], -10);
    ck_assert_int_eq(array[10], -12);
    ck_assert_int_eq(array[11], 8);
 
    ck_assert_int_eq(middle, 0);
}
END_TEST

START_TEST(test_quick_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_quick_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_quick_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_quick_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_quick_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_quick_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_quick_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_quick_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_quick_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_quick_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST 

START_TEST(test_quick_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_quick_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_quick_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_quick_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_quick_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_quick_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    quick_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_rand_partition_1)
{
    int i;
    int middle;
    int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int start = 0;
    int end = 7;

    middle = rand_partition(array, start, end);

    ck_assert_int_gt(middle, start - 1);
    ck_assert_int_lt(middle, end + 1);

    for(i = start; i <= end; i++)
    {
        if (i < middle)
        {
            ck_assert_int_le(array[i], array[middle]);
        }
        else if (i > middle)
        {
            ck_assert_uint_gt(array[i], array[middle]);
        }
    }
}
END_TEST

START_TEST(test_rand_partition_2)
{
    int i;
    int middle;
    int array[] = {9, 7, 4, 3, 7, 5};
    int start = 0;
    int end = 5;

    middle = rand_partition(array, start, end);

    ck_assert_int_gt(middle, start - 1);
    ck_assert_int_lt(middle, end + 1);

    for(i = start; i <= end; i++)
    {
        if (i < middle)
        {
            ck_assert_int_le(array[i], array[middle]);
        }
        else if (i > middle)
        {
            ck_assert_uint_gt(array[i], array[middle]);
        }
    }
}
END_TEST

START_TEST(test_rand_partition_3)
{
    int i;
    int middle;
    int array[] = {-7, 7, 3, 8, 2, 5, -9, 4};
    int start = 0;
    int end = 7;

    middle = rand_partition(array, start, end);

    ck_assert_int_gt(middle, start - 1);
    ck_assert_int_lt(middle, end + 1);

    for(i = start; i <= end; i++)
    {
        if (i < middle)
        {
            ck_assert_int_le(array[i], array[middle]);
        }
        else if (i > middle)
        {
            ck_assert_uint_gt(array[i], array[middle]);
        }
    }
}
END_TEST

START_TEST(test_rand_partition_4)
{
  
    int i;
    int middle = 0;
    int array[] = {-9, -7, -5, -3, -1, 0, 2, 4, 6, 8, 10, 12, 15,
                   20, 25, 30, 50, 100, 200};
    int start = 0;
    int end = 18;

    middle = rand_partition(array, start, end);

    ck_assert_int_gt(middle, start - 1);
    ck_assert_int_lt(middle, end + 1);

    for(i = start; i <= end; i++)
    {
        if (i < middle)
        {
            ck_assert_int_le(array[i], array[middle]);
        }
        else if (i > middle)
        {
            ck_assert_uint_gt(array[i], array[middle]);
        }
    }
}
END_TEST

START_TEST(test_rand_partition_5)
{
    int i;
    int middle;
    int array[] = {8, 6, 4, 2, 0, -2, -4, -6, -8, -10, -12, -14};
    int start = 0;
    int end = 11;

    middle = rand_partition(array, start, end);

    ck_assert_int_gt(middle, start - 1);
    ck_assert_int_lt(middle, end + 1);

    for(i = start; i <= end; i++)
    {
        if (i < middle)
        {
            ck_assert_int_le(array[i], array[middle]);
        }
        else if (i > middle)
        {
            ck_assert_uint_gt(array[i], array[middle]);
        }
    }
}
END_TEST

START_TEST(test_rand_quick_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_rand_quick_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_rand_quick_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_rand_quick_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_rand_quick_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_rand_quick_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_rand_quick_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_rand_quick_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_rand_quick_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_rand_quick_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_rand_quick_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_rand_quick_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_rand_quick_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_rand_quick_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_rand_quick_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_rand_quick_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    rand_quick_sort(array, start, end, seed);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_selection_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_selection_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_selection_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_selection_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_selection_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_selection_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_selection_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_selection_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_selection_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_selection_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_selection_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_selection_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_selection_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_selection_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_selection_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_selection_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    selection_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_bubble_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_bubble_sort_2)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_bubble_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_bubble_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_bubble_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;
    
    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_bubble_sort_6)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int start = 2;
    int end = 7;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
}
END_TEST

START_TEST(test_bubble_sort_7)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int start = 0;
    int end = 5;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_bubble_sort_8)
{
    int array[] = {2, 4, 1, 5, 2, 3, 7, 6};
    int start = 2;
    int end = 5;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 2);
    ck_assert_int_eq(array[1], 4);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_bubble_sort_9)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 0;
    int end = 13;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_bubble_sort_10)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int start = 2;
    int end = 11;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], -200);
    ck_assert_int_eq(array[3], -100);
    ck_assert_int_eq(array[4], -80);
    ck_assert_int_eq(array[5], -7);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 300);
    ck_assert_int_eq(array[11], 700);
    ck_assert_int_eq(array[12], 150);
    ck_assert_int_eq(array[13], 570);
}
END_TEST

START_TEST(test_bubble_sort_11)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int start = 0;
    int end = 11;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_bubble_sort_12)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int start = 0;
    int end = 5;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_bubble_sort_13)
{
    int array[] = {5};
    int start = 0;
    int end = 0;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_bubble_sort_14)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int start = 0;
    int end = 10;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_bubble_sort_15)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 9;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_bubble_sort_16)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int start = 0;
    int end = 9;

    bubble_sort(array, start, end);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_heap_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int length = 6;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_heap_sort_2)
{
    int array[] = {5};
    int length = 1;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_heap_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int length = 11;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_heap_sort_4)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = 10;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_heap_sort_5)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int length = 10;
    
    heap_sort(array, length);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_heap_sort_6)
{
    int array[] = {2, 4, 5, 1, 2, 3, 7, 6};
    int length = 6;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 7);
    ck_assert_int_eq(array[7], 6);
}
END_TEST

START_TEST(test_heap_sort_7)
{
    int array[] = {0, 2, 3, 4, 55, 300, 700, -200,
                   -100, -80, -7, 30, 150, 570};
    int length = 14;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -100);
    ck_assert_int_eq(array[2], -80);
    ck_assert_int_eq(array[3], -7);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 2);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 4);
    ck_assert_int_eq(array[8], 30);
    ck_assert_int_eq(array[9], 55);
    ck_assert_int_eq(array[10], 150);
    ck_assert_int_eq(array[11], 300);
    ck_assert_int_eq(array[12], 570);
    ck_assert_int_eq(array[13], 700);
}
END_TEST

START_TEST(test_heap_sort_8)
{
    int array[] = {3, 15, 20, 30, 50, 75, -75, -50, -30, -20, -15, -3};
    int length = 12;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], -75);
    ck_assert_int_eq(array[1], -50);
    ck_assert_int_eq(array[2], -30);
    ck_assert_int_eq(array[3], -20);
    ck_assert_int_eq(array[4], -15);
    ck_assert_int_eq(array[5], -3);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 15);
    ck_assert_int_eq(array[8], 20);
    ck_assert_int_eq(array[9], 30);
    ck_assert_int_eq(array[10], 50);
    ck_assert_int_eq(array[11], 75);
}
END_TEST

START_TEST(test_heap_sort_9)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int length = 6;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 1);
    ck_assert_int_eq(array[1], 2);
    ck_assert_int_eq(array[2], 3);
    ck_assert_int_eq(array[3], 4);
    ck_assert_int_eq(array[4], 5);
    ck_assert_int_eq(array[5], 6);
}
END_TEST

START_TEST(test_heap_sort_10)
{
    int array[] = {5};
    int length = 1;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_heap_sort_11)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int length = 11;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], -200);
    ck_assert_int_eq(array[1], -20);
    ck_assert_int_eq(array[2], -10);
    ck_assert_int_eq(array[3], -5);
    ck_assert_int_eq(array[4], 0);
    ck_assert_int_eq(array[5], 15);
    ck_assert_int_eq(array[6], 30);
    ck_assert_int_eq(array[7], 50);
    ck_assert_int_eq(array[8], 75);
    ck_assert_int_eq(array[9], 100);
    ck_assert_int_eq(array[10], 200);
}
END_TEST

START_TEST(test_heap_sort_12)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = 10;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

START_TEST(test_heap_sort_13)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int length = 10;

    heap_sort(array, length);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
    ck_assert_int_eq(array[4], 4);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 6);
    ck_assert_int_eq(array[7], 7);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 9);
}
END_TEST

Suite *make_rbt_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Sorting Algorithms Test Suite");

    tc_core = tcase_create("Test Cases with Setup and Teardown");

    tcase_add_test(tc_core, test_insertion_sort_1);
    tcase_add_test(tc_core, test_insertion_sort_2);
    tcase_add_test(tc_core, test_insertion_sort_3);
    tcase_add_test(tc_core, test_insertion_sort_4);
    tcase_add_test(tc_core, test_insertion_sort_5);
    tcase_add_test(tc_core, test_insertion_sort_6);
    tcase_add_test(tc_core, test_insertion_sort_7);
    tcase_add_test(tc_core, test_insertion_sort_8);
    tcase_add_test(tc_core, test_insertion_sort_9);
    tcase_add_test(tc_core, test_insertion_sort_10);
    tcase_add_test(tc_core, test_insertion_sort_11);
    tcase_add_test(tc_core, test_insertion_sort_12);
    tcase_add_test(tc_core, test_insertion_sort_13);
    tcase_add_test(tc_core, test_insertion_sort_14);
    tcase_add_test(tc_core, test_insertion_sort_15);
    tcase_add_test(tc_core, test_insertion_sort_16);

    tcase_add_test(tc_core, test_merge_1);
    tcase_add_test(tc_core, test_merge_2);
    tcase_add_test(tc_core, test_merge_3);
    tcase_add_test(tc_core, test_merge_4);
    tcase_add_test(tc_core, test_merge_5);
    tcase_add_test(tc_core, test_merge_6);
    tcase_add_test(tc_core, test_merge_7);
    tcase_add_test(tc_core, test_merge_8);
    tcase_add_test(tc_core, test_merge_9);
    tcase_add_test(tc_core, test_merge_10);

    tcase_add_test(tc_core, test_merge_sort_1);
    tcase_add_test(tc_core, test_merge_sort_2);
    tcase_add_test(tc_core, test_merge_sort_3);
    tcase_add_test(tc_core, test_merge_sort_4);
    tcase_add_test(tc_core, test_merge_sort_5);
    tcase_add_test(tc_core, test_merge_sort_6);
    tcase_add_test(tc_core, test_merge_sort_7);
    tcase_add_test(tc_core, test_merge_sort_8);
    tcase_add_test(tc_core, test_merge_sort_9);
    tcase_add_test(tc_core, test_merge_sort_10);
    tcase_add_test(tc_core, test_merge_sort_11);
    tcase_add_test(tc_core, test_merge_sort_12);
    tcase_add_test(tc_core, test_merge_sort_13);
    tcase_add_test(tc_core, test_merge_sort_14);
    tcase_add_test(tc_core, test_merge_sort_15);
    tcase_add_test(tc_core, test_merge_sort_16);

    tcase_add_test(tc_core, test_inplace_merge_1);
    tcase_add_test(tc_core, test_inplace_merge_2);
    tcase_add_test(tc_core, test_inplace_merge_3);
    tcase_add_test(tc_core, test_inplace_merge_4);
    tcase_add_test(tc_core, test_inplace_merge_5);
    tcase_add_test(tc_core, test_inplace_merge_6);
    tcase_add_test(tc_core, test_inplace_merge_7);
    tcase_add_test(tc_core, test_inplace_merge_8);
    tcase_add_test(tc_core, test_inplace_merge_9);
    tcase_add_test(tc_core, test_inplace_merge_10);

    tcase_add_test(tc_core, test_inplace_merge_sort_1);
    tcase_add_test(tc_core, test_inplace_merge_sort_2);
    tcase_add_test(tc_core, test_inplace_merge_sort_3);
    tcase_add_test(tc_core, test_inplace_merge_sort_4);
    tcase_add_test(tc_core, test_inplace_merge_sort_5);
    tcase_add_test(tc_core, test_inplace_merge_sort_6);
    tcase_add_test(tc_core, test_inplace_merge_sort_7);
    tcase_add_test(tc_core, test_inplace_merge_sort_8);
    tcase_add_test(tc_core, test_inplace_merge_sort_9);
    tcase_add_test(tc_core, test_inplace_merge_sort_10);
    tcase_add_test(tc_core, test_inplace_merge_sort_11);
    tcase_add_test(tc_core, test_inplace_merge_sort_11);
    tcase_add_test(tc_core, test_inplace_merge_sort_12);
    tcase_add_test(tc_core, test_inplace_merge_sort_13);
    tcase_add_test(tc_core, test_inplace_merge_sort_14);
    tcase_add_test(tc_core, test_inplace_merge_sort_15);
    tcase_add_test(tc_core, test_inplace_merge_sort_16);

    tcase_add_test(tc_core, test_partition_1);
    tcase_add_test(tc_core, test_partition_2);
    tcase_add_test(tc_core, test_partition_3);
    tcase_add_test(tc_core, test_partition_4);
    tcase_add_test(tc_core, test_partition_5);

    tcase_add_test(tc_core, test_quick_sort_1);
    tcase_add_test(tc_core, test_quick_sort_2);
    tcase_add_test(tc_core, test_quick_sort_3);
    tcase_add_test(tc_core, test_quick_sort_4);
    tcase_add_test(tc_core, test_quick_sort_5);
    tcase_add_test(tc_core, test_quick_sort_6);
    tcase_add_test(tc_core, test_quick_sort_7);
    tcase_add_test(tc_core, test_quick_sort_8);
    tcase_add_test(tc_core, test_quick_sort_9);
    tcase_add_test(tc_core, test_quick_sort_10);
    tcase_add_test(tc_core, test_quick_sort_11);
    tcase_add_test(tc_core, test_quick_sort_12);
    tcase_add_test(tc_core, test_quick_sort_13);
    tcase_add_test(tc_core, test_quick_sort_14);
    tcase_add_test(tc_core, test_quick_sort_15);
    tcase_add_test(tc_core, test_quick_sort_16);

    tcase_add_test(tc_core, test_rand_partition_1);
    tcase_add_test(tc_core, test_rand_partition_2);
    tcase_add_test(tc_core, test_rand_partition_3);
    tcase_add_test(tc_core, test_rand_partition_4);
    tcase_add_test(tc_core, test_rand_partition_5);

    tcase_add_test(tc_core, test_rand_quick_sort_1);
    tcase_add_test(tc_core, test_rand_quick_sort_2);
    tcase_add_test(tc_core, test_rand_quick_sort_3);
    tcase_add_test(tc_core, test_rand_quick_sort_4);
    tcase_add_test(tc_core, test_rand_quick_sort_5);
    tcase_add_test(tc_core, test_rand_quick_sort_6);
    tcase_add_test(tc_core, test_rand_quick_sort_7);
    tcase_add_test(tc_core, test_rand_quick_sort_8);
    tcase_add_test(tc_core, test_rand_quick_sort_9);
    tcase_add_test(tc_core, test_rand_quick_sort_10);
    tcase_add_test(tc_core, test_rand_quick_sort_11);
    tcase_add_test(tc_core, test_rand_quick_sort_12);
    tcase_add_test(tc_core, test_rand_quick_sort_13);
    tcase_add_test(tc_core, test_rand_quick_sort_14);
    tcase_add_test(tc_core, test_rand_quick_sort_15);
    tcase_add_test(tc_core, test_rand_quick_sort_16);

    tcase_add_test(tc_core, test_selection_sort_1);
    tcase_add_test(tc_core, test_selection_sort_2);
    tcase_add_test(tc_core, test_selection_sort_3);
    tcase_add_test(tc_core, test_selection_sort_4);
    tcase_add_test(tc_core, test_selection_sort_5);
    tcase_add_test(tc_core, test_selection_sort_6);
    tcase_add_test(tc_core, test_selection_sort_7);
    tcase_add_test(tc_core, test_selection_sort_8);
    tcase_add_test(tc_core, test_selection_sort_9);
    tcase_add_test(tc_core, test_selection_sort_10);
    tcase_add_test(tc_core, test_selection_sort_11);
    tcase_add_test(tc_core, test_selection_sort_12);
    tcase_add_test(tc_core, test_selection_sort_13);
    tcase_add_test(tc_core, test_selection_sort_14);
    tcase_add_test(tc_core, test_selection_sort_15);
    tcase_add_test(tc_core, test_selection_sort_16);
 
    tcase_add_test(tc_core, test_bubble_sort_1);
    tcase_add_test(tc_core, test_bubble_sort_2);
    tcase_add_test(tc_core, test_bubble_sort_3);
    tcase_add_test(tc_core, test_bubble_sort_4);
    tcase_add_test(tc_core, test_bubble_sort_5);
    tcase_add_test(tc_core, test_bubble_sort_6);
    tcase_add_test(tc_core, test_bubble_sort_7);
    tcase_add_test(tc_core, test_bubble_sort_8);
    tcase_add_test(tc_core, test_bubble_sort_9);
    tcase_add_test(tc_core, test_bubble_sort_10);
    tcase_add_test(tc_core, test_bubble_sort_11);
    tcase_add_test(tc_core, test_bubble_sort_12);
    tcase_add_test(tc_core, test_bubble_sort_13);
    tcase_add_test(tc_core, test_bubble_sort_14);
    tcase_add_test(tc_core, test_bubble_sort_15);
    tcase_add_test(tc_core, test_bubble_sort_16);

    tcase_add_test(tc_core, test_heap_sort_1);
    tcase_add_test(tc_core, test_heap_sort_2);
    tcase_add_test(tc_core, test_heap_sort_3);
    tcase_add_test(tc_core, test_heap_sort_4);
    tcase_add_test(tc_core, test_heap_sort_5);
    tcase_add_test(tc_core, test_heap_sort_6);
    tcase_add_test(tc_core, test_heap_sort_7);
    tcase_add_test(tc_core, test_heap_sort_8);
    tcase_add_test(tc_core, test_heap_sort_9);
    tcase_add_test(tc_core, test_heap_sort_10);
    tcase_add_test(tc_core, test_heap_sort_11);
    tcase_add_test(tc_core, test_heap_sort_12);
    tcase_add_test(tc_core, test_heap_sort_13);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(make_rbt_suite());
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "test.log");
    srunner_set_xml(sr, "test.xml");
    srunner_run_all(sr, CK_VERBOSE);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
