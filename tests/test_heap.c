#include <check.h>
#include <heap.h>
#include <malloc.h>
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

START_TEST(test_max_heapify_1)
{
  Register* array;
  union Key k1, k2, k3, k4, k5;
  int heap_size, i;
  int length = 5;

  array = malloc(length * sizeof(Register));

  k1.i = 10;
  k2.i = 5;
  k3.i = 7;
  k4.i = -9;
  k5.i = 200;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  heap_size = 3;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 10);
  ck_assert_int_eq(array[1].key.i, 5);
  ck_assert_int_eq(array[2].key.i, 7);
  ck_assert_int_eq(array[3].key.i, -9);
  ck_assert_int_eq(array[4].key.i, 200);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_2)
{
  Register* array;
  union Key k1, k2, k3, k4, k5;
  int heap_size, i;
  int length = 5;

  array = malloc(length * sizeof(Register));

  k1.i = 10;
  k2.i = 5;
  k3.i = 7;
  k4.i = -9;
  k5.i = 200;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  heap_size = 3;
  i = 1; /* left child */

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 10);
  ck_assert_int_eq(array[1].key.i, 5);
  ck_assert_int_eq(array[2].key.i, 7);
  ck_assert_int_eq(array[3].key.i, -9);
  ck_assert_int_eq(array[4].key.i, 200);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_3)
{
  Register* array;
  union Key k1, k2, k3, k4, k5;
  int heap_size, i;
  int length = 5;

  array = malloc(length * sizeof(Register));

  k1.i = 10;
  k2.i = 5;
  k3.i = 7;
  k4.i = -9;
  k5.i = 200;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  heap_size = 3;
  i = 2; /* right child */

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 10);
  ck_assert_int_eq(array[1].key.i, 5);
  ck_assert_int_eq(array[2].key.i, 7);
  ck_assert_int_eq(array[3].key.i, -9);
  ck_assert_int_eq(array[4].key.i, 200);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_4)
{
  Register* array;
  union Key k1, k2, k3, k4, k5;
  int heap_size, i;
  int length = 5;

  array = malloc(length * sizeof(Register));

  heap_size = 3;
  i = 0;

  k1.i = 3;
  k2.i = 10;
  k3.i = 8;
  k4.i = 90;
  k5.i = -1500;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 10);
  ck_assert_int_eq(array[1].key.i, 3);
  ck_assert_int_eq(array[2].key.i, 8);
  ck_assert_int_eq(array[3].key.i, 90);
  ck_assert_int_eq(array[4].key.i, -1500);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_5)
{
  Register* array;
  union Key k1, k2, k3, k4, k5;
  int heap_size, i;
  int length = 5;

  array = malloc(length * sizeof(Register));

  k1.i = 3;
  k2.i = 8;
  k3.i = 10;
  k4.i = 90;
  k5.i = -1500;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;

  heap_size = 3;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 10);
  ck_assert_int_eq(array[1].key.i, 8);
  ck_assert_int_eq(array[2].key.i, 3);
  ck_assert_int_eq(array[3].key.i, 90);
  ck_assert_int_eq(array[4].key.i, -1500);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_6)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int heap_size, i;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 3;
  k2.i = 9;
  k3.i = 8;
  k4.i = 7;
  k5.i = 6;
  k6.i = 4;
  k7.i = 5;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  heap_size = 7;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 9);
  ck_assert_int_eq(array[1].key.i, 7);
  ck_assert_int_eq(array[2].key.i, 8);
  ck_assert_int_eq(array[3].key.i, 3);
  ck_assert_int_eq(array[4].key.i, 6);
  ck_assert_int_eq(array[5].key.i, 4);
  ck_assert_int_eq(array[6].key.i, 5);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_7)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int heap_size, i;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 3;
  k2.i = 9;
  k3.i = 8;
  k4.i = 6;
  k5.i = 7;
  k6.i = 4;
  k7.i = 5;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  heap_size = 7;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 9);
  ck_assert_int_eq(array[1].key.i, 7);
  ck_assert_int_eq(array[2].key.i, 8);
  ck_assert_int_eq(array[3].key.i, 6);
  ck_assert_int_eq(array[4].key.i, 3);
  ck_assert_int_eq(array[5].key.i, 4);
  ck_assert_int_eq(array[6].key.i, 5);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_8)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int heap_size, i;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 3;
  k2.i = 8;
  k3.i = 9;
  k4.i = 6;
  k5.i = 7;
  k6.i = 5;
  k7.i = 4;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  heap_size = 7;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 9);
  ck_assert_int_eq(array[1].key.i, 8);
  ck_assert_int_eq(array[2].key.i, 5);
  ck_assert_int_eq(array[3].key.i, 6);
  ck_assert_int_eq(array[4].key.i, 7);
  ck_assert_int_eq(array[5].key.i, 3);
  ck_assert_int_eq(array[6].key.i, 4);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_9)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int heap_size, i;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 3;
  k2.i = 8;
  k3.i = 9;
  k4.i = 6;
  k5.i = 7;
  k6.i = 4;
  k7.i = 5;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  heap_size = 7;
  i = 0;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 9);
  ck_assert_int_eq(array[1].key.i, 8);
  ck_assert_int_eq(array[2].key.i, 5);
  ck_assert_int_eq(array[3].key.i, 6);
  ck_assert_int_eq(array[4].key.i, 7);
  ck_assert_int_eq(array[5].key.i, 4);
  ck_assert_int_eq(array[6].key.i, 3);

  free(array);
}
END_TEST

START_TEST(test_max_heapify_10)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
  int heap_size, i;
  int length = 10;

  array = malloc(length * sizeof(Register));

  k1.i = 16;
  k2.i = 4;
  k3.i = 10;
  k4.i = 14;
  k5.i = 7;
  k6.i = 9;
  k7.i = 3;
  k8.i = 2;
  k9.i = 8;
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

  heap_size = 10;
  i = 1;

  max_heapify(array, heap_size, i, compare_int);

  ck_assert_int_eq(array[0].key.i, 16);
  ck_assert_int_eq(array[1].key.i, 14);
  ck_assert_int_eq(array[2].key.i, 10);
  ck_assert_int_eq(array[3].key.i, 8);
  ck_assert_int_eq(array[4].key.i, 7);
  ck_assert_int_eq(array[5].key.i, 9);
  ck_assert_int_eq(array[6].key.i, 3);
  ck_assert_int_eq(array[7].key.i, 2);
  ck_assert_int_eq(array[8].key.i, 4);
  ck_assert_int_eq(array[9].key.i, 1);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_1)
{
  Register* array;
  union Key k1;
  int length = 1;

  array = malloc(length * sizeof(Register));

  k1.i = 4;

  array[0].key = k1;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 4);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_2)
{
  Register* array;
  union Key k1, k2;
  int length = 2;

  array = malloc(length * sizeof(Register));

  k1.i = 4;
  k2.i = 8;

  array[0].key = k1;
  array[1].key = k2;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 8);
  ck_assert_int_eq(array[1].key.i, 4);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_3)
{
  Register* array;
  union Key k1, k2, k3;
  int length = 3;

  array = malloc(length * sizeof(Register));

  k1.i = 4;
  k2.i = 8;
  k3.i = 12;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 12);
  ck_assert_int_eq(array[1].key.i, 8);
  ck_assert_int_eq(array[2].key.i, 4);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_4)
{
  Register* array;
  union Key k1, k2, k3;
  int length = 2;

  array = malloc((length + 1) * sizeof(Register));

  k1.i = 4;
  k2.i = 8;
  k3.i = 12;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 8);
  ck_assert_int_eq(array[1].key.i, 4);
  ck_assert_int_eq(array[2].key.i, 12);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_5)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 1;
  k2.i = 2;
  k3.i = 3;
  k4.i = 4;
  k5.i = 5;
  k6.i = 6;
  k7.i = 7;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 7);
  ck_assert_int_eq(array[1].key.i, 5);
  ck_assert_int_eq(array[2].key.i, 6);
  ck_assert_int_eq(array[3].key.i, 4);
  ck_assert_int_eq(array[4].key.i, 2);
  ck_assert_int_eq(array[5].key.i, 1);
  ck_assert_int_eq(array[6].key.i, 3);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_6)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7;
  int length = 7;

  array = malloc(length * sizeof(Register));

  k1.i = 7;
  k2.i = 6;
  k3.i = 5;
  k4.i = 4;
  k5.i = 3;
  k6.i = 2;
  k7.i = 1;

  array[0].key = k1;
  array[1].key = k2;
  array[2].key = k3;
  array[3].key = k4;
  array[4].key = k5;
  array[5].key = k6;
  array[6].key = k7;

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 7);
  ck_assert_int_eq(array[1].key.i, 6);
  ck_assert_int_eq(array[2].key.i, 5);
  ck_assert_int_eq(array[3].key.i, 4);
  ck_assert_int_eq(array[4].key.i, 3);
  ck_assert_int_eq(array[5].key.i, 2);
  ck_assert_int_eq(array[6].key.i, 1);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_7)
{
  Register* array;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15;
  int length = 15;

  array = malloc(length * sizeof(Register));

  k1.i = 34;
  k2.i = -46;
  k3.i = 20;
  k4.i = 24;
  k5.i = 31;
  k6.i = 54;
  k7.i = 79;
  k8.i = -70;
  k9.i = -23;
  k10.i = 95;
  k11.i = -75;
  k12.i = 28;
  k13.i = -82;
  k14.i = -34;
  k15.i = -51;

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

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 95);
  ck_assert_int_eq(array[1].key.i, 34);
  ck_assert_int_eq(array[2].key.i, 79);
  ck_assert_int_eq(array[3].key.i, 24);
  ck_assert_int_eq(array[4].key.i, 31);
  ck_assert_int_eq(array[5].key.i, 54);
  ck_assert_int_eq(array[6].key.i, 20);
  ck_assert_int_eq(array[7].key.i, -70);
  ck_assert_int_eq(array[8].key.i, -23);
  ck_assert_int_eq(array[9].key.i, -46);
  ck_assert_int_eq(array[10].key.i, -75);
  ck_assert_int_eq(array[11].key.i, 28);
  ck_assert_int_eq(array[12].key.i, -82);
  ck_assert_int_eq(array[13].key.i, -34);
  ck_assert_int_eq(array[14].key.i, -51);

  free(array);
}
END_TEST

START_TEST(test_build_max_heap_8)
{
  Register* array;
  int length = 10;
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

  array = malloc(length * sizeof(Register));

  k1.i = 4;
  k2.i = 1;
  k3.i = 3;
  k4.i = 2;
  k5.i = 16;
  k6.i = 9;
  k7.i = 10;
  k8.i = 14;
  k9.i = 8;
  k10.i = 7;

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

  build_max_heap(array, length, compare_int);

  ck_assert_int_eq(array[0].key.i, 16);
  ck_assert_int_eq(array[1].key.i, 14);
  ck_assert_int_eq(array[2].key.i, 10);
  ck_assert_int_eq(array[3].key.i, 8);
  ck_assert_int_eq(array[4].key.i, 7);
  ck_assert_int_eq(array[5].key.i, 9);
  ck_assert_int_eq(array[6].key.i, 3);
  ck_assert_int_eq(array[7].key.i, 2);
  ck_assert_int_eq(array[8].key.i, 4);
  ck_assert_int_eq(array[9].key.i, 1);

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

  tcase_add_test(tc_core, test_build_max_heap_1);
  tcase_add_test(tc_core, test_build_max_heap_2);
  tcase_add_test(tc_core, test_build_max_heap_3);
  tcase_add_test(tc_core, test_build_max_heap_4);
  tcase_add_test(tc_core, test_build_max_heap_5);
  tcase_add_test(tc_core, test_build_max_heap_6);
  tcase_add_test(tc_core, test_build_max_heap_7);
  tcase_add_test(tc_core, test_build_max_heap_8);

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
