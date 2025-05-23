#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y) {
    pair_t res = malloc(sizeof(pair_t));

    res->fst = x;
    res->snd = y;

    return res;
}


int pair_first(pair_t p) {
    return p->fst;
}


int pair_second(pair_t p) {
    return p->snd;
}


pair_t pair_swapped(pair_t p) {
    pair_t q = malloc(sizeof(size_t));
    q->fst = p->snd;
    q->snd = p->fst;

    return q;
    //return pair_new(p->snd, p->fst);
}


pair_t pair_destroy(pair_t p) {
    free(p);
    p = NULL;
    return p;
}

/*
    Again, it does not achieve encapsulation because inside .h programmer can
        see that s_pair_t has a fst and snd;
*/