#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t length = 0;

    while(str[length] != '\0')
        length++;

    return length;
}



char *string_filter(const char *str, char c) {
    if (!str)
        return NULL;

    size_t length = string_length(str);
    char *out = calloc(length + 1, sizeof(char));

    if (!out)
        return NULL;

    size_t i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            out[j] = str[i];
            j++;
        }
        i++;
    }

    out[j] = '\0';
    return out;
}



bool string_is_symmetric(const char *str) {
    if  (!str)
        return false;

    bool res = true;
    size_t j = string_length(str);

    if (j < 2)
        return true;

    size_t i = 0;
    j = j -1;
    while (i < j) {
        if (str[i] != str[j]) {
            res = false;
        }
        i++; j--;
    }

    return res;
}