#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <stdbool.h>
#include <sort.h>

void setup(void);
void teardown(void);
Suite *make_rbt_suite(void);

void setup(void)
{
}

void teardown(void)
{

}

START_TEST(test_insertion_sort_1)
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int length = 6;

    insertion_sort(array, length);

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
    int length = 1;

    insertion_sort(array, length);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_insertion_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int length = 11;

    insertion_sort(array, length);

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
    int length = 10;

    insertion_sort(array, length);

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
    int length = 10;

    insertion_sort(array, length);

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
    int p = 0;
    int q = 3;
    int r = 7;

    merge(array, p, q, r);

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
    int p = 0;
    int q = 0;
    int r = 1;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], -2);
    ck_assert_int_eq(array[1], 2);
}
END_TEST

START_TEST(test_merge_3)
{
    int array[] = {-5, 0};
    int p = 0;
    int q = 0;
    int r = 1;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_merge_4)
{
    int array[] = {-5, 0};
    int p = 0;
    int q = 0;
    int r = 1;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_merge_5)
{
    int array[] = {5, 3, 7};
    int p = 0;
    int q = 0;
    int r = 2;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], 3);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
}
END_TEST

START_TEST(test_merge_6)
{
    int array[] = {8, -5, -3};
    int p = 0;
    int q = 0;
    int r = 2;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], -3);
    ck_assert_int_eq(array[2], 8);
}
END_TEST

START_TEST(test_merge_7)
{
    int array[] = {-10, -5, -1};
    int p = 0;
    int q = 0;
    int r = 2;

    merge(array, p, q, r);

    ck_assert_int_eq(array[0], -10);
    ck_assert_int_eq(array[1], -5);
    ck_assert_int_eq(array[2], -1);
}
END_TEST

START_TEST(test_merge_8)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int p = 2;
    int q = 4;
    int r = 7;

    merge(array, p, q, r);

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
    int p = 0;
    int q = 2;
    int r = 5;

    merge(array, p, q, r);

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
    int p = 2;
    int q = 3;
    int r = 5;

    merge(array, p, q, r);

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
    int p = 0;
    int r = 5;

    merge_sort(array, p, r);

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
    int p = 0;
    int r = 0;

    merge_sort(array, p, r);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_merge_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int p = 0;
    int r = 10;

    merge_sort(array, p, r);

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
    int p = 0;
    int r = 9;

    merge_sort(array, p, r);

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
    int p = 0;
    int r = 9;
    
    merge_sort(array, p, r);

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
    int p = 2;
    int r = 7;

    merge_sort(array, p, r);

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
    int p = 0;
    int r = 5;

    merge_sort(array, p, r);

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
    int p = 2;
    int r = 5;

    merge_sort(array, p, r);

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
    int p = 0;
    int r = 13;

    merge_sort(array, p, r);

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
    int p = 2;
    int r = 11;

    merge_sort(array, p, r);

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






























START_TEST(test_inplace_merge_1)
{
    int array[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int p = 0;
    int q = 3;
    int r = 7;

    inplace_merge(array, p, q, r);

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
    int p = 0;
    int q = 0;
    int r = 1;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], -2);
    ck_assert_int_eq(array[1], 2);
}
END_TEST

START_TEST(test_inplace_merge_3)
{
    int array[] = {-5, 0};
    int p = 0;
    int q = 0;
    int r = 1;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_inplace_merge_4)
{
    int array[] = {-5, 0};
    int p = 0;
    int q = 0;
    int r = 1;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], 0);
}
END_TEST

START_TEST(test_inplace_merge_5)
{
    int array[] = {5, 3, 7};
    int p = 0;
    int q = 0;
    int r = 2;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], 3);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 7);
}
END_TEST

START_TEST(test_inplace_merge_6)
{
    int array[] = {8, -5, -3};
    int p = 0;
    int q = 0;
    int r = 2;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], -5);
    ck_assert_int_eq(array[1], -3);
    ck_assert_int_eq(array[2], 8);
}
END_TEST

START_TEST(test_inplace_merge_7)
{
    int array[] = {-10, -5, -1};
    int p = 0;
    int q = 0;
    int r = 2;

    inplace_merge(array, p, q, r);

    ck_assert_int_eq(array[0], -10);
    ck_assert_int_eq(array[1], -5);
    ck_assert_int_eq(array[2], -1);
}
END_TEST

START_TEST(test_inplace_merge_8)
{
    int array[] = {2, 4, 1, 5, 7, 2, 3, 6};
    int p = 2;
    int q = 4;
    int r = 7;

    inplace_merge(array, p, q, r);

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
    int p = 0;
    int q = 2;
    int r = 5;

    inplace_merge(array, p, q, r);

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
    int p = 2;
    int q = 3;
    int r = 5;

    inplace_merge(array, p, q, r);

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
    int p = 0;
    int r = 5;

    inplace_merge_sort(array, p, r);

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
    int p = 0;
    int r = 0;

    inplace_merge_sort(array, p, r);

    ck_assert_int_eq(array[0], 5);
}
END_TEST

START_TEST(test_inplace_merge_sort_3)
{
    int array[] = {-10, 15, -5, -20, 50, 0, 100, 75, 30, 200, -200};
    int p = 0;
    int r = 10;

    inplace_merge_sort(array, p, r);

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
    int p = 0;
    int r = 9;

    inplace_merge_sort(array, p, r);

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
    int p = 0;
    int r = 9;
    
    inplace_merge_sort(array, p, r);

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
    int p = 2;
    int r = 7;

    inplace_merge_sort(array, p, r);

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
    int p = 0;
    int r = 5;

    inplace_merge_sort(array, p, r);

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
    int p = 2;
    int r = 5;

    inplace_merge_sort(array, p, r);

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
    int p = 0;
    int r = 13;

    inplace_merge_sort(array, p, r);

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
    int p = 2;
    int r = 11;

    inplace_merge_sort(array, p, r);

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
































Suite *make_rbt_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Red-Black Tree Test Suite");

    tc_core = tcase_create("Test Cases with Setup and Teardown");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_insertion_sort_1);
    tcase_add_test(tc_core, test_insertion_sort_2);
    tcase_add_test(tc_core, test_insertion_sort_3);
    tcase_add_test(tc_core, test_insertion_sort_4);
    tcase_add_test(tc_core, test_insertion_sort_5);

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
