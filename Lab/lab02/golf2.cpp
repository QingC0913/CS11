/*
 * Comp 11
 * Lab 2
 * 
 * golf2.cpp
 *
 * purpose: practice using booleans, conditionals, and constants
 *
 *          Program reads data about temperature, day, time, wind,
 *          whether it's raining, then prints out the price of
 *          admission to Minnie's Mini Golf for those conditions.
 *
 * modified by:  Qing Cheng
 * on:           2/17/2021
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function declarations
int get_int(string statement);
double temp_change(double price, int tempF);
double day_or_hour_change(double price, int dayOWeek, int hour);
double rain_change(double price, int rainP);
double wind_change(double price, int windMPH);

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// global constants for rules
const double    BASE_PRICE            = 9.0;
const int       HIGH_TEMP_CUTOFF      = 80;
const int       LOW_TEMP_CUTOFF       = 65;
const double    PER_DEGREE_PENALTY    = 0.10;
const int       EVENING_START         = 17;
const double    WEEKEND_EVE_SURCHARGE = 1.00;
const double    RAIN_PENALTY          = 2.00;
const int       RAIN_YES              = 1;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;


int main() 
{
        // -- define vars for input and a value used in the tests below
        int     tempF, dayOweek, hour, rainP, windMPH;
        double  price;

        //
        // Avoid unused variable warnings
        //
        (void) MON; 
        (void) TUE; 
        (void) WED; 
        (void) THR; 
        (void) FRI;

        // -- set the precision 
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from user
        tempF = get_int("Temperature (fahrenheit)? ");
        dayOweek = get_int("Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? ");
        hour = get_int("Hour of day (0..23)? ");
        rainP = get_int("Is it raining (0 = no, 1 = yes)? ");
        windMPH = get_int("Wind speed (MPH)? ");
        
        // -- compute price based on these values

        price = BASE_PRICE;             // start here then adjust

        //
        // Adjust for temperature
        //
        price = temp_change(price, tempF);
        
        //
        // Adjust for peak time periods
        //
        price = day_or_hour_change(price, dayOweek, hour);
        
        //
        // Adjust for rain
        //
        price = rain_change(price, rainP);

        //
        // Adjust for wind:  subtract for each WIND_GRANULARITY unit,
        //                   but NOT each fraction thereof.
        //                   I. e., if WIND_GRANULARITY is 15, then
        //                   20 MPH of wind only gets 1 WIND_PENALTY.
        //
        price = wind_change(price, windMPH);

        // -- report price to user
        cout << "Price: " << price << endl;

        return 0;
}

//get_input
//Purpose: reads inputs from users after given a prompt
//Parameter: string var that becomes the prompt that will be printed 
//Returns: an int var that the user inputs after the prompt
int get_int (string statement)
{   
    int result;
    cout << statement;
    cin >> result;
    return result;
}

//temp_change
//Purpose: change the price according to temperature 
//Parameters: the price of ticket, the Temperature
//Returns: the updated price, adjusted for temperature
double temp_change(double price, int tempF)
{
    if (tempF > HIGH_TEMP_CUTOFF) 
    {
            int degrees_too_high = tempF - HIGH_TEMP_CUTOFF;
            price -= PER_DEGREE_PENALTY * degrees_too_high;
    } 
    else if (tempF < LOW_TEMP_CUTOFF) 
    {
            int degrees_too_low = LOW_TEMP_CUTOFF - tempF;
            price -= PER_DEGREE_PENALTY * degrees_too_low;
    }
    return price;
}

//day_or_hour_change
//Purpose: change the price according to what day of week or
//  what time of the day it is
//Parameter: the price and int vars to check day of week and hour of days
//Returns: the updated price, adjusted for day of week or hour of day
double day_or_hour_change(double price, int dayOweek, int hour)
{
    if ((dayOweek == SAT) or (dayOweek == SUN) or (hour > EVENING_START))
            price += WEEKEND_EVE_SURCHARGE;
    return price;
}

//rain_change
//Purpose: change the price if it rains 
//Parameter: the price and int var for whether it is raining
//Returns: the updated price, adjusted for rain
double rain_change(double price, int rainP)
{
    if (rainP == RAIN_YES)
            price -= RAIN_PENALTY;
    return price;
}

//wind_change
//Purpose: change the price according to wind speed
//Parameter: the price and int var for wind speed
//Returns: the updated price, adjusted for wind speed
double wind_change(double price, int windMPH)
{ 
    return price -= (windMPH / WIND_GRANULARITY) * WIND_PENALTY;
}
