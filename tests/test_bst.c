#include <bst.h>
#include <check.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

Register* reg;
BinarySearchTree** root;

void setup(void);
void teardown(void);
Suite* make_test_suite(void);

static int compare(union Key k1, union Key k2)
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

void setup(void)
{
  reg = malloc(sizeof(Register));
  root = malloc(sizeof(BinarySearchTree*));
}

void teardown(void)
{
  free(reg);
  free(root);
}

START_TEST(test_bst_insert_1)
{
  union Key k;
  BinarySearchTree* node1;

  (*root) = NULL;

  k.i = 10;
  reg->key = k;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  free(node1);
}
END_TEST

START_TEST(test_bst_insert_2)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 10);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_3)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_4)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;
  k3.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_5)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_6)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_7)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_8)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_9)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_10)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_insert_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_1)
{
  union Key k;
  BinarySearchTree* min;

  (*root) = NULL;

  k.i = 10;
  reg->key = k;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, true);

  free(min);
}
END_TEST

START_TEST(test_bst_tree_minimum_2)
{
  union Key k;
  BinarySearchTree* node1;
  BinarySearchTree* min;

  (*root) = NULL;

  k.i = 10;
  reg->key = k;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, true);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, 10);
  ck_assert_int_eq(min == node1, true);
  ck_assert_int_eq(min == (*root), true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_3)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, false);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, 0);
  ck_assert_int_eq(min == node5, true);
  ck_assert_int_eq(min == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_4)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, false);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, -7);
  ck_assert_int_eq(min == node5, true);
  ck_assert_int_eq(min == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_5)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;
  k3.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, true);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, false);
  ck_assert_int_eq(min->data.key.i, 5);
  ck_assert_int_eq(min == node1, true);
  ck_assert_int_eq(min == (*root), true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_6)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, false);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, 0);
  ck_assert_int_eq(min == node4, true);
  ck_assert_int_eq(min == (*root), false);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_7)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, false);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, 2);
  ck_assert_int_eq(min == node3, true);
  ck_assert_int_eq(min == (*root), false);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_8)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, true);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, false);
  ck_assert_int_eq(min->data.key.i, -5);
  ck_assert_int_eq(min == node1, true);
  ck_assert_int_eq(min == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_minimum_9)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* min;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  min = tree_minimum(*root);

  ck_assert_int_eq(min == NULL, false);
  ck_assert_int_eq(min->p == NULL, false);
  ck_assert_int_eq(min->left == NULL, true);
  ck_assert_int_eq(min->right == NULL, true);
  ck_assert_int_eq(min->data.key.i, -30);
  ck_assert_int_eq(min == node7, true);
  ck_assert_int_eq(min == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_1)
{
  BinarySearchTree* max;

  (*root) = NULL;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, true);

  free(max);
}
END_TEST

START_TEST(test_bst_tree_maximum_2)
{
  union Key k1;
  BinarySearchTree* node1;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, true);
  ck_assert_int_eq(max->left == NULL, true);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 10);
  ck_assert_int_eq(max == node1, true);
  ck_assert_int_eq(max == (*root), true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_3)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, false);
  ck_assert_int_eq(max->left == NULL, true);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 12);
  ck_assert_int_eq(max == node4, true);
  ck_assert_int_eq(max == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_4)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, false);
  ck_assert_int_eq(max->left == NULL, false);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 15);
  ck_assert_int_eq(max == node3, true);
  ck_assert_int_eq(max == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_5)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;
  k3.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, false);
  ck_assert_int_eq(max->left == NULL, true);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 15);
  ck_assert_int_eq(max == node3, true);
  ck_assert_int_eq(max == (*root), false);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_6)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, true);
  ck_assert_int_eq(max->left == NULL, false);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 12);
  ck_assert_int_eq(max == node1, true);
  ck_assert_int_eq(max == (*root), true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_7)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, false);
  ck_assert_int_eq(max->left == NULL, true);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 19);
  ck_assert_int_eq(max == node6, true);
  ck_assert_int_eq(max == (*root), false);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_8)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, false);
  ck_assert_int_eq(max->left == NULL, true);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 150);
  ck_assert_int_eq(max == node7, true);
  ck_assert_int_eq(max == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_maximum_9)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* max;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  max = tree_maximum(*root);

  ck_assert_int_eq(max == NULL, false);
  ck_assert_int_eq(max->p == NULL, true);
  ck_assert_int_eq(max->left == NULL, false);
  ck_assert_int_eq(max->right == NULL, true);
  ck_assert_int_eq(max->data.key.i, 100);
  ck_assert_int_eq(max == node1, true);
  ck_assert_int_eq(max == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_1)
{
  union Key k;
  BinarySearchTree* node1;

  (*root) = NULL;

  k.i = 10;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  node1 = tree_search(*root, k, compare);

  ck_assert_int_eq(node1 == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_2)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 10;
  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_3)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_4)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 9;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_5)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -20;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_6)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_7)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 5);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_8)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_9)
{
  union Key k1, k2, k3, k4;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;
  k4.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  retrieved = tree_search(*root, k4, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 15);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_10)
{
  union Key k1, k2, k3, k4;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;
  k4.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  retrieved = tree_search(*root, k4, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node3, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 5);
  ck_assert_int_eq(retrieved == node7, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_12)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 12;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 12);
  ck_assert_int_eq(retrieved == node4, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_13)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, -7);
  ck_assert_int_eq(retrieved == node5, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_14)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 4;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 4);
  ck_assert_int_eq(retrieved == node6, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_15)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 15);
  ck_assert_int_eq(retrieved == node3, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_16)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -3);
  ck_assert_int_eq(retrieved == node2, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_17)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_18)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_19)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 17;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_20)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 2;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_21)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_22)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -12;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_23)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = tree_search(*root, k7, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 3);
  ck_assert_int_eq(retrieved == node6, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_24)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 4;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = tree_search(*root, k7, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_25)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = -5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -5);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_26)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = 25;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 25);
  ck_assert_int_eq(retrieved == node4, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_27)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 150);
  ck_assert_int_eq(retrieved == node7, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_28)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = 100;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 100);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_29)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = 40;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 40);
  ck_assert_int_eq(retrieved == node4, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_30)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, -30);
  ck_assert_int_eq(retrieved == node7, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_search_31)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 9;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = tree_search(node3, k7, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_1)
{
  union Key key;
  BinarySearchTree* node1;

  (*root) = NULL;
  key.i = 10;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  node1 = iterative_tree_search(*root, key, compare);

  ck_assert_int_eq(node1 == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_2)
{
  union Key key;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  key.i = 10;
  reg->key = key;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = iterative_tree_search(*root, key, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_3)
{
  union Key k;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k.i = 10;
  key = k;
  reg->key = k;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = iterative_tree_search(*root, key, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_4)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 9;
  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = iterative_tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_5)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -20;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  retrieved = iterative_tree_search(*root, k2, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_6)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_7)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 5);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_8)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k3, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_9)
{
  union Key k1, k2, k3, k4;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;
  k4.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  retrieved = iterative_tree_search(*root, k4, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 15);
  ck_assert_int_eq(retrieved == node2, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_10)
{
  union Key k1, k2, k3, k4;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;
  k4.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  retrieved = iterative_tree_search(*root, k4, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node3, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 5;
  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 5);
  ck_assert_int_eq(retrieved == node7, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_12)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 12;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 12);
  ck_assert_int_eq(retrieved == node4, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_13)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, -7);
  ck_assert_int_eq(retrieved == node5, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_14)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 4;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 4);
  ck_assert_int_eq(retrieved == node6, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_15)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 15);
  ck_assert_int_eq(retrieved == node3, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_16)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -3);
  ck_assert_int_eq(retrieved == node2, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_17)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 10);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_18)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_19)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 17;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_20)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 2;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_21)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = 7;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_22)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;
  k8.i = -12;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_23)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = iterative_tree_search(*root, k7, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 3);
  ck_assert_int_eq(retrieved == node6, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_24)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 4;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = iterative_tree_search(*root, k7, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_25)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = -5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, -5);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_26)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = 25;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, false);
  ck_assert_int_eq(retrieved->data.key.i, 25);
  ck_assert_int_eq(retrieved == node4, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_27)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;
  k8.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 150);
  ck_assert_int_eq(retrieved == node7, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_28)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = 100;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, true);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 100);
  ck_assert_int_eq(retrieved == node1, true);
  ck_assert_int_eq(retrieved == (*root), true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_29)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = 40;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, false);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, 40);
  ck_assert_int_eq(retrieved == node4, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_30)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;
  k8.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  retrieved = iterative_tree_search(*root, k8, compare);

  ck_assert_int_eq(retrieved->p == NULL, false);
  ck_assert_int_eq(retrieved->left == NULL, true);
  ck_assert_int_eq(retrieved->right == NULL, true);
  ck_assert_int_eq(retrieved->data.key.i, -30);
  ck_assert_int_eq(retrieved == node7, true);
  ck_assert_int_eq(retrieved == (*root), false);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_iterative_tree_search_31)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* retrieved;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;
  k7.i = 9;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  retrieved = iterative_tree_search(node3, k7, compare);

  ck_assert_int_eq(retrieved == NULL, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_1)
{
  BinarySearchTree* scsr;

  (*root) = NULL;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  scsr = tree_successor(*root);

  ck_assert_int_eq(scsr == NULL, true);
}
END_TEST

START_TEST(test_bst_tree_successor_2)
{
  union Key k;
  BinarySearchTree* node1;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k.i = 10;
  reg->key = k;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  scsr = tree_successor(*root);

  ck_assert_int_eq(scsr == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_3)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 10);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, true);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 10);
  ck_assert_int_eq(scsr == node2, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_4)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 10);

  scsr = tree_successor(node2);

  ck_assert_int_eq(scsr == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_5)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_6)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  scsr = tree_successor(node2);

  ck_assert_int_eq(scsr->p == NULL, true);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 10);
  ck_assert_int_eq(scsr == node1, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_7)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, true);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 10);
  ck_assert_int_eq(scsr == node3, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_8)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  scsr = tree_successor(node2);

  ck_assert_int_eq(scsr == NULL, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_9)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  scsr = tree_successor(node3);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 15);
  ck_assert_int_eq(scsr == node2, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_10)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, true);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 12);
  ck_assert_int_eq(scsr == node4, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  scsr = tree_successor(node5);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, false);
  ck_assert_int_eq(scsr->data.key.i, -3);
  ck_assert_int_eq(scsr == node2, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_12)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  scsr = tree_successor(node4);

  ck_assert_int_eq(scsr->p == NULL, true);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, false);
  ck_assert_int_eq(scsr->data.key.i, 12);
  ck_assert_int_eq(scsr == node1, true);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_13)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, true);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 13);
  ck_assert_int_eq(scsr == node9, true);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_14)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  scsr = tree_successor(node8);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, false);
  ck_assert_int_eq(scsr->data.key.i, 18);
  ck_assert_int_eq(scsr == node5, true);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_15)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  scsr = tree_successor(node5);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 9);
  ck_assert_int_eq(scsr == node2, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_16)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  scsr = tree_successor(node4);

  ck_assert_int_eq(scsr == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_17)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  scsr = tree_successor(node7);

  ck_assert_int_eq(scsr == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_18)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  scsr = tree_successor(node4);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, true);
  ck_assert_int_eq(scsr->right == NULL, false);
  ck_assert_int_eq(scsr->data.key.i, 50);
  ck_assert_int_eq(scsr == node5, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_19)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  scsr = tree_successor(node1);

  ck_assert_int_eq(scsr == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_successor_20)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* scsr;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  scsr = tree_successor(node4);

  ck_assert_int_eq(scsr->p == NULL, false);
  ck_assert_int_eq(scsr->left == NULL, false);
  ck_assert_int_eq(scsr->right == NULL, true);
  ck_assert_int_eq(scsr->data.key.i, 50);
  ck_assert_int_eq(scsr == node3, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_1)
{
  BinarySearchTree* pred;

  (*root) = NULL;

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  pred = tree_predecessor(*root);

  ck_assert_int_eq(pred == NULL, true);
}
END_TEST

START_TEST(test_bst_tree_predecessor_2)
{
  union Key k1;
  BinarySearchTree* node1;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);
  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  pred = tree_predecessor(*root);

  ck_assert_int_eq(pred == NULL, true);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_3)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 10);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_4)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 10);

  pred = tree_predecessor(node2);

  ck_assert_int_eq(pred->p == NULL, true);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 5);
  ck_assert_int_eq(node1 == node1, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_5)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 5);
  ck_assert_int_eq(pred == node2, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_6)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  pred = tree_predecessor(node2);

  ck_assert_int_eq(pred == NULL, true);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_7)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred == NULL, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_8)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  pred = tree_predecessor(node2);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 10);
  ck_assert_int_eq(pred == node3, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_9)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 15;
  k3.i = 10;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 10);

  pred = tree_predecessor(node3);

  ck_assert_int_eq(pred->p == NULL, true);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 5);
  ck_assert_int_eq(pred == node1, true);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_10)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 5);
  ck_assert_int_eq(pred == node7, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  pred = tree_predecessor(node5);

  ck_assert_int_eq(pred == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_12)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  pred = tree_predecessor(node4);

  ck_assert_int_eq(pred->p == NULL, true);
  ck_assert_int_eq(pred->left == NULL, false);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 10);
  ck_assert_int_eq(pred == node1, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_13)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  pred = tree_predecessor(node5);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 17);
  ck_assert_int_eq(pred == node8, true);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_14)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 5;
  k3.i = 2;
  k4.i = 9;
  k5.i = 18;
  k6.i = 19;
  k7.i = 15;
  k8.i = 17;
  k9.i = 13;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 9);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 18);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 13);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 9);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 18);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 19);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 15);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 17);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, true);
  ck_assert_int_eq(node9->right == NULL, true);
  ck_assert_int_eq(node9->data.key.i, 13);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 9);
  ck_assert_int_eq(pred == node4, true);

  free(node9);
  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_15)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  pred = tree_predecessor(node6);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, false);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 2);
  ck_assert_int_eq(pred == node3, true);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_16)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  pred = tree_predecessor(node6);

  ck_assert_int_eq(pred->p == NULL, true);
  ck_assert_int_eq(pred->left == NULL, false);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 5);
  ck_assert_int_eq(pred == node1, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_17)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  pred = tree_predecessor(node4);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, true);
  ck_assert_int_eq(pred->right == NULL, false);
  ck_assert_int_eq(pred->data.key.i, 15);
  ck_assert_int_eq(pred == node3, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_18)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = -5;
  k2.i = 0;
  k3.i = 15;
  k4.i = 25;
  k5.i = 50;
  k6.i = 100;
  k7.i = 150;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 0);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->data.key.i, 50);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->right->right->left == NULL,
                   true);
  ck_assert_int_eq((*root)->right->right->right->right->right->right == NULL,
                   false);
  ck_assert_int_eq((*root)->right->right->right->right->right->data.key.i, 100);

  ck_assert_int_eq((*root)->right->right->right->right->p == NULL, false);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->left == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->right == NULL, true);
  ck_assert_int_eq(
      (*root)->right->right->right->right->right->right->data.key.i, 150);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, -5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 0);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 25);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 50);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 100);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 150);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred == NULL, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_19)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  pred = tree_predecessor(node1);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, false);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 75);
  ck_assert_int_eq(pred == node2, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_predecessor_20)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* pred;

  (*root) = NULL;

  k1.i = 100;
  k2.i = 75;
  k3.i = 50;
  k4.i = 40;
  k5.i = 20;
  k6.i = 10;
  k7.i = -30;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 100);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 75);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 50);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 40);

  ck_assert_int_eq((*root)->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->left->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->left->left->left->left->p == NULL,
                   false);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->left == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->right == NULL,
                   true);
  ck_assert_int_eq((*root)->left->left->left->left->left->left->data.key.i,
                   -30);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 100);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 75);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 50);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 40);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 20);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 10);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, -30);

  pred = tree_predecessor(node4);

  ck_assert_int_eq(pred->p == NULL, false);
  ck_assert_int_eq(pred->left == NULL, false);
  ck_assert_int_eq(pred->right == NULL, true);
  ck_assert_int_eq(pred->data.key.i, 20);
  ck_assert_int_eq(pred == node5, true);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_1)
{
  union Key k;
  BinarySearchTree* node1;
  BinarySearchTree* removed;

  (*root) = NULL;

  k.i = 10;

  reg->key = k;
  node1 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  removed = tree_delete(root, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed->p == NULL, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, true);
  ck_assert_int_eq(removed->data.key.i, 10);

  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_2)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 15;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 15);

  removed = tree_delete(root, node2);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, true);
  ck_assert_int_eq(removed->data.key.i, 15);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_3)
{
  union Key k1, k2;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 8;
  k2.i = 5;
  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  removed = tree_delete(root, node2);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, true);
  ck_assert_int_eq(removed->data.key.i, 5);

  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_4)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 15;
  k3.i = 20;
  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 20);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 20);

  removed = tree_delete(root, node2);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 20);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 20);

  ck_assert_int_eq(node3->p->p == NULL, true);
  ck_assert_int_eq(node3->p->left == NULL, true);
  ck_assert_int_eq(node3->p->right == NULL, false);
  ck_assert_int_eq(node3->p->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node3, true);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, false);
  ck_assert_int_eq(removed->right == node3, true);
  ck_assert_int_eq(removed->data.key.i, 15);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_5)
{
  union Key k1, k2, k3;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 8;
  k2.i = 5;
  k3.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 3);

  removed = tree_delete(root, node2);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node1->left->data.key.i, 3);
  ck_assert_int_eq(node3->p->data.key.i, 8);
  ck_assert_int_eq(node1->left == node3, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node3, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, false);
  ck_assert_int_eq(removed->left == node3, true);
  ck_assert_int_eq(removed->right == NULL, true);
  ck_assert_int_eq(removed->data.key.i, 5);

  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_6)
{
  union Key k1, k2, k3, k4, k5;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 10;
  k2.i = 15;
  k3.i = 20;
  k4.i = 18;
  k5.i = 33;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 20);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 33);
  ck_assert_int_eq((*root)->right->right->left->data.key.i, 18);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 20);
  ck_assert_int_eq(node3->left == node4, true);
  ck_assert_int_eq(node3->right == node5, true);

  removed = tree_delete(root, node2);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 20);
  ck_assert_int_eq((*root)->right->right->data.key.i, 33);
  ck_assert_int_eq((*root)->right->left->data.key.i, 18);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 20);

  ck_assert_int_eq(node1->right == node2, false);
  ck_assert_int_eq(node1->right->left == node4, true);
  ck_assert_int_eq(node1->right->right == node5, true);
  ck_assert_int_eq(node3->left == node4, true);
  ck_assert_int_eq(node3->right == node5, true);
  ck_assert_int_eq(node3->p == node1, true);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node3, true);
  ck_assert_int_eq(node2->data.key.i, 15);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, false);
  ck_assert_int_eq(removed->right == node3, true);
  ck_assert_int_eq(removed->data.key.i, 15);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_7)
{
  union Key k1, k2, k3, k4, k5;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 8;
  k2.i = 5;
  k3.i = 3;
  k4.i = 0;
  k5.i = 4;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 3);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 4);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 3);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 4);

  removed = tree_delete(root, node2);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 8);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 3);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 8);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 3);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 4);

  ck_assert_int_eq(node3->p == node1, true);
  ck_assert_int_eq(node1->left == node3, true);
  ck_assert_int_eq(node3->left == node4, true);
  ck_assert_int_eq(node3->right == node5, true);
  ck_assert_int_eq(node1->left->left == node4, true);
  ck_assert_int_eq(node1->left->right == node5, true);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->p == node1, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node3, true);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 5);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, false);
  ck_assert_int_eq(removed->left == node3, true);
  ck_assert_int_eq(removed->right == NULL, true);
  ck_assert_int_eq(removed->data.key.i, 5);

  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_8)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 15;
  k2.i = 10;
  k3.i = 20;
  k4.i = 8;
  k5.i = 12;
  k6.i = 30;
  k7.i = 25;
  k8.i = 40;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 15);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 10);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 20);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 8);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 12);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 30);

  ck_assert_int_eq((*root)->right->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->left->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 40);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 20);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 8);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 12);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 30);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 25);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 40);

  removed = tree_delete(root, node3);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 15);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 8);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 12);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 30);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 40);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 8);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 12);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 30);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 25);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 40);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->p == node1, true);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->right == node6, true);
  ck_assert_int_eq(node3->data.key.i, 20);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node1, true);
  ck_assert_int_eq(removed->left == NULL, true);
  ck_assert_int_eq(removed->right == NULL, false);
  ck_assert_int_eq(removed->right == node6, true);
  ck_assert_int_eq(removed->data.key.i, 20);

  free(node8);
  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_9)
{
  union Key k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* node8;
  BinarySearchTree* node9;
  BinarySearchTree* node10;
  BinarySearchTree* node11;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 15;
  k2.i = 10;
  k3.i = 8;
  k4.i = 12;
  k5.i = 25;
  k6.i = 16;
  k7.i = 30;
  k8.i = 40;
  k9.i = 19;
  k10.i = 17;
  k11.i = 23;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);
  reg->key = k8;
  node8 = tree_insert(root, *reg, compare);
  reg->key = k9;
  node9 = tree_insert(root, *reg, compare);
  reg->key = k10;
  node10 = tree_insert(root, *reg, compare);
  reg->key = k11;
  node11 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 15);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 8);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 12);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 16);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 30);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 40);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->left->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right->data.key.i, 23);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 8);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 25);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 16);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 30);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 40);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, false);
  ck_assert_int_eq(node9->right == NULL, false);
  ck_assert_int_eq(node9->data.key.i, 19);

  ck_assert_int_eq(node10->p == NULL, false);
  ck_assert_int_eq(node10->left == NULL, true);
  ck_assert_int_eq(node10->right == NULL, true);
  ck_assert_int_eq(node10->data.key.i, 17);

  ck_assert_int_eq(node11->p == NULL, false);
  ck_assert_int_eq(node11->left == NULL, true);
  ck_assert_int_eq(node11->right == NULL, true);
  ck_assert_int_eq(node11->data.key.i, 23);

  removed = tree_delete(root, node1);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 16);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 10);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 8);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 12);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 25);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->right->data.key.i, 30);

  ck_assert_int_eq((*root)->right->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->right->data.key.i, 40);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, false);
  ck_assert_int_eq((*root)->right->left->right == NULL, false);
  ck_assert_int_eq((*root)->right->left->data.key.i, 19);

  ck_assert_int_eq((*root)->right->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->left->data.key.i, 17);

  ck_assert_int_eq((*root)->right->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->right->data.key.i, 23);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 10);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 8);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, false);
  ck_assert_int_eq(node5->data.key.i, 25);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 16);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, false);
  ck_assert_int_eq(node7->data.key.i, 30);

  ck_assert_int_eq(node8->p == NULL, false);
  ck_assert_int_eq(node8->left == NULL, true);
  ck_assert_int_eq(node8->right == NULL, true);
  ck_assert_int_eq(node8->data.key.i, 40);

  ck_assert_int_eq(node9->p == NULL, false);
  ck_assert_int_eq(node9->left == NULL, false);
  ck_assert_int_eq(node9->right == NULL, false);
  ck_assert_int_eq(node9->data.key.i, 19);

  ck_assert_int_eq(node10->p == NULL, false);
  ck_assert_int_eq(node10->left == NULL, true);
  ck_assert_int_eq(node10->right == NULL, true);
  ck_assert_int_eq(node10->data.key.i, 17);

  ck_assert_int_eq(node11->p == NULL, false);
  ck_assert_int_eq(node11->left == NULL, true);
  ck_assert_int_eq(node11->right == NULL, true);
  ck_assert_int_eq(node11->data.key.i, 23);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node5, true);
  ck_assert_int_eq(node1->data.key.i, 15);

  ck_assert_int_eq(removed->p == NULL, true);
  ck_assert_int_eq(removed->left == NULL, false);
  ck_assert_int_eq(removed->left == node2, true);
  ck_assert_int_eq(removed->right == NULL, false);
  ck_assert_int_eq(removed->right == node5, true);
  ck_assert_int_eq(removed->data.key.i, 15);

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
}
END_TEST

START_TEST(test_bst_tree_delete_10)
{
  union Key k1, k2, k3, k4, k5, k6;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* removed;

  (*root) = NULL;

  k1.i = 12;
  k2.i = 9;
  k3.i = 2;
  k4.i = 0;
  k5.i = 5;
  k6.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 2);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq((*root)->left->left->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->left->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, false);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 3);

  removed = tree_delete(root, node3);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 9);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->left->data.key.i, 3);

  ck_assert_int_eq((*root)->left->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->left->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, true);
  ck_assert_int_eq(node1->data.key.i, 12);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, true);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 0);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 5);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->p == node2, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node4, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->right == node5, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(removed->p == NULL, false);
  ck_assert_int_eq(removed->p == node2, true);
  ck_assert_int_eq(removed->left == NULL, false);
  ck_assert_int_eq(removed->left == node4, true);
  ck_assert_int_eq(removed->right == NULL, false);
  ck_assert_int_eq(removed->right == node5, true);
  ck_assert_int_eq(removed->data.key.i, 2);

  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_11)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* removed1;
  BinarySearchTree* removed2;

  (*root) = NULL;

  k1.i = 5;
  k2.i = 9;
  k3.i = 2;
  k4.i = 12;
  k5.i = 0;
  k6.i = 7;
  k7.i = 3;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, 2);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, true);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  removed1 = tree_delete(root, node1);
  removed2 = tree_delete(root, node3);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 7);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 9);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, 3);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, 0);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, 9);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, 0);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 7);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 3);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node3, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node2, true);
  ck_assert_int_eq(node1->data.key.i, 5);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node3, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node2, true);
  ck_assert_int_eq(removed1->data.key.i, 5);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->p == node6, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node5, true);
  ck_assert_int_eq(node3->right == NULL, false);
  ck_assert_int_eq(node3->right == node7, true);
  ck_assert_int_eq(node3->data.key.i, 2);

  ck_assert_int_eq(removed2->p == NULL, false);
  ck_assert_int_eq(removed2->p == node6, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node5, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node7, true);
  ck_assert_int_eq(removed2->data.key.i, 2);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

START_TEST(test_bst_tree_delete_12)
{
  union Key k1, k2, k3, k4, k5, k6, k7;
  BinarySearchTree* node1;
  BinarySearchTree* node2;
  BinarySearchTree* node3;
  BinarySearchTree* node4;
  BinarySearchTree* node5;
  BinarySearchTree* node6;
  BinarySearchTree* node7;
  BinarySearchTree* removed1;
  BinarySearchTree* removed2;
  BinarySearchTree* removed3;
  BinarySearchTree* removed4;
  BinarySearchTree* removed5;
  BinarySearchTree* removed6;
  BinarySearchTree* removed7;

  (*root) = NULL;

  k1.i = 10;
  k2.i = -3;
  k3.i = 15;
  k4.i = 12;
  k5.i = -7;
  k6.i = 4;
  k7.i = 5;

  reg->key = k1;
  node1 = tree_insert(root, *reg, compare);
  reg->key = k2;
  node2 = tree_insert(root, *reg, compare);
  reg->key = k3;
  node3 = tree_insert(root, *reg, compare);
  reg->key = k4;
  node4 = tree_insert(root, *reg, compare);
  reg->key = k5;
  node5 = tree_insert(root, *reg, compare);
  reg->key = k6;
  node6 = tree_insert(root, *reg, compare);
  reg->key = k7;
  node7 = tree_insert(root, *reg, compare);

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 10);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, false);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->right->left->p == NULL, false);
  ck_assert_int_eq((*root)->right->left->left == NULL, true);
  ck_assert_int_eq((*root)->right->left->right == NULL, true);
  ck_assert_int_eq((*root)->right->left->data.key.i, 12);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, false);
  ck_assert_int_eq(node4->left == NULL, true);
  ck_assert_int_eq(node4->right == NULL, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  removed1 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 12);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 15);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, false);
  ck_assert_int_eq(node3->left == NULL, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  removed2 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 15);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, false);
  ck_assert_int_eq((*root)->left->right == NULL, false);
  ck_assert_int_eq((*root)->left->data.key.i, -3);

  ck_assert_int_eq((*root)->left->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->left->data.key.i, -7);

  ck_assert_int_eq((*root)->left->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right == NULL, false);
  ck_assert_int_eq((*root)->left->right->data.key.i, 4);

  ck_assert_int_eq((*root)->left->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->left->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->left->right->right->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, false);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  removed3 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, -3);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, -7);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, false);
  ck_assert_int_eq((*root)->right->data.key.i, 4);

  ck_assert_int_eq((*root)->right->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->right->data.key.i, 5);

  ck_assert_int_eq(node2->p == NULL, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, false);
  ck_assert_int_eq(node6->left == NULL, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node2, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(removed3->p == NULL, true);
  ck_assert_int_eq(removed3->left == NULL, false);
  ck_assert_int_eq(removed3->left == node2, true);
  ck_assert_int_eq(removed3->right == NULL, true);
  ck_assert_int_eq(removed3->data.key.i, 15);

  removed4 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, false);
  ck_assert_int_eq((*root)->data.key.i, 4);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, -7);

  ck_assert_int_eq((*root)->right->p == NULL, false);
  ck_assert_int_eq((*root)->right->left == NULL, true);
  ck_assert_int_eq((*root)->right->right == NULL, true);
  ck_assert_int_eq((*root)->right->data.key.i, 5);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, false);
  ck_assert_int_eq(node7->left == NULL, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node2, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(removed3->p == NULL, true);
  ck_assert_int_eq(removed3->left == NULL, false);
  ck_assert_int_eq(removed3->left == node2, true);
  ck_assert_int_eq(removed3->right == NULL, true);
  ck_assert_int_eq(removed3->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node5, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node6, true);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(removed4->p == NULL, true);
  ck_assert_int_eq(removed4->left == NULL, false);
  ck_assert_int_eq(removed4->left == node5, true);
  ck_assert_int_eq(removed4->right == NULL, false);
  ck_assert_int_eq(removed4->right == node6, true);
  ck_assert_int_eq(removed4->data.key.i, -3);

  removed5 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, false);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, 5);

  ck_assert_int_eq((*root)->left->p == NULL, false);
  ck_assert_int_eq((*root)->left->left == NULL, true);
  ck_assert_int_eq((*root)->left->right == NULL, true);
  ck_assert_int_eq((*root)->left->data.key.i, -7);

  ck_assert_int_eq(node5->p == NULL, false);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node7->p == NULL, true);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node2, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(removed3->p == NULL, true);
  ck_assert_int_eq(removed3->left == NULL, false);
  ck_assert_int_eq(removed3->left == node2, true);
  ck_assert_int_eq(removed3->right == NULL, true);
  ck_assert_int_eq(removed3->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node5, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node6, true);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(removed4->p == NULL, true);
  ck_assert_int_eq(removed4->left == NULL, false);
  ck_assert_int_eq(removed4->left == node5, true);
  ck_assert_int_eq(removed4->right == NULL, false);
  ck_assert_int_eq(removed4->right == node6, true);
  ck_assert_int_eq(removed4->data.key.i, -3);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->left == node5, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->right == node7, true);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(removed5->p == NULL, true);
  ck_assert_int_eq(removed5->left == NULL, false);
  ck_assert_int_eq(removed5->left == node5, true);
  ck_assert_int_eq(removed5->right == NULL, false);
  ck_assert_int_eq(removed5->right == node7, true);
  ck_assert_int_eq(removed5->data.key.i, 4);

  removed6 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, false);

  ck_assert_int_eq((*root)->p == NULL, true);
  ck_assert_int_eq((*root)->left == NULL, true);
  ck_assert_int_eq((*root)->right == NULL, true);
  ck_assert_int_eq((*root)->data.key.i, -7);

  ck_assert_int_eq(node5->p == NULL, true);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node2, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(removed3->p == NULL, true);
  ck_assert_int_eq(removed3->left == NULL, false);
  ck_assert_int_eq(removed3->left == node2, true);
  ck_assert_int_eq(removed3->right == NULL, true);
  ck_assert_int_eq(removed3->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node5, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node6, true);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(removed4->p == NULL, true);
  ck_assert_int_eq(removed4->left == NULL, false);
  ck_assert_int_eq(removed4->left == node5, true);
  ck_assert_int_eq(removed4->right == NULL, false);
  ck_assert_int_eq(removed4->right == node6, true);
  ck_assert_int_eq(removed4->data.key.i, -3);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->left == node5, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->right == node7, true);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(removed5->p == NULL, true);
  ck_assert_int_eq(removed5->left == NULL, false);
  ck_assert_int_eq(removed5->left == node5, true);
  ck_assert_int_eq(removed5->right == NULL, false);
  ck_assert_int_eq(removed5->right == node7, true);
  ck_assert_int_eq(removed5->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, true);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->left == node5, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(removed6->p == NULL, true);
  ck_assert_int_eq(removed6->left == NULL, false);
  ck_assert_int_eq(removed6->left == node5, true);
  ck_assert_int_eq(removed6->right == NULL, true);
  ck_assert_int_eq(removed6->data.key.i, 5);

  removed7 = tree_delete(root, (*root));

  ck_assert_int_eq(root == NULL, false);
  ck_assert_int_eq((*root) == NULL, true);

  ck_assert_int_eq(node1->p == NULL, true);
  ck_assert_int_eq(node1->left == NULL, false);
  ck_assert_int_eq(node1->left == node2, true);
  ck_assert_int_eq(node1->right == NULL, false);
  ck_assert_int_eq(node1->right == node3, true);
  ck_assert_int_eq(node1->data.key.i, 10);

  ck_assert_int_eq(removed1->p == NULL, true);
  ck_assert_int_eq(removed1->left == NULL, false);
  ck_assert_int_eq(removed1->left == node2, true);
  ck_assert_int_eq(removed1->right == NULL, false);
  ck_assert_int_eq(removed1->right == node3, true);
  ck_assert_int_eq(removed1->data.key.i, 10);

  ck_assert_int_eq(node4->p == NULL, true);
  ck_assert_int_eq(node4->left == NULL, false);
  ck_assert_int_eq(node4->left == node2, true);
  ck_assert_int_eq(node4->right == NULL, false);
  ck_assert_int_eq(node4->right == node3, true);
  ck_assert_int_eq(node4->data.key.i, 12);

  ck_assert_int_eq(removed2->p == NULL, true);
  ck_assert_int_eq(removed2->left == NULL, false);
  ck_assert_int_eq(removed2->left == node2, true);
  ck_assert_int_eq(removed2->right == NULL, false);
  ck_assert_int_eq(removed2->right == node3, true);
  ck_assert_int_eq(removed2->data.key.i, 12);

  ck_assert_int_eq(node3->p == NULL, true);
  ck_assert_int_eq(node3->left == NULL, false);
  ck_assert_int_eq(node3->left == node2, true);
  ck_assert_int_eq(node3->right == NULL, true);
  ck_assert_int_eq(node3->data.key.i, 15);

  ck_assert_int_eq(removed3->p == NULL, true);
  ck_assert_int_eq(removed3->left == NULL, false);
  ck_assert_int_eq(removed3->left == node2, true);
  ck_assert_int_eq(removed3->right == NULL, true);
  ck_assert_int_eq(removed3->data.key.i, 15);

  ck_assert_int_eq(node2->p == NULL, true);
  ck_assert_int_eq(node2->left == NULL, false);
  ck_assert_int_eq(node2->left == node5, true);
  ck_assert_int_eq(node2->right == NULL, false);
  ck_assert_int_eq(node2->right == node6, true);
  ck_assert_int_eq(node2->data.key.i, -3);

  ck_assert_int_eq(removed4->p == NULL, true);
  ck_assert_int_eq(removed4->left == NULL, false);
  ck_assert_int_eq(removed4->left == node5, true);
  ck_assert_int_eq(removed4->right == NULL, false);
  ck_assert_int_eq(removed4->right == node6, true);
  ck_assert_int_eq(removed4->data.key.i, -3);

  ck_assert_int_eq(node6->p == NULL, true);
  ck_assert_int_eq(node6->left == NULL, false);
  ck_assert_int_eq(node6->left == node5, true);
  ck_assert_int_eq(node6->right == NULL, false);
  ck_assert_int_eq(node6->right == node7, true);
  ck_assert_int_eq(node6->data.key.i, 4);

  ck_assert_int_eq(removed5->p == NULL, true);
  ck_assert_int_eq(removed5->left == NULL, false);
  ck_assert_int_eq(removed5->left == node5, true);
  ck_assert_int_eq(removed5->right == NULL, false);
  ck_assert_int_eq(removed5->right == node7, true);
  ck_assert_int_eq(removed5->data.key.i, 4);

  ck_assert_int_eq(node7->p == NULL, true);
  ck_assert_int_eq(node7->left == NULL, false);
  ck_assert_int_eq(node7->left == node5, true);
  ck_assert_int_eq(node7->right == NULL, true);
  ck_assert_int_eq(node7->data.key.i, 5);

  ck_assert_int_eq(removed6->p == NULL, true);
  ck_assert_int_eq(removed6->left == NULL, false);
  ck_assert_int_eq(removed6->left == node5, true);
  ck_assert_int_eq(removed6->right == NULL, true);
  ck_assert_int_eq(removed6->data.key.i, 5);

  ck_assert_int_eq(node5->p == NULL, true);
  ck_assert_int_eq(node5->left == NULL, true);
  ck_assert_int_eq(node5->right == NULL, true);
  ck_assert_int_eq(node5->data.key.i, -7);

  ck_assert_int_eq(removed7->p == NULL, true);
  ck_assert_int_eq(removed7->left == NULL, true);
  ck_assert_int_eq(removed7->right == NULL, true);
  ck_assert_int_eq(removed7->data.key.i, -7);

  free(node7);
  free(node6);
  free(node5);
  free(node4);
  free(node3);
  free(node2);
  free(node1);
}
END_TEST

Suite* make_test_suite(void)
{
  Suite* s;
  TCase* tc_core;

  s = suite_create("Binary Search Tree Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_bst_insert_1);
  tcase_add_test(tc_core, test_bst_insert_2);
  tcase_add_test(tc_core, test_bst_insert_3);
  tcase_add_test(tc_core, test_bst_insert_4);
  tcase_add_test(tc_core, test_bst_insert_5);
  tcase_add_test(tc_core, test_bst_insert_6);
  tcase_add_test(tc_core, test_bst_insert_7);
  tcase_add_test(tc_core, test_bst_insert_8);
  tcase_add_test(tc_core, test_bst_insert_9);
  tcase_add_test(tc_core, test_bst_insert_10);
  tcase_add_test(tc_core, test_bst_insert_11);

  tcase_add_test(tc_core, test_bst_tree_minimum_1);
  tcase_add_test(tc_core, test_bst_tree_minimum_2);
  tcase_add_test(tc_core, test_bst_tree_minimum_3);
  tcase_add_test(tc_core, test_bst_tree_minimum_4);
  tcase_add_test(tc_core, test_bst_tree_minimum_5);
  tcase_add_test(tc_core, test_bst_tree_minimum_6);
  tcase_add_test(tc_core, test_bst_tree_minimum_7);
  tcase_add_test(tc_core, test_bst_tree_minimum_8);
  tcase_add_test(tc_core, test_bst_tree_minimum_9);

  tcase_add_test(tc_core, test_bst_tree_maximum_1);
  tcase_add_test(tc_core, test_bst_tree_maximum_2);
  tcase_add_test(tc_core, test_bst_tree_maximum_3);
  tcase_add_test(tc_core, test_bst_tree_maximum_4);
  tcase_add_test(tc_core, test_bst_tree_maximum_5);
  tcase_add_test(tc_core, test_bst_tree_maximum_6);
  tcase_add_test(tc_core, test_bst_tree_maximum_7);
  tcase_add_test(tc_core, test_bst_tree_maximum_8);
  tcase_add_test(tc_core, test_bst_tree_maximum_9);

  tcase_add_test(tc_core, test_bst_tree_search_1);
  tcase_add_test(tc_core, test_bst_tree_search_2);
  tcase_add_test(tc_core, test_bst_tree_search_3);
  tcase_add_test(tc_core, test_bst_tree_search_4);
  tcase_add_test(tc_core, test_bst_tree_search_5);
  tcase_add_test(tc_core, test_bst_tree_search_6);
  tcase_add_test(tc_core, test_bst_tree_search_7);
  tcase_add_test(tc_core, test_bst_tree_search_8);
  tcase_add_test(tc_core, test_bst_tree_search_9);
  tcase_add_test(tc_core, test_bst_tree_search_10);
  tcase_add_test(tc_core, test_bst_tree_search_11);
  tcase_add_test(tc_core, test_bst_tree_search_12);
  tcase_add_test(tc_core, test_bst_tree_search_13);
  tcase_add_test(tc_core, test_bst_tree_search_14);
  tcase_add_test(tc_core, test_bst_tree_search_15);
  tcase_add_test(tc_core, test_bst_tree_search_16);
  tcase_add_test(tc_core, test_bst_tree_search_17);
  tcase_add_test(tc_core, test_bst_tree_search_18);
  tcase_add_test(tc_core, test_bst_tree_search_19);
  tcase_add_test(tc_core, test_bst_tree_search_20);
  tcase_add_test(tc_core, test_bst_tree_search_21);
  tcase_add_test(tc_core, test_bst_tree_search_22);
  tcase_add_test(tc_core, test_bst_tree_search_23);
  tcase_add_test(tc_core, test_bst_tree_search_24);
  tcase_add_test(tc_core, test_bst_tree_search_25);
  tcase_add_test(tc_core, test_bst_tree_search_26);
  tcase_add_test(tc_core, test_bst_tree_search_27);
  tcase_add_test(tc_core, test_bst_tree_search_28);
  tcase_add_test(tc_core, test_bst_tree_search_29);
  tcase_add_test(tc_core, test_bst_tree_search_30);
  tcase_add_test(tc_core, test_bst_tree_search_31);

  tcase_add_test(tc_core, test_bst_iterative_tree_search_1);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_2);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_3);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_4);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_5);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_6);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_7);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_8);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_9);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_10);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_11);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_12);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_13);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_14);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_15);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_16);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_17);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_18);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_19);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_20);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_21);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_22);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_23);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_24);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_25);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_26);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_27);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_28);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_29);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_30);
  tcase_add_test(tc_core, test_bst_iterative_tree_search_31);

  tcase_add_test(tc_core, test_bst_tree_successor_1);
  tcase_add_test(tc_core, test_bst_tree_successor_2);
  tcase_add_test(tc_core, test_bst_tree_successor_3);
  tcase_add_test(tc_core, test_bst_tree_successor_4);
  tcase_add_test(tc_core, test_bst_tree_successor_5);
  tcase_add_test(tc_core, test_bst_tree_successor_6);
  tcase_add_test(tc_core, test_bst_tree_successor_7);
  tcase_add_test(tc_core, test_bst_tree_successor_8);
  tcase_add_test(tc_core, test_bst_tree_successor_9);
  tcase_add_test(tc_core, test_bst_tree_successor_10);
  tcase_add_test(tc_core, test_bst_tree_successor_11);
  tcase_add_test(tc_core, test_bst_tree_successor_12);
  tcase_add_test(tc_core, test_bst_tree_successor_13);
  tcase_add_test(tc_core, test_bst_tree_successor_14);
  tcase_add_test(tc_core, test_bst_tree_successor_15);
  tcase_add_test(tc_core, test_bst_tree_successor_16);
  tcase_add_test(tc_core, test_bst_tree_successor_17);
  tcase_add_test(tc_core, test_bst_tree_successor_18);
  tcase_add_test(tc_core, test_bst_tree_successor_19);
  tcase_add_test(tc_core, test_bst_tree_successor_20);

  tcase_add_test(tc_core, test_bst_tree_predecessor_1);
  tcase_add_test(tc_core, test_bst_tree_predecessor_2);
  tcase_add_test(tc_core, test_bst_tree_predecessor_3);
  tcase_add_test(tc_core, test_bst_tree_predecessor_4);
  tcase_add_test(tc_core, test_bst_tree_predecessor_5);
  tcase_add_test(tc_core, test_bst_tree_predecessor_6);
  tcase_add_test(tc_core, test_bst_tree_predecessor_7);
  tcase_add_test(tc_core, test_bst_tree_predecessor_8);
  tcase_add_test(tc_core, test_bst_tree_predecessor_9);
  tcase_add_test(tc_core, test_bst_tree_predecessor_10);
  tcase_add_test(tc_core, test_bst_tree_predecessor_11);
  tcase_add_test(tc_core, test_bst_tree_predecessor_12);
  tcase_add_test(tc_core, test_bst_tree_predecessor_13);
  tcase_add_test(tc_core, test_bst_tree_predecessor_14);
  tcase_add_test(tc_core, test_bst_tree_predecessor_15);
  tcase_add_test(tc_core, test_bst_tree_predecessor_16);
  tcase_add_test(tc_core, test_bst_tree_predecessor_17);
  tcase_add_test(tc_core, test_bst_tree_predecessor_18);
  tcase_add_test(tc_core, test_bst_tree_predecessor_19);
  tcase_add_test(tc_core, test_bst_tree_predecessor_20);

  tcase_add_test(tc_core, test_bst_tree_delete_1);
  tcase_add_test(tc_core, test_bst_tree_delete_2);
  tcase_add_test(tc_core, test_bst_tree_delete_3);
  tcase_add_test(tc_core, test_bst_tree_delete_4);
  tcase_add_test(tc_core, test_bst_tree_delete_5);
  tcase_add_test(tc_core, test_bst_tree_delete_6);
  tcase_add_test(tc_core, test_bst_tree_delete_7);
  tcase_add_test(tc_core, test_bst_tree_delete_8);
  tcase_add_test(tc_core, test_bst_tree_delete_9);
  tcase_add_test(tc_core, test_bst_tree_delete_10);
  tcase_add_test(tc_core, test_bst_tree_delete_11);
  tcase_add_test(tc_core, test_bst_tree_delete_12);

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
