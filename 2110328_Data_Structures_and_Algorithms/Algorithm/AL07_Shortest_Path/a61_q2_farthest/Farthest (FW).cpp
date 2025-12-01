#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<ll>> adj(n, vector<ll>(n));

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            cin >> adj[u][v];

    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (adj[i][k] != -1 && adj[k][j] != -1)
                {
                    if (adj[i][j] == -1)
                        adj[i][j] = adj[i][k] + adj[k][j];
                    else
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    ll Mx = -1;
    for (int v = 1; v < n; v++)
    {
        if (adj[0][v] == -1)
        {
            cout << "-1";
            return 0;
        }
        Mx = max(Mx, adj[0][v]);
    }
    cout << Mx;

    return 0;
}