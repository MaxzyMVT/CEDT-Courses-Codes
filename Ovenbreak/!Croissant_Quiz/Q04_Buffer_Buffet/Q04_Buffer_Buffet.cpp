#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n,u,v;
    long long i=0, j;
    double sum = 0;
    cin >> n >> u >> v;
    j = n-1;
    vector<ull> T(n+1);
    vector<ull> F;
    vector<ull> S;

    for(ull i=0;i<n;i++)
        cin >> T[i];

    while(i<n && j>=0)
    {
        sum += T[i]*T[j];
        F.push_back(T[i]);
        S.push_back(T[j]);
        i+=u;
        j-=v;
    }


    double avg, fst, sec;
    int p = F.size();

    if(p%2)
    {
        fst = F[p/2];
        sec = S[p/2];
    }
    else
    {
        fst = (F[p/2-1] + F[p/2])/2.0;
        sec = (S[p/2-1] + S[p/2])/2.0;
    }

    avg = sum/p;

    cout << fixed << setprecision(2) << avg << " " << fst << " " << sec;


    return 0;
        
}