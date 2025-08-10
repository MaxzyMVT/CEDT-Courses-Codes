#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, i = 0, a, sum = 0;

    cin >> n;

    vector<long long> T(n+1);
    vector<long long> L(n+1);

    while(i++<n)
        cin >> L[i] >> T[i];

    cin >> n;

    for(i=1;i<=n;i++)
    {
        cin >> a;
        if(i==1)
        {
            cout << "T" << a << ": " << T[a] << "\n"; 
            sum += T[a];
        }
        else if(i==n)
        {
            cout << "L" << a << ": " << L[a] << "\n"; 
            sum += L[a];
        }
        else
        {
            cout << "L" << a << ": " << L[a] << "\n"; 
            cout << "T" << a << ": " << T[a] << "\n"; 
            sum += T[a] + L[a];
        }
    }

    cout << "Total : " << sum;



    return 0;
}