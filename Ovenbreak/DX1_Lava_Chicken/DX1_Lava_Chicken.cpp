#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, r, fried = 0, raw = 0;
    cin >> m >> n >> r;

    vector<vector<ll>> V(n+2,vector<ll>(m+2));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char com;
            cin >> com;
            if(com!='L')
                V[i][j] = com-'0';
            else
                V[i][j] = -1;    
        }    

    for(int i=1;i<=n;i++)
    {
        if(i%2) 
        for(int j=1;j<=m;j++)
        {
            if(V[i][j]==-1)
            {
                int cnt = 0;
                for(int p=i-1;p<=i+1;p++)
                    for(int q=j-1;q<=j+1;q++)
                        if(V[p][q]==-1) cnt++; 

                if(cnt>=4)
                    fried += raw*r;
                else
                    fried += raw/r;

                raw = 0;
            }
            else raw+=V[i][j];
        }
        else
        for(int j=m;j>=1;j--)
        {
            if(V[i][j]==-1)
            {
                int cnt = 0;
                for(int p=i-1;p<=i+1;p++)
                    for(int q=j-1;q<=j+1;q++)
                        if(V[p][q]==-1) cnt++; 

                if(cnt>=4)
                    fried += raw*r;
                else
                    fried += raw/r;

                raw = 0;
            }
            else raw+=V[i][j];
        }
        cout << "\n";

    }

    cout << fried;



    return 0;
}