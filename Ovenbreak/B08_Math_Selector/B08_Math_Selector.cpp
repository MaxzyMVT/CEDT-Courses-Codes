#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,z;

    cin >> x >> y >> z;

    switch(z)
    {
        case 1: cout << x+y; break;
        case 2: cout << x-y; break;
        case 3: cout << x*y; break;
        case 4:
            if(!y)
                cout << "cannot divide by zero";
            else
                cout << x/y; 
            break;
        case 5:             
            if(!y)
                cout << "cannot divide by zero";
            else
                cout << x%y; ; 
            break;
    }

    return 0;
}