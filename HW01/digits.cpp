// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Qing Cheng
//         date: 2/13/2021
///

#include <iostream>
using namespace std;

int input;

int main()
{
         
        cout << endl;
        cout << "Enter a number: ";
        cin  >> input;

        if ((input >= 100) || (input <= -100)) 
        {
            cout << "input has three or more digits" << endl;
        }
        else if ((input >= 10) || (input <= -10))
        {
            cout << "input has two digits" << endl;
        } 
        else if ((input >= 0) || (input < 0))
        {
            cout << "input has one digit" << endl;
        }
        
        if (input < 0)
            cout << "and input is negative" << endl;
         
        return 0;
}
