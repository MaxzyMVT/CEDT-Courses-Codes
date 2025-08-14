#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int Mx1 = INT_MIN, Mx2 = Mx1, Mn1 = INT_MAX, Mn2 = Mn1;
    int a;
    bool isLeft = true;
    bool isEven = false;

    while (cin >> a)
    {
        if (a == -998 || a == -999)
            break;
        if (isLeft ^ isEven)
        {
            Mn1 = min(Mn1, a);
            Mx2 = max(Mx2, a);
        }
        else
        {
            Mx1 = max(Mx1, a);
            Mn2 = min(Mn2, a);
        }
        if (!isLeft)
            isEven ^= 1;
        isLeft ^= 1;
    }

    if (a == -998)
        cout << Mn1 << " " << Mx1;
    else
        cout << Mn2 << " " << Mx2;

    return 0;
}