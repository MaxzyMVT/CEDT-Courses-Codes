#include <iostream>
#include <vector>
using namespace std;

void H(vector<vector<int>> &V, int a, int b, int r0, int c0, int rn, int cn)
{
    if (a == 0)
    {
        V[r0][c0] = b;
        return;
    }

    int rMid = (r0 + rn) / 2;
    int cMid = (c0 + cn) / 2;

    H(V, a - 1, b, r0, c0, rMid, cMid);
    H(V, a - 1, b - 1, r0, cMid, rMid, cn);
    H(V, a - 1, b + 1, rMid, c0, rn, cMid);
    H(V, a - 1, b, rMid, cMid, rn, cn);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    vector<vector<int>> V(1 << a, vector<int>(1 << a));

    H(V, a, b, 0, 0, 1 << a, 1 << a);

    for (auto &row : V)
    {
        for (auto &e : row)
            cout << e << " ";
        cout << "\n";
    }

    return 0;
}