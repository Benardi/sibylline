#include <check.h>
#include <malloc.h>
#include <sort.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Suite *make_test_suite(void);

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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {-9, -7, -5, -3, -1, 0,  2,  4,   6,  8,
                 10, 12, 15, 20, 25, 30, 50, 100, 200};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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

  for (i = start; i <= end; i++)
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

  for (i = start; i <= end; i++)
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

  for (i = start; i <= end; i++)
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
  int array[] = {-9, -7, -5, -3, -1, 0,  2,  4,   6,  8,
                 10, 12, 15, 20, 25, 30, 50, 100, 200};
  int start = 0;
  int end = 18;

  middle = rand_partition(array, start, end);

  ck_assert_int_gt(middle, start - 1);
  ck_assert_int_lt(middle, end + 1);

  for (i = start; i <= end; i++)
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

  for (i = start; i <= end; i++)
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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
  int array[] = {0, 2, 3, 4, 55, 300, 700, -200, -100, -80, -7, 30, 150, 570};
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

START_TEST(test_heap_sort_11)
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

START_TEST(test_heap_sort_12)
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

START_TEST(test_counting_sort_1)
{
  int *out;
  int length = 6;
  int upper_limit = 10;
  int array[] = {5, 2, 4, 6, 1, 3};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 3);
  ck_assert_int_eq(out[3], 4);
  ck_assert_int_eq(out[4], 5);
  ck_assert_int_eq(out[5], 6);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_2)
{
  int *out;
  int length = 1;
  int upper_limit = 10;
  int array[] = {5};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 5);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_3)
{
  int *out;
  int length = 11;
  int upper_limit = 250;
  int array[] = {10, 15, 5, 20, 50, 0, 100, 75, 30, 200, 2};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 5);
  ck_assert_int_eq(out[3], 10);
  ck_assert_int_eq(out[4], 15);
  ck_assert_int_eq(out[5], 20);
  ck_assert_int_eq(out[6], 30);
  ck_assert_int_eq(out[7], 50);
  ck_assert_int_eq(out[8], 75);
  ck_assert_int_eq(out[9], 100);
  ck_assert_int_eq(out[10], 200);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_4)
{
  int *out;
  int length = 10;
  int upper_limit = 250;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 1);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);
  ck_assert_int_eq(out[6], 6);
  ck_assert_int_eq(out[7], 7);
  ck_assert_int_eq(out[8], 8);
  ck_assert_int_eq(out[9], 9);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_5)
{
  int *out;
  int length = 10;
  int upper_limit = 20;
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 1);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);
  ck_assert_int_eq(out[6], 6);
  ck_assert_int_eq(out[7], 7);
  ck_assert_int_eq(out[8], 8);
  ck_assert_int_eq(out[9], 9);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_6)
{
  int *out;
  int length = 6;
  int upper_limit = 20;
  int array[] = {2, 4, 5, 1, 2, 3, 7, 6};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_7)
{
  int *out;
  int length = 14;
  int upper_limit = 1000;
  int array[] = {0, 4, 2, 55, 300, 3, 700, 200, 100, 80, 7, 30, 150, 570};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 3);
  ck_assert_int_eq(out[3], 4);
  ck_assert_int_eq(out[4], 7);
  ck_assert_int_eq(out[5], 30);
  ck_assert_int_eq(out[6], 55);
  ck_assert_int_eq(out[7], 80);
  ck_assert_int_eq(out[8], 100);
  ck_assert_int_eq(out[9], 150);
  ck_assert_int_eq(out[10], 200);
  ck_assert_int_eq(out[11], 300);
  ck_assert_int_eq(out[12], 570);
  ck_assert_int_eq(out[13], 700);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_8)
{
  int *out;
  int length = 12;
  int upper_limit = 1000;
  int array[] = {3, 15, 20, 30, 50, 75, 750, 500, 300, 200, 150, 10};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 3);
  ck_assert_int_eq(out[1], 10);
  ck_assert_int_eq(out[2], 15);
  ck_assert_int_eq(out[3], 20);
  ck_assert_int_eq(out[4], 30);
  ck_assert_int_eq(out[5], 50);
  ck_assert_int_eq(out[6], 75);
  ck_assert_int_eq(out[7], 150);
  ck_assert_int_eq(out[8], 200);
  ck_assert_int_eq(out[9], 300);
  ck_assert_int_eq(out[10], 500);
  ck_assert_int_eq(out[11], 750);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_9)
{
  int *out;
  int length = 6;
  int upper_limit = 10;
  int array[] = {5, 2, 4, 6, 1, 3};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 3);
  ck_assert_int_eq(out[3], 4);
  ck_assert_int_eq(out[4], 5);
  ck_assert_int_eq(out[5], 6);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_10)
{
  int *out;
  int length = 11;
  int upper_limit = 200;
  int array[] = {10, 15, 5, 20, 50, 0, 100, 75, 30, 200, 122};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 5);
  ck_assert_int_eq(out[2], 10);
  ck_assert_int_eq(out[3], 15);
  ck_assert_int_eq(out[4], 20);
  ck_assert_int_eq(out[5], 30);
  ck_assert_int_eq(out[6], 50);
  ck_assert_int_eq(out[7], 75);
  ck_assert_int_eq(out[8], 100);
  ck_assert_int_eq(out[9], 122);
  ck_assert_int_eq(out[10], 200);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_11)
{
  int *out;
  int length = 10;
  int upper_limit = 200;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 1);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);
  ck_assert_int_eq(out[6], 6);
  ck_assert_int_eq(out[7], 7);
  ck_assert_int_eq(out[8], 8);
  ck_assert_int_eq(out[9], 9);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_12)
{
  int *out;
  int length = 10;
  int upper_limit = 200;
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  out = malloc((length) * sizeof(int));

  counting_sort(array, out, length, upper_limit);

  ck_assert_int_eq(out[0], 0);
  ck_assert_int_eq(out[1], 1);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);
  ck_assert_int_eq(out[6], 6);
  ck_assert_int_eq(out[7], 7);
  ck_assert_int_eq(out[8], 8);
  ck_assert_int_eq(out[9], 9);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_1)
{
  int *out;
  int n = 1;
  int length = 9;
  int array[] = {81, 56, 47, 19, 24, 62, 93, 35, 8};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 81);
  ck_assert_int_eq(out[1], 62);
  ck_assert_int_eq(out[2], 93);
  ck_assert_int_eq(out[3], 24);
  ck_assert_int_eq(out[4], 35);
  ck_assert_int_eq(out[5], 56);
  ck_assert_int_eq(out[6], 47);
  ck_assert_int_eq(out[7], 8);
  ck_assert_int_eq(out[8], 19);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_2)
{
  int *out;
  int n = 2;
  int length = 10;
  int array[] = {160, 122, 128, 79, 77, 13, 99, 8, 26, 108};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 8);
  ck_assert_int_eq(out[1], 108);
  ck_assert_int_eq(out[2], 13);
  ck_assert_int_eq(out[3], 122);
  ck_assert_int_eq(out[4], 128);
  ck_assert_int_eq(out[5], 26);
  ck_assert_int_eq(out[6], 160);
  ck_assert_int_eq(out[7], 79);
  ck_assert_int_eq(out[8], 77);
  ck_assert_int_eq(out[9], 99);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_3)
{
  int *out;
  int n = 1;
  int length = 8;
  int array[] = {170, 45, 75, 90, 802, 24, 2, 66};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 170);
  ck_assert_int_eq(out[1], 90);
  ck_assert_int_eq(out[2], 802);
  ck_assert_int_eq(out[3], 2);
  ck_assert_int_eq(out[4], 24);
  ck_assert_int_eq(out[5], 45);
  ck_assert_int_eq(out[6], 75);
  ck_assert_int_eq(out[7], 66);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_4)
{
  int *out;
  int n = 2;
  int length = 8;
  int array[] = {170, 90, 802, 2, 24, 45, 75, 66};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 802);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 24);
  ck_assert_int_eq(out[3], 45);
  ck_assert_int_eq(out[4], 66);
  ck_assert_int_eq(out[5], 170);
  ck_assert_int_eq(out[6], 75);
  ck_assert_int_eq(out[7], 90);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_5)
{
  int *out;
  int n = 3;
  int length = 8;
  int array[] = {802, 2, 24, 45, 66, 170, 75, 90};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 2);
  ck_assert_int_eq(out[1], 24);
  ck_assert_int_eq(out[2], 45);
  ck_assert_int_eq(out[3], 66);
  ck_assert_int_eq(out[4], 75);
  ck_assert_int_eq(out[5], 90);
  ck_assert_int_eq(out[6], 170);
  ck_assert_int_eq(out[7], 802);

  free(out);
}
END_TEST

START_TEST(test_counting_sort_by_nth_digit_6)
{
  int *out;
  int n = 1;
  int length = 30;
  int array[] = {698, 506, 619, 179, 524, 714, 890, 41,  358, 656,
                 336, 755, 990, 242, 133, 258, 564, 338, 274, 305,
                 984, 220, 656, 307, 359, 836, 495, 426, 847, 387};

  out = malloc((length) * sizeof(int));

  counting_sort_by_nth_digit(array, out, length, n);

  ck_assert_int_eq(out[0], 890);
  ck_assert_int_eq(out[1], 990);
  ck_assert_int_eq(out[2], 220);
  ck_assert_int_eq(out[3], 41);
  ck_assert_int_eq(out[4], 242);
  ck_assert_int_eq(out[5], 133);
  ck_assert_int_eq(out[6], 524);
  ck_assert_int_eq(out[7], 714);
  ck_assert_int_eq(out[8], 564);
  ck_assert_int_eq(out[9], 274);
  ck_assert_int_eq(out[10], 984);
  ck_assert_int_eq(out[11], 755);
  ck_assert_int_eq(out[12], 305);
  ck_assert_int_eq(out[13], 495);
  ck_assert_int_eq(out[14], 506);
  ck_assert_int_eq(out[15], 656);
  ck_assert_int_eq(out[16], 336);
  ck_assert_int_eq(out[17], 656);
  ck_assert_int_eq(out[18], 836);
  ck_assert_int_eq(out[19], 426);
  ck_assert_int_eq(out[20], 307);
  ck_assert_int_eq(out[21], 847);
  ck_assert_int_eq(out[22], 387);
  ck_assert_int_eq(out[23], 698);
  ck_assert_int_eq(out[24], 358);
  ck_assert_int_eq(out[25], 258);
  ck_assert_int_eq(out[26], 338);
  ck_assert_int_eq(out[27], 619);
  ck_assert_int_eq(out[28], 179);
  ck_assert_int_eq(out[29], 359);

  free(out);
}
END_TEST

Suite *make_test_suite(void)
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

  tcase_add_test(tc_core, test_counting_sort_1);
  tcase_add_test(tc_core, test_counting_sort_2);
  tcase_add_test(tc_core, test_counting_sort_3);
  tcase_add_test(tc_core, test_counting_sort_4);
  tcase_add_test(tc_core, test_counting_sort_5);
  tcase_add_test(tc_core, test_counting_sort_6);
  tcase_add_test(tc_core, test_counting_sort_7);
  tcase_add_test(tc_core, test_counting_sort_8);
  tcase_add_test(tc_core, test_counting_sort_9);
  tcase_add_test(tc_core, test_counting_sort_10);
  tcase_add_test(tc_core, test_counting_sort_11);
  tcase_add_test(tc_core, test_counting_sort_12);

  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_1);
  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_2);
  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_3);
  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_4);
  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_5);
  tcase_add_test(tc_core, test_counting_sort_by_nth_digit_6);

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
