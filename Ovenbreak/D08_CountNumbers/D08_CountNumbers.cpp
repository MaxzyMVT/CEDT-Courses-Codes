#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N[10] = {}, a;
    string in;

    cin >> n;
    while(n--)
    {
        cin >> in;
        for(auto x : in)
            N[x-'0']++;
    }

    cin >> n;
    while(n--)
    {
        cin >> a;
        cout << a << ": " << N[a] << "\n";
    }




    return 0;
}