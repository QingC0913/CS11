/*
    moviedb.cpp
    Purpose: Interact with arrays of structs by manipulating
            and searching a movie database
    Written by: Keisha Mukasa
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_MOVIES = 450;
const int NUM_ACTORS = 5;

struct Movie
{
    string title;
    int year;
    double gross;
    string director;
    string actors[NUM_ACTORS];
};

void read_movie_data(Movie movies[NUM_MOVIES]);
//void print_movies(Movie movies[NUM_MOVIES], int num);
void find_movie(Movie movies[NUM_MOVIES]);
void movie_in_yr(Movie movies[NUM_MOVIES]);
void find_gross(Movie movies[NUM_MOVIES]);

int main()
{
    // This line of code declares a list of 450 movies obje
    Movie movie_list[NUM_MOVIES];
    // This function call is populating the movie list with all
    // the movies in the file. Do not worry about its implementation.
    read_movie_data(movie_list);

    /* Your code goes here */
    find_movie(movie_list);
    movie_in_yr(movie_list);
    find_gross(movie_list);
    
    return 0;
}
/*


YOUR FUNCTIONS GO HERE


*/

/************************************************************
 *                     NOTE                               
 * The function below are part of the starter code that enable
 * you to read in from a file. You do not need to understand
 * the code below to complete the lab and we encourage you to
 * ignore this code. This implementation will be covered in the
 * future but is not currently required for lab or hw.
*************************************************************/

/*  
*   READ_MOVIE_DATA
*   Parameters: Empty movie array
*   Purpose: Read lists of movies data from a file and store in array
*   Returns: Does not return anything
*/
void read_movie_data(Movie movies[NUM_MOVIES])
{
    // ifstream object declaration in order to open and read
    // from a file
    ifstream infile;
    string filename = "moviedata.txt";

    // open file
    infile.open(filename);

    // check if file successfully opened if it isn't the program is
    // exited immediately
    if (infile.fail())
    {
        cerr << "ERROR: Error opening file, please check file name: "
             << filename << endl;
        exit(EXIT_FAILURE);
    }

    // read through file
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        getline(infile, movies[i].title);
        infile >> movies[i].year;
        infile >> movies[i].gross;
        infile.ignore();
        getline(infile, movies[i].director);

        // reads in each actors name
        for (int j = 0; j < NUM_ACTORS; j++)
        {
            getline(infile, movies[i].actors[j]);
        }
    }
}

//find_movie
//Purpose: determines whether a given movie is in list, prints movie info
//Parameter: the array of Movie structs
//Returns: nothing
//Effects: if movie title given by user is found in array, print out the 
    //movie's info
void find_movie(Movie movies[NUM_MOVIES])
{
    string user_input;
    
    cout << "Enter name of the movie to search for: " ;
    getline(cin, user_input);
    
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        if (movies[i].title == user_input)
        {
            cout << "Title: " << movies[i].title << "\nYear: " 
                 << movies[i].year << "\nBox-Office Gross: "
                 << movies[i].gross << "\nDirector: " 
                 << movies[i].director << "\nActors: "; 
                 
            for (int x = 0; x < NUM_ACTORS; x++)
            {
                cout << movies[i].actors[x] << endl;
            } 
            return;
        }
    }    
        cout << user_input << " was not found in the movie database." 
             << endl;    
        cout << endl;       
}

//movie_in_yr
//Purpose: finds movies released in a given yr
//Parameter: the array of Movie structs
//Returns: nothing
//Effects: prints out a list of movies released in the yr dictated by the user
void movie_in_yr(Movie movies[NUM_MOVIES])
{
    int yr; 
    int counter = 0; 
    
    cout << "Enter the year to search for: " ;
    cin >> yr;
    
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        
        if (movies[i].year == yr)
        {
            counter++;
            cout << movies[i].title << endl;
        }
    }
    
    if (counter == 0)
        cout << "There is no movie for this year" << endl;
    
    cout << endl;       
}

//find_gross
//Purpose: finds highest grossing, lowest grossing, and avg gross from list
//Parameter: the array of Movie structs
//Returns: nothing
//Effects: prints the information found
void find_gross(Movie movies[NUM_MOVIES])
{
    int max = movies[0].gross;
    int min = movies[0].gross;
    double sum;
    int max_index = 0, min_index = 0;
    
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        sum += movies[i].gross; 
        if (movies[i].gross > max)
        {
            max = movies[i].gross;
            max_index = i;
        }
        else if (movies[i].gross < min)
        {
            min = movies[i].gross;
            min_index = i; 
        }
    }
    
    sum /= NUM_MOVIES; 
    cout << "highest grossing movie: " << movies[max_index].title << endl;
    cout << "gross: " << movies[max_index].gross << endl;
    cout << "lowest grossing movie: " << movies[min_index].title << endl;
    cout << "gross: " << movies[min_index].gross << endl;
    cout << "avg gross of the 450 movies: " << sum << endl;  
    
    cout << endl;           
}