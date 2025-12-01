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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> V(n + 1, vector<int>(n + 1, INF));
    vector<int> targets(k);

    for (int i = 0; i < k; i++)
        cin >> targets[i];

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        V[a][b] = w;
        V[b][a] = w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (V[i][k] != INF && V[k][j] != INF)
                    V[i][j] = min(V[i][j], V[i][k] + V[k][j]);
            }
        }
    }

    int Mn = INF;
    sort(targets.begin(), targets.end());
    do
    {
        int sum = 0;
        for (int i = 0; i < k - 1; i++)
        {
            int u = targets[i];
            int v = targets[i + 1];
            if (V[u][v] != INF)
                sum += V[u][v];
            else
            {
                sum = INF;
                break;
            }
        }

        Mn = min(sum, Mn);

    } while (next_permutation(targets.begin(), targets.end()));

    cout << Mn;

    return 0;
}
