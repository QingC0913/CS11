//q2.cpp
//Qing Cheng
//3/3/1/2021
//practice w pointers


#include <iostream>
using namespace std;

int main()
{
    int    m, n;
    int   *p1, *p2;

    p1 = &m;
    p2 = &n;
    *p1 = 8;
    cout << *p1 << endl;    //8
    
    *p2 = (*p1)++;    //dereferences first, so *p2 = 8, then (*p1)++; *p1 = 9
    // *p2 = ++(*p1) //*p2 = 1 + 8 = 9
    cout << *p1 << endl << *p2 <<endl;
    *p2 += *p2;    //8 + 8 = 16

    cout << m << " " << n << " "
         << *p1 << " " << *p2 << endl;

    return 0;
}