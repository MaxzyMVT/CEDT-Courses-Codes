#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for(int i=1;i<=n;i++, cout << "\n")
        for(int j=1;j<=i;j++)
            cout << '*';

    return 0;
}