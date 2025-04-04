#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
 * Note: insert_proc from theory is insert_sort here. 
 * We have to implement insert starting from 0.
 * void(lenght) is to avoid unused variable and allow debugging.
*/
static void insert(int a[], unsigned int i, unsigned int length) {
    (void)length;
    #ifdef DEBUG
    array_dump(a, length); printf("\n");
    #endif

    unsigned int j = i;
    while (j > 0 && goes_before(a[j], a[j-1])) {
        swap(a, j-1, j);
        j--;
    }
}

/*
 * Added assert inside for to check from [0, i)
 */
void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
        assert(array_is_sorted(a, i));
    }
}
