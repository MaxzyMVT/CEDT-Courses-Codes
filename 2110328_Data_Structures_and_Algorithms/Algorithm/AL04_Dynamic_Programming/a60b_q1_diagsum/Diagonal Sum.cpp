#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, Mx;
    cin >> n;

    vector<vector<int>> V(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> V[i][j];
            V[i][j] += V[i - 1][j - 1];
        }
    }

    Mx = V[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= min(i, j); k++)
            {
                int r = i - k, c = j - k;
                int sum = V[i][j] - V[r][c];
                Mx = max(Mx, sum);
            }
        }
    }

    cout << Mx;

    return 0;
}