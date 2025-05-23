#ifndef STRFUNCS_H
#define STRFUNCS_H
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/*
 * @brief: calcula la longitud de la cadena apuntada por str
 * @param: str
 * @return: size_t (length of the string)
 */
size_t string_length(const char *str);


/*
 * @brief: devuelve una nueva cadena con los caracteres distintos a c
 * @details: la cadena se obtiene tomando los caracteres de str que son
            distintos del caracter c
 * @param: str, c
 * @return: char *string_filter (cadena)
 */
char *string_filter(const char *str, char c);


/*
 * @brief: indica si la cadena apuntada por str es simétrica
 * @details: es simetrica si el primer caracter coincide con el ultimo, el
            anteultimo con el segundo y asi. Ejemplos: "aba", "abcba", "a", ""
 * @param: str
 * @return: bool
 */
bool string_is_symmetric(const char *str);

#endif