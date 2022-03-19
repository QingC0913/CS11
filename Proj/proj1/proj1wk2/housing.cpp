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
#include <string>

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
void query_loop(House all_houses[ROWS][COLS]);

void is_available_helper(House all_houses[ROWS][COLS]);
void matching_houses_helper(House all_houses[ROWS][COLS]);
void num_neighbors_helper(House all_houses[ROWS][COLS]);
int count_neighbors(string lot, House all_houses[ROWS][COLS]);
int rent_house_helper(House all_houses[ROWS][COLS]);

//required functions for proj1wk2
bool is_available(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color,
    int desired_bedrooms, House all_houses[ROWS][COLS],
    House results[ROWS * COLS]); 
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
int rent_house(int house_id, House all_houses[ROWS][COLS]);
    
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
        cerr << "housing.cpp: could not open file: " << filename << endl;
        return 1;   
    }
    
    query_loop(all_houses);
    
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
    
    one_house.no_house_here = false;  //can read from file, house exists
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
    
    input_file >> num_of_lines;    //reads n count at top of data file 
    for (int i = 0; i < num_of_lines; i++)  
    {
        each_house = read_one_house(input_file);    //store info in a struct
        row = row_from_lot(each_house.lot_code);
        col = col_from_lot(each_house.lot_code);
        all_houses[row][col] = each_house;    //put struct into House array
    }
    
    return true;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Self-defined function(s)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

//ask_user
//Purpose: gets user input, continuous, until user wants to stop,
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

//query_loop
//Purpose: asks user what command they would like to do
//Parameters: all_houses array of House structs 
//Returns: nothing
//Effects: calls diff helper functions depending on what user wants to do 
void query_loop(House all_houses[ROWS][COLS])
{
    string input;
    int i;
        
    do 
    {
        cout << "query-> ";
        cin >> input;
        
        if (input == "q")
            return;    
        else if (input == "a")
            is_available_helper(all_houses);
        else if (input == "m")
            matching_houses_helper(all_houses);
        else if(input == "n")
            num_neighbors_helper(all_houses);
        else if(input == "r")
        {
            i = rent_house_helper(all_houses);
            if (i == 0)
                return;    //user rents a house, return to main, end program    
        }
        else 
            cout << "Unknown command " << input << endl;
        
    } while (input != "q");
}


//is_available_helper
//Purpose: helper function in the query loop for is_available() function 
//Parameter: all_houses array 
//Returns: nothing
//Effects: prints results returned by is_available()
void is_available_helper(House all_houses[ROWS][COLS])
{
    int id; 
    
    cin >> id; 
    if (is_available(id, all_houses))
        cout << "House " << id << " is available" << endl; 
    else 
        cout << "Sorry, House " << id 
             << " is not available" << endl;
}

//matching_houses_helper
//Purpose: helper function in the query loop for matching_houses() funciton 
//Parameter: all_houses array 
//Returns: nothing
//Effects: prints results returned by matching_houses()
void matching_houses_helper(House all_houses[ROWS][COLS])
{
    float price; 
    string color;
    int bedrooms, num_match;
    House match_houses[ROWS * COLS];    //to store matched houses 
    
    cin >> price; 
    cin >> color;
    cin >> bedrooms;
    
    num_match = 
    matching_houses(price, color, bedrooms, all_houses, match_houses);

    cout << "Matching Houses:" << endl;    
    for (int i = 0; i < num_match; i++)
    {
        print_house(match_houses[i]);    //prints each matching house
    }
}

//num_neighbors_helper
//Purpose: helper function in the query loop for num_neighbors() funciton 
//Parameter: all_houses array 
//Returns: nothing
//Effects: prints results returned by num_neighbors()
void num_neighbors_helper(House all_houses[ROWS][COLS])
{
    int id, num_neigh; 
    
    cin >> id; 
    
    num_neigh = num_neighbors(id, all_houses);
    
    if (num_neigh == 0)
        cout << "You have no neighbors, practice your drums!" << endl;
    else if (num_neigh >= 1)
        cout << "You have " << num_neigh << " neighbors!" << endl;
}

//rent_house_helper
//Purpose: helper function in the query loop for rent_house() funciton 
//Parameter: all_houses array 
//Returns: an int, 0 to signal for query to return to main
//Effects: prints results returned by rent_house()  
int rent_house_helper(House all_houses[ROWS][COLS])
{
    int id, num;
    
    cin >> id;
    num = rent_house(id, all_houses);    //0, 1, or 2, based on availability
    
    if (num == 0)
        cout << "You can't rent a house that doesn't exist, but " 
             << "good try" << endl;
    else if (num == 2)
        cout << "Too late...i hear the dumpster behind hill has some "
             << "spaces open" << endl;
    else if (num == 1)
    {
        cout << "Congrats, you rented a house! Hope your door knobs "
             << "don't fall off" << endl; 
        return 0;    //sign for query_loop() to return to main()
    }
     
     return -1;    //just needs to return any value that is not 0
}

//is_available
//Purpose: given a house id, checks if the house is availabe or booked 
//Parameter: a house id, the House array of all the houses 
//Returns: true if available, false if booked or not listed
bool is_available(int house_id, House all_houses[ROWS][COLS])
{
    for (int row_i = 0; row_i < ROWS; row_i++)
    {
        for (int col_i = 0; col_i < COLS; col_i++)
        {
            if ((all_houses[row_i][col_i].id == house_id) and 
                (all_houses[row_i][col_i].avail_or_booked == "available"))
            return true;
        }
    }
    
    return false;
}

//matching_houses
//Purpose: given desired features, check all_houses array to create an array 
    //of houses that match the features
//Parameters: max price, desired house color, desired num of bedrooms, 
    //the all_houses array, and an empty array to store matched houses 
//Returns: number of houses that match the desired features 
int matching_houses(float max_price, string desired_color,
    int desired_bedrooms, House all_houses[ROWS][COLS],
    House results[ROWS * COLS])
{
    int counter = 0;
    
    for (int row_i = 0; row_i < ROWS; row_i++)
    {
        for (int col_i = 0; col_i < COLS; col_i++)
        {
            //if matches all three criteria: price, color, bedrooms
            if ((all_houses[row_i][col_i].price <= max_price) and 
                (all_houses[row_i][col_i].color == desired_color) and 
                (all_houses[row_i][col_i].num_bedrooms >= desired_bedrooms))
            {
                //add to new array and increase counter
                results[counter] = all_houses[row_i][col_i];
                counter++;
            }
        }
    }    
    
    return counter;
} 

//num_neighbors
//Purpose: find num of neighbors around a given house 
//Parameters: a house id and the array of houses 
//Returns: num of neighbors around the house 
//Effects: calls helper function count_neighbors()    
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
    string lot; 

    //use id to find lot code of house 
    for (int row_i = 0; row_i < ROWS; row_i++)
    {
        for (int col_i = 0; col_i < COLS; col_i++)
        {
            if (all_houses[row_i][col_i].id == house_id)       
            {
                lot = all_houses[row_i][col_i].lot_code;
                return count_neighbors(lot, all_houses);
            }
        }
    }
    
    return 0;
}

//count_neighbors
//Purpose: use lot code to find row and col of house, find if neighboring
    //houses are booked 
//Parameter: the lot code and the array of Houses
//Returns: num of neighbors 
//Effects: returns num of neighbors to the num_neighbors() function 
int count_neighbors(string lot, House all_houses[ROWS][COLS]) 
{
    int r = row_from_lot(lot), c = col_from_lot(lot), counter = 0;
    
    if (r - 1 >= 0) {    //checks neighbors in row above the current house
        if (((c - 1) >= 0) and (all_houses[r - 1][c - 1].avail_or_booked 
           == "booked"))
           counter++;
        if (all_houses[r - 1][c].avail_or_booked == "booked")
            counter++;
        if (((c + 1) < COLS) and (all_houses[r - 1][c + 1].avail_or_booked
           == "booked"))
            counter++;
    }

    if (r + 1 < ROWS) {    //checks neighbors in row below the current house
        if (((c - 1) >= 0) and (all_houses[r + 1][c - 1].avail_or_booked
           == "booked"))
           counter++;
        if (all_houses[r + 1][c].avail_or_booked == "booked")
           counter++;
        if (((c + 1) < COLS) and (all_houses[r + 1][c + 1].avail_or_booked
           == "booked"))
           counter++;
    }
    
    if (((c - 1) >= 0) and (all_houses[r][c - 1].avail_or_booked == "booked"))
        counter++;
    if (((c + 1) < COLS) and (all_houses[r][c + 1].avail_or_booked == "booked"))
        counter++;

    return counter;
}

//rent_house
//Purpose: given a house id, checks whether a house is available for rent 
//Parameters: the house id to check and array of all the houses 
//Returns: 0, 1, or 2, depending on the availability of the house
int rent_house(int house_id, House all_houses[ROWS][COLS])
{
    for (int row_i = 0; row_i < ROWS; row_i++)
    {
        for (int col_i = 0; col_i < COLS; col_i++)
        {
            if (all_houses[row_i][col_i].id == house_id)
            {
                if (all_houses[row_i][col_i].avail_or_booked == "booked")
                    return 2;
                    
                else if (all_houses[row_i][col_i].avail_or_booked 
                         == "available")
                {
                    all_houses[row_i][col_i].avail_or_booked == "booked";
                    return 1;
                }
            }
        }
    }
    
    return 0;    //if id wasn't matched in the array = doesn't exist
}