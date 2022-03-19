/*
 * flights.cpp
 * purpose: calculates layover and total flight time given data
 * Modified by: Qing Cheng
 * Date: 2/18/2021
 */
 
 #include <iostream>
 
 using namespace std;
 
 const int MIN_IN_HR = 60; 
 
 int calc_hrs(int hr_a, int min_a, int hr_b, int min_b);
 int convert_to_hr(int num);
 int convert_to_min(int num);
 
 int main()
 {
     int hr_1, min_1, hr_2, min_2, hr_3, min_3, hr_4, min_4;  
     int total_time = 0, flight_hrs, layover = 0, hr, min;
     
     cout << "Flight 1: ";
     cin >> hr_1; 
     cin >> min_1; 
     cin >> hr_2; 
     cin >> min_2;
     cout << "Flight 2: ";
     cin >> hr_3; 
     cin >> min_3; 
     cin >> hr_4; 
     cin >> min_4; 
     
     //duration of flight 1
     flight_hrs = calc_hrs(hr_1, min_1, hr_2, min_2);
     total_time += flight_hrs; 
     
     //duration of flight 2
     flight_hrs = calc_hrs(hr_3, min_3, hr_4, min_4);
     total_time += flight_hrs; 

     //now sum has total hrs of flight, need hrs of layover
     layover = calc_hrs(hr_2, min_2, hr_3, min_3);
     //total hours in airport = flights + layover
     total_time += layover; 
     
     //converts layover time into hours and minutes, print statement
     hr = convert_to_hr(layover); 
     min = convert_to_min(layover); 
     cout << "Layover: " << hr << " hr " << min << " min" << endl; 
     
     //converts total hours spend in airport into hours and minutes
     //print results in a statement
     hr = convert_to_hr(total_time); 
     min = convert_to_min(total_time); 
     cout << "Total: " << hr << " hr " << min << " min" << endl; 

     return 0;
 }
 
 /*************************************************************************
                         FUNCTION DECLARATIONS 
 *************************************************************************/
 //calc_hrs
 //Purpose: calculates how many mins there are between two given times
 //Parameters: four int vars representing the hours and mins of the times
 //Returns: total num of minutes between the two times
 int calc_hrs(int hr_a, int min_a, int hr_b, int min_b)
 {   
     //use this when the flight time is on the next day
     if (hr_a > hr_b)
     {
         hr_b += 24; 
     }
     
     return ((hr_b * MIN_IN_HR + min_b) - (hr_a * MIN_IN_HR + min_a));
 }
 
 //convert_to_hr
 //Purpose: converts minutes into whole hours
 //Parameters: an int representing total mins to be converted into hours 
 //Returns: the whole number of hours
 int convert_to_hr(int num)
 {
     return (num / MIN_IN_HR);    
 }

//convert_to_min
//Purpose: calculates remainder minutes (that is not in a whole hr)
//Parameters: an int representing total mins to be converted into hours 
//Returns: the mins leftover that is less than an hr
 int convert_to_min(int num)
 {
     return (num % MIN_IN_HR);
 }