#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <max_pq.h>

void setup(void);
void teardown(void);
Suite *make_test_suite(void);

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
    int array[] = {50, 30, 35, 13, 26, 20, 22, -10, 1000};
    
    i = 5;
    key = 40;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(array[0], 50);
    ck_assert_int_eq(array[1], 30);
    ck_assert_int_eq(array[2], 40);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 26);
    ck_assert_int_eq(array[5], 35);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);
}
END_TEST 

START_TEST(test_heap_increase_key_2)
{
    bool result;
    int i, key;
    int array[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    
    i = 8;
    key = 15;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(array[0], 16);
    ck_assert_int_eq(array[1], 15);
    ck_assert_int_eq(array[2], 10);
    ck_assert_int_eq(array[3], 14);
    ck_assert_int_eq(array[4], 7);
    ck_assert_int_eq(array[5], 9);
    ck_assert_int_eq(array[6], 3);
    ck_assert_int_eq(array[7], 2);
    ck_assert_int_eq(array[8], 8);
    ck_assert_int_eq(array[9], 1);
}
END_TEST 

START_TEST(test_heap_increase_key_3)
{
    bool result;
    int i, key;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    i = 8;
    key = 100;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(array[0], 100);
    ck_assert_int_eq(array[1], 70);
    ck_assert_int_eq(array[2], 65);
    ck_assert_int_eq(array[3], 63);
    ck_assert_int_eq(array[4], 57);
    ck_assert_int_eq(array[5], 53);
    ck_assert_int_eq(array[6], 51);
    ck_assert_int_eq(array[7], 30);
    ck_assert_int_eq(array[8], 50);
    ck_assert_int_eq(array[9], 18);
    ck_assert_int_eq(array[10], 24);
    ck_assert_int_eq(array[11], 13);
    ck_assert_int_eq(array[12], 36);
    ck_assert_int_eq(array[13], 8);
    ck_assert_int_eq(array[14], 26);
}
END_TEST 

START_TEST(test_heap_increase_key_4)
{
    bool result;
    int i, key;
    int array[] = {33, 29, 27, 15, 10, -5, -7};
    
    i = 2;
    key = 30;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(array[0], 33);
    ck_assert_int_eq(array[1], 29);
    ck_assert_int_eq(array[2], 30);
    ck_assert_int_eq(array[3], 15);
    ck_assert_int_eq(array[4], 10);
    ck_assert_int_eq(array[5], -5);
    ck_assert_int_eq(array[6], -7);
}
END_TEST 

START_TEST(test_heap_increase_key_5)
{
    bool result;
    int i, key;
    int array[] = {33, 29, 27, 15, 10, -5, -7};
    
    i = 2;
    key = 0;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(array[0], 33);
    ck_assert_int_eq(array[1], 29);
    ck_assert_int_eq(array[2], 27);
    ck_assert_int_eq(array[3], 15);
    ck_assert_int_eq(array[4], 10);
    ck_assert_int_eq(array[5], -5);
    ck_assert_int_eq(array[6], -7);
}
END_TEST 

START_TEST(test_heap_increase_key_6)
{
    bool result;
    int i, key;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    i = 0;
    key = 100;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(array[0], 100);
    ck_assert_int_eq(array[1], 63);
    ck_assert_int_eq(array[2], 65);
    ck_assert_int_eq(array[3], 50);
    ck_assert_int_eq(array[4], 57);
    ck_assert_int_eq(array[5], 53);
    ck_assert_int_eq(array[6], 51);
    ck_assert_int_eq(array[7], 30);
    ck_assert_int_eq(array[8], 42);
    ck_assert_int_eq(array[9], 18);
    ck_assert_int_eq(array[10], 24);
    ck_assert_int_eq(array[11], 13);
    ck_assert_int_eq(array[12], 36);
    ck_assert_int_eq(array[13], 8);
    ck_assert_int_eq(array[14], 26);
}
END_TEST 

START_TEST(test_heap_increase_key_7)
{
    bool result;
    int i, key;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    i = 0;
    key = 68;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(array[0], 70);
    ck_assert_int_eq(array[1], 63);
    ck_assert_int_eq(array[2], 65);
    ck_assert_int_eq(array[3], 50);
    ck_assert_int_eq(array[4], 57);
    ck_assert_int_eq(array[5], 53);
    ck_assert_int_eq(array[6], 51);
    ck_assert_int_eq(array[7], 30);
    ck_assert_int_eq(array[8], 42);
    ck_assert_int_eq(array[9], 18);
    ck_assert_int_eq(array[10], 24);
    ck_assert_int_eq(array[11], 13);
    ck_assert_int_eq(array[12], 36);
    ck_assert_int_eq(array[13], 8);
    ck_assert_int_eq(array[14], 26);
}
END_TEST 

START_TEST(test_heap_increase_key_8)
{
    bool result;
    int i, key;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    i = 3;
    key = 49;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(array[0], 70);
    ck_assert_int_eq(array[1], 63);
    ck_assert_int_eq(array[2], 65);
    ck_assert_int_eq(array[3], 50);
    ck_assert_int_eq(array[4], 57);
    ck_assert_int_eq(array[5], 53);
    ck_assert_int_eq(array[6], 51);
    ck_assert_int_eq(array[7], 30);
    ck_assert_int_eq(array[8], 42);
    ck_assert_int_eq(array[9], 18);
    ck_assert_int_eq(array[10], 24);
    ck_assert_int_eq(array[11], 13);
    ck_assert_int_eq(array[12], 36);
    ck_assert_int_eq(array[13], 8);
    ck_assert_int_eq(array[14], 26);
}
END_TEST 

START_TEST(test_heap_increase_key_9)
{
    bool result;
    int i, key;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    i = 9;
    key = 0;

    result = heap_increase_key(array, i, key);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(array[0], 70);
    ck_assert_int_eq(array[1], 63);
    ck_assert_int_eq(array[2], 65);
    ck_assert_int_eq(array[3], 50);
    ck_assert_int_eq(array[4], 57);
    ck_assert_int_eq(array[5], 53);
    ck_assert_int_eq(array[6], 51);
    ck_assert_int_eq(array[7], 30);
    ck_assert_int_eq(array[8], 42);
    ck_assert_int_eq(array[9], 18);
    ck_assert_int_eq(array[10], 24);
    ck_assert_int_eq(array[11], 13);
    ck_assert_int_eq(array[12], 36);
    ck_assert_int_eq(array[13], 8);
    ck_assert_int_eq(array[14], 26);
}
END_TEST 

START_TEST(test_max_heap_insert_1)
{
    int key; 
    int* heap_size;
    int array[] = {0, 0, 0};
    

    heap_size = malloc(sizeof(int));
    (*heap_size) = 0; 

    key = 15;
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 1);
    ck_assert_int_eq(array[0], 15);
    ck_assert_int_eq(array[1], 0);
    ck_assert_int_eq(array[2], 0);

    free(heap_size);
}
END_TEST

START_TEST(test_max_heap_insert_2)
{
    int key; 
    int* heap_size;
    int array[] = {0, 0, 0};
    

    heap_size = malloc(sizeof(int));
    (*heap_size) = 0; 

    key = 15;
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 1);
    ck_assert_int_eq(array[0], 15);
    ck_assert_int_eq(array[1], 0);
    ck_assert_int_eq(array[2], 0);

    key = 7;    
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 2);
    ck_assert_int_eq(array[0], 15);
    ck_assert_int_eq(array[1], 7);
    ck_assert_int_eq(array[2], 0);

    free(heap_size);
}
END_TEST

START_TEST(test_max_heap_insert_3)
{
    int key; 
    int* heap_size;
    int array[] = {0, 0, 0};
    

    heap_size = malloc(sizeof(int));
    (*heap_size) = 0; 

    key = 15;
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 1);
    ck_assert_int_eq(array[0], 15);
    ck_assert_int_eq(array[1], 0);
    ck_assert_int_eq(array[2], 0);

    key = 7;    
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 2);
    ck_assert_int_eq(array[0], 15);
    ck_assert_int_eq(array[1], 7);
    ck_assert_int_eq(array[2], 0);

    key = 30;    
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 3);
    ck_assert_int_eq(array[0], 30);
    ck_assert_int_eq(array[1], 7);
    ck_assert_int_eq(array[2], 15);

    free(heap_size);
}
END_TEST

START_TEST(test_max_heap_insert_4)
{
    int key; 
    int* heap_size;
    int array[] = {0, 0, 0, 0, 0};
    
    heap_size = malloc(sizeof(int));
    (*heap_size) = 0; 

    key = 1;
    max_heap_insert(array, key, heap_size);
    key = 2;    
    max_heap_insert(array, key, heap_size);
    key = 3;    
    max_heap_insert(array, key, heap_size);
    key = 5;    
    max_heap_insert(array, key, heap_size);
    key = 6;    
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 5);
    ck_assert_int_eq(array[0], 6);
    ck_assert_int_eq(array[1], 5);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 1);
    ck_assert_int_eq(array[4], 3);

    free(heap_size);
}
END_TEST

START_TEST(test_max_heap_insert_5)
{
    int key; 
    int* heap_size;
    int array[] = {56, 28, 43, 16, 21, 12, 8, 0, 0};
    
    heap_size = malloc(sizeof(int));
    (*heap_size) = 7; 

    key = 25;
    max_heap_insert(array, key, heap_size);

    ck_assert_int_eq((*heap_size), 8);
    ck_assert_int_eq(array[0], 56);
    ck_assert_int_eq(array[1], 28);
    ck_assert_int_eq(array[2], 43);
    ck_assert_int_eq(array[3], 25);
    ck_assert_int_eq(array[4], 21);
    ck_assert_int_eq(array[5], 12);
    ck_assert_int_eq(array[6], 8);
    ck_assert_int_eq(array[7], 16);
    ck_assert_int_eq(array[8], 0);

    free(heap_size);
}
END_TEST

START_TEST(test_heap_maximum_1)
{
    int maximum;
    int array[] = {50, 30, 35, 13, 26, 20, 22, -10, 1000};
    
    maximum = heap_maximum(array);

    ck_assert_int_eq(maximum, 50);
}
END_TEST

START_TEST(test_heap_maximum_2)
{
    int maximum;
    int array[] = {56, 28, 43, 16, 21, 12, 8, 0, 0};
    
    maximum = heap_maximum(array);

    ck_assert_int_eq(maximum, 56);
}
END_TEST

START_TEST(test_heap_maximum_3)
{
    int maximum;
    int array[] = {70, 63, 65, 50, 57, 53, 51, 30, 42, 18, 24, 13, 36, 8, 26};
    
    maximum = heap_maximum(array);

    ck_assert_int_eq(maximum, 70);
}
END_TEST

START_TEST(test_heap_extract_max_1)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {50, 30, 35, 13, 26, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 0; 

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(*heap_size, 0);
    
    ck_assert_int_eq(array[0], 50);
    ck_assert_int_eq(array[1], 30);
    ck_assert_int_eq(array[2], 35);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 26);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_2)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {34};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 1; 

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 0);
    ck_assert_int_eq(*extracted, 34);
    
    ck_assert_int_eq(array[0], 34);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_3)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {50, 30, 35, 13, 26, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 7; 

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 6);
    ck_assert_int_eq(*extracted, 50);
    
    ck_assert_int_eq(array[0], 35);
    ck_assert_int_eq(array[1], 30);
    ck_assert_int_eq(array[2], 22);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 26);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_4)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {35, 30, 22, 13, 26, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 6; 

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 5);
    ck_assert_int_eq(*extracted, 35);
    
    ck_assert_int_eq(array[0], 30);
    ck_assert_int_eq(array[1], 26);
    ck_assert_int_eq(array[2], 22);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_5)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {30, 26, 22, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 5; 

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 4);
    ck_assert_int_eq(*extracted, 30);
    
    ck_assert_int_eq(array[0], 26);
    ck_assert_int_eq(array[1], 20);
    ck_assert_int_eq(array[2], 22);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_6)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {26, 20, 22, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 4;

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 3);
    ck_assert_int_eq(*extracted, 26);
    
    ck_assert_int_eq(array[0], 22);
    ck_assert_int_eq(array[1], 20);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_7)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {22, 20, 13, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 3;

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 2);
    ck_assert_int_eq(*extracted, 22);
    
    ck_assert_int_eq(array[0], 20);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_8)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {20, 13, 13, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 2;

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 1);
    ck_assert_int_eq(*extracted, 20);
    
    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 0);
    ck_assert_int_eq(*extracted, 13);

    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(*heap_size, 0);

    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_9)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {13, 13, 13, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 1;

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, true);
    ck_assert_int_eq(*heap_size, 0);
    ck_assert_int_eq(*extracted, 13);

    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(*heap_size, 0);

    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

START_TEST(test_heap_extract_max_10)
{
    bool result;
    int* heap_size;
    int* extracted;
    int array[] = {13, 13, 13, 13, 20, 20, 22, -10, 1000};

    heap_size = malloc(sizeof(int));
    extracted = malloc(sizeof(int));
    (*heap_size) = 0;

    result = heap_extract_max(array, heap_size, extracted);

    ck_assert_int_eq(result, false);
    ck_assert_int_eq(*heap_size, 0);

    ck_assert_int_eq(array[0], 13);
    ck_assert_int_eq(array[1], 13);
    ck_assert_int_eq(array[2], 13);
    ck_assert_int_eq(array[3], 13);
    ck_assert_int_eq(array[4], 20);
    ck_assert_int_eq(array[5], 20);
    ck_assert_int_eq(array[6], 22);
    ck_assert_int_eq(array[7], -10);
    ck_assert_int_eq(array[8], 1000);

    free(heap_size);
    free(extracted);
}
END_TEST

Suite *make_test_suite(void)
{
    Suite *s;
    TCase *tc_core;

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
