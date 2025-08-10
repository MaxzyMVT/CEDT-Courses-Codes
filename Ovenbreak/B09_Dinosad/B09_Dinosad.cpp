#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double spd, hgt, wgh;
    cin >> spd >> hgt >> wgh;

    if(hgt < 100 || wgh > 200)
        cout << "It too weak.";
    else if(spd > 100)
        cout << "It can jump over.";
    else if(spd < 100)
        cout << "It can't jump over.";
    

    return 0;
}