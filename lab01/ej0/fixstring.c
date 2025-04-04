#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

/*
 * Get the length of a string.
 * Iterates starting in the first position until hit '\0'
 * counting the how many characters the string has.
 * Note we cannot use string.h library.
 */
unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;

    while (s[length] != '\0')
        length++;

    return length;
}

/*
 * Check if two strings has the same content.
 * Iterates checking character by character if are equal or if they are '\0'.
 * If are not the same character, return false, if are the same return true
 */
bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;

    return s1[i] == s2[i];
}

/*
 * Check if s1 is smaller alphabeticaly than s2
 * Iterates checking character by character if are equal or if they are '\0'.
 * If are not the same character, return true if s1 is smaller, false if not.
 */
bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;

    return s1[i] <= s2[i];
}

