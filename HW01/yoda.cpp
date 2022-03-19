/*
 * program name: yoda.cpp
 * purpose: manipulate user inputs
 * author: Qing Cheng
 * date: 2/10/2021
 */

#include <iostream>
#include <string>
using namespace std;

string word1, word2, word3, word4;

int main()
{
    cout << endl;
    cout << "Type in four words: ";
    cin >> word1 >> word2 >> word3 >> word4;
    
    cout << word4 << " " << word3 << " " << word2 << " " << word1 << endl;
    
    return 0;
}