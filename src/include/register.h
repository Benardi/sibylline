/**
 * @file register.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 10 Jan 2020
 * @brief Header file for Register and Key.
 *
 * Defines the structs Key and Register.
 */
#ifndef REGISTER_H
#define REGISTER_H

union Key
{
  int i;
  float f;
  unsigned int u;
} key;

typedef struct
{
  union Key key; /* Key that maps the register */
  void* value;
} Register;

#endif
