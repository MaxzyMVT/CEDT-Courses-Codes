#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> G(n, vector<int>(m));
    vector<vector<bool>> mark(n, vector<bool>(m));
    queue<tuple<int, int, int>> Q; // i, j ,infected date

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> G[i][j];
            if (G[i][j] == 1)
            {
                Q.push({i, j, 0});
                G[i][j] = 0;
            }
        }
    }

    while (Q.size())
    {
        auto [x, y, date] = Q.front();
        Q.pop();

        if (date > t || x < 0 || y < 0 || x >= n || y >= m || G[x][y] == 1 || G[x][y] == 2)
            continue;

        G[x][y] = 1;
        cnt++;

        Q.push({x + 1, y, date + 1});
        Q.push({x - 1, y, date + 1});
        Q.push({x, y + 1, date + 1});
        Q.push({x, y - 1, date + 1});
    }

    cout << cnt;

    return 0;
}