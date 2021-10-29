#include <check.h>
#include <malloc.h>
#include <max_pq.h>
#include <stdint.h>
#include <stdlib.h>

Suite* make_test_suite(void);

static int compare_int(union Key k1, union Key k2)
{
  int result;

  if (k1.i > k2.i)
    {
      result = 1;
    }
  else if (k1.i < k2.i)
    {
      result = -1;
    }
  else
    {
      result = 0;
    }
  return result;
}

START_TEST(test_heap_increase_key_1)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  int length = 9;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;

  i = 5;
  key.i = 40;

  array = malloc(length * sizeof(Register));

  k1.i = 50;
  k2.i = 30;
  k3.i = 35;
  k4.i = 13;
  k5.i = 26;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(array[0].key.i, 50);
  ck_assert_int_eq(array[1].key.i, 30);
  ck_assert_int_eq(array[2].key.i, 40);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 26);
  ck_assert_int_eq(array[5].key.i, 35);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_2)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  int length = 10;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  i = 8;
  key.i = 15;

  array = malloc(length * sizeof(Register));

  k1.i = 16;
  k2.i = 14;
  k3.i = 10;
  k4.i = 8;
  k5.i = 7;
  k6.i = 9;
  k7.i = 3;
  k8.i = 2;
  k9.i = 4;
  k10.i = 1;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(array[0].key.i, 16);
  ck_assert_int_eq(array[1].key.i, 15);
  ck_assert_int_eq(array[2].key.i, 10);
  ck_assert_int_eq(array[3].key.i, 14);
  ck_assert_int_eq(array[4].key.i, 7);
  ck_assert_int_eq(array[5].key.i, 9);
  ck_assert_int_eq(array[6].key.i, 3);
  ck_assert_int_eq(array[7].key.i, 2);
  ck_assert_int_eq(array[8].key.i, 8);
  ck_assert_int_eq(array[9].key.i, 1);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_3)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  int length = 15;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;

  i = 8;
  key.i = 100;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(array[0].key.i, 100);
  ck_assert_int_eq(array[1].key.i, 70);
  ck_assert_int_eq(array[2].key.i, 65);
  ck_assert_int_eq(array[3].key.i, 63);
  ck_assert_int_eq(array[4].key.i, 57);
  ck_assert_int_eq(array[5].key.i, 53);
  ck_assert_int_eq(array[6].key.i, 51);
  ck_assert_int_eq(array[7].key.i, 30);
  ck_assert_int_eq(array[8].key.i, 50);
  ck_assert_int_eq(array[9].key.i, 18);
  ck_assert_int_eq(array[10].key.i, 24);
  ck_assert_int_eq(array[11].key.i, 13);
  ck_assert_int_eq(array[12].key.i, 36);
  ck_assert_int_eq(array[13].key.i, 8);
  ck_assert_int_eq(array[14].key.i, 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_4)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  int length = 10;
  union Key k1, k2, k3, k4, k5, k6, k7;

  i = 2;
  key.i = 30;

  array = malloc(length * sizeof(Register));

  k1.i = 33;
  k2.i = 29;
  k3.i = 27;
  k4.i = 15;
  k5.i = 10;
  k6.i = -5;
  k7.i = -7;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(array[0].key.i, 33);
  ck_assert_int_eq(array[1].key.i, 29);
  ck_assert_int_eq(array[2].key.i, 30);
  ck_assert_int_eq(array[3].key.i, 15);
  ck_assert_int_eq(array[4].key.i, 10);
  ck_assert_int_eq(array[5].key.i, -5);
  ck_assert_int_eq(array[6].key.i, -7);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_5)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int length = 7;

  i = 2;
  key.i = 0;

  array = malloc(length * sizeof(Register));

  k1.i = 33;
  k2.i = 29;
  k3.i = 27;
  k4.i = 15;
  k5.i = 10;
  k6.i = -5;
  k7.i = -7;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(array[0].key.i, 33);
  ck_assert_int_eq(array[1].key.i, 29);
  ck_assert_int_eq(array[2].key.i, 27);
  ck_assert_int_eq(array[3].key.i, 15);
  ck_assert_int_eq(array[4].key.i, 10);
  ck_assert_int_eq(array[5].key.i, -5);
  ck_assert_int_eq(array[6].key.i, -7);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_6)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 0;
  key.i = 100;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(array[0].key.i, 100);
  ck_assert_int_eq(array[1].key.i, 63);
  ck_assert_int_eq(array[2].key.i, 65);
  ck_assert_int_eq(array[3].key.i, 50);
  ck_assert_int_eq(array[4].key.i, 57);
  ck_assert_int_eq(array[5].key.i, 53);
  ck_assert_int_eq(array[6].key.i, 51);
  ck_assert_int_eq(array[7].key.i, 30);
  ck_assert_int_eq(array[8].key.i, 42);
  ck_assert_int_eq(array[9].key.i, 18);
  ck_assert_int_eq(array[10].key.i, 24);
  ck_assert_int_eq(array[11].key.i, 13);
  ck_assert_int_eq(array[12].key.i, 36);
  ck_assert_int_eq(array[13].key.i, 8);
  ck_assert_int_eq(array[14].key.i, 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_7)
{
  bool result;
  int i;
  Register* array;
  union Key key, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14,
      k15;
  int length = 15;

  i = 0;
  key.i = 68;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(array[0].key.i, 70);
  ck_assert_int_eq(array[1].key.i, 63);
  ck_assert_int_eq(array[2].key.i, 65);
  ck_assert_int_eq(array[3].key.i, 50);
  ck_assert_int_eq(array[4].key.i, 57);
  ck_assert_int_eq(array[5].key.i, 53);
  ck_assert_int_eq(array[6].key.i, 51);
  ck_assert_int_eq(array[7].key.i, 30);
  ck_assert_int_eq(array[8].key.i, 42);
  ck_assert_int_eq(array[9].key.i, 18);
  ck_assert_int_eq(array[10].key.i, 24);
  ck_assert_int_eq(array[11].key.i, 13);
  ck_assert_int_eq(array[12].key.i, 36);
  ck_assert_int_eq(array[13].key.i, 8);
  ck_assert_int_eq(array[14].key.i, 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_8)
{
  bool result;
  int i;
  Register* array;
  union Key key, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14,
      k15;
  int length = 15;

  i = 3;
  key.i = 49;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(array[0].key.i, 70);
  ck_assert_int_eq(array[1].key.i, 63);
  ck_assert_int_eq(array[2].key.i, 65);
  ck_assert_int_eq(array[3].key.i, 50);
  ck_assert_int_eq(array[4].key.i, 57);
  ck_assert_int_eq(array[5].key.i, 53);
  ck_assert_int_eq(array[6].key.i, 51);
  ck_assert_int_eq(array[7].key.i, 30);
  ck_assert_int_eq(array[8].key.i, 42);
  ck_assert_int_eq(array[9].key.i, 18);
  ck_assert_int_eq(array[10].key.i, 24);
  ck_assert_int_eq(array[11].key.i, 13);
  ck_assert_int_eq(array[12].key.i, 36);
  ck_assert_int_eq(array[13].key.i, 8);
  ck_assert_int_eq(array[14].key.i, 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_9)
{
  bool result;
  int i;
  union Key key;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 9;
  key.i = 0;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  result = heap_increase_key(array, i, key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(array[0].key.i, 70);
  ck_assert_int_eq(array[1].key.i, 63);
  ck_assert_int_eq(array[2].key.i, 65);
  ck_assert_int_eq(array[3].key.i, 50);
  ck_assert_int_eq(array[4].key.i, 57);
  ck_assert_int_eq(array[5].key.i, 53);
  ck_assert_int_eq(array[6].key.i, 51);
  ck_assert_int_eq(array[7].key.i, 30);
  ck_assert_int_eq(array[8].key.i, 42);
  ck_assert_int_eq(array[9].key.i, 18);
  ck_assert_int_eq(array[10].key.i, 24);
  ck_assert_int_eq(array[11].key.i, 13);
  ck_assert_int_eq(array[12].key.i, 36);
  ck_assert_int_eq(array[13].key.i, 8);
  ck_assert_int_eq(array[14].key.i, 26);

  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_1)
{
  union Key key;
  int* heap_size;
  Register* array;
  union Key k1, k2, k3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 0;
  k2.i = 0;
  k3.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;

  (*heap_size) = 0;

  key.i = 15;
  max_heap_insert(array, key, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(array[0].key.i, 15);
  ck_assert_int_eq(array[1].key.i, 0);
  ck_assert_int_eq(array[2].key.i, 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_2)
{
  union Key key1, key2;
  int* heap_size;
  Register* array;
  union Key k1, k2, k3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 0;
  k2.i = 0;
  k3.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;

  (*heap_size) = 0;

  key1.i = 15;
  max_heap_insert(array, key1, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(array[0].key.i, 15);
  ck_assert_int_eq(array[1].key.i, 0);
  ck_assert_int_eq(array[2].key.i, 0);

  key2.i = 7;
  max_heap_insert(array, key2, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 2);
  ck_assert_int_eq(array[0].key.i, 15);
  ck_assert_int_eq(array[1].key.i, 7);
  ck_assert_int_eq(array[2].key.i, 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_3)
{
  int* heap_size;
  Register* array;
  union Key k1, k2, k3;
  union Key key1, key2, key3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 0;
  k2.i = 0;
  k3.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;

  (*heap_size) = 0;

  key1.i = 15;
  max_heap_insert(array, key1, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(array[0].key.i, 15);
  ck_assert_int_eq(array[1].key.i, 0);
  ck_assert_int_eq(array[2].key.i, 0);

  key2.i = 7;
  max_heap_insert(array, key2, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 2);
  ck_assert_int_eq(array[0].key.i, 15);
  ck_assert_int_eq(array[1].key.i, 7);
  ck_assert_int_eq(array[2].key.i, 0);

  key3.i = 30;
  max_heap_insert(array, key3, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 3);
  ck_assert_int_eq(array[0].key.i, 30);
  ck_assert_int_eq(array[1].key.i, 7);
  ck_assert_int_eq(array[2].key.i, 15);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_4)
{
  int* heap_size;
  Register* array;
  union Key k1, k2, k3, k4, k5;
  union Key key1, key2, key3, key4, key5;
  int length = 5;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 0;
  k2.i = 0;
  k3.i = 0;
  k4.i = 0;
  k5.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  (*heap_size) = 0;

  key1.i = 1;
  max_heap_insert(array, key1, heap_size, compare_int);
  key2.i = 2;
  max_heap_insert(array, key2, heap_size, compare_int);
  key3.i = 3;
  max_heap_insert(array, key3, heap_size, compare_int);
  key4.i = 5;
  max_heap_insert(array, key4, heap_size, compare_int);
  key5.i = 6;
  max_heap_insert(array, key5, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 5);
  ck_assert_int_eq(array[0].key.i, 6);
  ck_assert_int_eq(array[1].key.i, 5);
  ck_assert_int_eq(array[2].key.i, 2);
  ck_assert_int_eq(array[3].key.i, 1);
  ck_assert_int_eq(array[4].key.i, 3);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_5)
{
  union Key key;
  int* heap_size;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 56;
  k2.i = 28;
  k3.i = 43;
  k4.i = 16;
  k5.i = 21;
  k6.i = 12;
  k7.i = 8;
  k8.i = 0;
  k9.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 7;

  key.i = 25;
  max_heap_insert(array, key, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 8);
  ck_assert_int_eq(array[0].key.i, 56);
  ck_assert_int_eq(array[1].key.i, 28);
  ck_assert_int_eq(array[2].key.i, 43);
  ck_assert_int_eq(array[3].key.i, 25);
  ck_assert_int_eq(array[4].key.i, 21);
  ck_assert_int_eq(array[5].key.i, 12);
  ck_assert_int_eq(array[6].key.i, 8);
  ck_assert_int_eq(array[7].key.i, 16);
  ck_assert_int_eq(array[8].key.i, 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_heap_maximum_1)
{
  Register maximum;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));

  k1.i = 50;
  k2.i = 30;
  k3.i = 35;
  k4.i = 13;
  k5.i = 26;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  maximum = heap_maximum(array);

  ck_assert_int_eq(maximum.key.i, 50);

  free(array);
}
END_TEST

START_TEST(test_heap_maximum_2)
{
  Register maximum;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));

  k1.i = 56;
  k2.i = 28;
  k3.i = 43;
  k4.i = 16;
  k5.i = 21;
  k6.i = 12;
  k7.i = 8;
  k8.i = 0;
  k9.i = 0;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  maximum = heap_maximum(array);

  ck_assert_int_eq(maximum.key.i, 56);

  free(array);
}
END_TEST

START_TEST(test_heap_maximum_3)
{
  Register maximum;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  array = malloc(length * sizeof(Register));

  k1.i = 70;
  k2.i = 63;
  k3.i = 65;
  k4.i = 50;
  k5.i = 57;
  k6.i = 53;
  k7.i = 51;
  k8.i = 30;
  k9.i = 42;
  k10.i = 18;
  k11.i = 24;
  k12.i = 13;
  k13.i = 36;
  k14.i = 8;
  k15.i = 26;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;
  array[9].key = k10;
  array[10].key = k11;
  array[11].key = k12;
  array[12].key = k13;
  array[13].key = k14;
  array[14].key = k15;

  maximum = heap_maximum(array);

  ck_assert_int_eq(maximum.key.i, 70);

  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_1)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 50;
  k2.i = 30;
  k3.i = 35;
  k4.i = 13;
  k5.i = 26;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 0;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(array[0].key.i, 50);
  ck_assert_int_eq(array[1].key.i, 30);
  ck_assert_int_eq(array[2].key.i, 35);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 26);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_2)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1;

  array = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1.i = 34;

  array[0].key = k1;

  (*heap_size) = 1;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(extracted->key.i, 34);

  ck_assert_int_eq(array[0].key.i, 34);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_3)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 50;
  k2.i = 30;
  k3.i = 35;
  k4.i = 13;
  k5.i = 26;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 7;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 6);
  ck_assert_int_eq(extracted->key.i, 50);

  ck_assert_int_eq(array[0].key.i, 35);
  ck_assert_int_eq(array[1].key.i, 30);
  ck_assert_int_eq(array[2].key.i, 22);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 26);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_4)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 35;
  k2.i = 30;
  k3.i = 22;
  k4.i = 13;
  k5.i = 26;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 6;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 5);
  ck_assert_int_eq(extracted->key.i, 35);

  ck_assert_int_eq(array[0].key.i, 30);
  ck_assert_int_eq(array[1].key.i, 26);
  ck_assert_int_eq(array[2].key.i, 22);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_5)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 30;
  k2.i = 26;
  k3.i = 22;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 5;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 4);
  ck_assert_int_eq(extracted->key.i, 30);

  ck_assert_int_eq(array[0].key.i, 26);
  ck_assert_int_eq(array[1].key.i, 20);
  ck_assert_int_eq(array[2].key.i, 22);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_6)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1.i = 26;
  k2.i = 20;
  k3.i = 22;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 4;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 3);
  ck_assert_int_eq(extracted->key.i, 26);

  ck_assert_int_eq(array[0].key.i, 22);
  ck_assert_int_eq(array[1].key.i, 20);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_7)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 22;
  k2.i = 20;
  k3.i = 13;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 3;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 2);
  ck_assert_int_eq(extracted->key.i, 22);

  ck_assert_int_eq(array[0].key.i, 20);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_8)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1.i = 20;
  k2.i = 13;
  k3.i = 13;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 2;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 1);
  ck_assert_int_eq(extracted->key.i, 20);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(extracted->key.i, 13);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_9)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 13;
  k2.i = 13;
  k3.i = 13;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 1;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(extracted->key.i, 13);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_10)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1.i = 13;
  k2.i = 13;
  k3.i = 13;
  k4.i = 13;
  k5.i = 20;
  k6.i = 20;
  k7.i = 22;
  k8.i = -10;
  k9.i = 1000;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;
  array[7].key = k8;
  array[8].key = k9;

  (*heap_size) = 0;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(array[0].key.i, 13);
  ck_assert_int_eq(array[1].key.i, 13);
  ck_assert_int_eq(array[2].key.i, 13);
  ck_assert_int_eq(array[3].key.i, 13);
  ck_assert_int_eq(array[4].key.i, 20);
  ck_assert_int_eq(array[5].key.i, 20);
  ck_assert_int_eq(array[6].key.i, 22);
  ck_assert_int_eq(array[7].key.i, -10);
  ck_assert_int_eq(array[8].key.i, 1000);

  free(heap_size);
  free(extracted);
  free(array);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Stack Creation Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_test(tc_core, test_heap_increase_key_1);
  tcase_add_test(tc_core, test_heap_increase_key_2);
  tcase_add_test(tc_core, test_heap_increase_key_3);
  tcase_add_test(tc_core, test_heap_increase_key_4);
  tcase_add_test(tc_core, test_heap_increase_key_5);
  tcase_add_test(tc_core, test_heap_increase_key_6);
  tcase_add_test(tc_core, test_heap_increase_key_7);
  tcase_add_test(tc_core, test_heap_increase_key_8);
  tcase_add_test(tc_core, test_heap_increase_key_9);

  tcase_add_test(tc_core, test_max_heap_insert_1);
  tcase_add_test(tc_core, test_max_heap_insert_2);
  tcase_add_test(tc_core, test_max_heap_insert_3);
  tcase_add_test(tc_core, test_max_heap_insert_4);
  tcase_add_test(tc_core, test_max_heap_insert_5);

  tcase_add_test(tc_core, test_heap_maximum_1);
  tcase_add_test(tc_core, test_heap_maximum_2);
  tcase_add_test(tc_core, test_heap_maximum_3);

  tcase_add_test(tc_core, test_heap_extract_max_1);
  tcase_add_test(tc_core, test_heap_extract_max_2);
  tcase_add_test(tc_core, test_heap_extract_max_3);
  tcase_add_test(tc_core, test_heap_extract_max_4);
  tcase_add_test(tc_core, test_heap_extract_max_5);
  tcase_add_test(tc_core, test_heap_extract_max_6);
  tcase_add_test(tc_core, test_heap_extract_max_7);
  tcase_add_test(tc_core, test_heap_extract_max_8);
  tcase_add_test(tc_core, test_heap_extract_max_9);
  tcase_add_test(tc_core, test_heap_extract_max_10);

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
