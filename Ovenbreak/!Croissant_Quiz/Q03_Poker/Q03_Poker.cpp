#include <bits/stdc++.h>
using namespace std;


struct card
{
    int val;
    char shp;

    bool operator<(const card &x) const
    {
        return val < x.val;
    } 
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5, val, cntS = 0, cntH = 0, cntC = 0, cntD = 0, cntNum[15] = {};
    char shape;
    string string_val, ans;
    bool isFour = false, isThree = false, isTwo = false, is2Two = false, isSorted = true;

    vector<card> C(n+1);

    for(int i=1;i<=n;i++)
    {
        cin >> string_val >> shape;
        if(isdigit(string_val[0]))
            val = stoi(string_val);
        else if(string_val == "J")
            val = 11;       
        else if(string_val == "Q")
            val = 12;       
        else if(string_val == "K")
            val = 13;        
        else if(string_val == "A")
            val = 14;

        if(shape=='S') cntS++;
        if(shape=='H') cntH++;
        if(shape=='C') cntC++;
        if(shape=='D') cntD++;
        cntNum[val]++;

        C[i] = {val, shape};
    }    

    for(int x : cntNum)
    {
        if(x==4) isFour = true;
        if(x==3) isThree = true;
        if(x==2 && isTwo) is2Two = true;
        else if(x==2) isTwo = true;
    }

    sort(C.begin(),C.end());


    for(int i=2;i<=n;i++)
    {
        if(C[i].val!=C[i-1].val+1)
            isSorted = false;
    }



    if( max({cntS,cntH,cntC,cntD})==5 && isSorted)
    {
        if( C[1].val + C[2].val + C[3].val + C[4].val + C[5].val == 60)
            ans = "royal flush";
        else
            ans = "straight flush";
    }
    else if(isFour)
        ans = "four of a kind";
    else if(isThree && isTwo)
        ans = "full house";
    else if(max({cntS,cntH,cntC,cntD})==5)
        ans = "flush";
    else if(isSorted)
        ans = "straight";
    else if(isThree)
        ans = "three of a kind";
    else if(is2Two)
        ans = "two pair";
    else if(isTwo)
        ans = "pair";
    else
        ans = "high card";


    cout << ans;


    return 0;
        
}