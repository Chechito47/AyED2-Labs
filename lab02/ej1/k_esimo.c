#include <stdbool.h>
#include <stdio.h> //Only to use printf
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);
#ifdef DEBUG
void array_dump(int a[], int length);
#endif

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    if (length < 0 || k < 0 || k >= length)
        return -1;

    int lft = 0, rgt=length-1;
    int ppiv = partition(a, lft, rgt);
    #ifdef DEBUG
    array_dump(a, length);
    printf("\nleft: %u\nright: %u\nppiv: %u\n\n", lft, rgt, ppiv);
    #endif

    while (ppiv != k) {
        if (ppiv < k)
            lft = ppiv + 1;
        else
            rgt = ppiv - 1;
        ppiv = partition(a, lft, rgt);
        #ifdef DEBUG
        array_dump(a, length);
        printf("\nleft: %u\nright: %u\nppiv: %u\n\n", lft, rgt, ppiv);
        #endif
    }

    return a[k];
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

#ifdef DEBUG
void array_dump(int a[], int length) {
    fprintf(stdout, "%u\n", length);
    for (int i = 0; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}
#endif
