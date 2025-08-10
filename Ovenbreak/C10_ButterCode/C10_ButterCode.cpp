#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,sum=0;

    cin >> n;

    for(int i=2;i<=n;i++)
    {
        while(n%i==0)
            n/=i, sum+=i;
    }

    cout << sum;

    return 0;
}