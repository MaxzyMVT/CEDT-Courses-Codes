#include <iostream>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

int C(int n, int r, vector<vector<int>> &mem)
{
    if (r == 0 || r == n || !n)
        return 1;
    if (mem[n][r])
        return mem[n][r];

    return mem[n][r] = (C(n - 1, r, mem) % MOD + C(n - 1, r - 1, mem) % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m;

    vector<vector<int>> V(n + 1, vector<int>(m + 1));
    vector<vector<int>> mem(1001, vector<int>(1001));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'a')
                V[i][j] = 1;
            V[i][j] += V[i - 1][j] + V[i][j - 1] - V[i - 1][j - 1];
        }
    }

    cin >> q;
    while (q--)
    {
        int r0, rn, c0, cn, k;
        cin >> r0 >> c0 >> rn >> cn >> k;

        int acorn_cnt = V[rn][cn] - V[r0 - 1][cn] - V[rn][c0 - 1] + V[r0 - 1][c0 - 1];

        if (acorn_cnt < k)
        {
            cout << "-1\n";
            continue;
        }

        cout << C(acorn_cnt, k, mem) << "\n";
    }

    return 0;
}