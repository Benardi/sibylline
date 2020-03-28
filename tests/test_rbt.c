#include <check.h>
#include <malloc.h>
#include <rbt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
RedBlackTree** root;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);
int compare(void* key1, void* key2);

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

START_TEST(test_rbt_init_rbtree_1)
{
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq(nil->left == nil, true);
  ck_assert_int_eq(nil->right == nil, true);
  ck_assert_int_eq(nil->p == nil, true);
  ck_assert_int_eq(nil->color == BLACK, true);

  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root)->color == BLACK, true);
  ck_assert_int_eq((*root) == nil, true);

  free(nil);
}
END_TEST

START_TEST(test_rbt_left_rotate_1)
{
  int k1, k2, k3, k4, k5;
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

  init_rbtree(root, nil);

  k1 = 5;
  k2 = 15;
  k3 = -2;
  k4 = 10;
  k5 = 23;

  node1->data.key = &k1;
  node2->data.key = &k2;
  node3->data.key = &k3;
  node4->data.key = &k4;
  node5->data.key = &k5;

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

  ck_assert_int_eq(*((int*)node1->data.key), 5);
  ck_assert_int_eq(*((int*)node2->data.key), 15);
  ck_assert_int_eq(*((int*)node3->data.key), -2);
  ck_assert_int_eq(*((int*)node4->data.key), 10);
  ck_assert_int_eq(*((int*)node5->data.key), 23);

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

  ck_assert_int_eq(*((int*)node1->data.key), 5);
  ck_assert_int_eq(*((int*)node2->data.key), 15);
  ck_assert_int_eq(*((int*)node3->data.key), -2);
  ck_assert_int_eq(*((int*)node4->data.key), 10);
  ck_assert_int_eq(*((int*)node5->data.key), 23);

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
  int k1, k2, k3, k4, k5;
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

  init_rbtree(root, nil);

  k1 = 5;
  k2 = 15;
  k3 = -2;
  k4 = 10;
  k5 = 23;

  node1->data.key = &k1;
  node2->data.key = &k2;
  node3->data.key = &k3;
  node4->data.key = &k4;
  node5->data.key = &k5;

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

  ck_assert_int_eq(*((int*)node1->data.key), 5);
  ck_assert_int_eq(*((int*)node2->data.key), 15);
  ck_assert_int_eq(*((int*)node3->data.key), -2);
  ck_assert_int_eq(*((int*)node4->data.key), 10);
  ck_assert_int_eq(*((int*)node5->data.key), 23);

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

  ck_assert_int_eq(*((int*)node1->data.key), 5);
  ck_assert_int_eq(*((int*)node2->data.key), 15);
  ck_assert_int_eq(*((int*)node3->data.key), -2);
  ck_assert_int_eq(*((int*)node4->data.key), 10);
  ck_assert_int_eq(*((int*)node5->data.key), 23);

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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  k1 = 10;
  k2 = 5;
  k3 = 4;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == nil, true);
  ck_assert_int_eq(node1->right == nil, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == nil, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == nil, true);
  ck_assert_int_eq(node2->right == nil, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 5);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, RED);
  ck_assert_int_eq(node1->left == nil, true);
  ck_assert_int_eq(node1->right == nil, true);
  ck_assert_int_eq(node1->p == node2, true);

  ck_assert_int_eq(*((int*)node2->data.key), 5);
  ck_assert_int_eq(node2->color, BLACK);
  ck_assert_int_eq(node2->left == node3, true);
  ck_assert_int_eq(node2->right == node1, true);
  ck_assert_int_eq(node2->p == nil, true);

  ck_assert_int_eq(*((int*)node3->data.key), 4);
  ck_assert_int_eq(node3->color, RED);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == nil, true);
  ck_assert_int_eq(node3->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 5);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node3, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 4);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 10);
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

START_TEST(test_rbt_insert_2)
{
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  k1 = 10;
  k2 = -10;
  k3 = 20;
  k4 = 7;
  k5 = 15;
  k6 = 13;

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

  reg->key = &k1;
  node1->color = BLACK;
  node1->data = *reg;
  node1->left = node2;
  node1->right = node3;
  node1->p = nil;

  reg->key = &k2;
  node2->color = BLACK;
  node2->data = *reg;
  node2->left = nil;
  node2->right = node4;
  node2->p = node1;

  reg->key = &k3;
  node3->color = BLACK;
  node3->data = *reg;
  node3->left = node5;
  node3->right = nil;
  node3->p = node1;

  reg->key = &k4;
  node4->color = RED;
  node4->data = *reg;
  node4->left = nil;
  node4->right = nil;
  node4->p = node2;

  reg->key = &k5;
  node5->color = RED;
  node5->data = *reg;
  node5->left = nil;
  node5->right = nil;
  node5->p = node3;

  (*root) = node1;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, BLACK);
  ck_assert_int_eq(node2->left == nil, true);
  ck_assert_int_eq(node2->right == node4, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == node5, true);
  ck_assert_int_eq(node3->right == nil, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 7);
  ck_assert_int_eq(node4->color, RED);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 15);
  ck_assert_int_eq(node5->color, RED);
  ck_assert_int_eq(node5->left == nil, true);
  ck_assert_int_eq(node5->right == nil, true);
  ck_assert_int_eq(node5->p == node3, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 20);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node5, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node3, true);

  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node5, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 15);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node6, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 13);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node5, true);
  ck_assert_int_eq((*root)->right->left == node6, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 20);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node5, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node5, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, BLACK);
  ck_assert_int_eq(node2->left == nil, true);
  ck_assert_int_eq(node2->right == node4, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, RED);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == nil, true);
  ck_assert_int_eq(node3->p == node5, true);

  ck_assert_int_eq(*((int*)node4->data.key), 7);
  ck_assert_int_eq(node4->color, RED);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 15);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node6, true);
  ck_assert_int_eq(node5->right == node3, true);
  ck_assert_int_eq(node5->p == node1, true);

  ck_assert_int_eq(*((int*)node6->data.key), 13);
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
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  k1 = 10;
  k2 = -10;
  k3 = 20;
  k4 = 7;
  k5 = 15;
  k6 = 17;

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

  reg->key = &k1;
  node1->color = BLACK;
  node1->data = *reg;
  node1->left = node2;
  node1->right = node3;
  node1->p = nil;

  reg->key = &k2;
  node2->color = BLACK;
  node2->data = *reg;
  node2->left = nil;
  node2->right = node4;
  node2->p = node1;

  reg->key = &k3;
  node3->color = BLACK;
  node3->data = *reg;
  node3->left = node5;
  node3->right = nil;
  node3->p = node1;

  reg->key = &k4;
  node4->color = RED;
  node4->data = *reg;
  node4->left = nil;
  node4->right = nil;
  node4->p = node2;

  reg->key = &k5;
  node5->color = RED;
  node5->data = *reg;
  node5->left = nil;
  node5->right = nil;
  node5->p = node3;

  (*root) = node1;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, BLACK);
  ck_assert_int_eq(node2->left == nil, true);
  ck_assert_int_eq(node2->right == node4, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == node5, true);
  ck_assert_int_eq(node3->right == nil, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 7);
  ck_assert_int_eq(node4->color, RED);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 15);
  ck_assert_int_eq(node5->color, RED);
  ck_assert_int_eq(node5->left == nil, true);
  ck_assert_int_eq(node5->right == nil, true);
  ck_assert_int_eq(node5->p == node3, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 20);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node5, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node3, true);

  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node6, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 17);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node5, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node6, true);
  ck_assert_int_eq((*root)->right->left == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 20);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node6, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node6, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, BLACK);
  ck_assert_int_eq(node2->left == nil, true);
  ck_assert_int_eq(node2->right == node4, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, RED);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == nil, true);
  ck_assert_int_eq(node3->p == node6, true);

  ck_assert_int_eq(*((int*)node4->data.key), 7);
  ck_assert_int_eq(node4->color, RED);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 15);
  ck_assert_int_eq(node5->color, RED);
  ck_assert_int_eq(node5->left == nil, true);
  ck_assert_int_eq(node5->right == nil, true);
  ck_assert_int_eq(node5->p == node6, true);

  ck_assert_int_eq(*((int*)node6->data.key), 17);
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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
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

  k1 = 10;
  k2 = -10;
  k3 = 20;
  k4 = -20;
  k5 = 6;
  k6 = 15;
  k7 = 30;
  k8 = 1;
  k9 = 9;
  k10 = 4;

  reg->key = &k1;
  node1->data = *reg;
  node1->color = BLACK;
  node1->left = node2;
  node1->right = node3;
  node1->p = nil;

  reg->key = &k2;
  node2->data = *reg;
  node2->color = RED;
  node2->left = node4;
  node2->right = node5;
  node2->p = node1;

  reg->key = &k3;
  node3->data = *reg;
  node3->color = BLACK;
  node3->left = node6;
  node3->right = node7;
  node3->p = node1;

  reg->key = &k4;
  node4->data = *reg;
  node4->color = BLACK;
  node4->left = nil;
  node4->right = nil;
  node4->p = node2;

  reg->key = &k5;
  node5->data = *reg;
  node5->color = BLACK;
  node5->left = node8;
  node5->right = node9;
  node5->p = node2;

  reg->key = &k6;
  node6->data = *reg;
  node6->color = RED;
  node6->left = nil;
  node6->right = nil;
  node6->p = node3;

  reg->key = &k7;
  node7->data = *reg;
  node7->color = RED;
  node7->left = nil;
  node7->right = nil;
  node7->p = node3;

  reg->key = &k8;
  node8->data = *reg;
  node8->color = RED;
  node8->left = nil;
  node8->right = nil;
  node8->p = node5;

  reg->key = &k9;
  node9->data = *reg;
  node9->color = RED;
  node9->left = nil;
  node9->right = nil;
  node9->p = node5;

  (*root) = node1;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node5, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == node6, true);
  ck_assert_int_eq(node3->right == node7, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), -20);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 6);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node8, true);
  ck_assert_int_eq(node5->right == node9, true);
  ck_assert_int_eq(node5->p == node2, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 30);
  ck_assert_int_eq(node7->color, RED);
  ck_assert_int_eq(node7->left == nil, true);
  ck_assert_int_eq(node7->right == nil, true);
  ck_assert_int_eq(node7->p == node3, true);

  ck_assert_int_eq(*((int*)node8->data.key), 1);
  ck_assert_int_eq(node8->color, RED);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == nil, true);
  ck_assert_int_eq(node8->p == node5, true);

  ck_assert_int_eq(*((int*)node9->data.key), 9);
  ck_assert_int_eq(node9->color, RED);
  ck_assert_int_eq(node9->left == nil, true);
  ck_assert_int_eq(node9->right == nil, true);
  ck_assert_int_eq(node9->p == node5, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node5, true);
  ck_assert_int_eq((*root)->left->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 20);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node6, true);
  ck_assert_int_eq((*root)->right->right == node7, true);
  ck_assert_int_eq((*root)->right->p == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), -20);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 6);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == node8, true);
  ck_assert_int_eq((*root)->left->right->right == node9, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 30);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->left->data.key), 1);
  ck_assert_int_eq((*root)->left->right->left->color, RED);
  ck_assert_int_eq((*root)->left->right->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right->left->right == nil, true);
  ck_assert_int_eq((*root)->left->right->left->p == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->right->data.key), 9);
  ck_assert_int_eq((*root)->left->right->right->color, RED);
  ck_assert_int_eq((*root)->left->right->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->right->p == node5, true);

  reg->key = &k10;
  node10 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(*((int*)(*root)->data.key), 6);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node8, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 10);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == node9, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), -20);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 1);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == node10, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node8, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 9);
  ck_assert_int_eq((*root)->right->left->color, BLACK);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node1, true);
  ck_assert_int_eq((*root)->right->left == node9, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 20);
  ck_assert_int_eq((*root)->right->right->color, BLACK);
  ck_assert_int_eq((*root)->right->right->left == node6, true);
  ck_assert_int_eq((*root)->right->right->right == node7, true);
  ck_assert_int_eq((*root)->right->right->p == node1, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->right->left->color, RED);
  ck_assert_int_eq((*root)->right->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->right->left->p == node3, true);
  ck_assert_int_eq((*root)->right->right->left == node6, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->right->data.key), 30);
  ck_assert_int_eq((*root)->right->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->right->p == node3, true);
  ck_assert_int_eq((*root)->right->right->right == node7, true);

  ck_assert_int_eq(*((int*)node5->data.key), 6);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node2, true);
  ck_assert_int_eq(node5->right == node1, true);
  ck_assert_int_eq(node5->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), -10);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node8, true);
  ck_assert_int_eq(node2->p == node5, true);

  ck_assert_int_eq(*((int*)node1->data.key), 10);
  ck_assert_int_eq(node1->color, RED);
  ck_assert_int_eq(node1->left == node9, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == node5, true);

  ck_assert_int_eq(*((int*)node4->data.key), -20);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node8->data.key), 1);
  ck_assert_int_eq(node8->color, BLACK);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == node10, true);
  ck_assert_int_eq(node8->p == node2, true);

  ck_assert_int_eq(*((int*)node9->data.key), 9);
  ck_assert_int_eq(node9->color, BLACK);
  ck_assert_int_eq(node9->left == nil, true);
  ck_assert_int_eq(node9->right == nil, true);
  ck_assert_int_eq(node9->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 20);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == node6, true);
  ck_assert_int_eq(node3->right == node7, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 30);
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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
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

  k1 = 11;
  k2 = 2;
  k3 = 14;
  k4 = 1;
  k5 = 7;
  k6 = 15;
  k7 = 5;
  k8 = 8;
  k9 = 4;

  reg->key = &k1;
  node1->data = *reg;
  node1->color = BLACK;
  node1->left = node2;
  node1->right = node3;
  node1->p = nil;

  reg->key = &k2;
  node2->data = *reg;
  node2->color = RED;
  node2->left = node4;
  node2->right = node5;
  node2->p = node1;

  reg->key = &k3;
  node3->data = *reg;
  node3->color = BLACK;
  node3->left = nil;
  node3->right = node6;
  node3->p = node1;

  reg->key = &k4;
  node4->data = *reg;
  node4->color = BLACK;
  node4->left = nil;
  node4->right = nil;
  node4->p = node2;

  reg->key = &k5;
  node5->data = *reg;
  node5->color = BLACK;
  node5->left = node7;
  node5->right = node8;
  node5->p = node2;

  reg->key = &k6;
  node6->data = *reg;
  node6->color = RED;
  node6->left = nil;
  node6->right = nil;
  node6->p = node3;

  reg->key = &k7;
  node7->data = *reg;
  node7->color = RED;
  node7->left = nil;
  node7->right = nil;
  node7->p = node5;

  reg->key = &k8;
  node8->data = *reg;
  node8->color = RED;
  node8->left = nil;
  node8->right = nil;
  node8->p = node5;

  (*root) = node1;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 11);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), 2);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node5, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 14);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == node6, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 1);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 7);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node7, true);
  ck_assert_int_eq(node5->right == node8, true);
  ck_assert_int_eq(node5->p == node2, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 5);
  ck_assert_int_eq(node7->color, RED);
  ck_assert_int_eq(node7->left == nil, true);
  ck_assert_int_eq(node7->right == nil, true);
  ck_assert_int_eq(node7->p == node5, true);

  ck_assert_int_eq(*((int*)node8->data.key), 8);
  ck_assert_int_eq(node8->color, RED);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == nil, true);
  ck_assert_int_eq(node8->p == node5, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 11);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node5, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 14);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == node6, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 1);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == node7, true);
  ck_assert_int_eq((*root)->left->right->right == node8, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 15);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node3, true);
  ck_assert_int_eq((*root)->right->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->left->data.key), 5);
  ck_assert_int_eq((*root)->left->right->left->color, RED);
  ck_assert_int_eq((*root)->left->right->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right->left->right == nil, true);
  ck_assert_int_eq((*root)->left->right->left->p == node5, true);
  ck_assert_int_eq((*root)->left->right->left == node7, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->right->data.key), 8);
  ck_assert_int_eq((*root)->left->right->right->color, RED);
  ck_assert_int_eq((*root)->left->right->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->right->p == node5, true);
  ck_assert_int_eq((*root)->left->right->right == node8, true);

  reg->key = &k9;
  node9 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(*((int*)(*root)->data.key), 7);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node7, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 11);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == node8, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 1);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 5);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == node9, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node7, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 8);
  ck_assert_int_eq((*root)->right->left->color, BLACK);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node1, true);
  ck_assert_int_eq((*root)->right->left == node8, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 14);
  ck_assert_int_eq((*root)->right->right->color, BLACK);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);
  ck_assert_int_eq((*root)->right->right->p == node1, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->left->data.key), 4);
  ck_assert_int_eq((*root)->left->right->left->color, RED);
  ck_assert_int_eq((*root)->left->right->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right->left->right == nil, true);
  ck_assert_int_eq((*root)->left->right->left->p == node7, true);
  ck_assert_int_eq((*root)->left->right->left == node9, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->right->data.key), 15);
  ck_assert_int_eq((*root)->right->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->right->p == node3, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);

  ck_assert_int_eq(*((int*)node1->data.key), 11);
  ck_assert_int_eq(node1->color, RED);
  ck_assert_int_eq(node1->left == node8, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == node5, true);

  ck_assert_int_eq(*((int*)node2->data.key), 2);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node7, true);
  ck_assert_int_eq(node2->p == node5, true);

  ck_assert_int_eq(*((int*)node3->data.key), 14);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == node6, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 1);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 7);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node2, true);
  ck_assert_int_eq(node5->right == node1, true);
  ck_assert_int_eq(node5->p == nil, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 5);
  ck_assert_int_eq(node7->color, BLACK);
  ck_assert_int_eq(node7->left == node9, true);
  ck_assert_int_eq(node7->right == nil, true);
  ck_assert_int_eq(node7->p == node2, true);

  ck_assert_int_eq(*((int*)node8->data.key), 8);
  ck_assert_int_eq(node8->color, BLACK);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == nil, true);
  ck_assert_int_eq(node8->p == node1, true);

  ck_assert_int_eq(*((int*)node9->data.key), 4);
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
  int k1, k2, k3, k4, k5, k6, k7, k8, k9;
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

  k1 = 11;
  k2 = 2;
  k3 = 14;
  k4 = 1;
  k5 = 7;
  k6 = 15;
  k7 = 5;
  k8 = 8;
  k9 = 9;

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

  reg->key = &k1;
  node1->data = *reg;
  node1->color = BLACK;
  node1->left = node2;
  node1->right = node3;
  node1->p = nil;

  reg->key = &k2;
  node2->data = *reg;
  node2->color = RED;
  node2->left = node4;
  node2->right = node5;
  node2->p = node1;

  reg->key = &k3;
  node3->data = *reg;
  node3->color = BLACK;
  node3->left = nil;
  node3->right = node6;
  node3->p = node1;

  reg->key = &k4;
  node4->data = *reg;
  node4->color = BLACK;
  node4->left = nil;
  node4->right = nil;
  node4->p = node2;

  reg->key = &k5;
  node5->data = *reg;
  node5->color = BLACK;
  node5->left = node7;
  node5->right = node8;
  node5->p = node2;

  reg->key = &k6;
  node6->data = *reg;
  node6->color = RED;
  node6->left = nil;
  node6->right = nil;
  node6->p = node3;

  reg->key = &k7;
  node7->data = *reg;
  node7->color = RED;
  node7->left = nil;
  node7->right = nil;
  node7->p = node5;

  reg->key = &k8;
  node8->data = *reg;
  node8->color = RED;
  node8->left = nil;
  node8->right = nil;
  node8->p = node5;

  (*root) = node1;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)node1->data.key), 11);
  ck_assert_int_eq(node1->color, BLACK);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == nil, true);

  ck_assert_int_eq(*((int*)node2->data.key), 2);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node5, true);
  ck_assert_int_eq(node2->p == node1, true);

  ck_assert_int_eq(*((int*)node3->data.key), 14);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == node6, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 1);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 7);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node7, true);
  ck_assert_int_eq(node5->right == node8, true);
  ck_assert_int_eq(node5->p == node2, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 5);
  ck_assert_int_eq(node7->color, RED);
  ck_assert_int_eq(node7->left == nil, true);
  ck_assert_int_eq(node7->right == nil, true);
  ck_assert_int_eq(node7->p == node5, true);

  ck_assert_int_eq(*((int*)node8->data.key), 8);
  ck_assert_int_eq(node8->color, RED);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == nil, true);
  ck_assert_int_eq(node8->p == node5, true);

  ck_assert_int_eq(*((int*)(*root)->data.key), 11);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node5, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 14);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == node6, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 1);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == node7, true);
  ck_assert_int_eq((*root)->left->right->right == node8, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 15);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node3, true);
  ck_assert_int_eq((*root)->right->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->left->data.key), 5);
  ck_assert_int_eq((*root)->left->right->left->color, RED);
  ck_assert_int_eq((*root)->left->right->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right->left->right == nil, true);
  ck_assert_int_eq((*root)->left->right->left->p == node5, true);
  ck_assert_int_eq((*root)->left->right->left == node7, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->right->data.key), 8);
  ck_assert_int_eq((*root)->left->right->right->color, RED);
  ck_assert_int_eq((*root)->left->right->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->right->p == node5, true);
  ck_assert_int_eq((*root)->left->right->right == node8, true);

  reg->key = &k9;
  node9 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(*((int*)(*root)->data.key), 7);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node7, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 11);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == node8, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 1);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 5);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node7, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 8);
  ck_assert_int_eq((*root)->right->left->color, BLACK);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == node9, true);
  ck_assert_int_eq((*root)->right->left->p == node1, true);
  ck_assert_int_eq((*root)->right->left == node8, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 14);
  ck_assert_int_eq((*root)->right->right->color, BLACK);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);
  ck_assert_int_eq((*root)->right->right->p == node1, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->right->data.key), 15);
  ck_assert_int_eq((*root)->right->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->right->p == node3, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->right->data.key), 9);
  ck_assert_int_eq((*root)->right->left->right->color, RED);
  ck_assert_int_eq((*root)->right->left->right->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right->right == nil, true);
  ck_assert_int_eq((*root)->right->left->right->p == node8, true);
  ck_assert_int_eq((*root)->right->left->right == node9, true);

  ck_assert_int_eq(*((int*)node1->data.key), 11);
  ck_assert_int_eq(node1->color, RED);
  ck_assert_int_eq(node1->left == node8, true);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->p == node5, true);

  ck_assert_int_eq(*((int*)node2->data.key), 2);
  ck_assert_int_eq(node2->color, RED);
  ck_assert_int_eq(node2->left == node4, true);
  ck_assert_int_eq(node2->right == node7, true);
  ck_assert_int_eq(node2->p == node5, true);

  ck_assert_int_eq(*((int*)node3->data.key), 14);
  ck_assert_int_eq(node3->color, BLACK);
  ck_assert_int_eq(node3->left == nil, true);
  ck_assert_int_eq(node3->right == node6, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(*((int*)node4->data.key), 1);
  ck_assert_int_eq(node4->color, BLACK);
  ck_assert_int_eq(node4->left == nil, true);
  ck_assert_int_eq(node4->right == nil, true);
  ck_assert_int_eq(node4->p == node2, true);

  ck_assert_int_eq(*((int*)node5->data.key), 7);
  ck_assert_int_eq(node5->color, BLACK);
  ck_assert_int_eq(node5->left == node2, true);
  ck_assert_int_eq(node5->right == node1, true);
  ck_assert_int_eq(node5->p == nil, true);

  ck_assert_int_eq(*((int*)node6->data.key), 15);
  ck_assert_int_eq(node6->color, RED);
  ck_assert_int_eq(node6->left == nil, true);
  ck_assert_int_eq(node6->right == nil, true);
  ck_assert_int_eq(node6->p == node3, true);

  ck_assert_int_eq(*((int*)node7->data.key), 5);
  ck_assert_int_eq(node7->color, BLACK);
  ck_assert_int_eq(node7->left == nil, true);
  ck_assert_int_eq(node7->right == nil, true);
  ck_assert_int_eq(node7->p == node2, true);

  ck_assert_int_eq(*((int*)node8->data.key), 8);
  ck_assert_int_eq(node8->color, BLACK);
  ck_assert_int_eq(node8->left == nil, true);
  ck_assert_int_eq(node8->right == node9, true);
  ck_assert_int_eq(node8->p == node1, true);

  ck_assert_int_eq(*((int*)node9->data.key), 9);
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
  int k1, k2, k3, k4;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;

  RedBlackTree* nil;

  k1 = 10;
  k2 = 20;
  k3 = 30;
  k4 = 15;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 20);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);

  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 15);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  k1 = 50;
  k2 = 25;
  k3 = 10;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 50);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 50);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 25);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 25);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node3, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 50);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  k1 = 30;
  k2 = 15;
  k3 = 20;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 30);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 30);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 15);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 15);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node3, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  k1 = 12;
  k2 = 18;
  k3 = 24;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 12);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 12);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 18);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node2, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 18);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 12);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 24);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  k1 = -8;
  k2 = 15;
  k3 = 6;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), -8);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), -8);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 15);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node2, true);

  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 6);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -8);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node3, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 15);
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
  int k1;
  RedBlackTree* node1;
  RedBlackTree* nil;

  k1 = 50;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 50);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  k1 = 50;
  k2 = 25;
  k3 = 10;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 25);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node3, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 50);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  rb_delete(root, nil, node3);

  ck_assert_int_eq(*((int*)(*root)->data.key), 25);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == nil, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 50);
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
  int k1, k2, k3;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  k1 = 50;
  k2 = 25;
  k3 = 10;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 25);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node3, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 50);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 25);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node3, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
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
  int k1, k2, k3, k4;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  k1 = 10;
  k2 = 20;
  k3 = 30;
  k4 = 15;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 15);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node1, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 15);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
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
  int k1, k2, k3, k4;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  k1 = 10;
  k2 = 20;
  k3 = 30;
  k4 = 15;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 15);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node1, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  rb_delete(root, nil, node3);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 15);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node4, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 20);
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
  int k1, k2, k3, k4;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, true);

  k1 = 10;
  k2 = 20;
  k3 = 30;
  k4 = 5;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 5);
  ck_assert_int_eq((*root)->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node1, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 20);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 5);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 30);
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
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 10;
  k2 = -10;
  k3 = 20;
  k4 = 7;
  k5 = 15;
  k6 = 17;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);
  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 10);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node6, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 17);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node5, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 15);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node6, true);
  ck_assert_int_eq((*root)->right->left == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 20);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node6, true);
  ck_assert_int_eq((*root)->right->right == node3, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 15);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node6, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), -10);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node4, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 17);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == node3, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 7);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 20);
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
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 6;
  k2 = 4;
  k3 = 8;
  k4 = 2;
  k5 = 5;
  k6 = 7;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);
  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 6);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node3, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 4);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node5, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 8);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node6, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 2);
  ck_assert_int_eq((*root)->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 5);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 7);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node3, true);
  ck_assert_int_eq((*root)->right->left == node6, true);

  rb_delete(root, nil, node3);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 6);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node6, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 4);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node5, true);
  ck_assert_int_eq((*root)->left->p == node1, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 7);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node1, true);
  ck_assert_int_eq((*root)->right == node6, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 2);
  ck_assert_int_eq((*root)->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node2, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 5);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node5, true);

  rb_delete(root, nil, node6);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 4);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 6);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node5, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 5);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node1, true);
  ck_assert_int_eq((*root)->right->left == node5, true);

  rb_delete(root, nil, node2);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 5);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 6);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node1, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 5);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == nil, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
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
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 50;
  k2 = 75;
  k3 = 100;
  k4 = 200;
  k5 = 150;
  k6 = 400;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);
  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 75);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node5, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 50);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 150);
  ck_assert_int_eq((*root)->right->color, RED);
  ck_assert_int_eq((*root)->right->left == node3, true);
  ck_assert_int_eq((*root)->right->right == node4, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 100);
  ck_assert_int_eq((*root)->right->left->color, BLACK);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node5, true);
  ck_assert_int_eq((*root)->right->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 200);
  ck_assert_int_eq((*root)->right->right->color, BLACK);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);
  ck_assert_int_eq((*root)->right->right->p == node5, true);
  ck_assert_int_eq((*root)->right->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->right->data.key), 400);
  ck_assert_int_eq((*root)->right->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->right->p == node4, true);
  ck_assert_int_eq((*root)->right->right->right == node6, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 150);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node4, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 75);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node3, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 200);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == node6, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 100);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node2, true);
  ck_assert_int_eq((*root)->left->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 400);
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
  int k1, k2, k3, k4, k5;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 1;
  k2 = 2;
  k3 = 3;
  k4 = 5;
  k5 = 10;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 2);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node4, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 1);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 5);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node3, true);
  ck_assert_int_eq((*root)->right->right == node5, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 3);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node4, true);
  ck_assert_int_eq((*root)->right->left == node3, true);

  ck_assert_int_eq(*((int*)(*root)->right->right->data.key), 10);
  ck_assert_int_eq((*root)->right->right->color, RED);
  ck_assert_int_eq((*root)->right->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right->right == nil, true);
  ck_assert_int_eq((*root)->right->right->p == node4, true);
  ck_assert_int_eq((*root)->right->right == node5, true);

  rb_delete(root, nil, node5);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 2);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node1, true);
  ck_assert_int_eq((*root)->right == node4, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 1);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node1, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 5);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node3, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 3);
  ck_assert_int_eq((*root)->right->left->color, RED);
  ck_assert_int_eq((*root)->right->left->left == nil, true);
  ck_assert_int_eq((*root)->right->left->right == nil, true);
  ck_assert_int_eq((*root)->right->left->p == node4, true);
  ck_assert_int_eq((*root)->right->left == node3, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 3);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node2, true);
  ck_assert_int_eq((*root)->right == node4, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node3, true);
  ck_assert_int_eq((*root)->left == node2, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 5);
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
  int k1, k2, k3, k4, k5, k6;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* node6;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 500;
  k2 = 475;
  k3 = 450;
  k4 = 400;
  k5 = 425;
  k6 = 200;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);
  reg->key = &k6;
  node6 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 475);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node5, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 425);
  ck_assert_int_eq((*root)->left->color, RED);
  ck_assert_int_eq((*root)->left->left == node4, true);
  ck_assert_int_eq((*root)->left->right == node3, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node5, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 500);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 400);
  ck_assert_int_eq((*root)->left->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left->left == node6, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node5, true);
  ck_assert_int_eq((*root)->left->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 450);
  ck_assert_int_eq((*root)->left->right->color, BLACK);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node5, true);
  ck_assert_int_eq((*root)->left->right == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->left->data.key), 200);
  ck_assert_int_eq((*root)->left->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->left->p == node4, true);
  ck_assert_int_eq((*root)->left->left->left == node6, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 425);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 400);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == node6, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node5, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 475);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == node3, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node5, true);
  ck_assert_int_eq((*root)->right == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 200);
  ck_assert_int_eq((*root)->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node4, true);
  ck_assert_int_eq((*root)->left->left == node6, true);

  ck_assert_int_eq(*((int*)(*root)->right->left->data.key), 450);
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
  int k1, k2, k3, k4, k5;
  RedBlackTree* node1;
  RedBlackTree* node2;
  RedBlackTree* node3;
  RedBlackTree* node4;
  RedBlackTree* node5;
  RedBlackTree* nil;

  nil = malloc(sizeof(RedBlackTree));

  init_rbtree(root, nil);

  k1 = 10;
  k2 = 5;
  k3 = 3;
  k4 = 2;
  k5 = 1;

  reg->key = &k1;
  node1 = rb_insert(root, nil, *reg, compare);
  reg->key = &k2;
  node2 = rb_insert(root, nil, *reg, compare);
  reg->key = &k3;
  node3 = rb_insert(root, nil, *reg, compare);
  reg->key = &k4;
  node4 = rb_insert(root, nil, *reg, compare);
  reg->key = &k5;
  node5 = rb_insert(root, nil, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 5);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == node5, true);
  ck_assert_int_eq((*root)->left->right == node3, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 10);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->left->data.key), 1);
  ck_assert_int_eq((*root)->left->left->color, RED);
  ck_assert_int_eq((*root)->left->left->left == nil, true);
  ck_assert_int_eq((*root)->left->left->right == nil, true);
  ck_assert_int_eq((*root)->left->left->p == node4, true);
  ck_assert_int_eq((*root)->left->left == node5, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 3);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node4, true);
  ck_assert_int_eq((*root)->left->right == node3, true);

  rb_delete(root, nil, node5);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 5);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node1, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node2, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == node3, true);
  ck_assert_int_eq((*root)->left->p == node2, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 10);
  ck_assert_int_eq((*root)->right->color, BLACK);
  ck_assert_int_eq((*root)->right->left == nil, true);
  ck_assert_int_eq((*root)->right->right == nil, true);
  ck_assert_int_eq((*root)->right->p == node2, true);
  ck_assert_int_eq((*root)->right == node1, true);

  ck_assert_int_eq(*((int*)(*root)->left->right->data.key), 3);
  ck_assert_int_eq((*root)->left->right->color, RED);
  ck_assert_int_eq((*root)->left->right->left == nil, true);
  ck_assert_int_eq((*root)->left->right->right == nil, true);
  ck_assert_int_eq((*root)->left->right->p == node4, true);
  ck_assert_int_eq((*root)->left->right == node3, true);

  rb_delete(root, nil, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == nil, false);

  ck_assert_int_eq(*((int*)(*root)->data.key), 3);
  ck_assert_int_eq((*root)->color, BLACK);
  ck_assert_int_eq((*root)->left == node4, true);
  ck_assert_int_eq((*root)->right == node2, true);
  ck_assert_int_eq((*root)->p == nil, true);
  ck_assert_int_eq((*root) == node3, true);

  ck_assert_int_eq(*((int*)(*root)->left->data.key), 2);
  ck_assert_int_eq((*root)->left->color, BLACK);
  ck_assert_int_eq((*root)->left->left == nil, true);
  ck_assert_int_eq((*root)->left->right == nil, true);
  ck_assert_int_eq((*root)->left->p == node3, true);
  ck_assert_int_eq((*root)->left == node4, true);

  ck_assert_int_eq(*((int*)(*root)->right->data.key), 5);
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

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Red-Black Tree Test Suite");

  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_rbt_init_rbtree_1);

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
