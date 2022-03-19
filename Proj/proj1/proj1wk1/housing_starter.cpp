//===============================================================
//
//
//                        housing.cpp version
//                     Author: <your name here>
//
//
//     [Student should fill in the header per the style guide]
//
//===============================================================


#include <iostream>
#include <fstream>

using namespace std;

// DO NOT CHANGE THE FOLLOWING CONSTANTS. WHEN YOU SUBMIT,
// THEY MUST HAVE THESE VALUES AND THEY MUST BE USED 
// AS THE DIMENSIONS FOR YOUR all_houses ARRAY.
const int ROWS = 50;
const int COLS = 20;

//===============================================================
//
//                             House
//
//     Each House struct records the information about one
//     house.  Three of the fields are declared for you and
//     you MUST use them as given.  You should declare below
//     them any additional members that you need.
//
//     Note that if the "no_house_here" member field is set
//     to true, then the other fields are not used.  Of course,
//     if no_house_here is false; then all the fields should
//     be set.
//
//===============================================================

struct House {
        // ===================================================
        //    YOU MUST LEAVE THE DECLARATIONS FOR THESE FIELDS
        //    AS THEY ARE AND MUST USE THEM FOR THEIR STATED
        //    PURPOISE
        // ===================================================

        bool   no_house_here;  // true if there is NO house on this location
        int    id;             // id from the data file, converted to int
        string lot_code;       // lot_code string from the data file

        // ===================================================
        //          DECLARE ADDITIONAL FIELDS BELOW
        // ===================================================

};


//===============================================================
//                   REQUIRED FUNCTION PROTOTYPES
//
// Declare your other function prototypes here, but DO NOT 
// MODIFY ANY OF THE PROTOTYPES SUPPLIED FOR YOU BELOW!
// Note that these cannot be much higher up in your .cpp file because
// most of them need the declaration of struct House
//===============================================================

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file);

// print information about a single house
void print_house(House h);


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, compute the column and row (respectively)
// in the all_houses array
int
col_from_lot(string lot);

int
row_from_lot(string lot);

//  set the no_house_here marker for every position
//  in the array
void
fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool
read_all_house_data(string filename, House all_houses[ROWS][COLS]);


// ============================================================
//     INCLUDE COMP11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST COME 
//   AFTER YOUR PROTOTYPE FUNCTION DECLARATIONS.
// ============================================================

#include "housing_hooks.hpp"

// ===================================================
//     END FIXED STARTER CODE
// ===================================================



//======================================================================
//                              main 
//======================================================================

int
main(int argc, char *argv[])
{
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments

        (void)argc;
        (void)argv;

        //   =======================================================
        //           YOUR MAIN FUNCTION CODE HERE
        //   =======================================================

        return 0;
}

//======================================================================
//                       YOUR FUNCTIONS HERE
//
//        We give you empty starter code for some of the required
//        functions, but you should add any you need to make your
//        code well organized (if you feel the need!)
//======================================================================


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file) {
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments
        (void)input_file;

        // YOUR CODE HERE
}

// print information about a single house
void print_house(House h)  {
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) line and this comment once you start using
        // the arguments
        (void)h;
        
        // YOUR CODE HERE
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, compute the column and row (respectively)
// in the all_houses array
int
col_from_lot(string lot) {
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) line and this comment once you start using
        // the arguments
        (void)lot;

        // YOUR CODE HERE
}

int
row_from_lot(string lot) {
        // REMOVE WHEN IMPLEMENTING
        (void)lot;

        // YOUR CODE HERE
}

//  set the no_house_here marker for every position
//  in the array
void
fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments
        (void)rows;
        (void)cols;
        (void)all_houses;

        // YOUR CODE HERE
}

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool
read_all_house_data(string filename, House all_houses[ROWS][COLS]) {
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments
        (void)filename;
        (void)all_houses;

        // YOUR CODE HERE
}
