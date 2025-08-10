#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a=1,b=2,c=5,t;

    cin >> n;

    while(--n)
    {
        t = c*2+a;
        a=b;
        b=c;
        c=t;
    }

    cout << a;

    return 0;
}

//or: 1 2 5  11 24 53  117 258 569 1255
//*2: 2 4 10 22 48 106 234
//df:  0 1  1  2  5  11  24
