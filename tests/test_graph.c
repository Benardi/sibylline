#include <check.h>
#include <malloc.h>
#include <dll.h>
#include <graph.h>
#include <stdint.h>
#include <stdlib.h>

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
}

void teardown(void)
{
}

START_TEST(test_build_adj_list_1)
{
  int i, length;
  int u0, u1, u2, u3, u4;
  Register reg;
  DoublyLinkedList*** buckets;
 
  length = 5;
  u0 = 0;
  u1 = 1;
  u2 = 2;
  u3 = 3;
  u4 = 4; 
 
  buckets = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      buckets[i] = malloc(sizeof(DoublyLinkedList*));
      *buckets[i] = NULL;
    }

  reg.key = &u4;
  dll_insert(buckets[0], reg);
  reg.key = &u1;
  dll_insert(buckets[0], reg);

  reg.key = &u3;
  dll_insert(buckets[1], reg);
  reg.key = &u2;
  dll_insert(buckets[1], reg);
  reg.key = &u4;
  dll_insert(buckets[1], reg);
  reg.key = &u0;
  dll_insert(buckets[1], reg);

  reg.key = &u3;
  dll_insert(buckets[2], reg);
  reg.key = &u1;
  dll_insert(buckets[2], reg);

  reg.key = &u2;
  dll_insert(buckets[3], reg);
  reg.key = &u4;
  dll_insert(buckets[3], reg);
  reg.key = &u1;
  dll_insert(buckets[3], reg);

  reg.key = &u1;
  dll_insert(buckets[4], reg);
  reg.key = &u0;
  dll_insert(buckets[4], reg);
  reg.key = &u3;
  dll_insert(buckets[4], reg);

  ck_assert_int_eq(*((int*)(*buckets[0])->data.key), 1);
  ck_assert_int_eq(*((int*)(*buckets[0])->next->data.key), 4);

  ck_assert_int_eq(*((int*)(*buckets[1])->data.key), 0);
  ck_assert_int_eq(*((int*)(*buckets[1])->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*buckets[1])->next->next->data.key), 2);
  ck_assert_int_eq(*((int*)(*buckets[1])->next->next->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*buckets[2])->data.key), 1);
  ck_assert_int_eq(*((int*)(*buckets[2])->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*buckets[3])->data.key), 1);
  ck_assert_int_eq(*((int*)(*buckets[3])->next->data.key), 4);
  ck_assert_int_eq(*((int*)(*buckets[3])->next->next->data.key), 2);

  ck_assert_int_eq(*((int*)(*buckets[4])->data.key), 3);
  ck_assert_int_eq(*((int*)(*buckets[4])->next->data.key), 0);
  ck_assert_int_eq(*((int*)(*buckets[4])->next->next->data.key), 1);

  for (i = 0; i < length; i++)
    {
      dll_free_list(buckets[i]);
      free(buckets[i]);
    }

  free(buckets);
}
END_TEST

START_TEST(test_build_adj_list_2)
{
  int i, length;
  int u1, u3, u4, u5;
  Register reg;
  DoublyLinkedList*** buckets;
 
  length = 6;
  u1 = 1;
  u3 = 3;
  u4 = 4; 
  u5 = 5; 
 
  buckets = malloc(length * sizeof(DoublyLinkedList**));

  for (i = 0; i < length; i++)
    {
      buckets[i] = malloc(sizeof(DoublyLinkedList*));
      *buckets[i] = NULL;
    }

  reg.key = &u3;
  dll_insert(buckets[0], reg);
  reg.key = &u1;
  dll_insert(buckets[0], reg);

  reg.key = &u4;
  dll_insert(buckets[1], reg);
  
  reg.key = &u4;
  dll_insert(buckets[2], reg);
  reg.key = &u5;
  dll_insert(buckets[2], reg);
  
  reg.key = &u1;
  dll_insert(buckets[3], reg);

  reg.key = &u3;
  dll_insert(buckets[4], reg);
  
  reg.key = &u5;
  dll_insert(buckets[5], reg);

  ck_assert_int_eq(*((int*)(*buckets[0])->data.key), 1);
  ck_assert_int_eq(*((int*)(*buckets[0])->next->data.key), 3);

  ck_assert_int_eq(*((int*)(*buckets[1])->data.key), 4);

  ck_assert_int_eq(*((int*)(*buckets[2])->data.key), 5);
  ck_assert_int_eq(*((int*)(*buckets[2])->next->data.key), 4);

  ck_assert_int_eq(*((int*)(*buckets[3])->data.key), 1);

  ck_assert_int_eq(*((int*)(*buckets[4])->data.key), 3);

  ck_assert_int_eq(*((int*)(*buckets[5])->data.key), 5);
  
  for (i = 0; i < length; i++)
    {
      dll_free_list(buckets[i]);
      free(buckets[i]);
    }

  free(buckets);
}
END_TEST


START_TEST(test_build_adj_matrix_1)
{
  int row = 5;
  int col = 5;
  
  int *matrix = malloc(row * col * sizeof(int));
 
  matrix[row * 0 + 0] = 0; 
  matrix[row * 0 + 1] = 1; 
  matrix[row * 0 + 2] = 0; 
  matrix[row * 0 + 3] = 0; 
  matrix[row * 0 + 4] = 1; 

  matrix[row * 1 + 0] = 1; 
  matrix[row * 1 + 1] = 0; 
  matrix[row * 1 + 2] = 1; 
  matrix[row * 1 + 3] = 1; 
  matrix[row * 1 + 4] = 1; 
  
  matrix[row * 2 + 0] = 0; 
  matrix[row * 2 + 1] = 1; 
  matrix[row * 2 + 2] = 0; 
  matrix[row * 2 + 3] = 1; 
  matrix[row * 2 + 4] = 0; 

  matrix[row * 3 + 0] = 0; 
  matrix[row * 3 + 1] = 1; 
  matrix[row * 3 + 2] = 1; 
  matrix[row * 3 + 3] = 0; 
  matrix[row * 3 + 4] = 1; 

  matrix[row * 4 + 0] = 1; 
  matrix[row * 4 + 1] = 1; 
  matrix[row * 4 + 2] = 0; 
  matrix[row * 4 + 3] = 1; 
  matrix[row * 4 + 4] = 0; 

  ck_assert_int_eq(matrix[row * 0 + 0], 0); 
  ck_assert_int_eq(matrix[row * 0 + 1], 1); 
  ck_assert_int_eq(matrix[row * 0 + 2], 0); 
  ck_assert_int_eq(matrix[row * 0 + 3], 0); 
  ck_assert_int_eq(matrix[row * 0 + 4], 1); 

  ck_assert_int_eq(matrix[row * 1 + 0], 1); 
  ck_assert_int_eq(matrix[row * 1 + 1], 0); 
  ck_assert_int_eq(matrix[row * 1 + 2], 1); 
  ck_assert_int_eq(matrix[row * 1 + 3], 1); 
  ck_assert_int_eq(matrix[row * 1 + 4], 1); 
  
  ck_assert_int_eq(matrix[row * 2 + 0], 0); 
  ck_assert_int_eq(matrix[row * 2 + 1], 1); 
  ck_assert_int_eq(matrix[row * 2 + 2], 0); 
  ck_assert_int_eq(matrix[row * 2 + 3], 1); 
  ck_assert_int_eq(matrix[row * 2 + 4], 0); 

  ck_assert_int_eq(matrix[row * 3 + 0], 0); 
  ck_assert_int_eq(matrix[row * 3 + 1], 1); 
  ck_assert_int_eq(matrix[row * 3 + 2], 1); 
  ck_assert_int_eq(matrix[row * 3 + 3], 0); 
  ck_assert_int_eq(matrix[row * 3 + 4], 1); 

  ck_assert_int_eq(matrix[row * 4 + 0], 1); 
  ck_assert_int_eq(matrix[row * 4 + 1], 1); 
  ck_assert_int_eq(matrix[row * 4 + 2], 0); 
  ck_assert_int_eq(matrix[row * 4 + 3], 1); 
  ck_assert_int_eq(matrix[row * 4 + 4], 0); 
  
  free(matrix);
}
END_TEST


START_TEST(test_build_adj_matrix_2)
{
  int row = 6;
  int col = 6;
  
  int *matrix = malloc(row * col * sizeof(int));
 
  matrix[row * 0 + 0] = 0; 
  matrix[row * 0 + 1] = 1; 
  matrix[row * 0 + 2] = 0; 
  matrix[row * 0 + 3] = 1; 
  matrix[row * 0 + 4] = 0; 
  matrix[row * 0 + 5] = 0; 

  matrix[row * 1 + 0] = 0; 
  matrix[row * 1 + 1] = 0; 
  matrix[row * 1 + 2] = 0; 
  matrix[row * 1 + 3] = 0; 
  matrix[row * 1 + 4] = 1; 
  matrix[row * 1 + 5] = 0; 
  
  matrix[row * 2 + 0] = 0; 
  matrix[row * 2 + 1] = 0; 
  matrix[row * 2 + 2] = 0; 
  matrix[row * 2 + 3] = 0; 
  matrix[row * 2 + 4] = 1; 
  matrix[row * 2 + 5] = 1; 

  matrix[row * 3 + 0] = 0; 
  matrix[row * 3 + 1] = 1; 
  matrix[row * 3 + 2] = 0; 
  matrix[row * 3 + 3] = 0; 
  matrix[row * 3 + 4] = 0; 
  matrix[row * 3 + 5] = 0; 

  matrix[row * 4 + 0] = 0; 
  matrix[row * 4 + 1] = 0; 
  matrix[row * 4 + 2] = 0; 
  matrix[row * 4 + 3] = 1; 
  matrix[row * 4 + 4] = 0; 
  matrix[row * 4 + 5] = 0; 
  
  matrix[row * 5 + 0] = 0; 
  matrix[row * 5 + 1] = 0; 
  matrix[row * 5 + 2] = 0; 
  matrix[row * 5 + 3] = 0; 
  matrix[row * 5 + 4] = 0; 
  matrix[row * 5 + 5] = 1; 

  ck_assert_int_eq(matrix[row * 0 + 0], 0); 
  ck_assert_int_eq(matrix[row * 0 + 1], 1); 
  ck_assert_int_eq(matrix[row * 0 + 2], 0); 
  ck_assert_int_eq(matrix[row * 0 + 3], 1); 
  ck_assert_int_eq(matrix[row * 0 + 4], 0); 
  ck_assert_int_eq(matrix[row * 0 + 5], 0); 
                                         
  ck_assert_int_eq(matrix[row * 1 + 0], 0); 
  ck_assert_int_eq(matrix[row * 1 + 1], 0); 
  ck_assert_int_eq(matrix[row * 1 + 2], 0); 
  ck_assert_int_eq(matrix[row * 1 + 3], 0); 
  ck_assert_int_eq(matrix[row * 1 + 4], 1); 
  ck_assert_int_eq(matrix[row * 1 + 5], 0); 
                                         
  ck_assert_int_eq(matrix[row * 2 + 0], 0); 
  ck_assert_int_eq(matrix[row * 2 + 1], 0); 
  ck_assert_int_eq(matrix[row * 2 + 2], 0); 
  ck_assert_int_eq(matrix[row * 2 + 3], 0); 
  ck_assert_int_eq(matrix[row * 2 + 4], 1); 
  ck_assert_int_eq(matrix[row * 2 + 5], 1); 
                                         
  ck_assert_int_eq(matrix[row * 3 + 0], 0); 
  ck_assert_int_eq(matrix[row * 3 + 1], 1); 
  ck_assert_int_eq(matrix[row * 3 + 2], 0); 
  ck_assert_int_eq(matrix[row * 3 + 3], 0); 
  ck_assert_int_eq(matrix[row * 3 + 4], 0); 
  ck_assert_int_eq(matrix[row * 3 + 5], 0); 
                                         
  ck_assert_int_eq(matrix[row * 4 + 0], 0); 
  ck_assert_int_eq(matrix[row * 4 + 1], 0); 
  ck_assert_int_eq(matrix[row * 4 + 2], 0); 
  ck_assert_int_eq(matrix[row * 4 + 3], 1); 
  ck_assert_int_eq(matrix[row * 4 + 4], 0); 
  ck_assert_int_eq(matrix[row * 4 + 5], 0); 
                                         
  ck_assert_int_eq(matrix[row * 5 + 0], 0); 
  ck_assert_int_eq(matrix[row * 5 + 1], 0); 
  ck_assert_int_eq(matrix[row * 5 + 2], 0); 
  ck_assert_int_eq(matrix[row * 5 + 3], 0); 
  ck_assert_int_eq(matrix[row * 5 + 4], 0); 
  ck_assert_int_eq(matrix[row * 5 + 5], 1); 
  
  free(matrix);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Graph Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_build_adj_list_1);
  tcase_add_test(tc_core, test_build_adj_list_2);
  
  tcase_add_test(tc_core, test_build_adj_matrix_1);
  tcase_add_test(tc_core, test_build_adj_matrix_2);

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
