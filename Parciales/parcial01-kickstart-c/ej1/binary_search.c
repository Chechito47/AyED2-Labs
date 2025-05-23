#include "binary_search.h"

//NOTAR: AGREGAR binary_search_rec al .h

static int binary_search_rec(int a[], int x, int lft, int rgt);

int binary_search(int a[], int length, int x) {
    return binary_search_rec(a, x, 0, length-1);
}

/**
 * @brief Posición de un valor en un arreglo ordenado (parte recursiva).
 *  
 * Notar que el algortimo dado no devuelve el primer valor x de la lista,
 * si no que devuelve el mas cercano al mid calculado
 * Por lo tanto el caso { {1, 1, 0}, 3, 1, 0 } no devuelve 0, devuelve 1
 *
 * @param a Arreglo ordenado.
 * @param x Valor a buscar.
 * @param lft Cota inferior del arreglo.
 * @param rgt Cota superior del arreglo.
 */
int binary_search_rec(int a[], int x, int lft, int rgt) {
    int i;

    if (lft > rgt)
        i = -1;
    else {
        int mid = (lft+rgt) / 2;
        if (x < a[mid])
            i = binary_search_rec(a, x, lft, mid-1);
        else if (x == a[mid])
            i = mid;
        else
            i = binary_search_rec(a, x, mid+1, rgt);
    }

    return i;
}

