#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(elem x, elem y) {
    pair_t res = malloc(sizeof(pair_t));

    res->fst = x;
    res->snd = y;

    return res;
}


elem pair_first(pair_t p) {
    return p->fst;
}


elem pair_second(pair_t p) {
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
    Now is poliform, so it's also be able to use with other types like char
        instead only int.
    It's no neccessary to change anything, it works correctly.
*/