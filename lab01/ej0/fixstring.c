#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

/*
 * Get the length of a string
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
 * Check if two strings has the same content
 * First check if the two strings has the same length, if not: are not equal
 * If are, then check character by character if are equal
 */
bool fstring_eq(fixstring s1, fixstring s2) {
    bool equal = true;
    unsigned int max = fstring_length(s1);

    if (max != fstring_length(s2))
        equal = false;
    else {
        for (unsigned int lgth = 0; lgth < max && s1[lgth] != '\0'; lgth++) {
            if (s1[lgth] != s2[lgth])
                equal = false;    
        }
    }

    return equal;
}

/*
 * Check if s1 is smaller alphabeticaly than s2
 * We will obvius the length and only check for the lentgh of the smallest
 * If the first character of s1 is smaller than the first of s2 then s1 smaller
 * If not check if are bigger, if it's then s1 is not smaller
 * And if not then obviously are equal and check repeat the checks
 * If the strings are equal it will end the loop without change the return value
 */
bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool smaller = true;
    unsigned int max;

    if (fstring_length(s1) <= fstring_length(s2))
        max = fstring_length(s1);
    else
        max = fstring_length(s2);

    for (unsigned int length = 0; length < max && smaller; length++) {
        if (s1[length] < s2[length])
            return smaller;
        else
            if (s1[length] > s2[length]) {
                smaller = false;
                return smaller;
            }
    }

    return smaller;
}

