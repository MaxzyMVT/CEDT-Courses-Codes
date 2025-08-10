#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double tar,real,acc;
    char unit;

    cin >> tar >> unit >> real;

    switch(unit)
    {
        case 't': tar*=1000.0*1000.0; break;
        case 'k': tar*=1000.0; break;
    }

    acc = real/tar*100.0;

    if(acc == 100)
        cout << "Perfect";
    else if(acc > 105)
        cout << "Too Much";
    else if(acc >= 95)
        cout << "Pretty Good";
    else if(acc < 95)
        cout << "Add More";
    
    return 0;
}