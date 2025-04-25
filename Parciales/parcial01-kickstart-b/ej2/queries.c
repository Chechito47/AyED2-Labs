/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Máxima temperatura de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
//Returns highest temperature of a day in the indicated year
int year_max_temp(WeatherTable a, int year) {
    int i = 0, max = 0;
    while (i+1980 != year)
        i++;

    for (int month = 0; month < MONTHS; ++month) {
        for (int day = 0; day < DAYS; ++day) {
            if (a[i][month][day]._max_temp > max)
              max = a[i][month][day]._max_temp;
        }
    }

    return max;
}
