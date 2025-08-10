#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double c1, c2, c3, c4, Mx, Mn;
    cin >> c1 >> c2 >> c3 >> c4;

    Mx = c1;
    Mn = c1;

    if(Mx < c2)
        Mx = c2;
    if(Mx < c3)
        Mx = c3;
    if(Mx < c4)
        Mx = c4;

    if(Mn > c2)
        Mn = c2;
    if(Mn > c3)
        Mn = c3;
    if(Mn > c4)
        Mn = c4;

    cout << round((c1+c2+c3+c4-Mx-Mn)/2.0*100.0)/100.0 << "\n";


    return 0;
}