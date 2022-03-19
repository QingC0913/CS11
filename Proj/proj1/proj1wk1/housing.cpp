//===============================================================
//
//
//                     housing.cpp version
//                     Author: Qing Cheng
//
//
//   Purpose: proj1, practice with manipulating structs and arrays
//   Modified: 3/22/2021
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

struct House 
{
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
        float price; 
        int num_bedrooms;
        string color;
        string avail_or_booked; 
};


//===============================================================
//                   REQUIRED FUNCTION PROTOTYPES
//
// Declare your other function prototypes here, but DO NOT 
// MODIFY ANY OF THE PROTOTYPES SUPPLIED FOR YOU BELOW!
// Note that these cannot be much higher up in your .cpp file because
// most of them need the declaration of struct House
//===============================================================

//self defined function
void ask_user(House all_houses[ROWS][COLS]);

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

int main(int argc, char *argv[])
{
        if (argc < 2)    //will terminate if no file provided from commandline
        {
            cout << "You need two arguments for the command line" << endl; 
            return 1;
        }
        string filename = argv[1];  
        bool file_opened;                      
        House all_houses[ROWS][COLS]; 
        
        fill_with_no_houses(ROWS, COLS, all_houses);  
        file_opened = read_all_house_data(filename, all_houses);
        if (not file_opened)    //if file not open, print error msg
        {
            cerr << "housing.cpp: could not open file: "
                 << filename << endl;
            return 1;   
        }
        
        ask_user(all_houses);    //gets user input and prints info for houses

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

//read_one_house
//Purpose: read one line of the input_file; return corresponding House
//Parameter: reference to the file 
//Returns: a populated House struct
House read_one_house(ifstream& input_file) 
{   
    House one_house; 
    
    //one_house.no_house_here = false;
    input_file >> one_house.id;
    input_file >> one_house.lot_code;
    input_file >> one_house.price;
    input_file >> one_house.num_bedrooms;
    input_file >> one_house.color;
    input_file >> one_house.avail_or_booked;
    
    return one_house; 
}

//print_house
//Purpose: print information about a single house
//Parameter: a House struct
//Returns: nothing
//Effects: prints out house info based on the struct given
void print_house(House h)  
{
    if (h.no_house_here == true)
    {
        cout << "No house" << endl;
        return;
    }
    
    cout << "Id: " << h.id << " Lot: " << h.lot_code 
         << " Color: " << h.color << " Price: " << h.price 
         << " Bedrooms: " << h.num_bedrooms << " Available: ";
         
    if (h.avail_or_booked == "available")
        cout << "Yes";
    else 
        cout << "No";
    
    cout << endl;     
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

//col_from_lot
//Purpose: given a lot code, compute the column in the all_houses array
//Parameter: a string that is the lot code of a specific House 
//Returns: an int that represents the col that the House is in 
int 
col_from_lot(string lot) 
{
    return lot[0] - 'A';
}

//row_from_lot
//Purpose: given a lot code, compute the row in the all_houses array
//Parameter: a string that is the lot code of a specific house 
//Returns: an int that represents the col that the House is in 
int 
row_from_lot(string lot) 
{
    string nums;
    int num, final = 0;
    int size = lot.length();
    
    for (int i = size - 1; i >= 1; i--)   //get only the nums of the lot code
    {
        nums += lot[i];
    }

    for (int i = 0; i <= size - 2; i++)   
    {
        num = nums[i] - '0';   //convert a char to an int
        if (i == 1)
            num *= 10;    //at most two digits
            
        final += num; 
    }
    
    //column nums are 1 to COL, but col array index is from 0 to COL - 1
    return final - 1;
}

//fill_with_no_houses
//Purpose: sets the no_house_here marker for every position in array
//Parameter: ints for num of rows, num of cols, and the House array 
//Returns: nothing
void 
fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) 
{
        for (int row_i = 0; row_i < rows; row_i++)
        {
            for (int col_i = 0; col_i < cols; col_i ++ )
            {
                all_houses[row_i][col_i].no_house_here = true; 
            }
        }
}

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool 
read_all_house_data(string filename, House all_houses[ROWS][COLS]) 
{
    ifstream input_file; 
    int num_of_lines, row, col;
    House each_house;

    input_file.open(filename);    //opens file
    if (not input_file.is_open())    //makes sure file is opened
        return false;       
    
    input_file >> num_of_lines;
    for (int i = 0; i < num_of_lines; i++)    //iterates thru all the lines
    {
        each_house = read_one_house(input_file);    //gets each house's info
        row = row_from_lot(each_house.lot_code);
        col = col_from_lot(each_house.lot_code);
        all_houses[row][col] = each_house;    //put house info into House arr
    }

    return true;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Self-defined function(s)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

//ask_user
//Purpose: gets user input, continuous, until user wants to stop
    //uses user input to search for a house and print out the information
//Parameter: the array containing all the houses 
//Returns: nothing
//Effects: prints statements to ask for user inputs
void ask_user(House all_houses[ROWS][COLS])
{
    int row, col;
    
    do
    {
        cout << "Enter row: "; 
        cin >> row;
        if (row < 0)
            break;
        cout << "Enter col: ";
        cin >> col;
        if (col < 0)
            break;
            
        print_house(all_houses[row][col]);
    } while (true);
}

