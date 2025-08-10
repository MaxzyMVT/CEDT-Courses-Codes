#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n,now = 1,sum = 0;

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        now *= i;
        sum += now;
    }

    cout << sum;


    return 0;
}