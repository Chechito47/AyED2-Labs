#include "reverse.h"
#include <stdio.h>

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de invertir
 * el orden de los elementos de `l`
 *
 */
list reverse(list l) {
    if (is_empty(l))
        return l;
    list res = empty();
    for (int i = length(l)-1; i >= 0; i--) {
        elem x = index(l, i);
        res = addr(res, x);
    }

    return res;
}