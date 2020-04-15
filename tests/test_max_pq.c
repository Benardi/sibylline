#include <check.h>
#include <malloc.h>
#include <max_pq.h>
#include <stdint.h>
#include <stdlib.h>

void setup(void);
void teardown(void);
Suite* make_test_suite(void);
int compare_int(void* key1, void* key2);

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

void setup(void)
{
}

void teardown(void)
{
}

START_TEST(test_heap_increase_key_1)
{
  bool result;
  int i, key;
  Register* array;
  int length = 9;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;

  i = 5;
  key = 40;

  array = malloc(length * sizeof(Register));

  k1 = 50;
  k2 = 30;
  k3 = 35;
  k4 = 13;
  k5 = 26;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)array[0].key), 50);
  ck_assert_int_eq(*((int*)array[1].key), 30);
  ck_assert_int_eq(*((int*)array[2].key), 40);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 26);
  ck_assert_int_eq(*((int*)array[5].key), 35);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_2)
{
  bool result;
  int i, key;
  Register* array;
  int length = 10;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  i = 8;
  key = 15;

  array = malloc(length * sizeof(Register));

  k1 = 16;
  k2 = 14;
  k3 = 10;
  k4 = 8;
  k5 = 7;
  k6 = 9;
  k7 = 3;
  k8 = 2;
  k9 = 4;
  k10 = 1;

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

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)array[0].key), 16);
  ck_assert_int_eq(*((int*)array[1].key), 15);
  ck_assert_int_eq(*((int*)array[2].key), 10);
  ck_assert_int_eq(*((int*)array[3].key), 14);
  ck_assert_int_eq(*((int*)array[4].key), 7);
  ck_assert_int_eq(*((int*)array[5].key), 9);
  ck_assert_int_eq(*((int*)array[6].key), 3);
  ck_assert_int_eq(*((int*)array[7].key), 2);
  ck_assert_int_eq(*((int*)array[8].key), 8);
  ck_assert_int_eq(*((int*)array[9].key), 1);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_3)
{
  bool result;
  int i, key;
  Register* array;
  int length = 15;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;

  i = 8;
  key = 100;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)array[0].key), 100);
  ck_assert_int_eq(*((int*)array[1].key), 70);
  ck_assert_int_eq(*((int*)array[2].key), 65);
  ck_assert_int_eq(*((int*)array[3].key), 63);
  ck_assert_int_eq(*((int*)array[4].key), 57);
  ck_assert_int_eq(*((int*)array[5].key), 53);
  ck_assert_int_eq(*((int*)array[6].key), 51);
  ck_assert_int_eq(*((int*)array[7].key), 30);
  ck_assert_int_eq(*((int*)array[8].key), 50);
  ck_assert_int_eq(*((int*)array[9].key), 18);
  ck_assert_int_eq(*((int*)array[10].key), 24);
  ck_assert_int_eq(*((int*)array[11].key), 13);
  ck_assert_int_eq(*((int*)array[12].key), 36);
  ck_assert_int_eq(*((int*)array[13].key), 8);
  ck_assert_int_eq(*((int*)array[14].key), 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_4)
{
  bool result;
  int i, key;
  Register* array;
  int length = 10;
  int k1, k2, k3, k4, k5, k6, k7;

  i = 2;
  key = 30;

  array = malloc(length * sizeof(Register));

  k1 = 33;
  k2 = 29;
  k3 = 27;
  k4 = 15;
  k5 = 10;
  k6 = -5;
  k7 = -7;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)array[0].key), 33);
  ck_assert_int_eq(*((int*)array[1].key), 29);
  ck_assert_int_eq(*((int*)array[2].key), 30);
  ck_assert_int_eq(*((int*)array[3].key), 15);
  ck_assert_int_eq(*((int*)array[4].key), 10);
  ck_assert_int_eq(*((int*)array[5].key), -5);
  ck_assert_int_eq(*((int*)array[6].key), -7);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_5)
{
  bool result;
  int i, key;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7;
  int length = 7;

  i = 2;
  key = 0;

  array = malloc(length * sizeof(Register));

  k1 = 33;
  k2 = 29;
  k3 = 27;
  k4 = 15;
  k5 = 10;
  k6 = -5;
  k7 = -7;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)array[0].key), 33);
  ck_assert_int_eq(*((int*)array[1].key), 29);
  ck_assert_int_eq(*((int*)array[2].key), 27);
  ck_assert_int_eq(*((int*)array[3].key), 15);
  ck_assert_int_eq(*((int*)array[4].key), 10);
  ck_assert_int_eq(*((int*)array[5].key), -5);
  ck_assert_int_eq(*((int*)array[6].key), -7);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_6)
{
  bool result;
  int i, key;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 0;
  key = 100;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*((int*)array[0].key), 100);
  ck_assert_int_eq(*((int*)array[1].key), 63);
  ck_assert_int_eq(*((int*)array[2].key), 65);
  ck_assert_int_eq(*((int*)array[3].key), 50);
  ck_assert_int_eq(*((int*)array[4].key), 57);
  ck_assert_int_eq(*((int*)array[5].key), 53);
  ck_assert_int_eq(*((int*)array[6].key), 51);
  ck_assert_int_eq(*((int*)array[7].key), 30);
  ck_assert_int_eq(*((int*)array[8].key), 42);
  ck_assert_int_eq(*((int*)array[9].key), 18);
  ck_assert_int_eq(*((int*)array[10].key), 24);
  ck_assert_int_eq(*((int*)array[11].key), 13);
  ck_assert_int_eq(*((int*)array[12].key), 36);
  ck_assert_int_eq(*((int*)array[13].key), 8);
  ck_assert_int_eq(*((int*)array[14].key), 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_7)
{
  bool result;
  int i, key;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 0;
  key = 68;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)array[0].key), 70);
  ck_assert_int_eq(*((int*)array[1].key), 63);
  ck_assert_int_eq(*((int*)array[2].key), 65);
  ck_assert_int_eq(*((int*)array[3].key), 50);
  ck_assert_int_eq(*((int*)array[4].key), 57);
  ck_assert_int_eq(*((int*)array[5].key), 53);
  ck_assert_int_eq(*((int*)array[6].key), 51);
  ck_assert_int_eq(*((int*)array[7].key), 30);
  ck_assert_int_eq(*((int*)array[8].key), 42);
  ck_assert_int_eq(*((int*)array[9].key), 18);
  ck_assert_int_eq(*((int*)array[10].key), 24);
  ck_assert_int_eq(*((int*)array[11].key), 13);
  ck_assert_int_eq(*((int*)array[12].key), 36);
  ck_assert_int_eq(*((int*)array[13].key), 8);
  ck_assert_int_eq(*((int*)array[14].key), 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_8)
{
  bool result;
  int i, key;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 3;
  key = 49;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)array[0].key), 70);
  ck_assert_int_eq(*((int*)array[1].key), 63);
  ck_assert_int_eq(*((int*)array[2].key), 65);
  ck_assert_int_eq(*((int*)array[3].key), 50);
  ck_assert_int_eq(*((int*)array[4].key), 57);
  ck_assert_int_eq(*((int*)array[5].key), 53);
  ck_assert_int_eq(*((int*)array[6].key), 51);
  ck_assert_int_eq(*((int*)array[7].key), 30);
  ck_assert_int_eq(*((int*)array[8].key), 42);
  ck_assert_int_eq(*((int*)array[9].key), 18);
  ck_assert_int_eq(*((int*)array[10].key), 24);
  ck_assert_int_eq(*((int*)array[11].key), 13);
  ck_assert_int_eq(*((int*)array[12].key), 36);
  ck_assert_int_eq(*((int*)array[13].key), 8);
  ck_assert_int_eq(*((int*)array[14].key), 26);

  free(array);
}
END_TEST

START_TEST(test_heap_increase_key_9)
{
  bool result;
  int i, key;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  i = 9;
  key = 0;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  result = heap_increase_key(array, i, &key, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*((int*)array[0].key), 70);
  ck_assert_int_eq(*((int*)array[1].key), 63);
  ck_assert_int_eq(*((int*)array[2].key), 65);
  ck_assert_int_eq(*((int*)array[3].key), 50);
  ck_assert_int_eq(*((int*)array[4].key), 57);
  ck_assert_int_eq(*((int*)array[5].key), 53);
  ck_assert_int_eq(*((int*)array[6].key), 51);
  ck_assert_int_eq(*((int*)array[7].key), 30);
  ck_assert_int_eq(*((int*)array[8].key), 42);
  ck_assert_int_eq(*((int*)array[9].key), 18);
  ck_assert_int_eq(*((int*)array[10].key), 24);
  ck_assert_int_eq(*((int*)array[11].key), 13);
  ck_assert_int_eq(*((int*)array[12].key), 36);
  ck_assert_int_eq(*((int*)array[13].key), 8);
  ck_assert_int_eq(*((int*)array[14].key), 26);

  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_1)
{
  int key;
  int* heap_size;
  Register* array;
  int k1, k2, k3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 0;
  k2 = 0;
  k3 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;

  (*heap_size) = 0;

  key = 15;
  max_heap_insert(array, &key, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(*((int*)array[0].key), 15);
  ck_assert_int_eq(*((int*)array[1].key), 0);
  ck_assert_int_eq(*((int*)array[2].key), 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_2)
{
  int key1, key2;
  int* heap_size;
  Register* array;
  int k1, k2, k3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 0;
  k2 = 0;
  k3 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;

  (*heap_size) = 0;

  key1 = 15;
  max_heap_insert(array, &key1, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(*((int*)array[0].key), 15);
  ck_assert_int_eq(*((int*)array[1].key), 0);
  ck_assert_int_eq(*((int*)array[2].key), 0);

  key2 = 7;
  max_heap_insert(array, &key2, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 2);
  ck_assert_int_eq(*((int*)array[0].key), 15);
  ck_assert_int_eq(*((int*)array[1].key), 7);
  ck_assert_int_eq(*((int*)array[2].key), 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_3)
{
  int* heap_size;
  Register* array;
  int k1, k2, k3;
  int key1, key2, key3;
  int length = 3;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 0;
  k2 = 0;
  k3 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;

  (*heap_size) = 0;

  key1 = 15;
  max_heap_insert(array, &key1, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 1);
  ck_assert_int_eq(*((int*)array[0].key), 15);
  ck_assert_int_eq(*((int*)array[1].key), 0);
  ck_assert_int_eq(*((int*)array[2].key), 0);

  key2 = 7;
  max_heap_insert(array, &key2, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 2);
  ck_assert_int_eq(*((int*)array[0].key), 15);
  ck_assert_int_eq(*((int*)array[1].key), 7);
  ck_assert_int_eq(*((int*)array[2].key), 0);

  key3 = 30;
  max_heap_insert(array, &key3, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 3);
  ck_assert_int_eq(*((int*)array[0].key), 30);
  ck_assert_int_eq(*((int*)array[1].key), 7);
  ck_assert_int_eq(*((int*)array[2].key), 15);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_4)
{
  int* heap_size;
  Register* array;
  int k1, k2, k3, k4, k5;
  int key1, key2, key3, key4, key5;
  int length = 5;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 0;
  k2 = 0;
  k3 = 0;
  k4 = 0;
  k5 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;

  (*heap_size) = 0;

  key1 = 1;
  max_heap_insert(array, &key1, heap_size, compare_int);
  key2 = 2;
  max_heap_insert(array, &key2, heap_size, compare_int);
  key3 = 3;
  max_heap_insert(array, &key3, heap_size, compare_int);
  key4 = 5;
  max_heap_insert(array, &key4, heap_size, compare_int);
  key5 = 6;
  max_heap_insert(array, &key5, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 5);
  ck_assert_int_eq(*((int*)array[0].key), 6);
  ck_assert_int_eq(*((int*)array[1].key), 5);
  ck_assert_int_eq(*((int*)array[2].key), 2);
  ck_assert_int_eq(*((int*)array[3].key), 1);
  ck_assert_int_eq(*((int*)array[4].key), 3);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_max_heap_insert_5)
{
  int key;
  int* heap_size;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 56;
  k2 = 28;
  k3 = 43;
  k4 = 16;
  k5 = 21;
  k6 = 12;
  k7 = 8;
  k8 = 0;
  k9 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 7;

  key = 25;
  max_heap_insert(array, &key, heap_size, compare_int);

  ck_assert_int_eq((*heap_size), 8);
  ck_assert_int_eq(*((int*)array[0].key), 56);
  ck_assert_int_eq(*((int*)array[1].key), 28);
  ck_assert_int_eq(*((int*)array[2].key), 43);
  ck_assert_int_eq(*((int*)array[3].key), 25);
  ck_assert_int_eq(*((int*)array[4].key), 21);
  ck_assert_int_eq(*((int*)array[5].key), 12);
  ck_assert_int_eq(*((int*)array[6].key), 8);
  ck_assert_int_eq(*((int*)array[7].key), 16);
  ck_assert_int_eq(*((int*)array[8].key), 0);

  free(heap_size);
  free(array);
}
END_TEST

START_TEST(test_heap_maximum_1)
{
  Register maximum;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));

  k1 = 50;
  k2 = 30;
  k3 = 35;
  k4 = 13;
  k5 = 26;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  maximum = heap_maximum(array);

  ck_assert_int_eq(*((int*)maximum.key), 50);

  free(array);
}
END_TEST

START_TEST(test_heap_maximum_2)
{
  Register maximum;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));

  k1 = 56;
  k2 = 28;
  k3 = 43;
  k4 = 16;
  k5 = 21;
  k6 = 12;
  k7 = 8;
  k8 = 0;
  k9 = 0;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  maximum = heap_maximum(array);

  ck_assert_int_eq(*((int*)maximum.key), 56);

  free(array);
}
END_TEST

START_TEST(test_heap_maximum_3)
{
  Register maximum;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  array = malloc(length * sizeof(Register));

  k1 = 70;
  k2 = 63;
  k3 = 65;
  k4 = 50;
  k5 = 57;
  k6 = 53;
  k7 = 51;
  k8 = 30;
  k9 = 42;
  k10 = 18;
  k11 = 24;
  k12 = 13;
  k13 = 36;
  k14 = 8;
  k15 = 26;

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
  array[14].key = &k15;

  maximum = heap_maximum(array);

  ck_assert_int_eq(*((int*)maximum.key), 70);

  free(array);
}
END_TEST

START_TEST(test_heap_extract_max_1)
{
  bool result;
  int* heap_size;
  Register* extracted;
  Register* array;
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 50;
  k2 = 30;
  k3 = 35;
  k4 = 13;
  k5 = 26;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 0;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(*((int*)array[0].key), 50);
  ck_assert_int_eq(*((int*)array[1].key), 30);
  ck_assert_int_eq(*((int*)array[2].key), 35);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 26);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1;

  array = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1 = 34;

  array[0].key = &k1;

  (*heap_size) = 1;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(*((int*)extracted->key), 34);

  ck_assert_int_eq(*((int*)array[0].key), 34);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 50;
  k2 = 30;
  k3 = 35;
  k4 = 13;
  k5 = 26;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 7;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 6);
  ck_assert_int_eq(*((int*)extracted->key), 50);

  ck_assert_int_eq(*((int*)array[0].key), 35);
  ck_assert_int_eq(*((int*)array[1].key), 30);
  ck_assert_int_eq(*((int*)array[2].key), 22);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 26);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 35;
  k2 = 30;
  k3 = 22;
  k4 = 13;
  k5 = 26;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 6;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 5);
  ck_assert_int_eq(*((int*)extracted->key), 35);

  ck_assert_int_eq(*((int*)array[0].key), 30);
  ck_assert_int_eq(*((int*)array[1].key), 26);
  ck_assert_int_eq(*((int*)array[2].key), 22);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 30;
  k2 = 26;
  k3 = 22;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 5;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 4);
  ck_assert_int_eq(*((int*)extracted->key), 30);

  ck_assert_int_eq(*((int*)array[0].key), 26);
  ck_assert_int_eq(*((int*)array[1].key), 20);
  ck_assert_int_eq(*((int*)array[2].key), 22);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1 = 26;
  k2 = 20;
  k3 = 22;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 4;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 3);
  ck_assert_int_eq(*((int*)extracted->key), 26);

  ck_assert_int_eq(*((int*)array[0].key), 22);
  ck_assert_int_eq(*((int*)array[1].key), 20);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 22;
  k2 = 20;
  k3 = 13;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 3;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 2);
  ck_assert_int_eq(*((int*)extracted->key), 22);

  ck_assert_int_eq(*((int*)array[0].key), 20);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  heap_size = malloc(sizeof(int));
  extracted = malloc(sizeof(Register));

  k1 = 20;
  k2 = 13;
  k3 = 13;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 2;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 1);
  ck_assert_int_eq(*((int*)extracted->key), 20);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(*((int*)extracted->key), 13);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 13;
  k2 = 13;
  k3 = 13;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 1;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(*heap_size, 0);
  ck_assert_int_eq(*((int*)extracted->key), 13);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
  int length = 9;

  array = malloc(length * sizeof(Register));
  extracted = malloc(sizeof(Register));
  heap_size = malloc(sizeof(int));

  k1 = 13;
  k2 = 13;
  k3 = 13;
  k4 = 13;
  k5 = 20;
  k6 = 20;
  k7 = 22;
  k8 = -10;
  k9 = 1000;

  array[0].key = &k1;
  array[1].key = &k2;
  array[2].key = &k3;
  array[3].key = &k4;
  array[4].key = &k5;
  array[5].key = &k6;
  array[6].key = &k7;
  array[7].key = &k8;
  array[8].key = &k9;

  (*heap_size) = 0;

  result = heap_extract_max(array, heap_size, extracted, compare_int);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(*heap_size, 0);

  ck_assert_int_eq(*((int*)array[0].key), 13);
  ck_assert_int_eq(*((int*)array[1].key), 13);
  ck_assert_int_eq(*((int*)array[2].key), 13);
  ck_assert_int_eq(*((int*)array[3].key), 13);
  ck_assert_int_eq(*((int*)array[4].key), 20);
  ck_assert_int_eq(*((int*)array[5].key), 20);
  ck_assert_int_eq(*((int*)array[6].key), 22);
  ck_assert_int_eq(*((int*)array[7].key), -10);
  ck_assert_int_eq(*((int*)array[8].key), 1000);

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

  tcase_add_checked_fixture(tc_core, setup, teardown);

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
