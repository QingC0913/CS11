// Start with a base price,
// then adjust based on various conditions

 //add one condition at a time, then test it, 
 //9then add the next, and so on …
 /*
 name: Qing Cheng
 date: 2/10/2021
 purpose: this program determines the price of a ticket
          based on difference conditions (weather, temperature, weekend, etc.)
 */
 
 #include <iostream>
 using namespace std;

 int main()
 {
     const double BASE_PRICE = 9;
     const double PER_DEGREE_PENALTY = 0.1;
     const double  HIGH_TEMP = 80;
     const double  LOW_TEMP = 65;
     const int TIME = 1700;
     const int RAIN_PENALTY = 2;
     double price = BASE_PRICE;
     double temp; 
     char weekend;  
     int time;    
     char raining;
      
     //checks if temp is too high or too low
     cout << endl;
     cout << "Enter current tempterature, in whole degrees F:\n";
     cin >> temp;
     if (temp > HIGH_TEMP)
        price = price - (PER_DEGREE_PENALTY * (temp - HIGH_TEMP));
     
     else if (temp < LOW_TEMP)
        price = price - (PER_DEGREE_PENALTY * (LOW_TEMP - temp)); 

    //checks if is weekend
    cout << endl;
    cout << "Is it the weenkend? Enter only \'y\' or \'n\'\n";
    cin >> weekend;
    if (weekend == 'y')
    {
        cout << "It is the weekend! Additional $1!\n";
        price ++; 
    }
    
    //checks if is after 1700
    cout << endl;
    cout << "What time is it? Enter in military style.\n"
         << "For example, if it is 8 p.m., enter \'2000\'\n";
    cin >> time;
    if (time > TIME)
    {
        cout << "It is after 1700, or 5 p.m.! Additional $1!\n";
        price ++; 
    }

    //checks if it is raining
    cout << endl;
    cout << "Is it raining? Enter only \'y\' or \'n\'\n";
    cin >> raining;
    if (raining == 'y')
    {
            cout << "It is raining! $2 off!\n";
            price -= RAIN_PENALTY;    
    }    
    
    cout << "Your ticket price is: " << price << endl;
    cout << endl;
    
    return 0;
 }
