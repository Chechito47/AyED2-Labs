#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y) {
    pair_t res;

    res.fst = x;
    res.snd = y;

    return res;
}


//Cannot use assert
int pair_first(pair_t p) {
    return p.fst;
}


int pair_second(pair_t p) {
    return p.snd;
}


pair_t pair_swapped(pair_t p) {
    pair_t q;
    q.fst = p.snd;
    q.snd = p.fst;

    return q;
    //return pair_new(p.snd, p.fst);
}


//p is a struct so there's no memory to free
pair_t pair_destroy(pair_t p) {
    return p;
}