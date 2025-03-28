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
 * Also is not necessay to check der > izq or izq >= der because the arguments
 * that quick_sort passes asure it.
 */
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    (void)length;
    #ifdef DEBUG
    array_dump(a, length); printf("\n");
    #endif

//    if (izq >= der)
//        return;

    unsigned int ppiv = partition(a, izq, der);
    if (izq < ppiv)
        quick_sort_rec(a, izq, ppiv - 1, length);

    if (der > ppiv)
        quick_sort_rec(a, ppiv + 1, der, length);
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}

