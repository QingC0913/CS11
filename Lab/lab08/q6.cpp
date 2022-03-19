//q6.cpp
//Qing Cheng
//3/3/1/2021
//practice w pointers

#include <iostream>
using namespace std;
    
struct Day {
    int hitemp, lotemp;
};

int main()
{
    Day week[7];
    //Day *t = &week[0];    //also works
    Day *t = week;
    for (int i = 0; i < 7; i++){
        //(*t).hitemp = 100 + i;
        t->hitemp = 100 + i;
        week[i].lotemp = week[i].hitemp - 10;
        t++;
    }
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i << " " 
             << week[i].lotemp << " " 
             << week[i].hitemp << endl;
    }
    return 0;
}
      