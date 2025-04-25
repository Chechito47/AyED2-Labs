#include <assert.h>
#include <stdbool.h>
#include "first_zero.h"

/**
 * @brief Posición del primero cero en un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0].
 * 
 * Dado un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0], devolver la
 * posición del primer elemento que es un cero (0). Si no hay ningún cero,
 * devolver -1. La búsqueda se realiza usando una estrategia divide y vencerás
 * de complejidad O(log n).
 *
 * @param a Arreglo de forma [1, 1, ... , 1, 0, 0, ..., 0].
 * @param length Largo del arreglo.
 */
//Returns position of first 0 [1,...1,...0,...0]
//Note: add first_zero_rec to .h
int first_zero(int a[], int length) {
    return first_zero_rec(a, 0, length-1); 
}

int first_zero_rec(int a[], int lft, int rgt) {
    int result;
    if (lft == rgt) {
        if (a[lft] == 0)
            result = lft;
        else
            result = -1;
    } else if (lft < rgt) {
        int mid = (lft+rgt) / 2;
        if (a[mid] == 0)
            result = first_zero_rec(a, lft, mid);
        else if (a[mid] == 1)
            result = first_zero_rec(a, mid+1, rgt);
    } else
        result = -1;

    return result;
}

/*
Another way without recursion and without add .h
int first_zero(int a[], int length) {
    int lft = 0, rgt = length-1, mid, result;

    if (lft > rgt)
        return -1;

    while (lft < rgt) {
        mid = (lft+rgt)/2;
        if (a[mid] == 0)
            rgt = mid;
        else if (a[mid] == 1)
            lft = mid+1;
    }

    if (lft == rgt) {
        if (a[lft] == 0)
            result = lft;
        else
            result = -1;
    }

    return result;
}
*/