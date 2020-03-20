/**
 * @file bst.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 2 Jan 2020
 * @brief Header file for Binary Search Tree module.
 * 
 * Defines the  struct BinarySearchTree and the prototypes for the routines
 * of the Binary Search Tree module.
 */
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

/** @brief Finds node in Binary Search Tree with the key of lowest value.
 * 
 * Transverses tree in-order printing to the standard output the key of nodes
 * encountered during the tranversal.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @return Void.
 */
void inorder_tree_walk(BinarySearchTree* node);

/** @brief Finds node in Binary Search Tree with the key of lowest value.
 * 
 * Transverses tree in post-order printing to the standard output the key of
 * nodes encountered during the tranversal.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @return Void.
 */
void postorder_tree_walk(BinarySearchTree* node);

/** @brief Finds node in Binary Search Tree with the key of lowest value.
 * 
 * Transverses tree in pre-order printing to the standard output the key of
 * nodes encountered during the tranversal.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @return Void.
 */
void preorder_tree_walk(BinarySearchTree* node);

/** @brief Finds node in Binary Search Tree with the key of lowest value.
 * 
 * Transverses tree looking for the node with the key of lowest value. If
 * the tree is empty returns @c NULL.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @return Pointer to node with the key of lowest value.
 */
BinarySearchTree* tree_minimum(BinarySearchTree* root);

/** @brief Finds node in Binary Search Tree with the key of highest value.
 * 
 * Transverses tree looking for the node with the key of highest value. If
 * the tree is empty returns @c NULL.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @return Pointer to node with the key of highest value.
 */
BinarySearchTree* tree_maximum(BinarySearchTree* root);

/** @brief Inserts node with given Register/Key in Binary Search Tree.
 * 
 * Inserts node with provided Register/Key in Binary Search Tree. Insertion
 * is done as to ensure properties of Binary Search Tree. Returns pointer to
 * inserted node.
 *
 * @param node Pointer to pointer to root of tree. 
 * @param reg Register with key and satellite data of inserted node. 
 * @return Pointer to inserted node. 
 */
BinarySearchTree* tree_insert(BinarySearchTree** root, Register reg);

/** @brief Searches Binary Search Tree recursively for node of matching key.
 * 
 * Transverses tree recursively looking for a node that matches given key.
 * If there's one such node returns a pointer to it, else returns @c NULL.
 *
 * @param node Pointer to node who serves as current starting point of search. 
 * @param k Search key.
 * @return Pointer to found node.
 */
BinarySearchTree* tree_search(BinarySearchTree* node, Key k);

/** @brief Searches Binary Search Tree iteratively for node of matching key.
 * 
 * Transverses tree iteratively looking for a node that matches given key.
 * If there's one such node returns a pointer to it, else returns @c NULL.
 *
 * @param root Pointer to root of tree to be taken into consideration. 
 * @param k Search key.
 * @return Pointer to found node.
 */
BinarySearchTree* iterative_tree_search(BinarySearchTree* root, Key k);

/** @brief Searches Binary Search Tree for successor node in terms of key.
 * 
 * Transverses tree iteratively looking for a node whose key is the most
 * immediate successor of given node's key. If there's no such node
 * returns @c NULL.
 *
 * @param node Pointer to node whose successor must be found. 
 * @param k Search key.
 * @return Pointer to successor node.
 */
BinarySearchTree* tree_successor(BinarySearchTree* node);

/** @brief Searches Binary Search Tree for predecessor node in terms of key.
 * 
 * Transverses tree iteratively looking for a node whose key is the most
 * immediate predecessor of given node's key. If there's no such node
 * returns @c NULL.
 *
 * @param node Pointer to node whose predecessor must be found. 
 * @return Pointer to predecessor node.
 */
BinarySearchTree* tree_predecessor(BinarySearchTree* node);

/** @brief Removes given node from Binary Search Tree.
 * 
 * Removes given node from Binary Search Tree. Removal is done as to preserve
 * properties of a Binary Search Tree. Attributes of removed node are not 
 * changed, thus although not connected to Binary Search Tree it may point to
 * nodes in it. It's up to user to either free the node or make use of its
 * attributes. If root node is replaced, pointer to pointer is updated. If
 * Binary Search Tree becomes empty, pointer to pointer is set to @c NULL. 
 *
 * @param node Pointer to pointer to root of tree. 
 * @param node Pointer to node to be deleted. 
 * @return Pointer to removed node.
 */
BinarySearchTree* tree_delete(BinarySearchTree** root, BinarySearchTree* node);

#endif