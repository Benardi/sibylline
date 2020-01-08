#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <stdbool.h>
#include <sll.h>

Suite *make_sll_suite(void);

START_TEST(test_sll_insert_1)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node1, true);

    ck_assert_int_eq((*head)->next == NULL, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 200);
    ck_assert_int_eq(node1->data.key, 200);

    free(node1);
    free(head);
}
END_TEST

START_TEST(test_sll_insert_2)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_insert_3)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_search_1)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_search(head, 100);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, true);
    ck_assert_int_eq(node1 == NULL, true);
    ck_assert_int_eq(node1 == (*head), true);

    free(node1);
    free(head);
}
END_TEST

START_TEST(test_sll_search_2)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_search(head, 200);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node1, true);

    ck_assert_int_eq((*head)->next == NULL, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 200);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head) == node2, true);
    ck_assert_int_eq(node2->next == NULL, true);
    ck_assert_int_eq(node2->data.key, 200);
    ck_assert_int_eq(node2 == node1, true);

    free(node1);
    free(head);
}
END_TEST

START_TEST(test_sll_search_3)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_search(head, -35);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node1, true);

    ck_assert_int_eq((*head)->next == NULL, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 200);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq(node2 == NULL, true);

    free(node1);
    free(head);
}
END_TEST

START_TEST(test_sll_search_4)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);
    retrieved = sll_search(head, 200);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    ck_assert_int_eq((*head)->next == retrieved, true);
    ck_assert_int_eq(node2->next == retrieved, true);
    ck_assert_int_eq(retrieved->next == NULL, true);
    ck_assert_int_eq(retrieved->data.key, 200);
    ck_assert_int_eq(retrieved == node1, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_search_5)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);
    retrieved = sll_search(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    ck_assert_int_eq((*head) == retrieved, true);
    ck_assert_int_eq(retrieved->next == node1, true);
    ck_assert_int_eq(retrieved->data.key, 250);
    ck_assert_int_eq(retrieved == node2, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_search_6)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);
    retrieved = sll_search(head, 0);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    ck_assert_int_eq(retrieved == NULL, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_search_7)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);
    retrieved = sll_search(head, 10);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    ck_assert_int_eq(retrieved == NULL, true);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_search_8)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);
    retrieved = sll_search(head, 33);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    ck_assert_int_eq(node4->next == retrieved, true);
    ck_assert_int_eq(retrieved->next == node2, true);
    ck_assert_int_eq((*head)->next == retrieved, true);
    ck_assert_int_eq(retrieved->data.key, 33);
    ck_assert_int_eq(retrieved == node3, true);


    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_search_9)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;
    SinglyLinkedList* retrieved;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));
    retrieved = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);
    retrieved = sll_search(head, 200);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    ck_assert_int_eq(node2->next == retrieved, true);
    ck_assert_int_eq(retrieved->next == NULL, true);
    ck_assert_int_eq(retrieved->data.key, 200);
    ck_assert_int_eq((*head)->next->next->next == retrieved, true);
    ck_assert_int_eq(retrieved == node1, true);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_1)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node1, true);

    ck_assert_int_eq((*head)->next == NULL, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 200);
    ck_assert_int_eq(node1->data.key, 200);

    sll_delete(head, node1);
    
    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, true);

    free(node1);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_2)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    sll_delete(head, node2);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node1, true);
    ck_assert_int_eq((*head)->data.key, 200);
    ck_assert_int_eq(node1->next == NULL, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_3)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    sll_delete(head, node1);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq(node1->next == NULL, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_4)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    sll_delete(head, node1);
    sll_delete(head, node2);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_5)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, 250);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node2, true);

    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);
    ck_assert_int_eq(node1->data.key, 200);
    ck_assert_int_eq(node2->data.key, 250);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
    ck_assert_int_eq((*head)->data.key, 250);
    ck_assert_int_eq((*head)->next->data.key, 200);

    sll_delete(head, node2);
    sll_delete(head, node1);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, true);

    free(node1);
    free(node2);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_6)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node2);
    
    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_7)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node3);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node2, true);
    ck_assert_int_eq((*head)->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_8)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node4);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node3, true);

    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node2, true);
    ck_assert_int_eq((*head)->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, 33);
    ck_assert_int_eq((*head)->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_9)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node1);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_10)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node1);
    sll_delete(head, node4);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node3, true);

    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == NULL, true);

    ck_assert_int_eq((*head)->next == node2, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);
 
    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, 33);
    ck_assert_int_eq((*head)->next->data.key, -80);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_11)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node2);
    sll_delete(head, node3);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node1, true);
    ck_assert_int_eq((*head)->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

START_TEST(test_sll_delete_12)
{
    SinglyLinkedList** head;
    SinglyLinkedList* node1;
    SinglyLinkedList* node2;
    SinglyLinkedList* node3;
    SinglyLinkedList* node4;

    head = malloc(sizeof(SinglyLinkedList**));
    node1 = malloc(sizeof(SinglyLinkedList*));
    node2 = malloc(sizeof(SinglyLinkedList*));
    node3 = malloc(sizeof(SinglyLinkedList*));
    node4 = malloc(sizeof(SinglyLinkedList*));

    *head = NULL;
    node1 = sll_insert(head, 200);
    node2 = sll_insert(head, -80);
    node3 = sll_insert(head, 33);
    node4 = sll_insert(head, -730);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, false);
    ck_assert_int_eq((*head) == node4, true);

    ck_assert_int_eq(node4->next == node3, true);
    ck_assert_int_eq(node3->next == node2, true);
    ck_assert_int_eq(node2->next == node1, true);
    ck_assert_int_eq(node1->next == NULL, true);

    ck_assert_int_eq((*head)->next == node3, true);
    ck_assert_int_eq((*head)->next->next == node2, true);
    ck_assert_int_eq((*head)->next->next->next == node1, true);
    ck_assert_int_eq((*head)->next->next->next->next == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    ck_assert_int_eq((*head)->data.key, -730);
    ck_assert_int_eq((*head)->next->data.key, 33);
    ck_assert_int_eq((*head)->next->next->data.key, -80);
    ck_assert_int_eq((*head)->next->next->next->data.key, 200);

    sll_delete(head, node3);
    sll_delete(head, node1);
    sll_delete(head, node4);
    sll_delete(head, node2);

    ck_assert_int_eq(head == NULL, false);
    ck_assert_int_eq((*head) == NULL, true);

    ck_assert_int_eq(node4->data.key, -730);
    ck_assert_int_eq(node3->data.key, 33);
    ck_assert_int_eq(node2->data.key, -80);
    ck_assert_int_eq(node1->data.key, 200);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(head);
}
END_TEST

Suite *make_sll_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("DoublyLinkedList Test Suite");

    /* Creation test case */
    tc_core = tcase_create("Test Cases with no Setup/Teardown");

    tcase_add_test(tc_core, test_sll_insert_1);
    tcase_add_test(tc_core, test_sll_insert_2);    
    tcase_add_test(tc_core, test_sll_insert_3);

    tcase_add_test(tc_core, test_sll_search_1);
    tcase_add_test(tc_core, test_sll_search_2);
    tcase_add_test(tc_core, test_sll_search_3);
    tcase_add_test(tc_core, test_sll_search_4);
    tcase_add_test(tc_core, test_sll_search_5);
    tcase_add_test(tc_core, test_sll_search_6);
    tcase_add_test(tc_core, test_sll_search_7);
    tcase_add_test(tc_core, test_sll_search_8);
    tcase_add_test(tc_core, test_sll_search_9);

    tcase_add_test(tc_core, test_sll_delete_1);
    tcase_add_test(tc_core, test_sll_delete_2);
    tcase_add_test(tc_core, test_sll_delete_3);
    tcase_add_test(tc_core, test_sll_delete_4);
    tcase_add_test(tc_core, test_sll_delete_5);
    tcase_add_test(tc_core, test_sll_delete_6);
    tcase_add_test(tc_core, test_sll_delete_7);
    tcase_add_test(tc_core, test_sll_delete_8);
    tcase_add_test(tc_core, test_sll_delete_9);
    tcase_add_test(tc_core, test_sll_delete_10);
    tcase_add_test(tc_core, test_sll_delete_11);
    tcase_add_test(tc_core, test_sll_delete_12);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(make_sll_suite());
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "test.log");
    srunner_set_xml(sr, "test.xml");
    srunner_run_all(sr, CK_VERBOSE);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}