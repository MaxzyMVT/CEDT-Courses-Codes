#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define Walk tuple<int, int, int>
#define check(type, d, r, c) (dir[type][d] && dir[V[r][c]][d ^ 1])

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m;

    vector<vector<int>> V(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> V[i][j];
        }
    }

    vector<vector<bool>> dir(7, vector<bool>(4));

    dir[1] = {0, 0, 1, 1};
    dir[2] = {1, 1, 0, 0};
    dir[3] = {0, 1, 1, 0};
    dir[4] = {1, 0, 1, 0};
    dir[5] = {1, 0, 0, 1};
    dir[6] = {0, 1, 0, 1};

    queue<Walk> Q;
    vector<vector<int>> dis(n, vector<int>(m));

    int Mx = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!dis[i][j])
                Q.push({i, j, 1});
            while (Q.size())
            {
                auto [r, c, w] = Q.front();
                Q.pop();

                if (dis[r][c] && dis[r][c] < w)
                    continue;

                if (dis[r][c] == w)
                {
                    cnt++;
                    int cycle_size = dis[r][c] * 2 - 2;
                    Mx = max(Mx, cycle_size);
                    break;
                }

                dis[r][c] = w;
                int type = V[r][c];

                if (r + 1 < n && check(type, 0, r + 1, c))
                    Q.push({r + 1, c, w + 1});
                if (r - 1 >= 0 && check(type, 1, r - 1, c))
                    Q.push({r - 1, c, w + 1});
                if (c + 1 < m && check(type, 2, r, c + 1))
                    Q.push({r, c + 1, w + 1});
                if (c - 1 >= 0 && check(type, 3, r, c - 1))
                    Q.push({r, c - 1, w + 1});
            }
        }
    }

    cout << cnt << " " << Mx << "\n";

    return 0;
}