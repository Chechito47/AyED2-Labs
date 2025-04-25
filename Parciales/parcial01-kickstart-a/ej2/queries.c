/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
//Given a year returns rainfalls on the whole year
int year_rainfall(WeatherTable a, int year) {
    int i = 0;
    while (i+1980 != year) {
        i++;
    }

    int rains = 0;
    for (int month = 0; month < MONTHS; ++month) {
        for (int day = 0; day < DAYS; ++day) {
            rains += a[i][month][day]._rainfall;
        }
    }

    return rains;
}
