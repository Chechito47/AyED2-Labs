#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t *messi = malloc(sizeof(data_t));
    if (!messi) {
        perror("malloc failed");
        return EXIT_FAILURE;
    }


    strcpy(messi->name, "Leo Messi");
    messi->age = 39;
    messi->height = 169;

    print_data(*messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n",
            sizeof(messi->name),
            sizeof(messi->age),
            sizeof(messi->height),
            sizeof(messi));

    printf("name-address  : %p\n"
           "age-address   : %p\n"
           "height-address: %p\n"
           "data_t-address: %p\n\n",
            (void *)&messi->name,
            (void *)&messi->age,
            (void *)&messi->height,
            (void *)&messi);

    printf("name-index  : %lu\n"
           "age-index   : %lu\n"
           "height-index: %lu\n"
           "data_t-index: %lu\n",
            (uintptr_t)&messi->name,
            (uintptr_t)&messi->age,
            (uintptr_t)&messi->height,
            (uintptr_t)&messi);

    free(messi);

    return EXIT_SUCCESS;
}
