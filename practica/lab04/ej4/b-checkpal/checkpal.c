#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;

    //scanf to fgets
    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    if (fgets(user_input, MAX_LENGTH, stdin) == NULL) {
        perror("fgets error");
        exit(EXIT_FAILURE);
    }

    //Deletes \n
    size_t length = string_length(user_input);
    if (length > 0 && user_input[length-1] == '\n') {
        user_input[length-1] = '\0';
    }

    filtered = string_filter(user_input, ignore_chars[0]);
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        filtered = string_filter(filtered, ignore_chars[i]);
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    return EXIT_SUCCESS;
}

