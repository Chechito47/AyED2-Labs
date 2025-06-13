#include "remove.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */
list remove_elem(list l, elem e) {
    list res = empty();
    elem x;
    int len = length(l);

    for (int i = 0; i < len; i++) {
        x = index(l, i);
        if (x != e) {
            res = addr(res, x);
        }
    }

    return res;
}
