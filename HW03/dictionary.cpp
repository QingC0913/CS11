//dictionary.cpp
//Purpose: returns definition if user input word is in the list of words
//Qing Cheng
//2/26/2021

#include <iostream>

using namespace std;

void search_dictionary(string word);
void get_input();

int main()
{
    get_input();
    
    return 0;
}
/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//get_input
//Purpose: get user input, then call search_dictionary funciton
//Parameter: none
//Returns: nothing
//Effects: calls search_dictionary function
void get_input()
{
    string word;
    cin >> word;
    
    //JFFE
    for (unsigned int i = 0; i < word.length(); i++)
    {
        word[i]= tolower(word[i]);
    }
        
    search_dictionary(word);
}

//search_dictionary
//Purpose: if user input matches one of the words in the dictionary, print
    //definition
//Parameter: the word to search for 
//Returns: nothing
//EFfects: prints the definition if word is found, otherwise, print that it 
    //is not found
void search_dictionary(string word)
{
    if (word == "variable")
        cout << "A location in the computer's memory that can store a value";
    else if (word == "function")
        cout << "A named block of code that can be invoked as a " 
             << "statement or within an expression"; 
    else if (word == "recursion")
        cout << "A situation in which a definition refers "
             << "to the term it is defining"; 
    else if (word == "pseudocode")
        cout << "A detailed description, written in human-readable "
             << "language, of an algorithm to be implemented";
    else if (word == "conditional")
        cout << "A method to execute a block of code depending on the "
             << "outcome of an expression";
    else if (word == "comp11")
        cout << "An introductory CS course at Tufts University focusing on"
             << " applying problem-solving methods in a modern context";
    else if (word == "parameter")
        cout << "A reference declared in function declaration"
             << " or definition to stand in for the argument";        
    else 
        cout << "Definition Not Found";
    
    cout << endl;
    return;
}