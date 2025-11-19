#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define edge tuple<int, int, int>
#define process(r, c, w) (G[r][c] = 2, Q.push({w, r, c}))

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> G(n, vector<int>(m));
    queue<edge> Q;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> G[r][c];

    if (k > 0)
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
            {
                if (G[r][c] == 1)
                {
                    if (r + 1 < n && G[r + 1][c] == 0)
                        process(r + 1, c, k - 1);
                    if (r - 1 >= 0 && G[r - 1][c] == 0)
                        process(r - 1, c, k - 1);
                    if (c + 1 < m && G[r][c + 1] == 0)
                        process(r, c + 1, k - 1);
                    if (c - 1 >= 0 && G[r][c - 1] == 0)
                        process(r, c - 1, k - 1);
                }
            }

    while (Q.size())
    {
        auto [w, r, c] = Q.front();
        Q.pop();

        if (w <= 0 || r < 0 || c < 0 || r >= n || c >= m)
            continue;

        if (r + 1 < n && G[r + 1][c] == 0)
            process(r + 1, c, w - 1);
        if (r - 1 >= 0 && G[r - 1][c] == 0)
            process(r - 1, c, w - 1);
        if (c + 1 < m && G[r][c + 1] == 0)
            process(r, c + 1, w - 1);
        if (c - 1 >= 0 && G[r][c - 1] == 0)
            process(r, c - 1, w - 1);
    }

    for (int r = 0; r < n; r++, cout << "\n")
        for (int c = 0; c < m; c++)
            cout << G[r][c] << " ";

    return 0;
}