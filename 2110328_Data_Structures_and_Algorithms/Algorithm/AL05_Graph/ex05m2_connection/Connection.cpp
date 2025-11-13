#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, k;
    cin >> n >> e >> k;

    vector<vector<int>> G(n, vector<int>(0));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Mx = 0;
    for (int i = 0; i < n; i++)
    {
        queue<pair<int, int>> Q;
        vector<bool> mark(n);

        Q.push({i, k});
        while (Q.size())
        {
            auto [u, round] = Q.front();
            Q.pop();

            mark[u] = true;

            if (round <= 0)
                continue;

            for (int v : G[u])
                Q.push({v, round - 1});
        }

        int cnt = 0;
        for (bool isKthFriend : mark)
            if (isKthFriend)
                cnt++;
        Mx = max(Mx, cnt);
    }
    cout << Mx;

    return 0;
}