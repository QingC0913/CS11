/*
 * guess.cpp
 * purpose: generate a random num, give user 3 chances to guess it
 * Modified by: Qing Cheng
 * Date: 2/18/2021
 */

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;
 
int gen_random_num();
void guessing(int ran);
 
int main()
{
    // Leave the following line as the first line of main.
    // Do not call srand() again.  This is enough to enable
        // you to get a different random number each time you
        // call the program
    srand(time(nullptr));

    // Put the rest of your main here:
    int ran = gen_random_num();
    //this function asks for user input (the guess) and then outputs 
    //whether the guesses are too low, too high, or right 
    //by comparing to the ran num generated
    guessing(ran);
    
    return 0;
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//random_num
//Purpose: generates a random num between 5 and 15, inclusive
//Parameter: none
//Returns: the random int
int gen_random_num()
{
    int bigrand = rand();
    int boundedrand = bigrand % 11;
    boundedrand += 5; 
    
    return boundedrand; 
}

//guessing
//Purpose: tells user whether their guesses are too low or too high
//Parameter: the random number generated before
//Returns: nothing 
//Effect: prints result of the guesses
void guessing(int ran)
{
    int guess; 
    //counter for num of chances the user has used
    int chances = 1;
    bool correct_answer = false;
    
    do
    {
        cout << "Enter a guess: ";
        cin >> guess;
        
        if (guess > ran)
        {
            cout << "That was too high. ";
        }
        else if (guess < ran)
        {
            cout << "That was too low. ";
        }
        else 
        {
            cout << "You guessed it! Good job!" << endl;
            correct_answer = true;
            //so user doesn't have to keep guessing after getting it right
            break;
        }
        
        //counter for how many tries the user has already used
        chances++;
        
    } while (chances <= 3);
    
    //if the user has guessed 3xs and didn't guess right
    if (correct_answer == false)
        cout << "The number was " << ran << ". Better luck next time!" 
             << endl;
}
