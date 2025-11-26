#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m;

    vector<vector<int>> V(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> V[i][j];
        }
    }

    vector<vector<bool>> dir(7, vector<bool>(4));

    dir[1] = {0, 0, 1, 1};
    dir[2] = {1, 1, 0, 0};
    dir[3] = {0, 1, 1, 0};
    dir[4] = {1, 0, 1, 0};
    dir[5] = {1, 0, 0, 1};
    dir[6] = {0, 1, 0, 1};

    return 0;

    return 0;
}