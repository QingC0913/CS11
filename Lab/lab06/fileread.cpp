//                            fileread.cpp
//                         Author: Noah Mendelsohn
//
//         Demonstration of reading lines from a named file
//Modified by Qing Cheng
//3/17/2021
//lab06

#include <iostream>
#include <fstream>    // *** Needed to use ifstream ***

using namespace std;

struct ClassInfo  
{
    int classNum;
    string className;
};

void read_from_file(ifstream& input);
void print_struct(ClassInfo a_class);

int main(int argc, char *argv[])
{
        //string filename = "schedule2.data";       //for opening file
        //string dep;
        //int classNum;         
        ifstream input_file;    //creates ifstream type var 
        
        if (argc < 2)
        {
            cout << "You need two arguments for the command line" << endl; 
        }
        
        //input_file.open("filename");
        
        input_file.open(argv[1]);    // opens file  from the command line

        if (not input_file.is_open())     //makes sure file is opened
        {
                cerr << "fileread.cpp: could not open file" << endl;
                return 1;           // non-zero return from main means error
        }

         read_from_file(input_file);

        /*ClassInfo FirstPeriod;    //stores one line of info in struct
        input_file >> FirstPeriod.className; 
        input_file >> FirstPeriod.classNum;
        cout << "from struct: " << FirstPeriod.className 
             << FirstPeriod.classNum << endl; */
        
        /*for (int i = 0; i < 4; i++)    //prints four lines from the file
        {        
            input_file >> dep; 
            input_file >> classNum;
            cout << dep << " " << classNum << endl;
        };*/

        input_file.close();    //closes file

        return 0;
}

//print_struct
//Parameters: a struct of ClassInfo type
//Returns: nothing
//Effects: prints out the variables in the struct
void print_struct(ClassInfo a_class)
{
    cout << "from print_struct: " << a_class.className 
         << a_class.classNum << endl; 
}

//read_from_file
//Parameters: an ifstream reference to the input file 
//Returns: nothing
//Effects: populates a struct with info read from the file 
    //calls print_struct() function 
void read_from_file(ifstream& input)
{
    ClassInfo one_class; 
    input >> one_class.className; 
    input >> one_class.classNum;
    print_struct(one_class);
}

