#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, k;
    char A[501][501] = {};

    cin >> n >> m >> k;

    while (k--)
    {
        char clr;
        int r, x, y;
        cin >> clr >> r >> x >> y;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (abs(x - i) + abs(y - j) <= r)
                    A[i][j] = clr;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
            {
                cout << "- ";
            }
            else
                cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}