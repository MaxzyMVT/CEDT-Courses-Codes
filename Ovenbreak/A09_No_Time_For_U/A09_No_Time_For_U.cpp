#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    double v,u,a,s;

    cin >> s >> u >> a;

    cout << fixed << setprecision(2) << sqrt(u*u+2*a*s);

    return 0;
}