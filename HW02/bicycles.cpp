/*
 * bicycles.cpp
 * purpose: calculates num of bikes that can be made from a number of parts
 * Modified by: Qing Cheng
 * Date: 2/18/2021
 */
 
 #include <iostream>
 #include <string>

 using namespace std;

 void calc_num_of_bikes(int num_of_frames, int num_of_links, 
                        int num_of_wheels, int num_of_bikes);
 string sin_or_plur_word(string word, int num);

 int main()
 {
     int num_of_frames, num_of_links, num_of_wheels, num_of_bikes = 0;
     
     cout << "Enter the number of wheels: ";
     cin >> num_of_wheels;
     cout << "Enter the number of frames: ";
     cin >> num_of_frames;
     cout << "Enter the number of links: ";
     cin >> num_of_links;
     
     //to calculate and update num of bikes using the num of each part
     calc_num_of_bikes(num_of_frames, num_of_links,  
                       num_of_wheels, num_of_bikes);
     
     return 0;
 }
 
 /*************************************************************************
                         FUNCTION DECLARATIONS 
 *************************************************************************/
 //calc_num_of_bikes
 //Purpose: calculate number of bikes that can be made with 
 // the given parts, then prints a statement with that information
 //Parameter: number of frames, links, wheels, and bikes 
     //notes: tried to declare var bike in the function and initialize to 0,
     //but clears the total number of bikes during recursion calls 
 //Returns: nothing
 //Effects: alters num of bikes, prints a message telling how many bikes 
         // can be made and how many of each part is left
 void calc_num_of_bikes(int num_of_frames, int num_of_links, 
                        int num_of_wheels, int num_of_bikes)
 {
     string frame = "frame", link = "link", wheel = "wheel", bike = "bike";
     
     //see if there is enough of each part to make one whole bike
     if ((num_of_frames >= 1) and 
         (num_of_links >= 50) and 
         (num_of_wheels >= 2))
     {
         num_of_frames -= 1;
         num_of_links -= 50;
         num_of_wheels -= 2;
         num_of_bikes++;
         
         //recursion
         calc_num_of_bikes(num_of_frames, num_of_links, 
                           num_of_wheels, num_of_bikes);
     }
     
     //if there aren't enough of one or more parts
     //base case
     else
     {
         //modifies wording: singular or regular?
         frame = sin_or_plur_word(frame, num_of_frames);
         link = sin_or_plur_word(link, num_of_links);
         wheel = sin_or_plur_word(wheel, num_of_wheels);
         bike = sin_or_plur_word(bike, num_of_bikes);
         
         //prints out final statement:
         //how many bikes can be made and how many of each part is left
         //only print when recursion is over, so only one statement will print
         cout << "You can make " << num_of_bikes << " " << bike << ". ";
         cout << "There are " << num_of_wheels << " " << wheel 
              << ", " << num_of_frames << " " << frame << ", "
              << num_of_links << " " << link << " leftover." << endl; 
      }
 }

 //sin_or_plur_word
 //Purpose: modifies a given word given the number of parts 
 //Parameter: the string to be modified, the number of parts 
 //Returns: the modified string
 string sin_or_plur_word(string word, int num)
 {
     if (num != 1)
         //concatenation
         word = word + "s";
    //else if num is indeed 1, will return word unchanged     
     return word;
 }