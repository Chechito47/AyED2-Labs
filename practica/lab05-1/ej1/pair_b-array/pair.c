#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y) {
    pair_t par;
    par.values[0] = x;
    par.values[1] = y;

    return par;
}

int pair_first(pair_t p) {
    return p.values[0];
}

int pair_second(pair_t p) {
    return p.values[1];
}

pair_t pair_swapped(pair_t p) {
    pair_t q;
    q.values[0] = p.values[1];
    q.values[1] = p.values[0];

    return q;
}

pair_t pair_destroy(pair_t p) {
    return p;
}