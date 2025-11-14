#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MOD 100'000'007
#define cnt tuple<int, int, int, int> // X Y Z Sum
#define sumMod(a, b) (a % MOD + b % MOD) % MOD
#define dir(nx, door, sum) (nx = (sumMod(nx, sum) - door + MOD) % MOD)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<cnt>> G(n + 2, vector<cnt>(m + 1, {0, 0, 0, -1}));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            bool isProhibited;
            cin >> isProhibited;
            if (isProhibited)
                G[i][j] = {0, 0, 0, -1};
            else if (j == 1)
                G[i][j] = {0, 0, 0, 1};
            else
                G[i][j] = {0, 0, 0, 0};
        }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            auto &[x, y, z, sum] = G[i][j];
            if (sum == -1)
                continue;
            for (int k = -1; k <= 1; k++)
            {
                auto &[x2, y2, z2, sum2] = G[i + k][j + 1];
                if (sum2 == -1)
                    continue;

                if (k == -1)
                    dir(x2, x, sum), dir(sum2, x, sum);
                else if (k == 0)
                    dir(y2, y, sum), dir(sum2, y, sum);
                else if (k == 1)
                    dir(z2, z, sum), dir(sum2, z, sum);
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sumMod(max(get<3>(G[i][m]), 0), sum);
    cout << sum;

    return 0;
}