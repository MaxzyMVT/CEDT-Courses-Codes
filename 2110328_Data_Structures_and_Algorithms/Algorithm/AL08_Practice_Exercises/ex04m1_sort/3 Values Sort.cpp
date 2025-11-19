#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pos[4] = {};
    cin >> n;

    vector<int> V(n);

    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
        pos[V[i]]++;
    }

    vector<vector<int>> wrong(4, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        if (i < pos[1] && V[i] != 1)
            wrong[1][V[i]]++;
        else if (i >= pos[1] && i < pos[1] + pos[2] && V[i] != 2)
            wrong[2][V[i]]++;
        else if (i >= pos[1] + pos[2] && V[i] != 3)
            wrong[3][V[i]]++;
    }

    int cnt = 0, left = 0;
    for (int i = 1; i < 3; i++)
        for (int j = i + 1; j <= 3; j++)
        {
            int swaps = min(wrong[i][j], wrong[j][i]);
            wrong[i][j] -= swaps;
            wrong[j][i] -= swaps;
            cnt += swaps;
            left = max(wrong[i][j], wrong[j][i]);
        }

    cout << cnt + left * 2;

    return 0;
}
