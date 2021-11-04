#ifndef STR_BUILDER_H
#define STR_BUILDER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int STR_BUILDER_INCREASE_FACTOR = 2;

typedef struct
{
  int size;
  int capacity;
  char* array;
} StringBuilder;

/** @brief Initializes StringBuilder with given capacity.
 *
 * Sets the capacity and size attributes. Size is set to 0. Allocates the array
 * attribute using the capacity argument. The argument capacity must be greater
 * than 0 as at the very least we must store the nullbyte character to represent
 * an empty string. If an invalid capacity value is provided no work is
 * performed and the value false is returned.
 *
 * @param str_bldr StringBuilder instance to be initialized.
 * @param capacity Number of characters the StringBuilder can comport.
 * @return Whether the StringBuilder was successfully initialized.
 */
bool init_str_builder(StringBuilder* str_bldr, int length);

/** @brief Appends an array of characters to a StringBuilder.
 *
 * Appends a given array of characters to an initalized StringBuilder. This
 * function expects the StringBuilder's array to contain a valid string of
 * characters (ending with a nullbyte). If the StringBuilder's current capacity
 * does not suffice to fit the array of character to be appended this function
 * expands the StringBuilder's array. The StringBuilder's capacity is multiplied
 * by the value STR_BUILDER_INCREASE_FACTOR until the array of character to be
 * appended fits the StringBuilder's array.
 *
 * @param str_bldr StringBuilder instance.
 * @param str Array of characters to be appended to StringBuilder's array.
 * @return Void.
 */
void append_str(StringBuilder* str_bldr, char str[]);

/** @brief Delete first occurrence of substring.
 *
 * The first occurrence of the given substring is removed from the
 * StringBuilder's array. The array is pieced back together to make a contiguous
 * string of characters. The StringBuilder's size is updated accordingly. If
 * there's no match for the substring this function simply returns the value
 * false.
 *
 * @param str_bldr StringBuilder instance.
 * @param target Substring to be removed from StringBuilder's array.
 * @return Whether the substring could be found and removed.
 */
bool del_str(StringBuilder* str_bldr, char target[]);

/** @brief Ensures StringBuilder's capacity matches given value.
 *
 * If current StringBuilder's array doesn't match given capacity steps are taken
 * to fix it. Fix is made by copying over StringBuilder's array to a new one
 * that matches the expected capacity.
 *
 * @param str_bldr StringBuilder instance.
 * @param capacity Number of characters StringBuilder's array must accomodate.
 * @return Void.
 */
void ensure_capacity(StringBuilder* str_bldr, int capacity);

/** @brief Insert character string into StringBuilder's array at index.
 *
 * Inserts a given string of characters into StringBuilder's array at given
 * index. A valid index must be at least 0 and at most equal to the
 * StringBuilder's current size. Providing an invalid index entails the function
 * performing no work and returning the value false. Once the string of
 * characters has been inserted the StringBuilder's array is pieced together to
 * ensure it forms a contiguous string of characters.
 *
 * @param str_bldr StringBuilder instance.
 * @param index Position where the string of characters will be inserted.
 * @param str String of characters to be inserted.
 * @return Whether the string of characters could be inserted.
 */
bool insert_str(StringBuilder* str_bldr, int index, char str[]);

/** @brief Remove substring from StringBuilder's array based on indexes.
 *
 * Removes characters in StringBuilder's array based on indexes. The start
 * and end indexes signal the substring to be removed and are also included in
 * the removal. If invalid indexes are provided the function simply returns
 * false and performs no work. The start index must be at least 0. The end index
 * must be less than the StringBuilder's current size. Also, the end index must
 * be at least equal to the start index.
 *
 * @param str_bldr StringBuilder instance.
 * @param start Starting position of substring to be removed.
 * @param end Ending position of substring to be removed.
 * @return Whether the substring could be removed.
 */
bool del_str_range(StringBuilder* str_bldr, int start, int end);

/** @brief Replace substring in StringBuilder's array based on indexes.
 *
 * Replaces characters in StringBuilder's array based on indexes. The start
 * and end indexes signal the substring to be replaced and are also included in
 * the replacement. If invalid indexes are provided the function simply returns
 * false and performs no work. The start index must be at least 0. The end index
 * must be less than the StringBuilder's current size. Also, the end index must
 * be at least equal to the start index. If there's no capacity for the
 * replacement string The StringBuilder's capacity is multiplied by the value
 * STR_BUILDER_INCREASE_FACTOR until we can accomodate the replacement string.
 *
 * @param str_bldr StringBuilder instance.
 * @param start Starting position of substring to be replaced.
 * @param end Ending position of substring to be replaced.
 * @return Whether the substring could be replaced.
 */
bool replace_str(StringBuilder* str_bldr, int start, int end, char str[]);

#endif
