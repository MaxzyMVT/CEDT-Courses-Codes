#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b,sum=0;

    cin >> n >> m;

    vector<vector<int>> V(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> V[i][j];    

    cin >> a >> b;

    for(int i=1;i<=n;i++)
        sum += V[i][b];

    for(int j=1;j<=m;j++)
        sum += V[a][j];


    sum -= V[a][b];

    cout << sum;



    return 0;
}