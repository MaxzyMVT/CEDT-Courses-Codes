#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod_pow(ll a, ll b, ll mod)
{
    if(b==0) return 1;
    if(b==1) return a;

    ll res = 1;
    while(b>0)
    {
        if(b%2)
        {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b /= 2;
    }
    return res%mod;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, N, x, y, k, p;

    cin >> t;
    while(t--)
    {
        ll sum1 = 0;
        cin >> N >> x >> y >> k >> p;


        // Front
        ll tmp_mod = k*6;
        sum1 = ((N%tmp_mod * (N+1)%tmp_mod)%tmp_mod * ((N+2)%tmp_mod))/6;
        sum1 = (sum1%k*(x%k + (2*x%k*y%k)%k + y%k)%k)%k;
        
        // Mid
        sum1 = (sum1%k + N%k)%k;

        // The Great p !!!!
        if(N>=2)
            sum1 = (sum1%k + p*3)%k;
        else
            sum1 = (sum1%k + p*1)%k; 

        // Outer
        tmp_mod = k*2;
        sum1 = (sum1%k + mod_pow(((N%tmp_mod * (N+1)%tmp_mod)%tmp_mod)/2, 2, k))%k;


        cout << sum1%k << "\n"; 
    }







    return 0;
}