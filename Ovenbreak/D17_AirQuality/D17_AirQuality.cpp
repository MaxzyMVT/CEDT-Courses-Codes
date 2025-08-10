#include <bits/stdc++.h>
using namespace std;

int A[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b,Mx = INT_MIN,Mn = INT_MAX,good = 0,decent = 0,bad = 0;
    cin >> n >> m;

    vector<vector<int>> C(n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> A[i][j];

    cin >> a >> b;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(A[i][j]<a) good++;
            else if(A[i][j]<b) decent++;
            else bad++;
            Mx = max(Mx, A[i][j]);
            Mn = min(Mn, A[i][j]);
        }

    cout << "Good: " << good << "\n";
    cout << "Decent: " << decent << "\n";
    cout << "Bad: " << bad << "\n";
    cout << "Min: " << Mn << "\n";
    cout << "Max: " << Mx;


    return 0;
}