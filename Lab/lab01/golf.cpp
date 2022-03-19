/*
 * golf.cpp
 * purpose:      practice using booleans and constants
 * modified by: Qing Cheng
 * on date: 2/10/2021
 */

#include <iostream>
#include <iomanip>

using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double    BASE_PRICE            = 9.0;
const int       HIGH_TEMP_CUTOFF      = 80;
const int       LOW_TEMP_CUTOFF       = 65;
const double    PER_DEGREE_PENALTY    = 0.10;
const int       EVENING_START         = 17;
const double    WEEKEND_EVE_SURCHARGE = 1.00;
const double    RAIN_PENALTY          = 2.00;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;

int main() 
{
        // -- define vars for input
        int tempF, dayOweek, hour, rainP, windMPH;
        double wind_charge; 
        // -- changes depending on conditions
        double price;

        // -- set the precision used to output floating point numbers
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from user
        cout << endl;
        cout << "Temperature (degrees fahrenheit)? ";
        cin  >> tempF;

        cout << "Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? ";
        cin  >> dayOweek;
        
        cout << "Hour of day (0..23)? ";
        cin  >> hour;

        cout << "Is it raining (0 = no, 1 = yes)? ";
        cin  >> rainP;

        cout << "Wind speed (MPH)? ";
        cin  >> windMPH;
        cout << endl;

        // -- compute price based on input values

        price = BASE_PRICE;             
        
        if (tempF > HIGH_TEMP_CUTOFF)
            price = price - (PER_DEGREE_PENALTY * (tempF - HIGH_TEMP_CUTOFF));
        else if (tempF < LOW_TEMP_CUTOFF)
            price = price - (PER_DEGREE_PENALTY * (LOW_TEMP_CUTOFF - tempF));
        
        if ((dayOweek == 0) || (dayOweek == 6) || (hour > EVENING_START) )
            price += WEEKEND_EVE_SURCHARGE; 
        else if (dayOweek > 6 || dayOweek < 0)
            cout << "Error! You entered " << dayOweek
                 << " for day of the week!" << endl;
            
        if (rainP == 1)
            price -= RAIN_PENALTY;
        else if (rainP != 0)
            cout << "Error! You did not enter 0 or 1!" << endl;

        wind_charge = (windMPH / WIND_GRANULARITY) * WIND_PENALTY;
        price -= wind_charge; 
        cout << endl;
        // -- report price to user

        cout << "Price: " << price << endl;
        return 0;
}
