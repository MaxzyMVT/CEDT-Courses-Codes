#include <iostream>
using namespace std;

int main()
{
    int n, m, command;
    int A[21][21];
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    cin >> command;
    while (command != -1)
    {
        if (command == 1)
        {
            // SCALE
            int a, k;
            cin >> a >> k;
            for (int j = 0; j < m; j++)
            {
                A[a - 1][j] *= k;
            }
        }
        else if (command == 2)
        {
            // PIVOT
            int a, b, k;
            cin >> a >> b >> k;
            for (int j = 0; j < m; j++)
            {
                A[a - 1][j] += A[b - 1][j] * k;
            }
        }
        else if (command == 3)
        {
            // SWAP
            int a, b;
            cin >> a >> b;
            for (int j = 0; j < m; j++)
            {
                swap(A[a - 1][j], A[b - 1][j]);
            }
        }

        cin >> command;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}