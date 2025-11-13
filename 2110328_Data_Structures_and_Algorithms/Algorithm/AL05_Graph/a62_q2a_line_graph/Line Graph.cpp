#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<vector<int>> G(n, vector<int>(0));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> mark(n);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (mark[i])
            continue;

        queue<int> Q;
        Q.push(i);

        bool isLinear = true;
        int deg1Cnt = 0;
        int deg2Cnt = 0;
        while (Q.size())
        {
            int u = Q.front();
            Q.pop();

            if (mark[u])
                continue;
            mark[u] = true;

            if (G[u].size() > 2)
            {
                isLinear = false;
                break;
            }

            if (G[u].size() == 1)
                deg1Cnt++;
            else if (G[u].size() == 2)
                deg2Cnt++;

            for (int v : G[u])
                Q.push(v);
        }
        if ((deg1Cnt == 2 || deg1Cnt == 0 && deg2Cnt == 0) && isLinear)
            cnt++;
    }
    cout << cnt;

    return 0;
}