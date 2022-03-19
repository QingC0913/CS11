/*
 * rps.cpp
 * purpose: generates a game of rock, paper, scissors against user
 * Modified by: Qing Cheng
 * Date: 2/18/2021
 */

#include <iostream>
#include <string>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;
 
int gen_random_num();
int rps_to_num(char user_move);
void who_wins(int user_int, int computer_int);
string num_to_rps(int move_int);

int main()
{
    // Leave the following line as the first line of main.
    // Do not call srand() again.  This is enough to enable
    // you to get a different random number each time you
    // call the program
    srand(time(nullptr));
    
    // Put the rest of your main here:
    char user_move;
    int user_int;
    //computer makes a move based on a ran num
    int computer_int = gen_random_num();
    
    //user enters a move --  a char        
    cout << "Enter rock (r), paper (p), or scissors (s): ";
    cin >> user_move;
    
    //JFFE
    user_move = tolower(user_move);
    //if it's not one of these 3 letters
    if ((user_move != 'r') and (user_move != 'p') and (user_move != 's'))
    {
        cout << "Please only enter rock (r), paper (p), or scissors (s): ";
        cin >> user_move;
    }
    
    //converts user choice --  a char -- into 0, 1, or 2
    user_int = rps_to_num(user_move);
    //method to determine who wins by comparing the two ints
    who_wins(user_int, computer_int);
    
    return 0;
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/
//random_num
//Purpose: generates a random num between 0 and 2, inclusive
//Parameter: none
//Returns: the random int
int gen_random_num()
{
    int bigrand = rand();
    int boundedrand = bigrand % 3;

    return boundedrand; 
}

//rps_to_num
//Purpose: converts the user input (a charachter) into a number
//Parameter: a char that is the user input
//Returns: an int that is the user input
int rps_to_num(char user_move)
{
    if (user_move == 'r')
        return 0;
    else if (user_move == 'p')
        return 1;
    else 
        return 2;
}

//who_wins
//Purpose: determines whether the user wins, loses, or it's a tie 
//Parameter: int vars -- user and computer moves
//Returns: nothing, prints statement of game outcome
//Effects: prints result of the game
void who_wins(int user_int, int computer_int)
{
    //situations when the computer would win
    if ((computer_int == 2 and user_int == 1) 
     || (computer_int == 1 and user_int == 0) 
     || (computer_int == 0 and user_int == 2))
    {
         cout << "You lost. The computer chose " << num_to_rps(computer_int) 
              << "." << endl;
    }
    //if the two ints are the same, then it's a tie
    else if (computer_int == user_int)
    {
        cout << "It's a tie. The computer also chose " 
             << num_to_rps(computer_int) << "." << endl;
    }
    //rest of the outcomes = the user wins
    else
    {
        cout << "You won! The computer chose " << num_to_rps(computer_int) 
             << "." << endl;
    }
}

//num_to_rps
//Purpose: converts whatever move the computer or user makes into a word 
//parameters: an int, whatever move the computer or user makes
//Returns: a string -- rock, paper, or scissors
string num_to_rps(int move_int)
{
    if (move_int == 0)
        return "rock";
    else if (move_int == 1)
        return "paper";
    else
        return "scissors";
}
