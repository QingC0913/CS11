//Qing Cheng
//Modified 3/11/2021
//60 mins
//hw 05
//practice with arrays

#include <iostream>
using namespace std;

int most_common_int(int numbers[], int length);
void print_array(int numbers[], int length);
void succ_or_fail(int returned, int correct_result);

const int LENGTH = 10;
int main()
{
    int num1[] = {1, 3, 3, 6, 7, 4, 2, 4, 4, 4};
    int num2[] = {5, 8, 2, 7, 8, 8, 6, 6, 0, 6};
    int num3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num4[] = {4, 6, 8, 4, 56, 12, 7, 8, 3, 78};
    
    //four test cases: print each array then print success or failure
    print_array(num1, LENGTH);
    succ_or_fail(most_common_int(num1, LENGTH), 4);
    print_array(num2, LENGTH);
    succ_or_fail(most_common_int(num2, LENGTH), 6);
    print_array(num3, LENGTH);
    succ_or_fail(most_common_int(num3, LENGTH), 1);
    print_array(num4, LENGTH);
    succ_or_fail(most_common_int(num4, LENGTH), 4);
    
    return 0; 
}

/*************************************************************************
                        FUNCTION DECLARATIONS 
*************************************************************************/

//most_common_int
//Purpose: takes array, finds most repeated num; if tie, return smallest num 
//Parameters: array of nums, length of array
//Returns: num appeared most often
int most_common_int(int numbers[], int length) {
    int most_common_num = numbers[0], most_common_counter = 1; 
    int temp_counter = 1, temp_loc, temp_num;

    for (int i = 0; i < length; i++) {    //loops thru each num in array
        temp_counter = 1;   //resets counter
        
        for (int j = i + 1; j < length; j++) {    //checks the rest of the nums
            temp_loc = j;
            
            if (numbers[j] == numbers[i])
                temp_counter++;             
        }        
        
        //if current num appears more than the most common num,
        if (temp_counter > most_common_counter) {
            most_common_counter = temp_counter;
            most_common_num = numbers[i];
        }

        else if (temp_counter == most_common_counter) {    //two equally common
            temp_num = numbers[temp_loc];

            if (temp_num < most_common_num)    //choose smaller num
                most_common_num = temp_num;
        }            
    }
    return most_common_num; 
}

//print_array
//Purpose: prints the items in an arrays
//Parameters: an array of nums and the length 
//Returns: nothing
//Effects: prints each item in the array
void print_array(int numbers[], int length)
{
    cout << "TESTING: "; 
    for (int i = 0; i < length; i++)
    {
        cout << numbers[i] << " ";
    }
    
    cout << endl;
}

////succ_or_fail
//Purpose: checks whether the value returned by most_common_int() is correct
//Parameter: int returned by function and also the correct result
//Returns: nothing
//Effects: prints whether the returned value is success or failure
void succ_or_fail(int returned, int correct_result)
{
    if (returned == correct_result)
        cout << "SUCCESS: "; 
    else 
        cout << "FAILURE: ";
        
    cout << returned << endl;
}
