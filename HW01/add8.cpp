/*
 * program name: add8.cpp
 * purpose: manipulate user inputs, find sum
 * author: Qing Cheng
 * date: 2/10/2021
 *
 *method 1: 9 variables
 *8 variables to store user inputs, 1 variable to store the sum
 *alternate print statements ("Enter a floating number: ") with asking for 
 *user input (cin >> var). Add each to sum (it is 0 at default) at the end.
 *
 *method 2: 2 variables
 *1 variable to store user inputs, 1 variable to store the sum
 *Print statement, ask for input, add to sum -- repeat process 7 more times.
 *
 *method 3: 2 variables, use for or while loop
 *no need to copy and paste the same statements so many times 
 *
 */
 
 #include <iostream>
 using namespace std;
 
 float num, sum;
 
 int main()
 {

    //method 2
    cout << endl;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    cout << "Enter a floating point number: ";
    cin >> num;
    sum += num;
    
    cout << "The sum is: " << sum << endl;
    
     return 0;
 }
