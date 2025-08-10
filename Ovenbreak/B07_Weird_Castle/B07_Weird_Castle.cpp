#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int st,en,st_lvl,en_lvl,mid_st_lvl,mid_en_lvl,hor,ver,ans=0;
    cin >> st >> en;

    st_lvl = ceil(sqrt(st));
    en_lvl = ceil(sqrt(en));

    mid_st_lvl = (st_lvl*st_lvl + (st_lvl-1)*(st_lvl-1) + 1)/2;
    mid_en_lvl = (en_lvl*en_lvl + (en_lvl-1)*(en_lvl-1) + 1)/2;

    ver = st_lvl-en_lvl;
    hor = abs((st-mid_st_lvl) + (mid_en_lvl-en));

    ans += (ver-1)*2+1; //at least 
    
    // obstruct
    if(!(st_lvl%2^st%2)) 
        ans++,hor--;
    if(en_lvl%2^en%2)
        ans++,hor--;

    hor-=ver;

    ans += max(hor+1,0);

    cout << ans;

    return 0;
}

/*

1 4 9 16 25 36

A = n^2 = last_tri
sqrt(last_tri) = n

even lvl -> even up

*/