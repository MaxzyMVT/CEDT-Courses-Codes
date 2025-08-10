#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double scl,spd,dis,x1,x2,y1,y2,time;

    cin >> scl >> spd >> x1 >> y1 >> x2 >> y2;

    dis = scl * sqrt(pow(x1+x2,2)+pow(y1+y2,2));

    time = dis/(spd*18.0/5.0);

    cout << int(time) << " hr " << ceil(60*(time-int(time))) << " min";


    return 0;
}