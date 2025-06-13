#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Calcula la longitud de la cadena apuntada por str
 *
 * @param str puntero a una cadena
 * 
 * @return size_t tipo longsize
 */
size_t string_length(const char *str);


/**
 * @brief nueva cadena sin el caracter especificado
 * 
 * @details una nueva cadena en memomoria dinamica obtenida tomando los
 * caracteres que son distintos a c
 * 
 * @param str puntero a una cadena
 * @param c letra
 * 
 * @return cadena nueva
 */
char *string_filter(const char *str, char c);

/**
 * @brief indica si la cadena es simetrica
 * 
 * @details es simetrica si el primer caracter coincide con el ultimo, el segundo
 * con el anteultimo y asi...
 * ejemplo: "aba", "abcba", "a", ""
 * 
 * @param str puntero a una cadena
 * 
 * @retval true o false
 */
bool string_is_symmetric(const char *str);

#endif