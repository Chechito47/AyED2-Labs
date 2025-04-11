#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      //arreglo, largo, resultado esperado
        { {8}, 1, true },
        { {1, 2, 3, 1}, 4, true },
        { {3, 4, 5}, 3, false },
        { {5, 4, 3}, 3, false },
        { {3, 4, 2}, 3, true },
        { {3, 4, 2, 5}, 4, false },
        { {1, 4, 4}, 3, false },
        { {4, 4, 4}, 3, false },
        { {4, 2}, 2, false },
        { {4, 5, 4}, 3, true },

    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        //arreglo, largo, resultado esperado
        { {8}, 1, 0 },
        { {1, 2, 3, 1}, 4, 2 },
        { {3, 4, 2}, 3, 1 },
        { {4, 5, 4}, 3, 1 },
        { {4, 5, 4, 3, 2}, 5, 1 },
        { {0, 1, 0}, 3, 1 },
        { {1, 2, 3, 2, 1}, 5, 2 },
        { {2}, 1, 0 },
        { {0}, 1, 0 },
        { {10, 11, 10}, 3, 1 },
    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
