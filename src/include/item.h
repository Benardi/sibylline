/**
 * @file item.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 10 Jan 2020
 * @brief Header file for Item and Key.
 *
 * Defines the structs Key, Item and ExtendedItem.
 */
#ifndef ITEM_H
#define ITEM_H

union Key
{
  int i;
  float f;
  unsigned int u;
};

typedef struct
{
  int key;
  void* value;
} Item;

typedef struct
{
  union Key key; /* Key that maps the item */
  void* value;
} ExtendedItem;

#endif
