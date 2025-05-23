#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    int fst;
    int snd;
};

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
    Now we assure encapsulation because if we implement the struct in .c a
        programmer who wants to access to memebers of our implementation can't
        because now he don't now how it's implemented, for example if we used a
        single element like .values[2] or used two like .fst and .snd because
        that information is in .c and that's something we don't export
    (We export .o and .h)
    Also is neccessary to change in main.c the way we obtain the first and
        second element, fot that we can use the functions we made
*/