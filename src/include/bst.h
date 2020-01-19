#ifndef BST_H
#define BST_H

#include <stddef.h>
#include <register.h>

typedef struct BinarySearchTree 
{
  struct BinarySearchTree* p;
  struct BinarySearchTree* left;
  struct BinarySearchTree* right;
  Register data;
}
BinarySearchTree;

void inorder_tree_walk(BinarySearchTree* node);

void postorder_tree_walk(BinarySearchTree* node);

void preorder_tree_walk(BinarySearchTree* node);

BinarySearchTree* tree_minimum(BinarySearchTree* root);

BinarySearchTree* tree_maximum(BinarySearchTree* root);

BinarySearchTree* tree_insert(BinarySearchTree** root, Register reg);

BinarySearchTree* tree_search(BinarySearchTree* node, Key k);

BinarySearchTree* iterative_tree_search(BinarySearchTree* root, Key k);

BinarySearchTree* tree_sucessor(BinarySearchTree* node);

BinarySearchTree* tree_predecessor(BinarySearchTree* node);

BinarySearchTree* tree_delete(BinarySearchTree** root, BinarySearchTree* node);

#endif