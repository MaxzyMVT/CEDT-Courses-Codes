#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
#define edge tuple<ll, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<edge>> G(n, vector<edge>());
    vector<int> W(n);
    vector<int> infected;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<bool> mark(n);

    while (k--)
    {
        int st;
        cin >> st;
        infected.push_back(st);
    }

    for (int i = 0; i < n; i++)
        cin >> W[i];

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back({W[b], b});
        G[b].push_back({W[a], a});
    }

    for (int st : infected)
        pq.push({W[st], st});

    int time = 0;
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (mark[u])
            continue;
        mark[u] = true;

        time = w;

        for (auto [w_nx, v] : G[u])
            pq.push({w + w_nx, v});
    }

    cout << time;

    return 0;
}