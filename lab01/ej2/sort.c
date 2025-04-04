#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
 * Note: partition return uint asserting lft <= ppiv <= rgt
 * We don't have to check izq <= ppiv because quick_sort_rec takes ppiv -1
 * IDEM with der <= ppiv.
 * Need to check der > izq to assure precondition of partition (0 <= izq < der)
 * it's useful to avoid swap in case length=0
 * Check if ppiv=0, if it's don't change the value, if not it's higher so ppiv-1
 * It's not necessary to check the same with der, in case that ppiv+1 >= der
 * then the if(der > izq) will fail
 */
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    if (der > izq) {
        (void)length;
        #ifdef DEBUG
        array_dump(a, length); printf("\n");
        #endif

        unsigned int ppiv = partition(a, izq, der);
        //if (izq < ppiv)
        quick_sort_rec(a, izq, (ppiv == 0) ? 0 : ppiv -1, length);

        //if (der > ppiv)
        quick_sort_rec(a, ppiv + 1, der, length);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}

