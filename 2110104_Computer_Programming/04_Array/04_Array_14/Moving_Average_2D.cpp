#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double arr[100][100];
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            double mov_avg = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
                             arr[i][j - 1] + arr[i][j] + arr[i][j + 1] +
                             arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            cout << round(mov_avg / 9.0 * 100.0) / 100.0 << " ";
        }
        cout << "\n";
    }

    return 0;
}