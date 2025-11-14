#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define ll long long
#define edge tuple<ll, int>
#define INF LLONG_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<edge>> G(n + 1, vector<edge>());
    vector<ll> dist(n + 1, INF);

    G[1].push_back({k, 2});
    G[2].push_back({k, 1});
    dist[1] = 0;
    dist[2] = k;

    for (int u = 3; u <= n; u++)
    {
        int m;
        priority_queue<edge, vector<edge>, greater<edge>> pq;

        cin >> m;
        while (m--)
        {
            int v, w;
            cin >> v >> w;

            G[u].push_back({w, v});
            G[v].push_back({w, u});
            if (dist[v] != INF)
                dist[u] = min(dist[u], dist[v] + w);
        }

        if (dist[u] != INF)
            pq.push({dist[u], u});
        while (pq.size())
        {
            auto [w, u] = pq.top();
            pq.pop();

            if (w > dist[u])
                continue;

            dist[u] = w;

            for (auto [w_nx, v] : G[u])
                if (w + w_nx < dist[v])
                    pq.push({w + w_nx, v});
        }
        cout << dist[2] << " ";
    }

    return 0;
}