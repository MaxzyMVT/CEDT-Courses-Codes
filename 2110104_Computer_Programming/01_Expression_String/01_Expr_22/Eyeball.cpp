#include <iostream> 
#include <cmath>
 
using namespace std; 
 
int main() { 
    
    double xm, ym, xe, ye, re, rp, ratio, A, B, C, a, b, c;
    cin >> xe >> ye >> re >> rp >> xm >> ym;

    C = sqrt((xm - xe) * (xm - xe) + (ym - ye) * (ym - ye));
    c = abs(re - rp);
    
    ratio = C / c;

    A = xm - xe;
    B = ym - ye;

    a = A / ratio;
    b = B / ratio;

    cout << round(a+xe) << " " << round(b+ye) << "\n";

    
}