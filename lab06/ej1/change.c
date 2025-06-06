#include <limits.h>
#include <stdio.h>
#include "change.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void print_table(int n, int k, int table[n][k]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (table[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Resuelve el problema de la moneda
 *
 * @param d denominaciones
 * @param n cantidad de denominaciones
 * @param k monto a pagar
 */
int change(int d[], int n, int k) {
    if (n == 0)
        return INT_MAX;

    int res=0, cam[n+1][k+1];

    for (int i = 0; i <= n; i++)
        cam[i][0] = 0;

    for (int j = 1; j <= k; j++)
        cam[0][j] = INT_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (d[i-1] > j)
                cam[i][j] = cam[i-1][j];
            else
                cam[i][j] = MIN(cam[i-1][j], 1 + cam[i][j-d[i-1]]);
            res = cam[i][j];
        }
    }
    print_table(n, k, cam);
    return res;
}

/*
    In print tamble change table[n][k] to table[n+1][k+1]
    Also in for change i<n and j<k to i<=n and j<=k

    In change:
    Again declarate cam[n+1][k+1]. That's because we need a table of n+1 dimension
    Then it's the same than theory except that we chaneg d[i] to d[i-1]
        because here arrays starts on 0 and that d in theory starts on 1
    Also in for make i<=n and j<=k
    then we just save in an int the result cam[i][j]
    Finally print the table using cam because it's takes an array[][] 
*/