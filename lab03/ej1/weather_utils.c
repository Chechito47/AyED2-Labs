#include <stdio.h>
#include <stdlib.h>

#include "weather.h"
#include "weather_table.h"
#include "weather_utils.h"

unsigned int lowest_temp_hist(WeatherTable table) {
    int result = table[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (unsigned int month = 0u; month < MONTHS; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._min_temp < result)
                    result = table[year][month][day]._min_temp;
            }
        }
    }
    return result;
}


void highest_temp_year(WeatherTable table, unsigned int res[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        int max = table[year][0][0]._max_temp;
        for (unsigned int month = 0u; month < MONTHS; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._max_temp > max)
                    max = table[year][month][day]._max_temp;
            }
        }
        res[year] = max;
    }
}


void most_rain_year(WeatherTable table, month_t res[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        month_t max_month = january;
        unsigned int max_rain = 0u;
        //Calculate rains by months
        for (unsigned int month = 0u; month < MONTHS; ++month) {
            unsigned int month_rain = 0u;
            for (unsigned int day = 0u; day < DAYS; ++day) {
                month_rain += table[year][month][day]._rainfall; 
            }

            if (month_rain > max_rain) {
                max_rain = month_rain;
                max_month = month;
            }
        }
        res[year] = max_month;
    }
}



