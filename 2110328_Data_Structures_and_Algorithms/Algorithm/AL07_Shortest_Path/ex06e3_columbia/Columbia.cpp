#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
#define edge tuple<ll, int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 2, vector<int>(m + 2));
    vector<vector<bool>> mark(n + 2, vector<bool>(m + 2));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> dist[i][j];

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    pq.push({0, 1, 1});
    while (pq.size())
    {
        auto [w, x, y] = pq.top();
        pq.pop();

        if (x < 1 || y < 1 || x > n || y > m || mark[x][y])
            continue;
        mark[x][y] = true;

        dist[x][y] = w;

        pq.push({dist[x + 1][y] + w, x + 1, y});
        pq.push({dist[x - 1][y] + w, x - 1, y});
        pq.push({dist[x][y + 1] + w, x, y + 1});
        pq.push({dist[x][y - 1] + w, x, y - 1});
    }

    for (int i = 1; i <= n; i++, cout << "\n")
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << " ";

    return 0;
}