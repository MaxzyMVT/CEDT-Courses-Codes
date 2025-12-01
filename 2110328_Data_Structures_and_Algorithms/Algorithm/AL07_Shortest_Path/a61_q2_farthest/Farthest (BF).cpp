#include <iostream>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

#define Edge tuple<int, int, int>
#define INF INT_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Edge> E(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            cin >> w;
            if (w != -1)
                E.push_back({w, i, j});
        }
    }

    vector<int> dis(n, INF);
    dis[0] = 0;

    int e = E.size() - 1;
    for (int i = 0; i < e; i++)
    {
        for (auto [w, u, v] : E)
            if (dis[u] != INF && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
    }

    int Mx = -1;
    for (int i = 1; i < n; i++)
    {
        if (dis[i] != INF)
            Mx = max(Mx, dis[i]);
        else
        {
            cout << "-1";
            return 0;
        }
    }

    cout << Mx;

    return 0;
}