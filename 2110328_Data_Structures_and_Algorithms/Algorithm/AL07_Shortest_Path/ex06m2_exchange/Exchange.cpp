#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<double>> Ex(n, vector<double>(n));

        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                cin >> Ex[u][v];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    Ex[i][j] = max(Ex[i][j], Ex[i][k] * Ex[k][j]);

        bool isINFINITEMONEYOMG = false;
        for (int u = 0; u < n; u++)
            if (Ex[u][u] > 1)
            {
                isINFINITEMONEYOMG = true;
                break;
            }

        cout << (isINFINITEMONEYOMG ? "YES\n" : "NO\n");
    }

    return 0;
}