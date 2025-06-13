#include "remove.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */
list remove_elem(list l, elem e) {
    list res = empty();
    int len = length(l);
    elem aux;

    for (int i = 0; i < len; i++) {
        aux = index(l, i);
        if (aux != e) {
            res = addr(res, aux);
        }
    }

    return res;
}
