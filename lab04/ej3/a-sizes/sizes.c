#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    //Size in bytes
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height));

    //Memory address
    printf("\n\nname-memory address  : %p\n"
           "age-memory address   : %p\n"
           "height-memory address: %p\n"
           "data_t-memory address: %p\n",
           (void *) &messi.name,
           (void *) &messi.age,
           (void *) &messi.height,
           (void *) &messi);

    //Indexes
    printf("\n\nname-index  : %lu bytes\n"
           "age-index   : %lu bytes\n"
           "height-index: %lu bytes\n"
           "data_t-index: %lu bytes\n",
           (uintptr_t) messi.name,
           (uintptr_t) messi.age,
           (uintptr_t) messi.height,
           (uintptr_t) messi.name + messi.age + messi.height);

    return EXIT_SUCCESS;
}

/*
    The size of name depends directly from NAME_MAXSIZE in data.h

    The memory directions are one next to the other, the only thing i could
    remark is that data_t starts on the same direction of name despite I change
    the NAME_MAXSIZE to 32.
    age and height uses 4bytes.
*/