#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    unsigned long long a, Mx = 0, Mx2 = 0;

    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a > Mx)
            Mx2 = Mx,
            Mx = a;
        else if(a < Mx && a > Mx2)
            Mx2 = a;
    }

    cout << Mx2; 

    return 0;
}