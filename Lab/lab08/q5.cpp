//q5.cpp
//Qing Cheng
//3/31/2021
//practice w pointrs
#include <iostream>
using namespace std;


struct Person {
    string name;
    int    age;
};

int main()
{
    Person x = { "Lee", 19 };
    Person y = { "Jan", 20 };
    Person *p, *q;

    p = &x;
    q = &y;

    (*p).age++; //Lee age 20
    (*q).age += 3;  //Jan age 23

    x.name = (*q).name ; //x name is Jan
    q->name = "Rob";  //deref q's name change it to Rob

    cout << x.name << " " << x.age << endl
         << y.name << " " << y.age << endl;

    return 0;
}