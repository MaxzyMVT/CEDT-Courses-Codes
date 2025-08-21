#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, Mx = 0;
    cin >> n;

    int X1[100];
    int Y1[100];
    int X2[100];
    int Y2[100];
    int Pairs[100][100];

    for (int i = 0; i < n; i++)
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int overlap = 0;
            int p1 = max(X1[i], X1[j]);
            int p2 = min(X2[i], X2[j]);
            int q1 = max(Y1[i], Y1[j]);
            int q2 = min(Y2[i], Y2[j]);

            if (p1 >= p2 || q1 >= q2)
                overlap = 0;
            else
                overlap = (p2 - p1) * (q2 - q1);

            Pairs[i][j] = overlap;
            Mx = max(Mx, overlap);
        }
    }

    if (Mx == 0)
    {
        cout << "No overlaps";
        return 0;
    }

    cout << "Max overlapping area = " << Mx << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (Pairs[i][j] == Mx)
                cout << "rectangles " << i << " and " << j << "\n";
        }
    }

    return 0;
}