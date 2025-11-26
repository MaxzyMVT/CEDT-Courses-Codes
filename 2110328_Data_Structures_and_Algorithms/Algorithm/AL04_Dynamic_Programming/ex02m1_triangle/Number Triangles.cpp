#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> V(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> V[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            V[i][j] = max(V[i - 1][j] + V[i][j], V[i - 1][j - 1] + V[i][j]);
        }
    }

    int Mx = V[n][1];
    for (int j = 2; j <= n; j++)
    {
        Mx = max(V[n][j], Mx);
    }

    cout << Mx;

    return 0;
}