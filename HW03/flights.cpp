//flights.cpp
//Purpose:modified version of hw02's flights.cpp, with small, modular Functions
//Qing Cheng
//Modified 2/28/2021

#include <iostream>

using namespace std;

const int MIN_IN_HR = 60;
const int HR_IN_DAY = 24;

int time_in_minutes(int hr, int min);
void print_hr_and_min(int n);
int time_lapse(int min_a, int min_b);
void get_input_and_results();

int main()
{
    get_input_and_results();
    
    return 0;
}
/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//get_input_and_results
//Purpose: this function will get the timestamps of the two flights from the
  //the user and calculate and display the layover and total time 
//Parameter: none
//Returns: nothing
//Effects: will print two prompts for the timestamps and print the 
  //layover and total time in hrs and mins
void get_input_and_results()
{
    int hr_1, min_1, hr_2, min_2, hr_3, min_3, hr_4, min_4;
    int flight1, flight2, layover, total;
    
    cout << "Flight 1:";
    cin >> hr_1 >> min_1 >> hr_2 >> min_2;
    //calculate total mins between two timestamps of flight 1
    flight1 = time_lapse(time_in_minutes(hr_1, min_1),  
              time_in_minutes(hr_2, min_2));
    
    cout << "Flight 2:";
    cin >> hr_3 >> min_3 >> hr_4 >> min_4;
    //calculate total mins between two timestamps of flight 2
    flight2 = time_lapse(time_in_minutes(hr_3, min_3),  
              time_in_minutes(hr_4, min_4)); 
     
    //calculate total mins between arrival of flight 1 and start of flight 2
    layover = time_lapse(time_in_minutes(hr_2, min_2),  
              time_in_minutes(hr_3, min_3));
             
    total = flight1 + flight2 + layover;

    cout << "Layover: ";
    print_hr_and_min(layover);
    cout << "Total: ";
    print_hr_and_min(total);
}

//time_in_minutes
//Purpose: converts a timestamp given in hrs and mins into total num of mins 
//parameters: hrs and mins 
//Returns: total num of minutes
int time_in_minutes(int hr, int min)
{
    return (hr * MIN_IN_HR + min);
}

//print_hr_and_min
//Purpose: prints mins into hrs and minutes
//Parameter: number of minutes 
//Returns: nothing 
//Effects: prints lapse in hrs and minutes
void print_hr_and_min(int n)
{
    //get whole number of hours
    int hr = n / MIN_IN_HR;
    //get the remainder minutes
    int min = n % MIN_IN_HR;
    cout << hr << " hr " << min << " min" << endl;    
}

//time_lapse
//Purpose: calculates the num of minutes before two timestamps in minutes
//Parameter: the two timestamps, in minutes 
//Returns: total num of minutes betwe;en the two timestamps 
int time_lapse(int min_a, int min_b)
{   
    //if a flight is on the next day, add 24 hrs to timestamp
    if (min_b < min_a)
        min_b += (HR_IN_DAY * MIN_IN_HR);
        
    return min_b - min_a;
}