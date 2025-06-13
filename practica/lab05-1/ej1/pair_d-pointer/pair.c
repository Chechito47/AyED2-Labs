#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
    pair_t par = NULL;
    par = malloc(sizeof(struct s_pair_t));
    if (!par) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }

    par->fst = x;
    par->snd = y;

    return par;
}

int pair_first(pair_t p) {
    if (!p) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }
    return p->fst;
}
int pair_second(pair_t p) {
    if (!p) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    if (!p) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }
    pair_t par = NULL;
    par = malloc(sizeof(struct s_pair_t));
    if (!par) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }

    par->fst = p->snd;
    par->snd = p->fst;

    return par;
}

pair_t pair_destroy(pair_t p) {
    if (p != NULL) {
        free(p);
        p = NULL;
    }

    return p;
}