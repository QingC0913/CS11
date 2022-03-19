/*
 * Preliminary program that reads in the standard input one whitespace 
 * delimited string at a time and prints the lowercase version of those 
 * that begin with a letter.
 * 
 * Only works for ASCII --- Real text is hard!
 *
 * Name: Qing Cheng     
 * Date: 04/18/2021
 * Notes:
 */
/*************  Put your program below  *************/

#include <iostream>
#include <string>
#include <fstream>    

using namespace std;

void read_words();

int main()
{
    read_words();
    
    return 0;
}

//read_words
//purpose: reads input through cin (Either user input or directed from a file)
//Parameters: none 
//Returns: nothing
//effects: if the string is a word (begins with a letter), it will be printed
 // on its own line 
void read_words()
{
    string s; 
    char c; 
    
    cin >> s; 
    
    while (not cin.eof())
    {
        c = s[0];    //takes first char  
        
        //if first char is indeed a letter, then make lowercase and print  
        if ((c >= 65  and c <= 90) or (c >= 97 and c <= 122))    
        {
            for (unsigned int i = 0; i < s.length(); i++)
            {
                s[i] = tolower(s[i]);
            }
            
            cout << s << endl;
        }
        
        cin >> s; 
    }
}
