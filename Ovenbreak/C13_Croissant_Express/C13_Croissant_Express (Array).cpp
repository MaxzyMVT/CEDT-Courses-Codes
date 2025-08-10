#include <bits/stdc++.h>
using namespace std;


//Try Array OR We Failed -_-

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 10007;
    unsigned long long td_prof = 0, e4_prof = 0, ZOON = 0, cnt = 0;
    long long n,t,e,i=0;
    bool td_left = 1, e4_left = 0, ZOON_left;

    cin >> n >> t >> e;


    long long td_bd = t, e4_bd = e;
    vector<bool> TD(n+1), E4(n+1);
    vector<long long> shop(2);

    while(i++<n)
    {
        cin >> shop[1] >> shop[0];


        if(td_bd<=0)
            td_bd = t,
            td_left^=1;       
        if(e4_bd<=0)
            e4_bd = e,
            e4_left^=1;


        if(shop[td_left]>0)
        {
            td_prof = (td_prof%MOD + (shop[td_left]+MOD)%MOD)%MOD,
            td_bd--;
        }
        if(shop[e4_left]>0)
        {
            e4_prof = ((e4_prof?e4_prof:1)%MOD * (shop[e4_left]+MOD)%MOD)%MOD,
            e4_bd--;          
        }

        TD[i] = td_left;
        E4[i] = e4_left;
    }

    for(i=1;i<=n;i++)
    {
        if(TD[i]^E4[i])
            cnt = 0;
        else if(!cnt)
            cnt++, ZOON_left = TD[i];
        else
        {
            cnt++;
            if(ZOON_left^TD[i])
                cnt = 1, ZOON_left^=1;
        }
        ZOON = max(ZOON ,cnt);
    }

    
    cout << td_prof%MOD << " " << e4_prof%MOD << " " << ZOON;


    return 0;
}