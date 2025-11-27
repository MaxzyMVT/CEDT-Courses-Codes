#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define Pos tuple<int, int>
#define Walk tuple<int, int, int>
#define isPop(i, j) (V[i][j] >= '1' && V[i][j] <= '5')

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> V(n, vector<char>(m));
    vector<vector<Pos>> Pop(6, vector<Pos>(2));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> V[i][j];
            if (isPop(i, j))
            {
                int num = V[i][j] - '0';
                swap(Pop[num][0], Pop[num][1]);
                Pop[num][0] = {i, j};
            }
        }

    queue<Walk> Q;

    Q.push({0, 0, 0});
    while (Q.size())
    {
        auto [r, c, w] = Q.front();
        Q.pop();

        if (r < 0 || c < 0 || r >= n || c >= m || V[r][c] == 'X')
            continue;

        if (r == n - 1 && c == m - 1)
        {
            cout << w;
            return 0;
        }

        if (isPop(r, c))
        {
            int num = V[r][c] - '0';
            for (auto [x, y] : Pop[num])
            {
                Q.push({x, y - 1, w + 1});
                Q.push({x, y + 1, w + 1});
                Q.push({x + 1, y, w + 1});
            }
        }
        else
        {
            Q.push({r, c - 1, w + 1});
            Q.push({r, c + 1, w + 1});
            Q.push({r + 1, c, w + 1});
        }

        V[r][c] = 'X';
    }

    return 0;
}