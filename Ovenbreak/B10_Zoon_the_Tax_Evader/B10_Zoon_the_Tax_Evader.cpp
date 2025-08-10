#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ZOON;
    double ans;

    cin >> ZOON;

    if(ZOON <= 150000)
        ans = 0;
    else if(ZOON <= 300000)
        ans = ZOON*5.0/100;
    else if(ZOON <= 500000)
        ans = ZOON*10.0/100;    
    else if(ZOON <= 1000000)
        ans = ZOON*15.0/100;    
    else if(ZOON <= 2000000)
        ans = ZOON*20.0/100;    
    else if(ZOON <= 4000000)
        ans = ZOON*25.0/100;    
    else
        ans = ZOON*30.0/100;    

    cout << fixed << setprecision(0) << ceil(ans);


    return 0;
}