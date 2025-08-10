#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll H[5000][5000];
ll S[5000][5000];
ll happy[5000];
ll sad[5000];
ll len[5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, N, l, c, v, h, s, Mx = 0;

    cin >> L >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> l >> c >> v;
        len[i] = l;
        if(c==1)
            sad[i] = v, happy[i] = 0;
        else
            sad[i] = 0, happy[i] = v;
    }


    for(int i=1;i<=N;i++)
    {
        l = len[i];
        h = happy[i];
        s = sad[i];

        for(int j=1;j<=L;j++)
        {
            if(j<l)
            {
                H[i][j] = H[i-1][j];
                S[i][j] = S[i-1][j];
                continue;
            }
            H[i][j] = max(H[i-1][j], H[i-1][j-l] + h);
            S[i][j] = max(S[i-1][j], S[i-1][j-l] + s);
        }
    }    

    for(int j=1;j<=L;j++)
    {
        Mx = max(Mx, min(S[N][j], H[N][L-j]));
    }
    

    cout << Mx;

    return 0;
}