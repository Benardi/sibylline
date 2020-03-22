/**
 * @file utils.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 15 Feb 2020
 * @brief Header file for Utils module.
 *
 * Defines generic routines employed by others local modules.
 */
#ifndef UTILS_H
#define UTILS_H

/** @brief Switches the values at two given positions in the parameter array.
 *
 * @param array parameter array contain the two values/positions.
 * @param pos1 Position the array of element one to be switched.
 * @param pos2 Position in the array of element two to be in switched.
 * @return Void.
 */
void swap(int array[], int pos1, int pos2);

/** @brief Finds elements of highest value in array and returns its position.
 *
 * Iterates parameter array from start (parameter) to end (parameter)
 * position. Finds elements of highest value in the part of the array taken
 * into consideration and returns its position.
 *
 * @param array Parameter array contain the two values/positions.
 * @param start Position of first array element to be considered by routine.
 * @param end Position of last array element to be considered by routine.
 * @return Position of element of maximum value in array.
 */
int max(int array[], int start, int end);

/** @brief Produces randomly a value in the interval [lower, upper].
 *
 * Produces randomly a value in the interval [lower, upper]. Random value
 * is greater or equal than given lower bound and lower or equal than given
 * upper bound. If lower and upper bound are equal a numerical error is
 * generated.
 *
 * @param array Parameter array contain the two values/positions.
 * @param start Position of first array element to be considered by routine.
 * @param end Position of last array element to be considered by routine.
 * @return Random value in the interval [lower, upper].
 */
int sample(int lower, int upper);

int ipow(int base, int exp);
int nth_digit(int number, int nth, int base);

#endif
