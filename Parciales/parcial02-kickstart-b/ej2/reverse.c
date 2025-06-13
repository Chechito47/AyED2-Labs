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
    for (int j = length(l)-1; j >= 0; j--) {
        res = addr(res, index(l, j));
    }

    return res;
}