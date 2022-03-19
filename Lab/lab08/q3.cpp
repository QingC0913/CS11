

#include <iostream>
using namespace std;

int f(int *z);

int main()
{
    int    m = 6, n;

    n = f(&m);
    m = f(&n);
    cout << m << " " << n << endl;

    return 0;
}

int f(int *z)
{
    return 3 + *z ;
}