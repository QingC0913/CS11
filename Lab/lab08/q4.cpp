//q4.cpp
//Qing Cheng
//3/3/1/2021
//practice w pointers

#include <iostream>
using namespace std;

int f(int *z);

int main()
{
    int m = 5, n;

    n = f(&m);

    cout << m << " " << n << endl;

    return 0;
}

int f(int *z)
{
    if ( *z <= 0 )
        return *z + 1;

    *z -= 2;

    return f(z);
}