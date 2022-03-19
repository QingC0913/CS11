/*
 * program name: make_change.cpp
 * purpose: makes changes 
 * author: Qing Cheng
 * date: 2/10/2021
 */
 
 #include <iostream>
 using namespace std;
 
 const int QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1;
 int amount_given, rem, quarters, dimes, nickels, pennies;
 
 int main()
 {
     cout << endl;
     cout << "Amount of change in cents: ";
     cin >> amount_given;
     
     //calculates num of quarters
     quarters = amount_given / QUARTER;
     rem = amount_given % QUARTER;
     
     if (rem > 0)
     {
         //calculates num of dimes
         dimes = rem;
         dimes = rem / DIME;
         rem = rem % DIME;
         
         if (rem > 0)
         {
             //calculates num of nickels
             nickels = rem;
             nickels = rem / NICKEL;
             rem = rem % NICKEL;
             
             if (rem > 0)
             {
                 //calculates num of pennies
                 pennies = rem;
                 pennies = rem / PENNY;
                 rem = rem % PENNY;
             }
         }
     }
     
     cout << quarters << " quarters, " << dimes << " dimes, " << nickels 
          << " nickels, " << pennies << " pennies" << endl;
     
     return 0;
 }