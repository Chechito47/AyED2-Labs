/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Mínima humedad de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_min_moisture(WeatherTable a, int year) {
    unsigned int i = year-FST_YEAR, min_mois = a[i][0][0]._moisture;

    for (int month = 0; month < MONTHS; ++month) {
        for (int day = 0; day < DAYS; ++day) {
            if (a[i][month][day]._moisture < min_mois)
                min_mois = a[i][month][day]._moisture;
        }
    }

    return min_mois;
}
