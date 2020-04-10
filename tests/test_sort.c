#include <check.h>
#include <malloc.h>
#include <math.h>
#include <sort.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Suite* make_test_suite(void);
int compare_int(void* key1, void* key2);
int compare_float(void* key1, void* key2);
int compare_double(void* key1, void* key2);
int mul_plus_floor_float(int n, void* key);
int mul_plus_floor_double(int n, void* key);

int seed = 23;

int compare_int(void* key1, void* key2)
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

int compare_float(void* key1, void* key2)
{
  int result;
  float k1 = *((float*)key1);
  float k2 = *((float*)key2);

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

int compare_double(void* key1, void* key2)
{
  int result;
  double k1 = *((double*)key1);
  double k2 = *((double*)key2);

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

int mul_plus_floor_float(int n, void* key)
{
  int result;
  float temp = *((float*)key);
  temp = floor(n * temp);
  result = (int)temp;

  return result;
}

int mul_plus_floor_double(int n, void* key)
{
  int result;
  double temp = *((double*)key);
  temp = floor(n * temp);
  result = (int)temp;

  return result;
}

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
  Register* array;
  int k1, k2, k3, k4, k5, k6;
  int length = 6;

  array = malloc(length * sizeof(Register));

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 3);
  ck_assert_int_eq(*((int*)array[3].key), 4);
  ck_assert_int_eq(*((int*)array[4].key), 5);
  ck_assert_int_eq(*((int*)array[5].key), 6);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_2)
{
  Register* array;
  int k1;
  int length = 1;

  array = malloc(length * sizeof(Register));

  k1 = 5;

  array[0].key = &k1;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 5);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_3)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;

  array = malloc(length * sizeof(Register));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -20);
  ck_assert_int_eq(*((int*)array[2].key), -10);
  ck_assert_int_eq(*((int*)array[3].key), -5);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 15);
  ck_assert_int_eq(*((int*)array[6].key), 30);
  ck_assert_int_eq(*((int*)array[7].key), 50);
  ck_assert_int_eq(*((int*)array[8].key), 75);
  ck_assert_int_eq(*((int*)array[9].key), 100);
  ck_assert_int_eq(*((int*)array[10].key), 200);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_4)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_5)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  array = malloc(length * sizeof(Register));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_6)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8;
  int length = 6;

  array = malloc((length + 2) * sizeof(Register));

  k1 = 2;
  k2 = 4;
  k3 = 5;
  k4 = 1;
  k5 = 2;
  k6 = 3;
  k7 = 7;
  k8 = 6;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 7);
  ck_assert_int_eq(*((int*)array[7].key), 6);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_7)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;
  int length = 14;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 2;
  k3 = 3;
  k4 = 4;
  k5 = 55;
  k6 = 300;
  k7 = 700;
  k8 = -200;
  k9 = -100;
  k10 = -80;
  k11 = -7;
  k12 = 30;
  k13 = 150;
  k14 = 570;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;
  array[12].key = &k13;
  array[13].key = &k14;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -100);
  ck_assert_int_eq(*((int*)array[2].key), -80);
  ck_assert_int_eq(*((int*)array[3].key), -7);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 2);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 4);
  ck_assert_int_eq(*((int*)array[8].key), 30);
  ck_assert_int_eq(*((int*)array[9].key), 55);
  ck_assert_int_eq(*((int*)array[10].key), 150);
  ck_assert_int_eq(*((int*)array[11].key), 300);
  ck_assert_int_eq(*((int*)array[12].key), 570);
  ck_assert_int_eq(*((int*)array[13].key), 700);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_8)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12;
  int length = 12;

  array = malloc(length * sizeof(Register));

  k1 = 3;
  k2 = 15;
  k3 = 20;
  k4 = 30;
  k5 = 50;
  k6 = 75;
  k7 = -75;
  k8 = -50;
  k9 = -30;
  k10 = -20;
  k11 = -15;
  k12 = -3;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -75);
  ck_assert_int_eq(*((int*)array[1].key), -50);
  ck_assert_int_eq(*((int*)array[2].key), -30);
  ck_assert_int_eq(*((int*)array[3].key), -20);
  ck_assert_int_eq(*((int*)array[4].key), -15);
  ck_assert_int_eq(*((int*)array[5].key), -3);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 15);
  ck_assert_int_eq(*((int*)array[8].key), 20);
  ck_assert_int_eq(*((int*)array[9].key), 30);
  ck_assert_int_eq(*((int*)array[10].key), 50);
  ck_assert_int_eq(*((int*)array[11].key), 75);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_9)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6;
  int length = 6;

  array = malloc(length * sizeof(Register));

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 3);
  ck_assert_int_eq(*((int*)array[3].key), 4);
  ck_assert_int_eq(*((int*)array[4].key), 5);
  ck_assert_int_eq(*((int*)array[5].key), 6);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_10)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;

  array = malloc(length * sizeof(Register));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -20);
  ck_assert_int_eq(*((int*)array[2].key), -10);
  ck_assert_int_eq(*((int*)array[3].key), -5);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 15);
  ck_assert_int_eq(*((int*)array[6].key), 30);
  ck_assert_int_eq(*((int*)array[7].key), 50);
  ck_assert_int_eq(*((int*)array[8].key), 75);
  ck_assert_int_eq(*((int*)array[9].key), 100);
  ck_assert_int_eq(*((int*)array[10].key), 200);

  free(array);
}
END_TEST

START_TEST(test_heap_sort_11)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST
START_TEST(test_heap_sort_12)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  array = malloc(length * sizeof(Register));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  heap_sort(array, length, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_counting_sort_1)
{
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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
  int* out;
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

START_TEST(test_radix_sort_1)
{
  int* out;
  int length = 6;
  int max_decimal_place = 1;
  int array[] = {5, 2, 4, 6, 1, 3};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 3);
  ck_assert_int_eq(out[3], 4);
  ck_assert_int_eq(out[4], 5);
  ck_assert_int_eq(out[5], 6);

  free(out);
}
END_TEST

START_TEST(test_radix_sort_2)
{
  int* out;
  int length = 1;
  int max_decimal_place = 1;
  int array[] = {5};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

  ck_assert_int_eq(out[0], 5);

  free(out);
}
END_TEST

START_TEST(test_radix_sort_3)
{
  int* out;
  int length = 11;
  int max_decimal_place = 3;
  int array[] = {10, 15, 5, 20, 50, 0, 100, 75, 30, 200, 2};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_4)
{
  int* out;
  int length = 10;
  int max_decimal_place = 1;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_5)
{
  int* out;
  int length = 10;
  int max_decimal_place = 1;
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_6)
{
  int* out;
  int length = 6;
  int max_decimal_place = 1;
  int array[] = {2, 4, 5, 1, 2, 3, 7, 6};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 2);
  ck_assert_int_eq(out[3], 3);
  ck_assert_int_eq(out[4], 4);
  ck_assert_int_eq(out[5], 5);

  free(out);
}
END_TEST

START_TEST(test_radix_sort_7)
{
  int* out;
  int length = 14;
  int max_decimal_place = 3;
  int array[] = {0, 4, 2, 55, 300, 3, 700, 200, 100, 80, 7, 30, 150, 570};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_8)
{
  int* out;
  int length = 12;
  int max_decimal_place = 3;
  int array[] = {3, 15, 20, 30, 50, 75, 750, 500, 300, 200, 150, 10};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_9)
{
  int* out;
  int length = 6;
  int max_decimal_place = 1;
  int array[] = {5, 2, 4, 6, 1, 3};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

  ck_assert_int_eq(out[0], 1);
  ck_assert_int_eq(out[1], 2);
  ck_assert_int_eq(out[2], 3);
  ck_assert_int_eq(out[3], 4);
  ck_assert_int_eq(out[4], 5);
  ck_assert_int_eq(out[5], 6);

  free(out);
}
END_TEST

START_TEST(test_radix_sort_10)
{
  int* out;
  int length = 11;
  int max_decimal_place = 3;
  int array[] = {10, 15, 5, 20, 50, 0, 100, 75, 30, 200, 122};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_11)
{
  int* out;
  int length = 10;
  int max_decimal_place = 1;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_radix_sort_12)
{
  int* out;
  int length = 10;
  int max_decimal_place = 1;
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  out = malloc((length) * sizeof(int));

  radix_sort(array, out, length, max_decimal_place);

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

START_TEST(test_insertion_sort_gnrc_1)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6;
  int length = 6;
  int start = 0;
  int end = 5;

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 3);
  ck_assert_int_eq(*((int*)array[3].key), 4);
  ck_assert_int_eq(*((int*)array[4].key), 5);
  ck_assert_int_eq(*((int*)array[5].key), 6);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_2)
{
  Register* array;
  int k1 = 5;
  int length = 1;
  int start = 0;
  int end = 0;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 5);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_3)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;
  int start = 0;
  int end = 10;

  array = malloc(length * sizeof(Register));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -20);
  ck_assert_int_eq(*((int*)array[2].key), -10);
  ck_assert_int_eq(*((int*)array[3].key), -5);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 15);
  ck_assert_int_eq(*((int*)array[6].key), 30);
  ck_assert_int_eq(*((int*)array[7].key), 50);
  ck_assert_int_eq(*((int*)array[8].key), 75);
  ck_assert_int_eq(*((int*)array[9].key), 100);
  ck_assert_int_eq(*((int*)array[10].key), 200);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_4)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;
  int start = 0;
  int end = 9;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_5)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;
  int start = 0;
  int end = 9;

  array = malloc(length * sizeof(Register));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_6)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8;
  int length = 8;
  int start = 2;
  int end = 7;

  array = malloc(length * sizeof(Register));

  k1 = 2;
  k2 = 4;
  k3 = 1;
  k4 = 5;
  k5 = 7;
  k6 = 2;
  k7 = 3;
  k8 = 6;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 2);
  ck_assert_int_eq(*((int*)array[1].key), 4);
  ck_assert_int_eq(*((int*)array[2].key), 1);
  ck_assert_int_eq(*((int*)array[3].key), 2);
  ck_assert_int_eq(*((int*)array[4].key), 3);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_7)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8;
  int length = 8;
  int start = 0;
  int end = 5;

  array = malloc(length * sizeof(Register));

  k1 = 2;
  k2 = 4;
  k3 = 5;
  k4 = 1;
  k5 = 2;
  k6 = 3;
  k7 = 7;
  k8 = 6;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 7);
  ck_assert_int_eq(*((int*)array[7].key), 6);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_8)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8;
  int length = 8;
  int start = 2;
  int end = 5;

  array = malloc(length * sizeof(Register));

  k1 = 2;
  k2 = 4;
  k3 = 1;
  k4 = 5;
  k5 = 2;
  k6 = 3;
  k7 = 7;
  k8 = 6;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 2);
  ck_assert_int_eq(*((int*)array[1].key), 4);
  ck_assert_int_eq(*((int*)array[2].key), 1);
  ck_assert_int_eq(*((int*)array[3].key), 2);
  ck_assert_int_eq(*((int*)array[4].key), 3);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 7);
  ck_assert_int_eq(*((int*)array[7].key), 6);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_9)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;
  int length = 14;
  int start = 0;
  int end = 13;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 2;
  k3 = 3;
  k4 = 4;
  k5 = 55;
  k6 = 300;
  k7 = 700;
  k8 = -200;
  k9 = -100;
  k10 = -80;
  k11 = -7;
  k12 = 30;
  k13 = 150;
  k14 = 570;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;
  array[12].key = &k13;
  array[13].key = &k14;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -100);
  ck_assert_int_eq(*((int*)array[2].key), -80);
  ck_assert_int_eq(*((int*)array[3].key), -7);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 2);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 4);
  ck_assert_int_eq(*((int*)array[8].key), 30);
  ck_assert_int_eq(*((int*)array[9].key), 55);
  ck_assert_int_eq(*((int*)array[10].key), 150);
  ck_assert_int_eq(*((int*)array[11].key), 300);
  ck_assert_int_eq(*((int*)array[12].key), 570);
  ck_assert_int_eq(*((int*)array[13].key), 700);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_10)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;
  int length = 14;
  int start = 2;
  int end = 11;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 2;
  k3 = 3;
  k4 = 4;
  k5 = 55;
  k6 = 300;
  k7 = 700;
  k8 = -200;
  k9 = -100;
  k10 = -80;
  k11 = -7;
  k12 = 30;
  k13 = 150;
  k14 = 570;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;
  array[12].key = &k13;
  array[13].key = &k14;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), -200);
  ck_assert_int_eq(*((int*)array[3].key), -100);
  ck_assert_int_eq(*((int*)array[4].key), -80);
  ck_assert_int_eq(*((int*)array[5].key), -7);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 4);
  ck_assert_int_eq(*((int*)array[8].key), 30);
  ck_assert_int_eq(*((int*)array[9].key), 55);
  ck_assert_int_eq(*((int*)array[10].key), 300);
  ck_assert_int_eq(*((int*)array[11].key), 700);
  ck_assert_int_eq(*((int*)array[12].key), 150);
  ck_assert_int_eq(*((int*)array[13].key), 570);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_11)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12;
  int length = 12;
  int start = 0;
  int end = 11;

  array = malloc(length * sizeof(Register));

  k1 = 3;
  k2 = 15;
  k3 = 20;
  k4 = 30;
  k5 = 50;
  k6 = 75;
  k7 = -75;
  k8 = -50;
  k9 = -30;
  k10 = -20;
  k11 = -15;
  k12 = -3;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -75);
  ck_assert_int_eq(*((int*)array[1].key), -50);
  ck_assert_int_eq(*((int*)array[2].key), -30);
  ck_assert_int_eq(*((int*)array[3].key), -20);
  ck_assert_int_eq(*((int*)array[4].key), -15);
  ck_assert_int_eq(*((int*)array[5].key), -3);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 15);
  ck_assert_int_eq(*((int*)array[8].key), 20);
  ck_assert_int_eq(*((int*)array[9].key), 30);
  ck_assert_int_eq(*((int*)array[10].key), 50);
  ck_assert_int_eq(*((int*)array[11].key), 75);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_12)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6;
  int length = 6;
  int start = 0;
  int end = 5;

  array = malloc(length * sizeof(Register));

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 1);
  ck_assert_int_eq(*((int*)array[1].key), 2);
  ck_assert_int_eq(*((int*)array[2].key), 3);
  ck_assert_int_eq(*((int*)array[3].key), 4);
  ck_assert_int_eq(*((int*)array[4].key), 5);
  ck_assert_int_eq(*((int*)array[5].key), 6);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_13)
{
  Register* array;
  int k1;
  int length = 1;
  int start = 0;
  int end = 0;

  array = malloc(length * sizeof(Register));

  k1 = 5;

  array[0].key = &k1;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 5);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_14)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;
  int start = 0;
  int end = 10;

  array = malloc(length * sizeof(Register));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), -200);
  ck_assert_int_eq(*((int*)array[1].key), -20);
  ck_assert_int_eq(*((int*)array[2].key), -10);
  ck_assert_int_eq(*((int*)array[3].key), -5);
  ck_assert_int_eq(*((int*)array[4].key), 0);
  ck_assert_int_eq(*((int*)array[5].key), 15);
  ck_assert_int_eq(*((int*)array[6].key), 30);
  ck_assert_int_eq(*((int*)array[7].key), 50);
  ck_assert_int_eq(*((int*)array[8].key), 75);
  ck_assert_int_eq(*((int*)array[9].key), 100);
  ck_assert_int_eq(*((int*)array[10].key), 200);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_15)
{
  Register* array;
  int length = 10;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int start = 0;
  int end = 9;

  array = malloc(length * sizeof(Register));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_gnrc_16)
{
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;
  int start = 0;
  int end = 9;

  array = malloc(length * sizeof(Register));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  insertion_sort_gnrc(array, start, end, compare_int);

  ck_assert_int_eq(*((int*)array[0].key), 0);
  ck_assert_int_eq(*((int*)array[1].key), 1);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 3);
  ck_assert_int_eq(*((int*)array[4].key), 4);
  ck_assert_int_eq(*((int*)array[5].key), 5);
  ck_assert_int_eq(*((int*)array[6].key), 6);
  ck_assert_int_eq(*((int*)array[7].key), 7);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 9);

  free(array);
}
END_TEST

START_TEST(test_insertion_sort_dll_1)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;

  int k1, k2, k3, k4, k5, k6;
  int start = 0;
  int end = 5;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 1);

  ck_assert_int_eq(*((int*)(*head)->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 6);

  free(node1);
  free(node2);
  free(node3);
  free(node4);
  free(node5);
  free(node6);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_2)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;

  int k1 = 5;
  int start = 0;
  int end = 0;

  head = malloc(sizeof(DoublyLinkedList*));

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 5);
  ck_assert_int_eq(*((int*)node1->data.key), 5);

  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_3)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  DoublyLinkedList* node11;

  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int start = 0;
  int end = 10;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);
  reg.key = &k11;
  node11 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), -200);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -20);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), -10);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -5);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key),
                   15);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 30);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 50);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      75);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      100);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->data.key),
                   200);

  free(node11);
  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_4)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;

  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int start = 0;
  int end = 9;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 6);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      8);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      9);

  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_5)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  int start = 0;
  int end = 9;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 6);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      8);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      9);

  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_6)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  int k1, k2, k3, k4, k5, k6, k7, k8;

  int start = 2;
  int end = 7;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 2;
  k2 = 4;
  k3 = 1;
  k4 = 5;
  k5 = 7;
  k6 = 2;
  k7 = 3;
  k8 = 6;

  *head = NULL;
  reg.key = &k8; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k7; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k6;
  node3 = dll_insert(head, reg);
  reg.key = &k5;
  node4 = dll_insert(head, reg);
  reg.key = &k4;
  node5 = dll_insert(head, reg);
  reg.key = &k3;
  node6 = dll_insert(head, reg);
  reg.key = &k2;
  node7 = dll_insert(head, reg);
  reg.key = &k1;
  node8 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 6);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 7);

  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_7)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  int k1, k2, k3, k4, k5, k6, k7, k8;

  int start = 0;
  int end = 5;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 2;
  k2 = 4;
  k3 = 5;
  k4 = 1;
  k5 = 2;
  k6 = 3;
  k7 = 7;
  k8 = 6;

  *head = NULL;
  reg.key = &k8; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k7; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k6;
  node3 = dll_insert(head, reg);
  reg.key = &k5;
  node4 = dll_insert(head, reg);
  reg.key = &k4;
  node5 = dll_insert(head, reg);
  reg.key = &k3;
  node6 = dll_insert(head, reg);
  reg.key = &k2;
  node7 = dll_insert(head, reg);
  reg.key = &k1;
  node8 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 6);

  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_8)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  int k1, k2, k3, k4, k5, k6, k7, k8;

  int start = 2;
  int end = 5;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 2;
  k2 = 4;
  k3 = 1;
  k4 = 5;
  k5 = 2;
  k6 = 3;
  k7 = 7;
  k8 = 6;

  *head = NULL;
  reg.key = &k8; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k7; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k6;
  node3 = dll_insert(head, reg);
  reg.key = &k5;
  node4 = dll_insert(head, reg);
  reg.key = &k4;
  node5 = dll_insert(head, reg);
  reg.key = &k3;
  node6 = dll_insert(head, reg);
  reg.key = &k2;
  node7 = dll_insert(head, reg);
  reg.key = &k1;
  node8 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 6);

  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_9)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  DoublyLinkedList* node11;
  DoublyLinkedList* node12;
  DoublyLinkedList* node13;
  DoublyLinkedList* node14;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;

  int start = 0;
  int end = 13;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 0;
  k2 = 2;
  k3 = 3;
  k4 = 4;
  k5 = 55;
  k6 = 300;
  k7 = 700;
  k8 = -200;
  k9 = -100;
  k10 = -80;
  k11 = -7;
  k12 = 30;
  k13 = 150;
  k14 = 570;

  *head = NULL;
  reg.key = &k14; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k13; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k12;
  node3 = dll_insert(head, reg);
  reg.key = &k11;
  node4 = dll_insert(head, reg);
  reg.key = &k10;
  node5 = dll_insert(head, reg);
  reg.key = &k9;
  node6 = dll_insert(head, reg);
  reg.key = &k8;
  node7 = dll_insert(head, reg);
  reg.key = &k7;
  node8 = dll_insert(head, reg);
  reg.key = &k6;
  node9 = dll_insert(head, reg);
  reg.key = &k5;
  node10 = dll_insert(head, reg);
  reg.key = &k4;
  node11 = dll_insert(head, reg);
  reg.key = &k3;
  node12 = dll_insert(head, reg);
  reg.key = &k2;
  node13 = dll_insert(head, reg);
  reg.key = &k1;
  node14 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), -200);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -100);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), -80);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -7);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 2);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 3);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 4);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      30);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      55);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->data.key),
                   150);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->data.key),
                   300);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->next->data.key),
                   570);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->next->next->data.key),
                   700);

  free(node14);
  free(node13);
  free(node12);
  free(node11);
  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_10)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  DoublyLinkedList* node11;
  DoublyLinkedList* node12;
  DoublyLinkedList* node13;
  DoublyLinkedList* node14;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;

  int start = 2;
  int end = 11;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 0;
  k2 = 2;
  k3 = 3;
  k4 = 4;
  k5 = 55;
  k6 = 300;
  k7 = 700;
  k8 = -200;
  k9 = -100;
  k10 = -80;
  k11 = -7;
  k12 = 30;
  k13 = 150;
  k14 = 570;

  *head = NULL;
  reg.key = &k14; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k13; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k12;
  node3 = dll_insert(head, reg);
  reg.key = &k11;
  node4 = dll_insert(head, reg);
  reg.key = &k10;
  node5 = dll_insert(head, reg);
  reg.key = &k9;
  node6 = dll_insert(head, reg);
  reg.key = &k8;
  node7 = dll_insert(head, reg);
  reg.key = &k7;
  node8 = dll_insert(head, reg);
  reg.key = &k6;
  node9 = dll_insert(head, reg);
  reg.key = &k5;
  node10 = dll_insert(head, reg);
  reg.key = &k4;
  node11 = dll_insert(head, reg);
  reg.key = &k3;
  node12 = dll_insert(head, reg);
  reg.key = &k2;
  node13 = dll_insert(head, reg);
  reg.key = &k1;
  node14 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), -200);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -100);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), -80);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key),
                   -7);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 3);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 4);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      30);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      55);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->data.key),
                   300);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->data.key),
                   700);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->next->data.key),
                   150);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->next->next->data.key),
                   570);

  free(node14);
  free(node13);
  free(node12);
  free(node11);
  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_11)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  DoublyLinkedList* node11;
  DoublyLinkedList* node12;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12;

  int start = 0;
  int end = 11;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 3;
  k2 = 15;
  k3 = 20;
  k4 = 30;
  k5 = 50;
  k6 = 75;
  k7 = -75;
  k8 = -50;
  k9 = -30;
  k10 = -20;
  k11 = -15;
  k12 = -3;

  *head = NULL;
  reg.key = &k12; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k11; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k10;
  node3 = dll_insert(head, reg);
  reg.key = &k9;
  node4 = dll_insert(head, reg);
  reg.key = &k8;
  node5 = dll_insert(head, reg);
  reg.key = &k7;
  node6 = dll_insert(head, reg);
  reg.key = &k6;
  node7 = dll_insert(head, reg);
  reg.key = &k5;
  node8 = dll_insert(head, reg);
  reg.key = &k4;
  node9 = dll_insert(head, reg);
  reg.key = &k3;
  node10 = dll_insert(head, reg);
  reg.key = &k2;
  node11 = dll_insert(head, reg);
  reg.key = &k1;
  node12 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), -75);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -50);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), -30);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -20);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), -15);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key),
                   -3);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 3);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 15);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      20);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      30);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->data.key),
                   50);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->next->data.key),
                   75);

  free(node12);
  free(node11);
  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_12)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  int k1, k2, k3, k4, k5, k6;

  int start = 0;
  int end = 5;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 5;
  k2 = 2;
  k3 = 4;
  k4 = 6;
  k5 = 1;
  k6 = 3;

  *head = NULL;
  reg.key = &k6; /* we put in reverse order */
  node1 = dll_insert(head, reg);
  reg.key = &k5; /* because the dll pushes nodes */
  node2 = dll_insert(head, reg);
  reg.key = &k4;
  node3 = dll_insert(head, reg);
  reg.key = &k3;
  node4 = dll_insert(head, reg);
  reg.key = &k2;
  node5 = dll_insert(head, reg);
  reg.key = &k1;
  node6 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 5);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 6);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_13)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  int k1;
  int start = 0;
  int end = 0;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 5;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 5);

  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_14)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  DoublyLinkedList* node11;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;

  int start = 0;
  int end = 10;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = -10;
  k2 = 15;
  k3 = -5;
  k4 = -20;
  k5 = 50;
  k6 = 0;
  k7 = 100;
  k8 = 75;
  k9 = 30;
  k10 = 200;
  k11 = -200;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);
  reg.key = &k11;
  node11 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), -200);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), -20);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), -10);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), -5);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key),
                   15);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 30);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 50);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      75);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      100);
  ck_assert_int_eq(*((int*)(*head)
                         ->next->next->next->next->next->next->next->next->next
                         ->next->data.key),
                   200);

  free(node11);
  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_15)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  int start = 0;
  int end = 9;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 0;
  k2 = 1;
  k3 = 2;
  k4 = 3;
  k5 = 4;
  k6 = 5;
  k7 = 6;
  k8 = 7;
  k9 = 8;
  k10 = 9;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_int);

  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 6);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      8);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      9);

  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_insertion_sort_dll_16)
{
  Register reg;
  DoublyLinkedList** head;
  DoublyLinkedList* node1;
  DoublyLinkedList* node2;
  DoublyLinkedList* node3;
  DoublyLinkedList* node4;
  DoublyLinkedList* node5;
  DoublyLinkedList* node6;
  DoublyLinkedList* node7;
  DoublyLinkedList* node8;
  DoublyLinkedList* node9;
  DoublyLinkedList* node10;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  int start = 0;
  int end = 9;

  head = malloc(sizeof(DoublyLinkedList*));

  k1 = 9;
  k2 = 8;
  k3 = 7;
  k4 = 6;
  k5 = 5;
  k6 = 4;
  k7 = 3;
  k8 = 2;
  k9 = 1;
  k10 = 0;

  *head = NULL;
  reg.key = &k1;
  node1 = dll_insert(head, reg);
  reg.key = &k2;
  node2 = dll_insert(head, reg);
  reg.key = &k3;
  node3 = dll_insert(head, reg);
  reg.key = &k4;
  node4 = dll_insert(head, reg);
  reg.key = &k5;
  node5 = dll_insert(head, reg);
  reg.key = &k6;
  node6 = dll_insert(head, reg);
  reg.key = &k7;
  node7 = dll_insert(head, reg);
  reg.key = &k8;
  node8 = dll_insert(head, reg);
  reg.key = &k9;
  node9 = dll_insert(head, reg);
  reg.key = &k10;
  node10 = dll_insert(head, reg);

  insertion_sort_dll(head, start, end, compare_float);

  ck_assert_int_eq(*((int*)(*head)->data.key), 0);
  ck_assert_int_eq(*((int*)(*head)->next->data.key), 1);
  ck_assert_int_eq(*((int*)(*head)->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->data.key), 3);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*head)->next->next->next->next->next->data.key), 5);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->data.key), 6);
  ck_assert_int_eq(
      *((int*)(*head)->next->next->next->next->next->next->next->data.key), 7);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->data.key),
      8);
  ck_assert_int_eq(
      *((int*)(*head)
            ->next->next->next->next->next->next->next->next->next->data.key),
      9);

  free(node10);
  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
  free(head);
}
END_TEST

START_TEST(test_bucket_sort_1)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6;
  int length = 6;

  k1 = 0.5;
  k2 = 0.2;
  k3 = 0.4;
  k4 = 0.6;
  k5 = 0.1;
  k6 = 0.3;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0.1);
  ck_assert_float_eq(*((float*)array[1].key), 0.2);
  ck_assert_float_eq(*((float*)array[2].key), 0.3);
  ck_assert_float_eq(*((float*)array[3].key), 0.4);
  ck_assert_float_eq(*((float*)array[4].key), 0.5);
  ck_assert_float_eq(*((float*)array[5].key), 0.6);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_2)
{
  Register* array;
  float k1;
  int length = 1;

  k1 = 0.5;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0.5);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_3)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;

  k1 = 0.01;
  k2 = 0.015;
  k3 = 0.005;
  k4 = 0.02;
  k5 = 0.05;
  k6 = 0;
  k7 = 0.1;
  k8 = 0.075;
  k9 = 0.03;
  k10 = 0.2;
  k11 = 0.002;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0);
  ck_assert_float_eq(*((float*)array[1].key), 0.002);
  ck_assert_float_eq(*((float*)array[2].key), 0.005);
  ck_assert_float_eq(*((float*)array[3].key), 0.01);
  ck_assert_float_eq(*((float*)array[4].key), 0.015);
  ck_assert_float_eq(*((float*)array[5].key), 0.02);
  ck_assert_float_eq(*((float*)array[6].key), 0.03);
  ck_assert_float_eq(*((float*)array[7].key), 0.05);
  ck_assert_float_eq(*((float*)array[8].key), 0.075);
  ck_assert_float_eq(*((float*)array[9].key), 0.1);
  ck_assert_float_eq(*((float*)array[10].key), 0.2);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_4)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  k1 = 0;
  k2 = 0.1;
  k3 = 0.2;
  k4 = 0.3;
  k5 = 0.4;
  k6 = 0.5;
  k7 = 0.6;
  k8 = 0.7;
  k9 = 0.8;
  k10 = 0.9;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0);
  ck_assert_float_eq(*((float*)array[1].key), 0.1);
  ck_assert_float_eq(*((float*)array[2].key), 0.2);
  ck_assert_float_eq(*((float*)array[3].key), 0.3);
  ck_assert_float_eq(*((float*)array[4].key), 0.4);
  ck_assert_float_eq(*((float*)array[5].key), 0.5);
  ck_assert_float_eq(*((float*)array[6].key), 0.6);
  ck_assert_float_eq(*((float*)array[7].key), 0.7);
  ck_assert_float_eq(*((float*)array[8].key), 0.8);
  ck_assert_float_eq(*((float*)array[9].key), 0.9);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_5)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  k1 = 0.9;
  k2 = 0.8;
  k3 = 0.7;
  k4 = 0.6;
  k5 = 0.5;
  k6 = 0.4;
  k7 = 0.3;
  k8 = 0.2;
  k9 = 0.1;
  k10 = 0;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0);
  ck_assert_float_eq(*((float*)array[1].key), 0.1);
  ck_assert_float_eq(*((float*)array[2].key), 0.2);
  ck_assert_float_eq(*((float*)array[3].key), 0.3);
  ck_assert_float_eq(*((float*)array[4].key), 0.4);
  ck_assert_float_eq(*((float*)array[5].key), 0.5);
  ck_assert_float_eq(*((float*)array[6].key), 0.6);
  ck_assert_float_eq(*((float*)array[7].key), 0.7);
  ck_assert_float_eq(*((float*)array[8].key), 0.8);
  ck_assert_float_eq(*((float*)array[9].key), 0.9);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_6)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8;
  int length = 6;

  k1 = 0.02;
  k2 = 0.04;
  k3 = 0.05;
  k4 = 0.01;
  k5 = 0.02;
  k6 = 0.03;
  k7 = 0.7;
  k8 = 0.6;

  array = malloc((length + 2) * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0.01);
  ck_assert_float_eq(*((float*)array[1].key), 0.02);
  ck_assert_float_eq(*((float*)array[2].key), 0.02);
  ck_assert_float_eq(*((float*)array[3].key), 0.03);
  ck_assert_float_eq(*((float*)array[4].key), 0.04);
  ck_assert_float_eq(*((float*)array[5].key), 0.05);
  ck_assert_float_eq(*((float*)array[6].key), 0.7);
  ck_assert_float_eq(*((float*)array[7].key), 0.6);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_7)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14;
  int length = 14;

  k1 = 0;
  k2 = 0.004;
  k3 = 0.002;
  k4 = 0.055;
  k5 = 0.3;
  k6 = 0.003;
  k7 = 0.7;
  k8 = 0.2;
  k9 = 0.1;
  k10 = 0.08;
  k11 = 0.007;
  k12 = 0.03;
  k13 = 0.15;
  k14 = 0.57;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;
  array[12].key = &k13;
  array[13].key = &k14;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0);
  ck_assert_float_eq(*((float*)array[1].key), 0.002);
  ck_assert_float_eq(*((float*)array[2].key), 0.003);
  ck_assert_float_eq(*((float*)array[3].key), 0.004);
  ck_assert_float_eq(*((float*)array[4].key), 0.007);
  ck_assert_float_eq(*((float*)array[5].key), 0.03);
  ck_assert_float_eq(*((float*)array[6].key), 0.055);
  ck_assert_float_eq(*((float*)array[7].key), 0.08);
  ck_assert_float_eq(*((float*)array[8].key), 0.1);
  ck_assert_float_eq(*((float*)array[9].key), 0.15);
  ck_assert_float_eq(*((float*)array[10].key), 0.2);
  ck_assert_float_eq(*((float*)array[11].key), 0.3);
  ck_assert_float_eq(*((float*)array[12].key), 0.57);
  ck_assert_float_eq(*((float*)array[13].key), 0.7);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_8)
{
  Register* array;
  float k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12;
  int length = 12;

  k1 = 0.003;
  k2 = 0.015;
  k3 = 0.02;
  k4 = 0.03;
  k5 = 0.05;
  k6 = 0.075;
  k7 = 0.75;
  k8 = 0.5;
  k9 = 0.3;
  k10 = 0.2;
  k11 = 0.15;
  k12 = 0.01;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;
  array[11].key = &k12;

  bucket_sort(array, length, mul_plus_floor_float, compare_float);

  ck_assert_float_eq(*((float*)array[0].key), 0.003);
  ck_assert_float_eq(*((float*)array[1].key), 0.01);
  ck_assert_float_eq(*((float*)array[2].key), 0.015);
  ck_assert_float_eq(*((float*)array[3].key), 0.02);
  ck_assert_float_eq(*((float*)array[4].key), 0.03);
  ck_assert_float_eq(*((float*)array[5].key), 0.05);
  ck_assert_float_eq(*((float*)array[6].key), 0.075);
  ck_assert_float_eq(*((float*)array[7].key), 0.15);
  ck_assert_float_eq(*((float*)array[8].key), 0.2);
  ck_assert_float_eq(*((float*)array[9].key), 0.3);
  ck_assert_float_eq(*((float*)array[10].key), 0.5);
  ck_assert_float_eq(*((float*)array[11].key), 0.75);

  free(array);
}

START_TEST(test_bucket_sort_9)
{
  Register* array;
  double k1, k2, k3, k4, k5, k6;
  int length = 6;

  k1 = 0.5;
  k2 = 0.2;
  k3 = 0.4;
  k4 = 0.6;
  k5 = 0.1;
  k6 = 0.3;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;

  bucket_sort(array, length, mul_plus_floor_double, compare_double);

  ck_assert_double_eq(*((double*)array[0].key), 0.1);
  ck_assert_double_eq(*((double*)array[1].key), 0.2);
  ck_assert_double_eq(*((double*)array[2].key), 0.3);
  ck_assert_double_eq(*((double*)array[3].key), 0.4);
  ck_assert_double_eq(*((double*)array[4].key), 0.5);
  ck_assert_double_eq(*((double*)array[5].key), 0.6);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_10)
{
  Register* array;
  double k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  int length = 11;

  k1 = 0.01;
  k2 = 0.015;
  k3 = 0.005;
  k4 = 0.02;
  k5 = 0.05;
  k6 = 0;
  k7 = 0.1;
  k8 = 0.075;
  k9 = 0.03;
  k10 = 0.2;
  k11 = 0.122;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;
  array[10].key = &k11;

  bucket_sort(array, length, mul_plus_floor_double, compare_double);

  ck_assert_double_eq(*((double*)array[0].key), 0);
  ck_assert_double_eq(*((double*)array[1].key), 0.005);
  ck_assert_double_eq(*((double*)array[2].key), 0.01);
  ck_assert_double_eq(*((double*)array[3].key), 0.015);
  ck_assert_double_eq(*((double*)array[4].key), 0.02);
  ck_assert_double_eq(*((double*)array[5].key), 0.03);
  ck_assert_double_eq(*((double*)array[6].key), 0.05);
  ck_assert_double_eq(*((double*)array[7].key), 0.075);
  ck_assert_double_eq(*((double*)array[8].key), 0.1);
  ck_assert_double_eq(*((double*)array[9].key), 0.122);
  ck_assert_double_eq(*((double*)array[10].key), 0.2);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_11)
{
  Register* array;
  double k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  k1 = 0;
  k2 = 0.001;
  k3 = 0.002;
  k4 = 0.003;
  k5 = 0.004;
  k6 = 0.005;
  k7 = 0.006;
  k8 = 0.007;
  k9 = 0.008;
  k10 = 0.9;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  bucket_sort(array, length, mul_plus_floor_double, compare_double);

  ck_assert_double_eq(*((double*)array[0].key), 0);
  ck_assert_double_eq(*((double*)array[1].key), 0.001);
  ck_assert_double_eq(*((double*)array[2].key), 0.002);
  ck_assert_double_eq(*((double*)array[3].key), 0.003);
  ck_assert_double_eq(*((double*)array[4].key), 0.004);
  ck_assert_double_eq(*((double*)array[5].key), 0.005);
  ck_assert_double_eq(*((double*)array[6].key), 0.006);
  ck_assert_double_eq(*((double*)array[7].key), 0.007);
  ck_assert_double_eq(*((double*)array[8].key), 0.008);
  ck_assert_double_eq(*((double*)array[9].key), 0.9);

  free(array);
}
END_TEST

START_TEST(test_bucket_sort_12)
{
  Register* array;
  double k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int length = 10;

  k1 = 0.9;
  k2 = 0.8;
  k3 = 0.7;
  k4 = 0.6;
  k5 = 0.5;
  k6 = 0.4;
  k7 = 0.3;
  k8 = 0.2;
  k9 = 0.1;
  k10 = 0;

  array = malloc(length * sizeof(Register));

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;
  array[9].key = &k10;

  bucket_sort(array, length, mul_plus_floor_double, compare_double);

  ck_assert_double_eq(*((double*)array[0].key), 0);
  ck_assert_double_eq(*((double*)array[1].key), 0.1);
  ck_assert_double_eq(*((double*)array[2].key), 0.2);
  ck_assert_double_eq(*((double*)array[3].key), 0.3);
  ck_assert_double_eq(*((double*)array[4].key), 0.4);
  ck_assert_double_eq(*((double*)array[5].key), 0.5);
  ck_assert_double_eq(*((double*)array[6].key), 0.6);
  ck_assert_double_eq(*((double*)array[7].key), 0.7);
  ck_assert_double_eq(*((double*)array[8].key), 0.8);
  ck_assert_double_eq(*((double*)array[9].key), 0.9);

  free(array);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

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

  tcase_add_test(tc_core, test_radix_sort_1);
  tcase_add_test(tc_core, test_radix_sort_2);
  tcase_add_test(tc_core, test_radix_sort_3);
  tcase_add_test(tc_core, test_radix_sort_4);
  tcase_add_test(tc_core, test_radix_sort_5);
  tcase_add_test(tc_core, test_radix_sort_6);
  tcase_add_test(tc_core, test_radix_sort_7);
  tcase_add_test(tc_core, test_radix_sort_8);
  tcase_add_test(tc_core, test_radix_sort_9);
  tcase_add_test(tc_core, test_radix_sort_10);
  tcase_add_test(tc_core, test_radix_sort_11);
  tcase_add_test(tc_core, test_radix_sort_12);

  tcase_add_test(tc_core, test_insertion_sort_gnrc_1);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_2);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_3);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_4);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_5);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_6);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_7);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_8);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_9);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_10);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_11);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_12);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_13);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_14);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_15);
  tcase_add_test(tc_core, test_insertion_sort_gnrc_16);

  tcase_add_test(tc_core, test_insertion_sort_dll_1);
  tcase_add_test(tc_core, test_insertion_sort_dll_2);
  tcase_add_test(tc_core, test_insertion_sort_dll_3);
  tcase_add_test(tc_core, test_insertion_sort_dll_4);
  tcase_add_test(tc_core, test_insertion_sort_dll_5);
  tcase_add_test(tc_core, test_insertion_sort_dll_6);
  tcase_add_test(tc_core, test_insertion_sort_dll_7);
  tcase_add_test(tc_core, test_insertion_sort_dll_8);
  tcase_add_test(tc_core, test_insertion_sort_dll_9);
  tcase_add_test(tc_core, test_insertion_sort_dll_10);
  tcase_add_test(tc_core, test_insertion_sort_dll_11);
  tcase_add_test(tc_core, test_insertion_sort_dll_12);
  tcase_add_test(tc_core, test_insertion_sort_dll_13);
  tcase_add_test(tc_core, test_insertion_sort_dll_14);
  tcase_add_test(tc_core, test_insertion_sort_dll_15);
  tcase_add_test(tc_core, test_insertion_sort_dll_16);

  tcase_add_test(tc_core, test_bucket_sort_1);
  tcase_add_test(tc_core, test_bucket_sort_2);
  tcase_add_test(tc_core, test_bucket_sort_3);
  tcase_add_test(tc_core, test_bucket_sort_4);
  tcase_add_test(tc_core, test_bucket_sort_5);
  tcase_add_test(tc_core, test_bucket_sort_6);
  tcase_add_test(tc_core, test_bucket_sort_7);
  tcase_add_test(tc_core, test_bucket_sort_8);
  tcase_add_test(tc_core, test_bucket_sort_9);
  tcase_add_test(tc_core, test_bucket_sort_10);
  tcase_add_test(tc_core, test_bucket_sort_11);
  tcase_add_test(tc_core, test_bucket_sort_12);

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
