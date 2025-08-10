#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,z;

    cin >> x >> y >>z;
    
    while(true)
    {
        if(x%2 > y%4)
        {
            x+=2;
            y=x/2;
            if(z<y+2)
                z+=3;
        }
        else
        {
            y-=2;
            if(y>0) 
                continue;
            break;
        }
    }

    y=z+3;
    z=5+x;
    cout << x << " " << y << " " << z;

    return 0;
}