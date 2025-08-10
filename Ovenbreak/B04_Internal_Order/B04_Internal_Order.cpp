#include <bits/stdc++.h>
using namespace std;

struct tanbucha
{
    string name;
    int ID;

    bool operator<(const tanbucha &x) const
    {
        return name < x.name;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string in;
    int daisuki, n=4,i=0,o;
    bool omg,mu,ee,YAY;

    vector<tanbucha> V,C;
    vector<int> ANS = {0,0,0,0,0};

    cin >> daisuki;
    while(i++<n)
        cin >> in, V.push_back({in,i});
    sort(V.begin(),V.end());

    C.insert(C.end(),V.begin()+daisuki-1,V.end());
    C.insert(C.end(),V.begin(),V.begin()+daisuki-1);

    for(i=1;i<=4;i++)
        ANS[C[i-1].ID] = i;

    omg = (ANS[2]==1 || daisuki==1) && ANS[3]<ANS[4];

    mu = ANS[3]>ANS[2] && ANS[3]<ANS[1] && ANS[4]!=3;

    ee = (omg^mu && ANS[1]>ANS[4]) || ANS[2]!=4;

    YAY = ee && (ANS[4]<ANS[2] || ANS[3]>ANS[1]);

    if(YAY)
    {
        cout << "CROISSANT with ordering: ";
        for(i=1;i<=4;i++)
            cout << ANS[i] << " ";
    }
    else
        cout << "No Croissant :(";


    return 0;
}
