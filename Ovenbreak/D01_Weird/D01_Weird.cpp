#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, i = 0, sum = 0, Mx = -1, ans = 0;

    cin >> n;

    vector<int> V(n+1);

    while(i++<n)
        cin >> V[i], sum+=V[i];

    double avg = sum/double(n);

    for(i=1;i<=n;i++)
    {
        if(Mx < abs(V[i]-avg))
        {
            Mx = abs(V[i]-avg);
            ans = V[i];
        }
    }

    cout << ans;



    return 0;
}