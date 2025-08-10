#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n,a = 0,b = 1,c = 1, sum=0;
    cin >> n;

    while(n--)
    {
        a = b;
        b = c;
        c = a+b;
        sum += a;
    }

    cout << sum;

    return 0;
}