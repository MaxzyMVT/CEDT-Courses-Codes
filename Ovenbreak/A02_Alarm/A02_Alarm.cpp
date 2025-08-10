#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int sth, stm, enh, enm, res;

    cin >> sth >> stm >> enh >> enm;

    if(enh < sth || enh==sth && enm < stm)
        enh += 24;

    stm += sth*60;
    enm += enh*60;
    res = enm - stm;

    cout << res/60 << " hr " << res%60 << " min until alarm rings.";



    return 0;
}