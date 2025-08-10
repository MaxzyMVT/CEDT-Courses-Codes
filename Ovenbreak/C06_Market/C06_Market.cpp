#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0, price = 0, a,b; 

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> a >> b;
        cnt += a, price += b*a;
    }

    if(cnt >= 2*n)
    {
        price*=0.97;
        if(cnt > 14 && price > 25)
            price -= 10;
    }
    else if(cnt < 20 && price < 500)
        price += 600;
    else
        price-=n*0.35;

    cout << price;



    return 0;
}