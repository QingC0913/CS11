/*
 * wordfreq
 *
 * 1. Reads in strings from the standard input (cin)
 *    Ignores non-words (where a "word" is a sequence of non-whitespace
 *    characters beginnig with an upper or lowercase letter
 * 2. Converts each word to lower case
 * 3. Inserts each word into a WordFreqList to track the number of
 *    times each word is seen

 * 4. When the input is fully processed, prints a line for each word
 *    in the WordFreqList formatted thus:
 *    the interger number of occurrences of the word, a single space,
 *    the word itself, a newline.  E. g., "14 we\n"
 *
 * Only works for ASCII --- Real text is hard!
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 *
 *
 * Student name: Qing Cheng 
 * Date: 4/27/2021
 *
 * Anything else you would like to include
 */

#include <iostream>
#include <string>
#include <cctype>

// The following file will be a copy of the file you want
// DON'T CHANGE THIS!
#include "WordFreqList.h"
// Seriously, Don't change the line above.  It's important!

using namespace std;

/*************  Put your program below  *************/
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
    WordFreqList obj; 
    
    cin >> s; 
    
   while (not cin.eof())
    {
        c = s[0];    //takes first char  
        
        //if first char is indeed a letter, then make lowercase and add
        if ((c >= 65  and c <= 90) or (c >= 97 and c <= 122))    
        {
            for (unsigned int i = 0; i < s.length(); i++)
            {
                s[i] = tolower(s[i]);     
            }
            
            obj.countOccurrence(s);
        }
        
        cin >> s; 
    }
    
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj.get(i).freq << " " << obj.get(i).word << endl;
    }
    
}
