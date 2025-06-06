#include <limits.h>
#include <stdio.h>
#include "knapsack.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void print_table(int n, int k, int table[n+1][k+1]) {
    printf("\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
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
 * @brief Resuelve el problema de la mochila
 *
 * @param values valores de los objetos
 * @param weights pesos de los objetos
 * @param n cantidad de objetos
 * @param W capacidad de la mochila
 */
int knapsack(int values[], int weights[], int n, int W) {
    if (W == 0)
        return 0;

    int r=0, moch[n+1][W+1];

    for (int i = 0; i <= n; i++)
        moch[i][0] = 0;

    for (int j = 1; j <= W; j++)
        moch[0][j] = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i-1] > j)
                moch[i][j] = moch[i-1][j];
            else
                moch[i][j] = MAX(moch[i-1][j], values[i-1] + moch[i-1][j-weights[i-1]]);
            r = moch[i][j];
        }
    }
    print_table(n, W, moch);
    return r;
}
