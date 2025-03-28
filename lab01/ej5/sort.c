#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq, i = izq + 1, j = der;

    //assert(izq < der);

    #ifdef DEBUG
    printf("\nleft: %u\nright: %u\nppiv: %u\n\n", izq, der, ppiv);
    #endif

    while (i <= j) {
        if (goes_before((a[i]), (a[ppiv])))
            i++;
        else if (goes_before((a[ppiv]),(a[j])))
            j--;
        else
            swap(a, i, j);
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der, unsigned int length) {
    (void)length;
    #ifdef DEBUG
    printf("BEFORE:\n"); array_dump(a, length);
    #endif

    unsigned int ppiv = partition(a, izq, der);

    (void)length;
    #ifdef DEBUG
    printf("AFTER:\n"); array_dump(a, length); printf("\n\n\n");
    #endif

    if (izq < ppiv)
        quick_sort_rec(a, izq, ppiv - 1, length);

    if (der > ppiv)
        quick_sort_rec(a, ppiv + 1, der, length);
}

/*
 * Order the array by array length
 */
void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}


