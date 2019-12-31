/**
 * @file seq_list.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 12 Oct 2019
 * @brief Header file for Sequential List module.
 *
 * Defines the constant MAX number of elements, the structs Key, Register 
 * and SeqList and the prototypes for the subroutines of the Sequential 
 * List module.
 */
#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <stdbool.h>

#define MAX 50

typedef int Key;
typedef struct
{
  Key key;  /* Key that maps the register */
} Register;
typedef struct
{
  Register A[MAX+1]; /* Array that stores the elements */
  int nElem; /* Current number of elements in Sequential List */
} SeqList;

/** @brief Initializes Sequential List with 0 elements.
 *
 *  Sets the attribute nElems of a Sequential List given
 *  as a pointer to 0.
 *
 *  @param pointer Sequential List to be initialized
 *  @return Void
 */
void init_seq_list(SeqList* sl);

/** @brief Reinitializes Sequential List with 0 elements.
 *
 *  Sets the attribute nElems of a Sequential List (that has
 *  been used before) given as a pointer to 0.
 *
 *  @param pointer Sequential List to be reinitialized
 *  @return Void
 */
void reinit_seq_list(SeqList* sl);

/** @brief Calculates the size of a Sequential List.
 *
 *  Calculates the size of a initialized Sequential List, 
 *  undefined behavior if not properly initialized
 *
 *  @param pointer Sequential List 
 *  @return The size of the Sequential List
 */
int size(SeqList* sl);

/** @brief Inserts register in Sequential List at given
 *         position. 
 *
 *  If given position is invalid (bigger than MAX/nElems
 *  or less than zero) the Sequential List is 
 *  kept unchanged and false is returned. Else, the element
 *  is inserted and true returned.
 *
 *  @param pointer Sequential List 
 *  @param struct element that contains key
 *  @param int position where to insert 
 *  @return whether element could be inserted
 */
bool insert_elem(SeqList* sl, Register reg, int i);

/** @brief Sequentially searchs a Sequential List and
 *         returns index of first occurrence.
 *
 *  Sequentially iterates over Sequential List in
 *  ascending order of index. Returns index of first
 *  occurrence that matches given Register key, else
 *  returns -1. 
 * 
 *  @param pointer Sequential List
 *  @param int Key to be found
 *  @return Index of first match
 */
int seq_search(SeqList* sl, Key k);

/** @brief Sequentially searchs a Sequential List and
 *         returns index of first occurrence.
 *  
 *  Sequentially iterates over Sequential List in
 *  ascending order of index. Sentinel is appended to
 *  List to allow a more efficient search. Returns 
 *  index of first occurrence that matches given 
 *  Register key, else returns -1. 
 * 
 *  @param pointer Sequential List
 *  @param int Key to be found
 *  @return Index of first match
 */
int sentinel_search(SeqList* sl, Key k);

/** @brief Sequentially searchs a Sequential List and
 *         removes first occurrence.
 *
 *  Sequentially iterates over Sequential List in
 *  ascending order of index. Removes first occurrence
 *  that matches given Register key and shifts remaining
 *  elements to the right to keep Sequential List 
 *  contiguous. Else, keeps Sequential List untouched. 
 *
 *  @param int Key to be found
 *  @param pointer Sequential List 
 *  @return whetjer element could be removed
 */
bool remove_elem(Key key, SeqList* sl);

/** @brief Prints elements in Sequential List
 *
 *  Sequentially iterates over Sequential List in
 *  ascending order of index, printing the key of
 *  each existing element separated by a blank space.  
 * 
 *  @param pointer Sequential List 
 *  @return Void
 */
void show_list(SeqList* sl);

#endif /* SEQ_LIST_H */
