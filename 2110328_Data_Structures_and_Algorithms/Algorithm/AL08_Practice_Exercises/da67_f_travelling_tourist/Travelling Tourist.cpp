#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define INF INT_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p, a, b, w;
    cin >> n >> m >> p;

    vector<vector<int>> G(n + 1, vector<int>(n + 1, INF));
    vector<int> targets;

    for (int i = 0; i < p; i++)
        cin >> a, targets.push_back(a);

    while (m--)
    {
        cin >> a >> b >> w;
        G[b][a] = w;
        G[a][b] = w;
        G[a][a] = 0;
        G[b][b] = 0;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (G[i][k] != INF && G[k][j] != INF)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }

    int Mn = INF;
    sort(targets.begin(), targets.end());
    do
    {
        int sum = 0;
        for (int j = 0; j < p - 1; j++)
            if (G[targets[j]][targets[j + 1]] == INF)
            {
                sum = INF;
                break;
            }
            else
                sum += G[targets[j]][targets[j + 1]];

        Mn = min(sum, Mn);
    } while (next_permutation(targets.begin(), targets.end()));

    cout << Mn;

    return 0;
}
