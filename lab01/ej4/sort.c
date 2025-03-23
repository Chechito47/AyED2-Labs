#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}

/*
 * Note: insert_proc from theory is insert_sort here. 
 * We have to implement insert starting from 0.
 * void(lenght) is to avoid unused variable and allow debugging.
*/
static void insert(int a[], unsigned int i, unsigned int length) {
    (void)length;
    #ifdef DEBUG
    array_dump(a, length);
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

/*
 * Chop the array and return a pivot with it's correct order and position
 * Note: there's no need to check (a[i] > a[ppiv] && a[j] < a[ppiv]) because
 * that cases are the final else.
 * Also, can't return if izq < der because it's not a void function.
 * Need to use if instead of while to check goes_before because a while will
 * iterate until the last i <= j and the other while will never start.
 */
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq, i = izq + 1, j = der;

    assert(izq < der);

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
 */
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    if (izq >= der)
        return;

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

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}
