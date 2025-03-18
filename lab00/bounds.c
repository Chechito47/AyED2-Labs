#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

/* 
 * Struct to save value status:
 * is_upperbound: if value is bigger than everything in the array.
 * is_lowerbound: if value is smaller than everything in the array.
 * exists: if the value is in the array.
 */
struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

/* 
 * Perform checks about the value
 * Check if its upperbound, lowerbound or if exists.
 * If exists also saves the position in the array.
 */
struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;

    for (unsigned int i=0; i < length; i++) {
        if (value < arr[i]) {
            res.is_upperbound = false;
        }
        if (value > arr[i]) {
            res.is_lowerbound = false;
        }
        if (value == arr[i]) {
            res.exists = true;
            res.where = i;
        }
    }

    return res;
}

/* 
 * Asks the user to enter the array and value.
 * Then print the results.
 */
int main(void) {

    int a[ARRAY_SIZE];

    for (unsigned int i=0; i < ARRAY_SIZE ; i++) {
        printf("Enter the value of element arr[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("The array entered is: [");
    for (unsigned int i=0; i < ARRAY_SIZE-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[ARRAY_SIZE-1]);;

    int value = printf("Enter the reference value: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound) {
        result.exists
            ? printf("The value is upper bound and exists in position arr[%d]\n", result.where)
            : printf("The value is upper bound\n");
    } else if (result.is_lowerbound) {
        result.exists
            ? printf("The value is lower bound and exists in position arr[%d]\n", result.where)
            : printf("The value is lower bound\n");
    } else {
        result.exists
            ? printf("The value is not a bound but exists in position arr[%d]\n", result.where)
            : printf("The value is not a bound and doesn't exists\n");
    }

    return EXIT_SUCCESS;
}

