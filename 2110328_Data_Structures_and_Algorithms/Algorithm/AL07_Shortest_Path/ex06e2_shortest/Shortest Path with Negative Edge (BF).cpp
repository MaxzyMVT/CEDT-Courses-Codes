#include <iostream>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define edge tuple<ll, int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, s;
    cin >> n >> e >> s;

    vector<ll> distFromS(n, INF);
    vector<ll> negCycleFindS(n, 0);
    vector<edge> E(n);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({w, u, v});
    }

    // Bellman-Ford Algorithm
    distFromS[s] = 0;
    bool hasNegCycle = false;
    for (int i = 0; i < n; i++)
    {
        hasNegCycle = false;
        for (auto [w, u, v] : E)
        {
            if (distFromS[u] < INF && distFromS[u] + w < distFromS[v])
                distFromS[v] = distFromS[u] + w;

            if (negCycleFindS[u] + w < negCycleFindS[v])
            {
                negCycleFindS[v] = negCycleFindS[u] + w;
                hasNegCycle = true;
            }
        }
    }

    // neg cycle detection (change dist at last iteration when all dist is 0 from start)
    if (hasNegCycle)
    {
        cout << -1;
        return 0;
    }

    for (int v = 0; v < n; v++)
        cout << distFromS[v] << " ";

    return 0;
}