#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string name;
    unsigned long long Mn,Mx,Big,Small;

    cin >> name >> Mn >> Mx;

    Mn--;

    Big = (Mx+1)*(Mx+1) + (Mx*Mx);
    Small = (Mn+1)*(Mn+1) + (Mn*Mn);

    cout << name << " has " << Big - Small << " attackable tiles.";

    return 0;
}