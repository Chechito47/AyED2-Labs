#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdio.h>
#include <stdlib.h>

#include "weather.h"
#include "weather_table.h"
#include "weather_utils.h"

unsigned int lowest_temp_hist(WeatherTable table); //Only needs WeatherTable array because with the table we can get year, month, day and the temperature
/*
    Function to get the lowest historical temperature.
*/

void highest_temp_year(WeatherTable table, unsigned int res[YEARS]);
/*
    Function to get the biggest temperature per year.
*/

void most_rain_year(WeatherTable table, month_t res[YEARS]);
/*
    Function to get the month with most rains per year
*/

#endif