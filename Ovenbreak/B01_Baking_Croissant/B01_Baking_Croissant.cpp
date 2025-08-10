#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int temp;
    cin >> temp;
    
    if(temp < 160)
        cout << "Undercooked";
    else if(temp > 180)
        cout << "Burnt";
    else    
        cout << "Perfect";
    
    return 0;
}