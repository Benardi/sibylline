/**
 * @file rbt.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 5 Feb 2020
 * @brief Header file for Red Black Tree module.
 * 
 * Defines the  struct RedBlackTree and the prototypes for the routines
 * of the Red Black Tree module.
 */
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

/** @brief Sets nil's attributes. Assigns nil to root.
 * 
 * Sets attributes of nil/sentinel node to correct values. Assigns nil
 * to root's pointer to pointer.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @return Void.
 */
void init_rbtree(RedBlackTree** root, RedBlackTree* nil);

/** @brief Rotates given node x to the left.
 * 
 * Works on given node x and its right child y. Turns y's left subtree into
 * x's right subtree. Link's x's parent to y. Puts x on y's left. Assumes that
 * x's left isn't NIL and root's parent is NIL. 
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @param node Pointer to node x to be rotated to the left. 
 * @return Void.
 */
void left_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

/** @brief Rotates given node y to the right.
 * 
 * Works on given node y and its left child x. Turns x's right subtree into
 * y's left subtree. Links y's parent to x. Puts y on x's right. Assumes that
 * y's right isn't NIL and root's parent is NIL.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @param node Pointer to node x to be rotated to the right. 
 * @return Void.
 */
void right_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

/** @brief Finds node in Binary Search Tree with the key of lowest value.
 * 
 * Transverses tree looking for the node with the key of lowest value. If
 * the tree is empty returns pointer to nil node.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @return Pointer to node with the key of lowest value.
 */
RedBlackTree* rb_tree_minimum(RedBlackTree* root, RedBlackTree* nil);

/** @brief Inserts node with given Register/Key in Red Black Tree.
 * 
 * Inserts node with provided Register/Key in Red Black Tree. Insertion is
 * done as to ensure properties of Red Black Tree. Returns pointer to
 * inserted node.
 *
 * @param root Pointer to pointer to root of tree. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @param reg Register with key and satellite data of inserted node. 
 * @return Pointer to inserted node. 
 */
RedBlackTree* rb_insert(RedBlackTree** root, RedBlackTree* nil, Register reg);

/** @brief Removes given node from Red Black Tree.
 * 
 * Removes given node from Red Black Tree. Removal is done as to preserve
 * properties of a Red Black Tree. Attributes of removed node are not changed
 * thus although not connected to Red Black Tree it may point to nodes in it.
 * It's up to user to either free the node or make use of its attributes. If
 * root node is replaced, pointer to pointer is updated. If Red Black Tree
 * becomes empty, pointer to pointer is set to nil node.
 *
 * @param root Pointer to pointer to root of tree. 
 * @param nil Pointer to node used as nil/sentinel. 
 * @param node Pointer to node to be deleted. 
 * @return Pointer to removed node.
 */
void rb_delete(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node);

#endif