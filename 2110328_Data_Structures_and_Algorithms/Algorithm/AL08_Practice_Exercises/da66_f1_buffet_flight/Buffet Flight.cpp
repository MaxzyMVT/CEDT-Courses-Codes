#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define edge pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> ci(n), co(n);

    for (int i = 0; i < n; i++)
        cin >> ci[i];

    for (int i = 0; i < n; i++)
        cin >> co[i];

    vector<vector<edge>> G(n, vector<edge>());

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back({co[a] + ci[b], b});
    }

    vector<int> dist(n, -1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    pq.push({0, 0});
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (dist[u] != -1 && dist[u] < w)
            continue;
        dist[u] = w;

        for (auto [w_nx, v] : G[u])
            if (dist[v] == -1 || dist[v] > w + w_nx)
                pq.push({w + w_nx, v});
    }

    for (int d : dist)
        cout << d << " ";

    return 0;
}