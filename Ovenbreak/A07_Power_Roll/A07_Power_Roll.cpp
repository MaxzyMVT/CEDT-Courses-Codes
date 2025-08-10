#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long DD = 69;
    double I,V,L,H,tt,px,py,d,M1,M2,MM,Plug,UP,DOWN;
    double PP = 3.28, PI = 3.14159, SS = 1.15112, NN = 4.80852, LL = 13.0725;

    cin >> I >> V >> L >> H >> tt >> px >> py >> d;

    tt = tt*PI/180.0;

    M1 = cos(tt)*px + (-sin(tt))*py;
    M2 = sin(tt)*px + 1.0*py;
    MM = sqrt(M1*M1 + M2*M2);

    cout << MM << "\n";
    cout << tan(MM/LL*PP) << "\n";

    UP = tan(MM/LL*PP)*I*V;
    DOWN = L * double( (unsigned long long)ceil(exp(NN*d))%DD ) * pow(H,1.0/3.0);

    Plug = PP * (log(abs( cbrt(UP/DOWN) )) / log(SS));

    cout << round(Plug*1e4)/1e4 << " NP";


    return 0;
}