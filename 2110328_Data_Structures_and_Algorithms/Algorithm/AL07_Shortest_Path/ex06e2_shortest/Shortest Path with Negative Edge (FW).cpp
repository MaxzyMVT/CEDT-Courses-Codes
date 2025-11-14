#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, s;
    cin >> n >> e >> s;

    vector<vector<bool>> adj(n, vector<bool>(n));
    vector<vector<ll>> dist(n, vector<ll>(n));

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = true;
        dist[u][v] = w;
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[j][j] = true;
                if (adj[i][k] && adj[k][j])
                {
                    if (adj[i][j])
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    else
                        dist[i][j] = dist[i][k] + dist[k][j], adj[i][j] = true;
                }
            }
        }
    }

    // neg cycle detection (final dist[v][v] < 0)
    for (int v = 0; v < n; v++)
    {
        if (dist[v][v] < 0)
        {
            cout << "-1";
            return 0;
        }
    }

    for (int v = 0; v < n; v++)
        cout << dist[s][v] << " ";

    return 0;
}