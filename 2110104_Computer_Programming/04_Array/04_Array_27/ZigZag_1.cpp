#include <iostream>

using namespace std;

int main()
{
    int n;
    int L[100], R[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> L[i] >> R[i];

    string com;
    cin >> com;

    int Mn, Mx;
    if (com == "Zig-Zag")
    {
        Mn = L[0];
        Mx = R[0];
        for (int i = 1; i < n; i++)
        {
            if (i % 2)
            {
                Mn = min(R[i], Mn);
                Mx = max(L[i], Mx);
            }
            else
            {
                Mn = min(L[i], Mn);
                Mx = max(R[i], Mx);
            }
        }
    }
    else
    {
        Mn = R[0];
        Mx = L[0];
        for (int i = 1; i < n; i++)
        {
            if (i % 2)
            {
                Mn = min(L[i], Mn);
                Mx = max(R[i], Mx);
            }
            else
            {
                Mn = min(R[i], Mn);
                Mx = max(L[i], Mx);
            }
        }
    }

    cout << Mn << " " << Mx;

    return 0;
}