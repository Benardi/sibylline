#ifndef RBT_H
#define RBT_H

#include <register.h>

typedef enum Color { RED = 1, BLACK = 0 } Color;

typedef struct RedBlackTree
{
    struct RedBlackTree* p;
    struct RedBlackTree* left;
    struct RedBlackTree* right;
    Register data;
    Color color;

}
RedBlackTree;

/* Assumes node->left != NIL and (*root)->p == NIL */
void left_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

/* Assumes node->right != NIL and (*root)->p == NIL */
void right_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

RedBlackTree* rb_tree_minimum(RedBlackTree* root, RedBlackTree* nil);

RedBlackTree* rb_insert(RedBlackTree** root, RedBlackTree* nil, Register reg);

void rb_delete(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

#endif