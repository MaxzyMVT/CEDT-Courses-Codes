#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define edge pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<edge>> G(n, vector<edge>());

    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            int w;
            cin >> w;
            G[u].push_back({w, v});
            G[v].push_back({w, u});
        }
    }

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<bool> mark(n);

    int sum = 0;
    pq.push({0, 0});
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (mark[u])
            continue;
        mark[u] = true;

        sum += w;

        for (auto e : G[u])
            pq.push(e);
    }

    cout << sum;

    return 0;
}