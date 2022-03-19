// welcome.cpp
//
// Purpose: Welcome the squad to their new favorite class.
// Author:  Megan Monroe (mmonroe)
// Edited by Qing Cheng, 2/2/2021 
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
        string name;
        
        // Get the user's name
        cout << endl;
        cout << "Hello!";
        cout << endl;
        cout << "Please enter your name: ";
        cin >> name;

        // Print the welcome message
        cout << endl;
        cout << name << " is excited to start the CS11 class! Yay! ";
        cout << "Welcome to Comp 11!" << endl;
        cout << endl;

        return 0;
} 
