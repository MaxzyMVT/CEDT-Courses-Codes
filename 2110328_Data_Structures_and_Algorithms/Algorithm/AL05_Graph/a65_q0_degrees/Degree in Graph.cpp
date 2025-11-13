#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> adj(n, vector<bool>(n));
    vector<int> deg_cnt(n);

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
        {
            bool val;
            cin >> val;
            adj[u][v] = val;
        }

    int Mx = 0;
    for (int u = 0; u < n; u++)
    {
        int cnt = 0;
        for (int v = 0; v < n; v++)
            if (adj[u][v])
                cnt++;
        Mx = max(Mx, cnt);
        deg_cnt[cnt]++;
    }

    for (int d = 0; d <= Mx; d++)
        cout << deg_cnt[d] << " ";

    return 0;
}