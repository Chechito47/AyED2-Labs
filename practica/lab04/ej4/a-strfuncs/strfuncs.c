#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t aux = 0;
    while (str[aux] != '\0') {
        aux++;
    }

    return aux;
}



char *string_filter(const char *str, char c) {
    //Chequeo si la cadena existe
    if (!str) {
        perror("str not exist");
        exit(EXIT_FAILURE);
    }

    //Pido memoria para la nueva cadena
    char *new_string = NULL;
    new_string = calloc(string_length(str) + 1, sizeof(char));
    if (!new_string) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    //Lleno el nuevo arreglo con los elementos distintos a c
    size_t i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            new_string[j] = str[i];
            j++;
        }
        i++;
    }

    //Indico que el ultimo elemento debe ser el que termina los strings
    new_string[j] = '\0';
    return new_string;
}



bool string_is_symmetric(const char *str) {
    if (!str) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    bool res = true;
    int i = 0, j = string_length(str)-1;

    if (j == 0)
        return true;

    while (i < j) {
        if (str[i] != str[j])
            res = false;
        i++; j--;
    }

    return res;
}