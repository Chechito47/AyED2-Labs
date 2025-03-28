#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

/*
 * Get the length of a string.
 * Iterates starting in the first position to the FIXSTRING_MAX or until hit '0'
 * counting the how many characters the string has.
 * Note we cannot use string.h library.
 */
unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;

    while (s[length] != '\0' && length < FIXSTRING_MAX)
        length++;

    return length; 
}

/*
 * Check if two strings has the same content.
 * There's no need to check for '\0' because it was already in fstring_length.
 * First check if the two strings has the same length, if not: are not equal
 * If are, then check character by character if are equal.
 */
bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int length_s1 = fstring_length(s1), 
                 length_s2 = fstring_length(s2);

    if (length_s1 != length_s2)
        return false;

    for (unsigned int i = 0; i < length_s1; i++) {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

/*
 * Check if s1 is smaller alphabeticaly than s2
 * We will iterate with the smallest string.
 * Check if characters are differents.
 * If they're, then return the true if char from s1 is smaller, or false if not.
 * If are equal, loop until end or until find a different pair.
 * If strings are full equal it will end the loop without a return, so strings
 * are equal or there are a prefix. End checking if s1 is less or equal than s2,
 * if it's then it's smaller or prefix, if not then s2 it's prefix.
 */
bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int length_s1 = fstring_length(s1),
                 length_s2 = fstring_length(s2),
                 min_length = (length_s1 < length_s2) ? length_s1 : length_s2;

    for (unsigned int i = 0; i < min_length; i++) {
        if (s1[i] != s2[i])
            return s1[i] < s2[i];
    }

    return length_s1 <= length_s2;
}

