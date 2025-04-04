#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
 * Chop the array and return a pivot with it's correct order and position
 * Note: there's no need to check (a[i] > a[ppiv] && a[j] < a[ppiv]) because
 * that cases are the final else.
 * Also, can't return if izq < der because it's not a void function.
 * Need to use if instead of while to check goes_before because a while will
 * iterate until the last i <= j and the other while will never start.
 * It's basically the same than the theory with the difference it leave the
 * elements == on the left side instead the right side.
 */
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq, i = izq + 1, j = der;

    //assert(izq < der);

    #ifdef DEBUG
    printf("\nleft: %u\nright: %u\nppiv: %u\n\n", izq, der, ppiv);
    #endif

    while (i <= j) {
        if (goes_before(a[i], a[ppiv]))
            i++;
        else if (goes_before(a[ppiv], a[j]))
            j--;
        else
            swap(a, i, j);
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

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
        printf("BEFORE:\n"); array_dump(a, length);
        #endif

        unsigned int ppiv = partition(a, izq, der);

        (void)length;
        #ifdef DEBUG
        printf("AFTER:\n"); array_dump(a, length); printf("\n\n\n");
        #endif

        //if (izq < ppiv)
        quick_sort_rec(a, izq, (ppiv == 0) ? 0 : ppiv -1, length);

        //if (der > ppiv)
        quick_sort_rec(a, ppiv + 1, der, length);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}

