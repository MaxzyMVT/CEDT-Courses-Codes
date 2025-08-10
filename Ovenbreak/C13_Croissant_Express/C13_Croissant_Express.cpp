#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 10007;
    unsigned long long td_prof = 0, e4_prof = 0, ZOON = 0, cnt = 0;
    long long n,t,e,shopL,shopR;
    bool td_left = 1, e4_left = 0, ZOON_left;

    cin >> n >> t >> e;

    long long td_bd = t, e4_bd = e;

    while(n--)
    {
        cin >> shopL >> shopR;

        if(td_bd<=0)
            td_bd = t,
            td_left^=1;       
        if(e4_bd<=0)
            e4_bd = e,
            e4_left^=1;

        if(td_left ^ e4_left)
            cnt = 0;
        else if(!cnt)
            cnt++, 
            ZOON_left = !td_left;
        else
        {
            cnt++;
            if(td_left==ZOON_left)
                cnt = 1, ZOON_left^=1;
        }

        ZOON = max(ZOON, cnt);

        if(shopL>0)
        {
            if(td_left && td_bd)
                td_prof = (td_prof%MOD + (shopL+MOD)%MOD)%MOD,
                td_bd--;
            if(e4_left && e4_bd)
                e4_prof = ((e4_prof?e4_prof:1)%MOD * (shopL+MOD)%MOD)%MOD,
                e4_bd--;
        }
        if(shopR>0)
        {
            if(!td_left && td_bd)
                td_prof = (td_prof%MOD + (shopR+MOD)%MOD)%MOD,
                td_bd--;
            if(!e4_left && e4_bd)
                e4_prof = ((e4_prof?e4_prof:1)%MOD * (shopR+MOD)%MOD)%MOD,
                e4_bd--;
        }

    }

    cout << td_prof%MOD << " " << e4_prof%MOD << " " << ZOON;

    return 0;
}