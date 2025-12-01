#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> V(n, vector<int>(m));
    queue<tuple<int, int, int>> Q;
    int dir[] = {-1, 0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> V[i][j];
            if (V[i][j] == 1)
                Q.push({i, j, k});
        }
    }

    while (Q.size())
    {
        auto [r, c, w] = Q.front();
        Q.pop();

        if (r < 0 || c < 0 || r >= n || c >= m || w <= 0)
            continue;

        for (int p = 0; p < 4; p++)
        {
            int x = r + dir[p];
            int y = c + dir[p + 1];
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;

            if (V[x][y] == 0)
            {
                V[x][y] = 2;
                if (w - 1 > 0)
                    Q.push({x, y, w - 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}