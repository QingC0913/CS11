//recursion.cpp
//Purpose: practice recursion
//Modified by：Qing Cheng
//Date: 2/24/2021

/* pseudocode
multiply: add x y number of times
x + func(x-1)
base case: x = 0, return 0; 

sum_from: add ints from a to b, inclusive
base: b == a, return 0 
recursive case: a + sum_from(a+1)

reverse: return string w chars in reversed order
base: the index is 0, return string[0]
recursive: empty string(first time) + string[length-1]

remove_non_numeric: remove chars in a string that are not nums
base: if str.length() <= 1 
recusive: empty string + recursive call to substr(rm first char)
*/

#include <iostream>
#include <string>
//for isdigit() function
#include <cctype>

using namespace std;

int multiply(int x, int y);
int sum_from(int a, int b);
string reverse (string s);
string remove_non_numeric(string s);

int main(){
    //this is for multiply()
    int x = 2, y = 5;
    cout << multiply(x, y) << endl;
    
    //this is for sum_from()
    int a = 1, b = 7; 
    cout << sum_from(a, b) << endl;
    
    //this is reverse()
    cout << reverse ("abcdefg") << endl;
    
    //this is remove_non_numeric()
    cout << remove_non_numeric("123hi456") << endl;

    return 0;
}
//multiply
//Purpose: calculates multiplication problem using addition only
//Parameter: x (the num to be multiplied/added), y (the num of times to add)
//Returns: the product 
int multiply(int x, int y)
{
    if (y == 0)
        return 0;
    else
        return (x + multiply(x, y - 1));
}

//sum_from
//Purpose: finds sum of nums from a to b, inclusive
//Parameter: a (starting num), b(ending num)
//Returns: sum of the nums
int sum_from(int a, int b)
{
    if (b != a)
        return (a + sum_from(a+1, b));
    else
        return b;
}

//reverse
//Purpose: return a string with all the chars reversed
//Parameter: a string to be manipulated
//Returns: the manipulated starting
string reverse (string s)
{
    if (s.length() > 0)
  //last char(stored as string) + recursive call of string w/o last letter
        return (s[s.length()-1] + reverse(s.substr(0,s.length()-1)));
    else
        return "";
}

//remove_non_numeric
//Purpose: remove all non-numeral chars in a string 
//Parameter: a string s to be manipulated
//Returns: the manipulated string, with only digits
string remove_non_numeric(string s)
{  
    string word;
    if (s.length() > 0)
    {
        //if the first char is a digit, will return the digit
        if (isdigit(s[0]))
            word = s[0];
        //if the first char is not a digit, will return essentially nothing
        else
            word = "";
        //recursive call: the digit, or nothing + the string w first char rm
        return (word + remove_non_numeric(s.substr(1, s.length())));
    }
    else
        return "";
}