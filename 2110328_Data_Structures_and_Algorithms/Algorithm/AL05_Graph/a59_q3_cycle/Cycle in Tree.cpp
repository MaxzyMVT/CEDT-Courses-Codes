#include <iostream>
#include <utility>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n;

    vector<vector<int>> G(n, vector<int>(0));

    e = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> mark(n);
    vector<int> dis(n);

    stack<pair<int, int>> ST;
    ST.push({0, 0});

    int cycleV;
    while (ST.size())
    {
        auto [u, distance] = ST.top();
        ST.pop();

        if (mark[u])
        {
            int cycle_siz = distance - dis[u];
            if (cycle_siz <= 2)
                continue;
            cout << cycle_siz;
            break;
        }
        mark[u] = true;

        dis[u] = distance;

        for (int v : G[u])
            ST.push({v, distance + 1});
    }

    return 0;
}