#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

/* Constructors */
counter counter_init(void) {
    counter contador = NULL;
    contador = malloc(sizeof(counter));
    if (!contador) {
        exit(EXIT_FAILURE);
    }
    contador->count = 0;

    return contador;
}

void counter_inc(counter c) {
    c->count++;
}


/* Operations */
bool counter_is_init(counter c) {
    return c->count == 0 ? true : false;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c) {
    counter copy = NULL;
    copy = counter_init();

    copy->count = c->count;

    return copy;
}

void counter_destroy(counter c) {
    if (c != NULL) {
        free(c);
        c = NULL;
    }
}
