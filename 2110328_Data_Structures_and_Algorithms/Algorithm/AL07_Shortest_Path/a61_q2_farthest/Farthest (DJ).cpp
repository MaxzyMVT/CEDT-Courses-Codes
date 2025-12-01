#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

#define Edge pair<int, int>
#define INF INT_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<Edge>> G(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            cin >> w;
            if (w == -1)
                continue;
            G[i].push_back({w, j});
        }
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> dis(n, INF);

    pq.push({0, 0});
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (dis[u] < w)
            continue;

        dis[u] = w;

        for (auto [wv, v] : G[u])
        {
            int w_nx = w + wv;
            if (dis[v] > w_nx)
            {
                dis[v] = w_nx;
                pq.push({w_nx, v});
            }
        }
    }

    int Mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INF)
        {
            cout << "-1";
            return 0;
        }
        Mx = max(Mx, dis[i]);
    }
    cout << Mx;

    return 0;
}
