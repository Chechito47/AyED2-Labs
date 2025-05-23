#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y) {
    pair_t res;

    res.values[0] = x;
    res.values[1] = y;

    return res;
}


//Cannot use assert
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
    //return pair_new(p.values[1], p.values[0]);
}


//p is a struct so there's no memory to free
pair_t pair_destroy(pair_t p) {
    return p;
}

/*
    It doesn't work because we changed the struct and now has only one element
    So now we need to change .fst and .snd for .values[0] and .values[1]

    No, it does not achieve encapsulation, because you can #include "pair.h"
        and see how pair is defined and can also change .values[0], .values[1]
    To avoid this is necessary to hide all of this to the programmer and only
        show him there are a function that takes arguments, do something and 
        return something. So anyone who use pair library should not see how it
        works.
    On this case, in .h, inside the struct we can see how it's implemented
        and that's what we don't want the programmer see
*/