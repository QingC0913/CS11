/*
 * string_converter.cpp
 * Program to test the string_to_int function, whose contract appears below
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * By:  Qing Cheng
 * Modified 3/14/2021
 */

#include <iostream>
#include <cctype>

using namespace std;
int string_to_int(string s);
void print_testing(string s);
void succ_or_fail(int returned, int correct_result);
int calculations(char c, int index);
int power(int base, int power);

int main()
{
    string s1 = "Comp11 at 12", s2 = "83adf0", s3 = "four classes in a day", 
    s4 = "m1m4m5";
    
    print_testing(s1);
    succ_or_fail(string_to_int(s1), 1112);
    print_testing(s2);
    succ_or_fail(string_to_int(s2), 830);
    print_testing(s3);
    succ_or_fail(string_to_int(s3), 0);
    print_testing(s4);
    succ_or_fail(string_to_int(s4), 145);
    
    return 0;
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//print_testing
//Purpose: prints the testing message, since it will be repeatedly used
//Parameter: a string to print out 
//Returns: nothing
//Effects: prints a message, including the string to modify later
void print_testing(string s)
{
    cout << "TESTING: " << s << endl;
}

//succ_or_fail
//Purpose: checks whether the value returned by string_to_int is correct
//Parameter: int returned by function and also the correct result
//Returns: nothing
//Effects: prints whether the returned value is success or failure
//NEED TO CHANGE TO INTS LATER!!
void succ_or_fail(int returned, int correct_result)
{
    if (returned == correct_result)
        cout << "SUCCESS: ";
    else
        cout << "FAILURE: "; 
    cout  << returned << endl;
}

/*
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * Examples:  "123abc56"   => 12356
 *            "   2times3" => 23
 *            "help me!"   => 0
 *            ""           => 0
 */
int string_to_int(string s)
 {
     string numbers = "", reversed = "";
     int size, final = 0;

     for (size_t i = 0; i < s.length(); i++)     
     {
         if (isdigit(s[i]))
             numbers += s[i];   //get the chars that are digits
     }
     
     //loop backwards: reverse order of digits for calculating into int later
     size = numbers.length();
     for (int i = size - 1; i >= 0; i--)
     {
         reversed += numbers[i];
     }
     
     //calculate the int equivalent of the digits based on their index
     for (int i = 0; i < size; i++)
     {
          final += calculations(reversed[i], i);
     }
     
     return final; 
 }

//callculations
//Purpose: turns a char into the equivalent int value
    //for example, if the original string contains "123", and 
    //'1' is entered into this function, then it will return 100
//Parameters: the char (a digit) to be converted, and its index in the reversed
    //string
//Returns: the int value equivalent of the char 
int calculations(char c, int index)
{
    //int representation of the char, which is a number   
    int num = c - '0';
    
    return (num * (power(10, index)));
}

//power 
//Purpose: self-defined pow() function
//Parameter: two ints: the base, then the power, which will be the index 
    //in how things were organized in calculations() and string_to_int()
//Returns: an int that is the base raised to the power
int power(int base, int power)
{
    int result = 1; 
    
    //if power is 0, then the result will be 1
    for (int i = 1; i <= power; i++)
    {
        result *= base;     //raise 10 to a power
    }
    
    return result;
}