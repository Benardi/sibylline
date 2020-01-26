#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <check.h>
#include <stdbool.h>
#include <rbt.h>

Register* reg;
RedBlackTree** root;

void setup(void);
void teardown(void);
Suite *make_rbt_suite(void);

void setup(void)
{
    reg = malloc(sizeof(Register));
    root = malloc(sizeof(RedBlackTree*));
}

void teardown(void)
{
    free(reg);
    free(root);
}

START_TEST(test_rbt_left_rotate_1)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* nil;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));
    nil = malloc(sizeof(RedBlackTree));

    (*root) = nil;

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1->data.key = 5;
    node2->data.key = 15;
    node3->data.key = -2;
    node4->data.key = 10;
    node5->data.key = 23;

    node1->left = node3;
    node1->right = node2;
    node1->p = nil;

    node3->left = nil;
    node3->right = nil;
    node3->p = node1;

    node2->left = node4;
    node2->right = node5;
    node2->p = node1;

    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    node5->left = nil;
    node5->right = nil;
    node5->p = node2;

    (*root) = node1;

    ck_assert_int_eq(node1->data.key, 5);
    ck_assert_int_eq(node2->data.key, 15);
    ck_assert_int_eq(node3->data.key, -2);
    ck_assert_int_eq(node4->data.key, 10);
    ck_assert_int_eq(node5->data.key, 23);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == NULL, false);

    ck_assert_int_eq((*root) == node1, true);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->right->left == node4, true);
    ck_assert_int_eq((*root)->right->right == node5, true);

    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right->left->p == node2, true);
    ck_assert_int_eq((*root)->right->right->p == node2, true);

    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);

    left_rotate(root, nil, node1);

    ck_assert_int_eq(node1->data.key, 5);
    ck_assert_int_eq(node2->data.key, 15);
    ck_assert_int_eq(node3->data.key, -2);
    ck_assert_int_eq(node4->data.key, 10);
    ck_assert_int_eq(node5->data.key, 23);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == NULL, false);

    ck_assert_int_eq((*root) == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node5, true);
    ck_assert_int_eq((*root)->left->left == node3, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->left->left->p == node1, true);
    ck_assert_int_eq((*root)->left->right->p == node1, true);

    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);

    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_right_rotate_1)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* nil;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));
    nil = malloc(sizeof(RedBlackTree));

    (*root) = nil;

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1->data.key = 5;
    node2->data.key = 15;
    node3->data.key = -2;
    node4->data.key = 10;
    node5->data.key = 23;

    node2->left = node1;
    node2->right = node5;
    node2->p = nil;

    node1->left = node3;
    node1->right = node4;
    node1->p = node2;

    node5->left = nil;
    node5->right = nil;
    node5->p = node2;

    node3->left = nil;
    node3->right = nil;
    node3->p = node1;

    node4->left = nil;
    node4->right = nil;
    node4->p = node1;

    (*root) = node2;

    ck_assert_int_eq(node1->data.key, 5);
    ck_assert_int_eq(node2->data.key, 15);
    ck_assert_int_eq(node3->data.key, -2);
    ck_assert_int_eq(node4->data.key, 10);
    ck_assert_int_eq(node5->data.key, 23);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == NULL, false);

    ck_assert_int_eq((*root) == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node5, true);
    ck_assert_int_eq((*root)->left->left == node3, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->left->left->p == node1, true);
    ck_assert_int_eq((*root)->left->right->p == node1, true);

    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);

    right_rotate(root, nil, node2);

    ck_assert_int_eq(node1->data.key, 5);
    ck_assert_int_eq(node2->data.key, 15);
    ck_assert_int_eq(node3->data.key, -2);
    ck_assert_int_eq(node4->data.key, 10);
    ck_assert_int_eq(node5->data.key, 23);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == NULL, false);

    ck_assert_int_eq((*root) == node1, true);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->right->left == node4, true);
    ck_assert_int_eq((*root)->right->right == node5, true);

    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right->left->p == node2, true);
    ck_assert_int_eq((*root)->right->right->p == node2, true);

    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);

    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_1)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 10;
    node1 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == nil, true);
    ck_assert_int_eq(node1->right == nil, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    reg->key = 5;
    node2 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == nil, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, 5);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == nil, true);
    ck_assert_int_eq(node2->right == nil, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 5);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    reg->key = 4;
    node3 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, RED);
    ck_assert_int_eq(node1->left == nil, true);
    ck_assert_int_eq(node1->right == nil, true);
    ck_assert_int_eq(node1->p == node2, true);

    ck_assert_int_eq(node2->data.key, 5);
    ck_assert_int_eq(node2->color, BLACK);
    ck_assert_int_eq(node2->left == node3, true);
    ck_assert_int_eq(node2->right == node1, true);
    ck_assert_int_eq(node2->p == nil, true);

    ck_assert_int_eq(node3->data.key, 4);
    ck_assert_int_eq(node3->color, RED);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == nil, true);
    ck_assert_int_eq(node3->p == node2, true);

    ck_assert_int_eq((*root)->data.key, 5);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 4);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node3, true);

    ck_assert_int_eq((*root)->right->data.key, 10);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_2)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));

    reg->key = 10;
    node1->color = BLACK;
    node1->data = *reg;
    node1->left = node2;
    node1->right = node3;
    node1->p = nil;

    reg->key = -10;
    node2->color = BLACK;
    node2->data = *reg;
    node2->left = nil;
    node2->right = node4;
    node2->p = node1;

    reg->key = 20;
    node3->color = BLACK;
    node3->data = *reg;
    node3->left = node5;
    node3->right = nil;
    node3->p = node1;

    reg->key = 7;
    node4->color = RED;
    node4->data = *reg;
    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    reg->key = 15;
    node5->color = RED;
    node5->data = *reg;
    node5->left = nil;
    node5->right = nil;
    node5->p = node3;

    (*root) = node1;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, BLACK);
    ck_assert_int_eq(node2->left == nil, true);
    ck_assert_int_eq(node2->right == node4, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == node5, true);
    ck_assert_int_eq(node3->right == nil, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 7);
    ck_assert_int_eq(node4->color, RED);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 15);
    ck_assert_int_eq(node5->color, RED);
    ck_assert_int_eq(node5->left == nil, true);
    ck_assert_int_eq(node5->right == nil, true);
    ck_assert_int_eq(node5->p == node3, true);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 20);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node5, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);

    ck_assert_int_eq((*root)->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node3, true);

    reg->key = 13;
    node6 = rb_insert(root, nil, *reg);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node5, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 15);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node6, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node5, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->right->left->data.key, 13);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node5, true);
    ck_assert_int_eq((*root)->right->left == node6, true);

    ck_assert_int_eq((*root)->right->right->data.key, 20);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node5, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node5, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, BLACK);
    ck_assert_int_eq(node2->left == nil, true);
    ck_assert_int_eq(node2->right == node4, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, RED);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == nil, true);
    ck_assert_int_eq(node3->p == node5, true);

    ck_assert_int_eq(node4->data.key, 7);
    ck_assert_int_eq(node4->color, RED);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 15);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node6, true);
    ck_assert_int_eq(node5->right == node3, true);
    ck_assert_int_eq(node5->p == node1, true);

    ck_assert_int_eq(node6->data.key, 13);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node5, true);

    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_3)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));

    reg->key = 10;
    node1->color = BLACK;
    node1->data = *reg;
    node1->left = node2;
    node1->right = node3;
    node1->p = nil;

    reg->key = -10;
    node2->color = BLACK;
    node2->data = *reg;
    node2->left = nil;
    node2->right = node4;
    node2->p = node1;

    reg->key = 20;
    node3->color = BLACK;
    node3->data = *reg;
    node3->left = node5;
    node3->right = nil;
    node3->p = node1;

    reg->key = 7;
    node4->color = RED;
    node4->data = *reg;
    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    reg->key = 15;
    node5->color = RED;
    node5->data = *reg;
    node5->left = nil;
    node5->right = nil;
    node5->p = node3;

    (*root) = node1;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, BLACK);
    ck_assert_int_eq(node2->left == nil, true);
    ck_assert_int_eq(node2->right == node4, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == node5, true);
    ck_assert_int_eq(node3->right == nil, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 7);
    ck_assert_int_eq(node4->color, RED);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 15);
    ck_assert_int_eq(node5->color, RED);
    ck_assert_int_eq(node5->left == nil, true);
    ck_assert_int_eq(node5->right == nil, true);
    ck_assert_int_eq(node5->p == node3, true);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 20);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node5, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);

    ck_assert_int_eq((*root)->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node3, true);

    reg->key = 17;
    node6 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node6, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 17);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node5, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node6, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node6, true);
    ck_assert_int_eq((*root)->right->left == node5, true);

    ck_assert_int_eq((*root)->right->right->data.key, 20);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node6, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node6, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, BLACK);
    ck_assert_int_eq(node2->left == nil, true);
    ck_assert_int_eq(node2->right == node4, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, RED);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == nil, true);
    ck_assert_int_eq(node3->p == node6, true);

    ck_assert_int_eq(node4->data.key, 7);
    ck_assert_int_eq(node4->color, RED);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 15);
    ck_assert_int_eq(node5->color, RED);
    ck_assert_int_eq(node5->left == nil, true);
    ck_assert_int_eq(node5->right == nil, true);
    ck_assert_int_eq(node5->p == node6, true);

    ck_assert_int_eq(node6->data.key, 17);
    ck_assert_int_eq(node6->color, BLACK);
    ck_assert_int_eq(node6->left == node5, true);
    ck_assert_int_eq(node6->right == node3, true);
    ck_assert_int_eq(node6->p == node1, true);

    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_4)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* node7;
    RedBlackTree* node8;
    RedBlackTree* node9;
    RedBlackTree* node10;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));
    node6 = malloc(sizeof(RedBlackTree));
    node7 = malloc(sizeof(RedBlackTree));
    node8 = malloc(sizeof(RedBlackTree));
    node9 = malloc(sizeof(RedBlackTree));

    reg->key = 10;
    node1->data = *reg;
    node1->color = BLACK;
    node1->left = node2;
    node1->right = node3;
    node1->p = nil;

    reg->key = -10;
    node2->data = *reg;
    node2->color = RED;
    node2->left = node4;
    node2->right = node5;
    node2->p = node1;

    reg->key = 20;
    node3->data = *reg;
    node3->color = BLACK;
    node3->left = node6;
    node3->right = node7;
    node3->p = node1;

    reg->key = -20;
    node4->data = *reg;
    node4->color = BLACK;
    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    reg->key = 6;
    node5->data = *reg;
    node5->color = BLACK;
    node5->left = node8;
    node5->right = node9;
    node5->p = node2;

    reg->key = 15;
    node6->data = *reg;
    node6->color = RED;
    node6->left = nil;
    node6->right = nil;
    node6->p = node3;

    reg->key = 30;
    node7->data = *reg;
    node7->color = RED;
    node7->left = nil;
    node7->right = nil;
    node7->p = node3;

    reg->key = 1;
    node8->data = *reg;
    node8->color = RED;
    node8->left = nil;
    node8->right = nil;
    node8->p = node5;

    reg->key = 9;
    node9->data = *reg;
    node9->color = RED;
    node9->left = nil;
    node9->right = nil;
    node9->p = node5;

    (*root) = node1;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node5, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == node6, true);
    ck_assert_int_eq(node3->right == node7, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, -20);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 6);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node8, true);
    ck_assert_int_eq(node5->right == node9, true);
    ck_assert_int_eq(node5->p == node2, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 30);
    ck_assert_int_eq(node7->color, RED);
    ck_assert_int_eq(node7->left == nil, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node3, true);

    ck_assert_int_eq(node8->data.key, 1);
    ck_assert_int_eq(node8->color, RED);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == nil, true);
    ck_assert_int_eq(node8->p == node5, true);

    ck_assert_int_eq(node9->data.key, 9);
    ck_assert_int_eq(node9->color, RED);
    ck_assert_int_eq(node9->left == nil, true);
    ck_assert_int_eq(node9->right == nil, true);
    ck_assert_int_eq(node9->p == node5, true);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node5, true);
    ck_assert_int_eq((*root)->left->p == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 20);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node6, true);
    ck_assert_int_eq((*root)->right->right == node7, true);
    ck_assert_int_eq((*root)->right->p == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, -20);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);

    ck_assert_int_eq((*root)->left->right->data.key, 6);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == node8, true);
    ck_assert_int_eq((*root)->left->right->right == node9, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);

    ck_assert_int_eq((*root)->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node3, true);

    ck_assert_int_eq((*root)->right->right->data.key, 30);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node3, true);

    ck_assert_int_eq((*root)->left->right->left->data.key, 1);
    ck_assert_int_eq((*root)->left->right->left->color, RED);
    ck_assert_int_eq((*root)->left->right->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left->p == node5, true);

    ck_assert_int_eq((*root)->left->right->right->data.key, 9);
    ck_assert_int_eq((*root)->left->right->right->color, RED);
    ck_assert_int_eq((*root)->left->right->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->right->p == node5, true);

    reg->key = 4;
    node10 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq((*root)->data.key, 6);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node8, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 10);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == node9, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, -20);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 1);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == node10, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node8, true);

    ck_assert_int_eq((*root)->right->left->data.key, 9);
    ck_assert_int_eq((*root)->right->left->color, BLACK);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node1, true);
    ck_assert_int_eq((*root)->right->left == node9, true);

    ck_assert_int_eq((*root)->right->right->data.key, 20);
    ck_assert_int_eq((*root)->right->right->color, BLACK);
    ck_assert_int_eq((*root)->right->right->left == node6, true);
    ck_assert_int_eq((*root)->right->right->right == node7, true);
    ck_assert_int_eq((*root)->right->right->p == node1, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    ck_assert_int_eq((*root)->right->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->right->left->color, RED);
    ck_assert_int_eq((*root)->right->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->right->left->p == node3, true);
    ck_assert_int_eq((*root)->right->right->left == node6, true);

    ck_assert_int_eq((*root)->right->right->right->data.key, 30);
    ck_assert_int_eq((*root)->right->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->right->p == node3, true);
    ck_assert_int_eq((*root)->right->right->right == node7, true);

    ck_assert_int_eq(node5->data.key, 6);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node2, true);
    ck_assert_int_eq(node5->right == node1, true);
    ck_assert_int_eq(node5->p == nil, true);

    ck_assert_int_eq(node2->data.key, -10);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node8, true);
    ck_assert_int_eq(node2->p == node5, true);

    ck_assert_int_eq(node1->data.key, 10);
    ck_assert_int_eq(node1->color, RED);
    ck_assert_int_eq(node1->left == node9, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == node5, true);

    ck_assert_int_eq(node4->data.key, -20);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node8->data.key, 1);
    ck_assert_int_eq(node8->color, BLACK);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == node10, true);
    ck_assert_int_eq(node8->p == node2, true);

    ck_assert_int_eq(node9->data.key, 9);
    ck_assert_int_eq(node9->color, BLACK);
    ck_assert_int_eq(node9->left == nil, true);
    ck_assert_int_eq(node9->right == nil, true);
    ck_assert_int_eq(node9->p == node1, true);

    ck_assert_int_eq(node3->data.key, 20);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == node6, true);
    ck_assert_int_eq(node3->right == node7, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 30);
    ck_assert_int_eq(node7->color, RED);
    ck_assert_int_eq(node7->left == nil, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node3, true);

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
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_5)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* node7;
    RedBlackTree* node8;
    RedBlackTree* node9;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));
    node6 = malloc(sizeof(RedBlackTree));
    node7 = malloc(sizeof(RedBlackTree));
    node8 = malloc(sizeof(RedBlackTree));

    reg->key = 11;
    node1->data = *reg;
    node1->color = BLACK;
    node1->left = node2;
    node1->right = node3;
    node1->p = nil;

    reg->key = 2;
    node2->data = *reg;
    node2->color = RED;
    node2->left = node4;
    node2->right = node5;
    node2->p = node1;

    reg->key = 14;
    node3->data = *reg;
    node3->color = BLACK;
    node3->left = nil;
    node3->right = node6;
    node3->p = node1;

    reg->key = 1;
    node4->data = *reg;
    node4->color = BLACK;
    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    reg->key = 7;
    node5->data = *reg;
    node5->color = BLACK;
    node5->left = node7;
    node5->right = node8;
    node5->p = node2;

    reg->key = 15;
    node6->data = *reg;
    node6->color = RED;
    node6->left = nil;
    node6->right = nil;
    node6->p = node3;

    reg->key = 5;
    node7->data = *reg;
    node7->color = RED;
    node7->left = nil;
    node7->right = nil;
    node7->p = node5;

    reg->key = 8;
    node8->data = *reg;
    node8->color = RED;
    node8->left = nil;
    node8->right = nil;
    node8->p = node5;

    (*root) = node1;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 11);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, 2);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node5, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 14);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == node6, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 1);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 7);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node7, true);
    ck_assert_int_eq(node5->right == node8, true);
    ck_assert_int_eq(node5->p == node2, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 5);
    ck_assert_int_eq(node7->color, RED);
    ck_assert_int_eq(node7->left == nil, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node5, true);

    ck_assert_int_eq(node8->data.key, 8);
    ck_assert_int_eq(node8->color, RED);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == nil, true);
    ck_assert_int_eq(node8->p == node5, true);

    ck_assert_int_eq((*root)->data.key, 11);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node5, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 14);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == node6, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->left->data.key, 1);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == node7, true);
    ck_assert_int_eq((*root)->left->right->right == node8, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node5, true);

    ck_assert_int_eq((*root)->right->right->data.key, 15);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node3, true);
    ck_assert_int_eq((*root)->right->right == node6, true);

    ck_assert_int_eq((*root)->left->right->left->data.key, 5);
    ck_assert_int_eq((*root)->left->right->left->color, RED);
    ck_assert_int_eq((*root)->left->right->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left->p == node5, true);
    ck_assert_int_eq((*root)->left->right->left == node7, true);

    ck_assert_int_eq((*root)->left->right->right->data.key, 8);
    ck_assert_int_eq((*root)->left->right->right->color, RED);
    ck_assert_int_eq((*root)->left->right->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->right->p == node5, true);
    ck_assert_int_eq((*root)->left->right->right == node8, true);

    reg->key = 4;
    node9 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq((*root)->data.key, 7);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);
    
    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node7, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 11);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == node8, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, 1);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 5);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == node9, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node7, true);

    ck_assert_int_eq((*root)->right->left->data.key, 8);
    ck_assert_int_eq((*root)->right->left->color, BLACK);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node1, true);
    ck_assert_int_eq((*root)->right->left == node8, true);

    ck_assert_int_eq((*root)->right->right->data.key, 14);
    ck_assert_int_eq((*root)->right->right->color, BLACK);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);
    ck_assert_int_eq((*root)->right->right->p == node1, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    ck_assert_int_eq((*root)->left->right->left->data.key, 4);
    ck_assert_int_eq((*root)->left->right->left->color, RED);
    ck_assert_int_eq((*root)->left->right->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left->p == node7, true);
    ck_assert_int_eq((*root)->left->right->left == node9, true);

    ck_assert_int_eq((*root)->right->right->right->data.key, 15);
    ck_assert_int_eq((*root)->right->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->right->p == node3, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);

    ck_assert_int_eq(node1->data.key, 11);
    ck_assert_int_eq(node1->color, RED);
    ck_assert_int_eq(node1->left == node8, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == node5, true);
    
    ck_assert_int_eq(node2->data.key, 2);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node7, true);
    ck_assert_int_eq(node2->p == node5, true);

    ck_assert_int_eq(node3->data.key, 14);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == node6, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 1);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 7);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node2, true);
    ck_assert_int_eq(node5->right == node1, true);
    ck_assert_int_eq(node5->p == nil, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 5);
    ck_assert_int_eq(node7->color, BLACK);
    ck_assert_int_eq(node7->left == node9, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node2, true);

    ck_assert_int_eq(node8->data.key, 8);
    ck_assert_int_eq(node8->color, BLACK);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == nil, true);
    ck_assert_int_eq(node8->p == node1, true);

    ck_assert_int_eq(node9->data.key, 4);
    ck_assert_int_eq(node9->color, RED);
    ck_assert_int_eq(node9->left == nil, true);
    ck_assert_int_eq(node9->right == nil, true);
    ck_assert_int_eq(node9->p == node7, true);

    free(node9);
    free(node8);
    free(node7);
    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_6)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* node7;
    RedBlackTree* node8;
    RedBlackTree* node9;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    node1 = malloc(sizeof(RedBlackTree));
    node2 = malloc(sizeof(RedBlackTree));
    node3 = malloc(sizeof(RedBlackTree));
    node4 = malloc(sizeof(RedBlackTree));
    node5 = malloc(sizeof(RedBlackTree));
    node6 = malloc(sizeof(RedBlackTree));
    node7 = malloc(sizeof(RedBlackTree));
    node8 = malloc(sizeof(RedBlackTree));

    reg->key = 11;
    node1->data = *reg;
    node1->color = BLACK;
    node1->left = node2;
    node1->right = node3;
    node1->p = nil;

    reg->key = 2;
    node2->data = *reg;
    node2->color = RED;
    node2->left = node4;
    node2->right = node5;
    node2->p = node1;

    reg->key = 14;
    node3->data = *reg;
    node3->color = BLACK;
    node3->left = nil;
    node3->right = node6;
    node3->p = node1;

    reg->key = 1;
    node4->data = *reg;
    node4->color = BLACK;
    node4->left = nil;
    node4->right = nil;
    node4->p = node2;

    reg->key = 7;
    node5->data = *reg;
    node5->color = BLACK;
    node5->left = node7;
    node5->right = node8;
    node5->p = node2;

    reg->key = 15;
    node6->data = *reg;
    node6->color = RED;
    node6->left = nil;
    node6->right = nil;
    node6->p = node3;

    reg->key = 5;
    node7->data = *reg;
    node7->color = RED;
    node7->left = nil;
    node7->right = nil;
    node7->p = node5;

    reg->key = 8;
    node8->data = *reg;
    node8->color = RED;
    node8->left = nil;
    node8->right = nil;
    node8->p = node5;

    (*root) = node1;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq(node1->data.key, 11);
    ck_assert_int_eq(node1->color, BLACK);
    ck_assert_int_eq(node1->left == node2, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == nil, true);

    ck_assert_int_eq(node2->data.key, 2);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node5, true);
    ck_assert_int_eq(node2->p == node1, true);

    ck_assert_int_eq(node3->data.key, 14);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == node6, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 1);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 7);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node7, true);
    ck_assert_int_eq(node5->right == node8, true);
    ck_assert_int_eq(node5->p == node2, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 5);
    ck_assert_int_eq(node7->color, RED);
    ck_assert_int_eq(node7->left == nil, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node5, true);

    ck_assert_int_eq(node8->data.key, 8);
    ck_assert_int_eq(node8->color, RED);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == nil, true);
    ck_assert_int_eq(node8->p == node5, true);

    ck_assert_int_eq((*root)->data.key, 11);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node5, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 14);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == node6, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->left->data.key, 1);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == node7, true);
    ck_assert_int_eq((*root)->left->right->right == node8, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node5, true);

    ck_assert_int_eq((*root)->right->right->data.key, 15);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node3, true);
    ck_assert_int_eq((*root)->right->right == node6, true);

    ck_assert_int_eq((*root)->left->right->left->data.key, 5);
    ck_assert_int_eq((*root)->left->right->left->color, RED);
    ck_assert_int_eq((*root)->left->right->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right->left->right == nil, true);
    ck_assert_int_eq((*root)->left->right->left->p == node5, true);
    ck_assert_int_eq((*root)->left->right->left == node7, true);

    ck_assert_int_eq((*root)->left->right->right->data.key, 8);
    ck_assert_int_eq((*root)->left->right->right->color, RED);
    ck_assert_int_eq((*root)->left->right->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->right->p == node5, true);
    ck_assert_int_eq((*root)->left->right->right == node8, true);

    reg->key = 9;
    node9 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq((*root)->data.key, 7);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);
    
    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node7, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 11);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == node8, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, 1);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 5);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node7, true);

    ck_assert_int_eq((*root)->right->left->data.key, 8);
    ck_assert_int_eq((*root)->right->left->color, BLACK);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == node9, true);
    ck_assert_int_eq((*root)->right->left->p == node1, true);
    ck_assert_int_eq((*root)->right->left == node8, true);

    ck_assert_int_eq((*root)->right->right->data.key, 14);
    ck_assert_int_eq((*root)->right->right->color, BLACK);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);
    ck_assert_int_eq((*root)->right->right->p == node1, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    ck_assert_int_eq((*root)->right->right->right->data.key, 15);
    ck_assert_int_eq((*root)->right->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->right->p == node3, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);

    ck_assert_int_eq((*root)->right->left->right->data.key, 9);
    ck_assert_int_eq((*root)->right->left->right->color, RED);
    ck_assert_int_eq((*root)->right->left->right->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right->right == nil, true);
    ck_assert_int_eq((*root)->right->left->right->p == node8, true);
    ck_assert_int_eq((*root)->right->left->right == node9, true);

    ck_assert_int_eq(node1->data.key, 11);
    ck_assert_int_eq(node1->color, RED);
    ck_assert_int_eq(node1->left == node8, true);
    ck_assert_int_eq(node1->right == node3, true);
    ck_assert_int_eq(node1->p == node5, true);
    
    ck_assert_int_eq(node2->data.key, 2);
    ck_assert_int_eq(node2->color, RED);
    ck_assert_int_eq(node2->left == node4, true);
    ck_assert_int_eq(node2->right == node7, true);
    ck_assert_int_eq(node2->p == node5, true);

    ck_assert_int_eq(node3->data.key, 14);
    ck_assert_int_eq(node3->color, BLACK);
    ck_assert_int_eq(node3->left == nil, true);
    ck_assert_int_eq(node3->right == node6, true);
    ck_assert_int_eq(node3->p == node1, true);

    ck_assert_int_eq(node4->data.key, 1);
    ck_assert_int_eq(node4->color, BLACK);
    ck_assert_int_eq(node4->left == nil, true);
    ck_assert_int_eq(node4->right == nil, true);
    ck_assert_int_eq(node4->p == node2, true);

    ck_assert_int_eq(node5->data.key, 7);
    ck_assert_int_eq(node5->color, BLACK);
    ck_assert_int_eq(node5->left == node2, true);
    ck_assert_int_eq(node5->right == node1, true);
    ck_assert_int_eq(node5->p == nil, true);

    ck_assert_int_eq(node6->data.key, 15);
    ck_assert_int_eq(node6->color, RED);
    ck_assert_int_eq(node6->left == nil, true);
    ck_assert_int_eq(node6->right == nil, true);
    ck_assert_int_eq(node6->p == node3, true);

    ck_assert_int_eq(node7->data.key, 5);
    ck_assert_int_eq(node7->color, BLACK);
    ck_assert_int_eq(node7->left == nil, true);
    ck_assert_int_eq(node7->right == nil, true);
    ck_assert_int_eq(node7->p == node2, true);

    ck_assert_int_eq(node8->data.key, 8);
    ck_assert_int_eq(node8->color, BLACK);
    ck_assert_int_eq(node8->left == nil, true);
    ck_assert_int_eq(node8->right == node9, true);
    ck_assert_int_eq(node8->p == node1, true);

    ck_assert_int_eq(node9->data.key, 9);
    ck_assert_int_eq(node9->color, RED);
    ck_assert_int_eq(node9->left == nil, true);
    ck_assert_int_eq(node9->right == nil, true);
    ck_assert_int_eq(node9->p == node8, true);
    ck_assert_int_eq(node9 == node9, true);

    free(node9);
    free(node8);
    free(node7);
    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_7)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;

    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 10;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);

    reg->key = 20;
    node2 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);

    ck_assert_int_eq((*root)->right->data.key, 20);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);

    reg->key = 30;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);

    reg->key = 15;
    node4 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->right->data.key, 15);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node1, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_8)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 50;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 50);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    reg->key = 25;
    node2 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 50);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 25);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    reg->key = 10;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 25);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node3, true);

    ck_assert_int_eq((*root)->right->data.key, 50);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_9)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 30;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 30);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    reg->key = 15;
    node2 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 30);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 15);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    reg->key = 20;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node3, true);

    ck_assert_int_eq((*root)->left->data.key, 15);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node3, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node3, true);
    ck_assert_int_eq((*root)->right == node1, true);

    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_10)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 12;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 12);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    reg->key = 18;
    node2 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 12);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 18);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node2, true);

    reg->key = 24;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 18);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 12);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 24);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_insert_11)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = -8;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, -8);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    reg->key = 15;
    node2 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, -8);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 15);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node2, true);

    reg->key = 6;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 6);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node3, true);

    ck_assert_int_eq((*root)->left->data.key, -8);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node3, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 15);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node3, true);
    ck_assert_int_eq((*root)->right == node2, true);


    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_1)
{
    RedBlackTree* node1;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 50;
    node1 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 50);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);


    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    free(node1);
    free(nil);
}
END_TEST


START_TEST(test_rbt_delete_2)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 50;
    node1 = rb_insert(root,  nil, *reg);
    reg->key = 25;
    node2 = rb_insert(root,  nil, *reg);
    reg->key = 10;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 25);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node3, true);

    ck_assert_int_eq((*root)->right->data.key, 50);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    rb_delete(root, nil, node3);

    ck_assert_int_eq((*root)->data.key, 25);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == nil, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 50);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_3)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 50;
    node1 = rb_insert(root,  nil, *reg);
    reg->key = 25;
    node2 = rb_insert(root,  nil, *reg);
    reg->key = 10;
    node3 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 25);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node3, true);

    ck_assert_int_eq((*root)->right->data.key, 50);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 25);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node3, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node3, true);

    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_4)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 10;
    node1 = rb_insert(root,  nil, *reg);
    reg->key = 20;
    node2 = rb_insert(root,  nil, *reg);
    reg->key = 30;
    node3 = rb_insert(root,  nil, *reg);
    reg->key = 15;
    node4 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->right->data.key, 15);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node1, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 15);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_5)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 10;
    node1 = rb_insert(root,  nil, *reg);
    reg->key = 20;
    node2 = rb_insert(root,  nil, *reg);
    reg->key = 30;
    node3 = rb_insert(root,  nil, *reg);
    reg->key = 15;
    node4 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->right->data.key, 15);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node1, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    rb_delete(root, nil, node3);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 15);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node4, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node4, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 20);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node4, true);
    ck_assert_int_eq((*root)->right == node2, true);
    
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_6)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, true);

    reg->key = 10;
    node1 = rb_insert(root,  nil, *reg);
    reg->key = 20;
    node2 = rb_insert(root,  nil, *reg);
    reg->key = 30;
    node3 = rb_insert(root,  nil, *reg);
    reg->key = 5;
    node4 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->left->data.key, 5);
    ck_assert_int_eq((*root)->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node1, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 20);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 5);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 30);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);

    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_7)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 10;
    node1 = rb_insert(root, nil, *reg);
    reg->key = -10;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 20;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 7;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 15;
    node5 = rb_insert(root, nil, *reg);
    reg->key = 17;
    node6 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 10);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node6, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 17);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node5, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node6, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->right->left->data.key, 15);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node6, true);
    ck_assert_int_eq((*root)->right->left == node5, true);

    ck_assert_int_eq((*root)->right->right->data.key, 20);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node6, true);
    ck_assert_int_eq((*root)->right->right == node3, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 15);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node6, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, -10);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node4, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 17);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == node3, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node6, true);

    ck_assert_int_eq((*root)->left->right->data.key, 7);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node4, true);

    ck_assert_int_eq((*root)->right->right->data.key, 20);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node6, true);
    ck_assert_int_eq((*root)->right->right == node3, true);


    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_8)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 6;
    node1 = rb_insert(root, nil, *reg);
    reg->key = 4;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 8;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 2;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 5;
    node5 = rb_insert(root, nil, *reg);
    reg->key = 7;
    node6 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 6);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node3, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 4);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node5, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 8);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node6, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node3, true);

    ck_assert_int_eq((*root)->left->left->data.key, 2);
    ck_assert_int_eq((*root)->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 5);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node5, true);

    ck_assert_int_eq((*root)->right->left->data.key, 7);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node3, true);
    ck_assert_int_eq((*root)->right->left == node6, true);

    rb_delete(root, nil, node3);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 6);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node6, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node1, true);

    ck_assert_int_eq((*root)->left->data.key, 4);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node5, true);
    ck_assert_int_eq((*root)->left->p == node1, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 7);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node1, true);
    ck_assert_int_eq((*root)->right == node6, true);

    ck_assert_int_eq((*root)->left->left->data.key, 2);
    ck_assert_int_eq((*root)->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node2, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 5);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node5, true);

    rb_delete(root, nil, node6);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 4);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 6);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node5, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->right->left->data.key, 5);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node1, true);
    ck_assert_int_eq((*root)->right->left == node5, true);

    rb_delete(root, nil, node2);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 5);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 6);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node1, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 5);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == nil, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node4, true);

    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_9)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 50;
    node1 = rb_insert(root, nil, *reg);
    reg->key = 75;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 100;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 200;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 150;
    node5 = rb_insert(root, nil, *reg);
    reg->key = 400;
    node6 = rb_insert(root,  nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 75);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node5, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 50);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 150);
    ck_assert_int_eq((*root)->right->color, RED);
    ck_assert_int_eq((*root)->right->left == node3, true);
    ck_assert_int_eq((*root)->right->right == node4, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node5, true);

    ck_assert_int_eq((*root)->right->left->data.key, 100);
    ck_assert_int_eq((*root)->right->left->color, BLACK);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node5, true);
    ck_assert_int_eq((*root)->right->left == node3, true);

    ck_assert_int_eq((*root)->right->right->data.key, 200);
    ck_assert_int_eq((*root)->right->right->color, BLACK);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);
    ck_assert_int_eq((*root)->right->right->p == node5, true);
    ck_assert_int_eq((*root)->right->right == node4, true);

    ck_assert_int_eq((*root)->right->right->right->data.key, 400);
    ck_assert_int_eq((*root)->right->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->right->p == node4, true);
    ck_assert_int_eq((*root)->right->right->right == node6, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 150);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node4, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, 75);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node3, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 200);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == node6, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 100);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node2, true);
    ck_assert_int_eq((*root)->left->right == node3, true);

    ck_assert_int_eq((*root)->right->right->data.key, 400);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node4, true);
    ck_assert_int_eq((*root)->right->right == node6, true);

    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_10)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 1;
    node1 = rb_insert(root, nil, *reg);
    reg->key = 2;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 3;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 5;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 10;
    node5 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 2);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node4, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 1);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 5);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node3, true);
    ck_assert_int_eq((*root)->right->right == node5, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node4, true);

    ck_assert_int_eq((*root)->right->left->data.key, 3);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node4, true);
    ck_assert_int_eq((*root)->right->left == node3, true);

    ck_assert_int_eq((*root)->right->right->data.key, 10);
    ck_assert_int_eq((*root)->right->right->color, RED);
    ck_assert_int_eq((*root)->right->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right->right == nil, true);
    ck_assert_int_eq((*root)->right->right->p == node4, true);
    ck_assert_int_eq((*root)->right->right == node5, true);

    rb_delete(root, nil, node5);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 2);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node1, true);
    ck_assert_int_eq((*root)->right == node4, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 1);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node1, true);

    ck_assert_int_eq((*root)->right->data.key, 5);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node3, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node4, true);

    ck_assert_int_eq((*root)->right->left->data.key, 3);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node4, true);
    ck_assert_int_eq((*root)->right->left == node3, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 3);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node2, true);
    ck_assert_int_eq((*root)->right == node4, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node3, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node3, true);
    ck_assert_int_eq((*root)->left == node2, true);

    ck_assert_int_eq((*root)->right->data.key, 5);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node3, true);
    ck_assert_int_eq((*root)->right == node4, true);

    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_11)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* node6;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 500;
    node1 = rb_insert(root, nil, *reg);
    reg->key = 475;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 450;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 400;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 425;
    node5 = rb_insert(root, nil, *reg);
    reg->key = 200;
    node6 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 475);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node5, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 425);
    ck_assert_int_eq((*root)->left->color, RED);
    ck_assert_int_eq((*root)->left->left == node4, true);
    ck_assert_int_eq((*root)->left->right == node3, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node5, true);

    ck_assert_int_eq((*root)->right->data.key, 500);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, 400);
    ck_assert_int_eq((*root)->left->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left->left == node6, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node5, true);
    ck_assert_int_eq((*root)->left->left == node4, true);

    ck_assert_int_eq((*root)->left->right->data.key, 450);
    ck_assert_int_eq((*root)->left->right->color, BLACK);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node5, true);
    ck_assert_int_eq((*root)->left->right == node3, true);

    ck_assert_int_eq((*root)->left->left->left->data.key, 200);
    ck_assert_int_eq((*root)->left->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->left->p == node4, true);
    ck_assert_int_eq((*root)->left->left->left == node6, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 425);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node5, true);

    ck_assert_int_eq((*root)->left->data.key, 400);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == node6, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node5, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 475);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == node3, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node5, true);
    ck_assert_int_eq((*root)->right == node2, true);

    ck_assert_int_eq((*root)->left->left->data.key, 200);
    ck_assert_int_eq((*root)->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node4, true);
    ck_assert_int_eq((*root)->left->left == node6, true);

    ck_assert_int_eq((*root)->right->left->data.key, 450);
    ck_assert_int_eq((*root)->right->left->color, RED);
    ck_assert_int_eq((*root)->right->left->left == nil, true);
    ck_assert_int_eq((*root)->right->left->right == nil, true);
    ck_assert_int_eq((*root)->right->left->p == node2, true);
    ck_assert_int_eq((*root)->right->left == node3, true);


    free(node6);
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

START_TEST(test_rbt_delete_12)
{
    RedBlackTree* node1;
    RedBlackTree* node2;
    RedBlackTree* node3;
    RedBlackTree* node4;
    RedBlackTree* node5;
    RedBlackTree* nil;

    nil = malloc(sizeof(RedBlackTree));

    nil->p = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;

    (*root) = nil;

    reg->key = 10;
    node1 = rb_insert(root, nil, *reg);
    reg->key = 5;
    node2 = rb_insert(root, nil, *reg);
    reg->key = 3;
    node3 = rb_insert(root, nil, *reg);
    reg->key = 2;
    node4 = rb_insert(root, nil, *reg);
    reg->key = 1;
    node5 = rb_insert(root, nil, *reg);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 5);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == node5, true);
    ck_assert_int_eq((*root)->left->right == node3, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 10);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->left->data.key, 1);
    ck_assert_int_eq((*root)->left->left->color, RED);
    ck_assert_int_eq((*root)->left->left->left == nil, true);
    ck_assert_int_eq((*root)->left->left->right == nil, true);
    ck_assert_int_eq((*root)->left->left->p == node4, true);
    ck_assert_int_eq((*root)->left->left == node5, true);

    ck_assert_int_eq((*root)->left->right->data.key, 3);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node4, true);
    ck_assert_int_eq((*root)->left->right == node3, true);

    rb_delete(root, nil, node5);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 5);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node1, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node2, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == node3, true);
    ck_assert_int_eq((*root)->left->p == node2, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 10);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node2, true);
    ck_assert_int_eq((*root)->right == node1, true);

    ck_assert_int_eq((*root)->left->right->data.key, 3);
    ck_assert_int_eq((*root)->left->right->color, RED);
    ck_assert_int_eq((*root)->left->right->left == nil, true);
    ck_assert_int_eq((*root)->left->right->right == nil, true);
    ck_assert_int_eq((*root)->left->right->p == node4, true);
    ck_assert_int_eq((*root)->left->right == node3, true);

    rb_delete(root, nil, node1);

    ck_assert_int_eq(root == NULL, false);
    ck_assert_int_eq((*root) == nil, false);

    ck_assert_int_eq((*root)->data.key, 3);
    ck_assert_int_eq((*root)->color, BLACK);
    ck_assert_int_eq((*root)->left == node4, true);
    ck_assert_int_eq((*root)->right == node2, true);
    ck_assert_int_eq((*root)->p == nil, true);
    ck_assert_int_eq((*root) == node3, true);

    ck_assert_int_eq((*root)->left->data.key, 2);
    ck_assert_int_eq((*root)->left->color, BLACK);
    ck_assert_int_eq((*root)->left->left == nil, true);
    ck_assert_int_eq((*root)->left->right == nil, true);
    ck_assert_int_eq((*root)->left->p == node3, true);
    ck_assert_int_eq((*root)->left == node4, true);

    ck_assert_int_eq((*root)->right->data.key, 5);
    ck_assert_int_eq((*root)->right->color, BLACK);
    ck_assert_int_eq((*root)->right->left == nil, true);
    ck_assert_int_eq((*root)->right->right == nil, true);
    ck_assert_int_eq((*root)->right->p == node3, true);
    ck_assert_int_eq((*root)->right == node2, true);

    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(nil);
}
END_TEST

Suite *make_rbt_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Red-Black Tree Test Suite");

    tc_core = tcase_create("Test Cases with Setup and Teardown");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_rbt_left_rotate_1);
    tcase_add_test(tc_core, test_rbt_right_rotate_1);

    tcase_add_test(tc_core, test_rbt_insert_1);
    tcase_add_test(tc_core, test_rbt_insert_2);
    tcase_add_test(tc_core, test_rbt_insert_3);
    tcase_add_test(tc_core, test_rbt_insert_4);
    tcase_add_test(tc_core, test_rbt_insert_5);
    tcase_add_test(tc_core, test_rbt_insert_6);
    tcase_add_test(tc_core, test_rbt_insert_7);
    tcase_add_test(tc_core, test_rbt_insert_8);
    tcase_add_test(tc_core, test_rbt_insert_9);
    tcase_add_test(tc_core, test_rbt_insert_10);
    tcase_add_test(tc_core, test_rbt_insert_11);

    tcase_add_test(tc_core, test_rbt_delete_1);
    tcase_add_test(tc_core, test_rbt_delete_2);
    tcase_add_test(tc_core, test_rbt_delete_3);
    tcase_add_test(tc_core, test_rbt_delete_4);
    tcase_add_test(tc_core, test_rbt_delete_5);
    tcase_add_test(tc_core, test_rbt_delete_6);
    tcase_add_test(tc_core, test_rbt_delete_7);
    tcase_add_test(tc_core, test_rbt_delete_8);
    tcase_add_test(tc_core, test_rbt_delete_9);
    tcase_add_test(tc_core, test_rbt_delete_10);
    tcase_add_test(tc_core, test_rbt_delete_11);
    tcase_add_test(tc_core, test_rbt_delete_12);

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
