/*
 * int_to_string.cpp
 * Program to test the int_to_string function, whose contract appears below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * By:  Qing Cheng
 * Modified 3/13/2021
 */

#include <iostream>

using namespace std;

void print_testing(int num);
void succ_or_fail(string returned, string correct_result);
string int_to_string(int num);
char int_to_char(int digit);
string reverse_char_order(string str);

int main()
{
    int num1 = 4609, num2 = -30, num3 = 0, num4 = -192837;
    
    //testing each case
    print_testing(num1);
    succ_or_fail(int_to_string(num1), "4609");
    print_testing(num2);
    succ_or_fail(int_to_string(num2), "-30");
    print_testing(num3);
    succ_or_fail(int_to_string(num3), "0");
    print_testing(num4);
    succ_or_fail(int_to_string(num4), "-192837");
            
    return 0;
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//print_testing
//Purpose: prints the testing message, since it will be repeatedly used
//Parameter: an int to print out
//Returns: nothing
//Effects: prints a message, including the int to be modify later
void print_testing(int num)
{
    cout << "TESTING: " << num << endl;
}

//succ_or_fail
//Purpose: checks whether the value returned by int_to_string is correct
//Parameter: string returned by function and also the correct result
//Returns: nothing
//Effects: prints whether the returned value is success or failure
void succ_or_fail(string returned, string correct_result)
{
    if (returned == correct_result)
        cout << "SUCCESS: ";
    else
        cout << "FAILURE: ";
        
    cout  << returned << endl;
}

//int_to_string
//Purpose: takes an int and converts it to a string representation
//Parameter: an int to be converted
//Returns: the int converted into a string
string int_to_string(int num)
{
    int last_digit, the_rest; 
    string reversed = "", final = "";
    
    if (num < 0)                      //handles neg nums
    {
        final += (string() + '-');    //adds neg sign to final str 
        num *= -1;                    //makes num positive
    }
    
    last_digit = num % 10, the_rest = num / 10; 
    
    //loop to extract last digit from the number, then add to revered string
    do
    {
        reversed += (string() + int_to_char(last_digit));
        last_digit = the_rest % 10;
        the_rest /= 10;
    } while (the_rest > 0);    //the_rest is the str minus the last digit
    
    if (last_digit > 0)
        reversed += (string() + int_to_char(last_digit));
        
    //get the chars back to the right order    
    final += reverse_char_order(reversed);
    
    return final;     
}

//int_to_char
//Purpose: converts an int digit into the equivalent ASCII char 
//Parameter: an int digit to be converted
//Returns: the char that is equivalent to the int digits
char int_to_char(int digit)
{
    int zero_ASCII = 48; 
    
    //if the last digit is 0, then will return 0 as a char instead of int 
    //same for other number chars after 0
    return zero_ASCII + digit;
}

//reverse_char_order
//Purpose: reverses the chars in a string 
//Parameter: the reversed string to be reversed backwards
//Returns: the reversed string
string reverse_char_order(string str)
{
    string final = "";

    //looping backwards, from last char to fisrt char at index 0
    for (int i = str.length() - 1; i >= 0; i--)
    {
        final += str[i];
    }
    
    return final;
}

