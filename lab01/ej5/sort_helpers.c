#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

/*
 * Equivalent to use unsigned int with a[]
 */
void swap(fixstring a[], unsigned int i, unsigned int j) {
    fixstring aux;
    fstring_set(aux, a[i]);
    fstring_set(a[i], a[j]);
    fstring_set(a[j], aux);
}

/*
 * It will depend on how we wanna sort
 */
bool goes_before(fixstring x, fixstring y) {
    //Alphabeticaly
    return fstring_less_eq(x, y);

    //Length
    //return fstring_length(x) <= fstring_length(y);
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

