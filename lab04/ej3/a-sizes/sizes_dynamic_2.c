#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void print_data(data_t *d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d->name, d->age, d->height);
}

int main(void) {

    //Ask for memory
    data_t *messi = malloc(sizeof(*messi));
    if (!messi) {
       perror("malloc failed");
       return EXIT_FAILURE;
    }

    //Initilize values
    strcpy(messi->name, "Leo Messi");
    messi->age = 36;
    messi->height = 169;

    //Print data
    print_data(messi);

    //Size in bytes
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi->name),
           sizeof(messi->age),
           sizeof(messi->height),
           sizeof(data_t));

    //Memory address
    printf("\n\nname-memory address  : %p\n"
           "age-memory address   : %p\n"
           "height-memory address: %p\n"
           "data_t-memory address: %p\n",
           (void *) &messi->name,
           (void *) &messi->age,
           (void *) &messi->height,
           (void *) &messi);

    //Indexes
    printf("\n\nname-index  : %lu\n"
           "age-index   : %lu\n"
           "height-index: %lu\n"
           "data_t-index: %lu\n",
           (uintptr_t) &messi->name,
           (uintptr_t) &messi->age,
           (uintptr_t) &messi->height,
           (uintptr_t) &messi);

    free(messi);

    return EXIT_SUCCESS;
}

/*
       This is another version using dynamic memory
       The difference is that print_data takes a pointer
       So instead of d.algo now we have to do d->algo
       Also, when we call print_data we only pass messi as argument
              and not *messi, because messi is already a pointer
       With the other implementation we have to pass *messi because
              that way we pass the values because d is not a pointer.
*/