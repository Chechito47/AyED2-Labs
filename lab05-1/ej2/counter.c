#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(counter));
    if (!c)
        exit(EXIT_FAILURE);

    c->count = 0;

    return c;
}

void counter_inc(counter c) {
    c->count = c->count + 1;
}

bool counter_is_init(counter c) {
    return c->count == 0 ? true : false;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));

    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter c_copy = malloc(sizeof(counter));

    c_copy = counter_init();
    c_copy->count = c->count;

    return c_copy;
}

//No need to set c=NULL because it's a void function
void counter_destroy(counter c) {
    free(c);
}
