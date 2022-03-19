/*
* COMP11
* Spring 2021
* students.cpp
*
* Qing Cheng
* Modified 3/13/2021
* Purpose: practice with structs
*/

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;

int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);

int main() {
    
    int id; 
    
    // declare and initialize array of 
    // student structs of size TOTAL_STUDENTS
    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };
    
    //reads an ID # from cin
    cin >> id;
    //prints student info associated with the info
    print_student(find_student(id, students, TOTAL_STUDENTS), students);
    
    return 0;
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/

//find_student
//Purpose: searches array for a specific student using their id
//Parameters: int id to search, array of STudent structs, int size of array
//Returns: int index of found student in array
int  find_student(int id, Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }
    
    return -1;
}

//print_student
//Purpose: prints student info from struct
//Parameters: int index of student in array, array of Student structs
//Returns: nothing
//Effects: prints student info
void print_student(int index, Student students[])
{
    //JFFE: if invalid ID
    if (index == -1)
    {
        cout << "The student associated with the ID you entered is not found.";
        cout << endl;
        return;
    }
    
    //if index is valid
    cout << "Name:" << " " << students[index].firstName << " "
         << students[index].lastInitial << endl;
    cout << "GPA:" << " " << students[index].gpa << endl;
}
