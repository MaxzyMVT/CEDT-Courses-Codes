#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double C,M,L;
    cin >> C >> M >> L;

    cout << fixed << setprecision(2) << ceil(((C*C)+log(M+1.0))*exp(L/(C+1.0)));



    return 0;
}