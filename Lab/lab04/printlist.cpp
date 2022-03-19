/*
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   Exercises:
 *    [a] print the list in reverse
 *    [b] change loop to print out only the birthdays in October
 *    [c] after printing out the October bdays, print a count of how many
 *    [d] change to print the count for each month, not the actual bdays
 *    [e] use a function to do [c]
 *    [f] EXTRA: print which month has the MOST birthdays
 */
#include <iostream>

using namespace std;

const int NUM_BIRTHDAYS = 1000;         // change as needed

int main() 
{
        int bdays[NUM_BIRTHDAYS];    // birthday data
        int used;               // number of spaces used so far
        int pos;                // position in array

        // read in NUM_BIRTHDAYS values
        pos = 0;
        while (pos < NUM_BIRTHDAYS) {
                cin >> bdays[pos];
                pos++;
        }
        used = pos;             // position is how far we got

        // now to print out the list
        // you can switch to a for loop if you know about those
        pos = 0;

        while (pos < used) {
                cout << pos << ". " << bdays[pos] << endl;
                pos++;
        }
        
        //print in reverse order 
        /*for (int i = used-1; i >= 0; i--)
        {
            cout << i << ". " << bdays[i] << endl;
        }*/
        
        //only print bdays in Oct 
        //prints num of Oct bdays
        /*
        int oct_bdays = 0;
        cout << "************************************************" << endl;
        cout << "                OCTOBER BDAYS"<< endl;
        cout << "************************************************"<< endl;
        for (int i = 0; i < used; i++)
        {           
            if (bdays[i] >= 1001 and bdays[i] < 1100)
            {
                oct_bdays++;
                cout << i << ". " << bdays[i] << endl;
            }
        }
        cout << "num of October bdays: " << oct_bdays << endl;
        */
        
        //count num of bdays in each Month
        //create array, holds 12 values, each value is num of bdays for that 
        //month
        //initialize to zero
        int num_bdays_month[12]; 
        for (int i = 0; i < 12; i++)
        {
            num_bdays_month[i] = 0;
        }
        
        //increment each month using the 1000.bd file bdays
        for (int i = 0; i < used; i++)
        {
            if (bdays[i] >= 1201 and bdays[i] <= 1231)
                num_bdays_month[11]++;
            else if (bdays[i] >= 1101 and bdays[i] <= 1130)
                num_bdays_month[10]++;
            else if (bdays[i] >= 1001 and bdays[i] <= 1031)
                    num_bdays_month[9]++;
            else if (bdays[i] >= 901 and bdays[i] <= 930)
                    num_bdays_month[8]++;
            else if (bdays[i] >= 801 and bdays[i] <= 831)
                    num_bdays_month[7]++;
            else if (bdays[i] >= 701 and bdays[i] <= 731)
                    num_bdays_month[6]++;
            else if (bdays[i] >= 601 and bdays[i] <= 630)
                    num_bdays_month[5]++;
            else if (bdays[i] >= 501 and bdays[i] <= 531)
                    num_bdays_month[4]++;
            else if (bdays[i] >= 401 and bdays[i] <= 430)
                    num_bdays_month[3]++;
            else if (bdays[i] >= 301 and bdays[i] <= 331)
                    num_bdays_month[2]++;
            else if (bdays[i] >= 201 and bdays[i] <= 229)
                    num_bdays_month[1]++;
            else if (bdays[i] >= 101 and bdays[i] <= 131)
                    num_bdays_month[0]++;
        }
        
        //print the results
        for (int i = 0; i < 12; i++)
        {
            cout << "Month " << i + 1 << endl;
            cout << num_bdays_month[i] << endl;
        }
        
        return 0;
}
