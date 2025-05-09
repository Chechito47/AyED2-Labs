#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

/**
 * @brief Main program function
 * 
 * @details Swap variable content using pointers.
 *          First print varibales, then call for swap passing memory directions 
 *          as arguments and then print them again

 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main() {
    int x = 6, y = 4;

    printf("%d, %d\n", x, y);

    swap(&x, &y);

    printf("%d, %d\n", x, y);

    return EXIT_SUCCESS;
}

/**
 * @brief Swap function
 */
void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
