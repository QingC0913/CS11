//*********************************************************************
//
//                       animaldb program
//
//  Author: Qing Cheng 
//  Date: 4/10/2021
//  modified: 4/12/2021
//
//  Purpose: practice with using class instances and using the heap
//
//  Known bugs: none
//
//*********************************************************************


// EXCEPT WHERE WE INDICATE THAT MODIFCATIONS ARE NEEDED, YOU
// CAN ASSUME THAT ALL CODE PROVIDED IN THIS FILE IS CORRECT.


#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"

// Command line string used to ask for classification
// report.
const string CLASSIFICATION_CMD = "classification";


//*************************************************************
//                   Function prototypes
//
//       Do not change any prototypes we provide you here.
//       You may define your own functions, in which case
//       place your own function headers below ours.
//
//       You do not need to modify our function contracts,
//       but please supply your own contract for functions
//       you write following the style guide.
//       
//*************************************************************

bool parse_cmdline(int argc, char *argv[], string *filename,
                   string *cmd, string *classification);
void print_usage_message();
void initialize_DB(ifstream& file, Animal_Array_List *all_animals);
Animal get_animal_from_file(ifstream& input_file);
void  do_classification_report(string classification,
                               Animal_Array_List *all_animals);


//*************************************************************
//                         main
//
//      THE CODE WE GIVE YOU IS CORRECT, BUT YOU WILL
//      NEED TO ADD YOUR OWN CODE TO MAKE THE PROGRAM WORK.
//
//      SEE INSTRUCTIONS IN THE COMMENTS BELOW.
//
//*************************************************************

int main(int argc, char *argv[])
{
        string filename, cmd, classification;

        // Get filename, cmd, classification from command line
        if (not parse_cmdline(argc, argv, &filename, &cmd, &classification)) {
                return 1;
        }

        // Open the file
        ifstream file;
        file.open(filename);
        if (not file.is_open()) {
            cerr << "File " << filename << " could not be opened!" 
                      << endl;
            return 1;
        }
        
        Animal_Array_List all_animals;
        initialize_DB(file, &all_animals);
        
        if (cmd == CLASSIFICATION_CMD)
            do_classification_report(classification, &all_animals);
        else
            all_animals.print();
     
        file.close();
        return 0;
}

//*************************************************************
//                     do_classification_repot
//
//  Reads animal data from the given file, and stores it in the array list
//
//  Parameters:  classification: class to search for, e.g. fish
//               Pointer to a list of animals to be searched
//  Outputs:     Prints a list of matching animals 
//
//      REPLACE THE ENTIRE BODY OF THIS FUNCTION WITH YOUR
//      CODE.
//
//*************************************************************

void  do_classification_report(string classification,
                               Animal_Array_List *all_animals) 
{   
    Animal_Array_List animal_in_class;
    int num_all_animals = all_animals->num_animals();
    int counter = 0; 

    for (int i = 0; i < num_all_animals; i++)
    {
        //use Animal_Array_List class function animal_at() to get each Animal
        //instance in the array 
        //use Animal class function classification() to check classification 
        if (all_animals->animal_at(i).classification() == classification)
        {
            animal_in_class.add(all_animals->animal_at(i));    //add to new arr
            counter++; 
        }
    }
    
    if (counter == 0)
        cout << "No animals with classification: " << classification << endl;
    else
        animal_in_class.print();
}




//===============================================================
//      THE FOLLOWING COMPLETE FUNCTIONS ARE PROVIDED FOR YOU
//
//      THE REMAINDER OF THE FUNCTIONS IN THIS FILE SHOULD BE
//      COMPLETE AND CORRECT, AND SHOULD NOT BE MODIFIED
//      BY STUDENTS.
//===============================================================



//*************************************************************
//                         initialize_DB
//
//  Reads animal data from the given file, and stores it in the array list
//
//  Parameters:  Filename to read data from, 
//               Pointer to a list to store the animals in
//  Outputs:     None
//  Effects:     Fills the passed list with animals, adding them to the back
//
//          THIS FUNCTION IS PROVIDED FOR YOU, DO NOT CHANGE IT.
//
//*************************************************************

void initialize_DB(ifstream& file, Animal_Array_List *all_animals)
{
        Animal a = get_animal_from_file(file);
        while (not file.eof()) {
            all_animals->add(a);
            a = get_animal_from_file(file);
        }
}

// Do not modify the follwoing function
Animal
get_animal_from_file(ifstream& input_file)
{
        Animal a(input_file);
        return a;
}


//*************************************************************
//
//                   parse_cmdline
//
//        Check that command line arguments are correct.
//        If not, print usage information to cerr and return false.
//        If OK return true and set values for filename, cmd
//        and classification.
//
//      THIS FUNCTION IS PROVIDED FOR YOU, DO NOT CHANGE IT.
//
//*************************************************************

bool parse_cmdline(int argc, char *argv[], string *filename,
                   string *cmd, string *classification)
{
        bool retval = true;
        
        if ( not ((argc == 2) or (argc == 4)) ) {
                retval = false;
        } else {
                // Right number of arguments supplied, surely first is filename
                *filename =  argv[1];
        }

        // Check for long commands
        if (argc == 4 ) {
                *cmd = string(argv[2]);
                // The only command we support is classification
                if (*cmd != CLASSIFICATION_CMD) {
                        retval = false;
                }
                *classification = string(argv[3]);
        }
        if (not retval) {      
                print_usage_message();
        }
        return retval;
}

void print_usage_message()
{
        cerr << "Usage: animaldb: <animal_db_filename>" << endl;
        cerr << "            -- or --" << endl;
        cerr << "Usage: animaldb: <animal_db_filename> "
                "classification <animal-class>" << endl;
        cerr << endl;
        cerr << "Typical classifications: amphibian, bird, "
                "crustacean, fish, "
                "insect, mammal, reptile" << endl;
}
