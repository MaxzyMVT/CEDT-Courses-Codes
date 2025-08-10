#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,Mx = INT_MIN,Mn = INT_MAX;
    double sum = 0;

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a, sum += a, Mx = max(Mx, a), Mn = min(Mn, a);

    cout << ceil(Mx + Mn + sum/n);


    return 0;
}