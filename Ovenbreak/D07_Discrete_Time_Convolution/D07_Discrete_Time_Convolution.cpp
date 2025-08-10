#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<long long> X(n);
    vector<long long> H(n);

    for(int i=0;i<n;i++)
        cin >> X[i];

    for(int i=0;i<n;i++)
        cin >> H[i];

    for(int i=0;i<2*n-1;i++)
    {
        long long sum = 0;
        for(int j=max(0,i-n+1);j<=min(i,n-1);j++)
            sum += X[j]*H[i-j];
        cout << sum << " ";
    }



    return 0;
}