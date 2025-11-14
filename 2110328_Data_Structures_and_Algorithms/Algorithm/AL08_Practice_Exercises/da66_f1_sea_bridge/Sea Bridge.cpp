#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define edge tuple<int, int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n, vector<int>(m));
    queue<edge> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> G[i][j];
            if (G[i][j] == 1)
                q.push({1, i, j});
        }

    while (q.size())
    {
        auto [w, x, y] = q.front();
        q.pop();

        if (x < 0 || y < 0 || x >= n || y >= m || G[x][y] == 3)
            continue;
        if (G[x][y] == 2)
        {
            cout << w;
            break;
        }

        G[x][y] = 3;

        q.push({w + 1, x + 1, y});
        q.push({w + 1, x - 1, y});
        q.push({w + 1, x, y + 1});
        q.push({w + 1, x, y - 1});
    }

    return 0;
}