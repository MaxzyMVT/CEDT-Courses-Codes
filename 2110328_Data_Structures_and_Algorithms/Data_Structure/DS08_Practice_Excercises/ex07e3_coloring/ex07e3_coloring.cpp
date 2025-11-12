#include <iostream>
#include <vector>

using namespace std;

bool canColor(int a, vector<vector<int>> &G, int num, vector<int> &color)
{
    if (a == -1)
        return true;
    for (int clr = 1; clr <= num; clr++)
    {
        bool aval = true;
        for (int b : G[a])
            if (color[b] == clr)
            {
                aval = false;
                break;
            }

        if (!aval)
            continue;

        color[a] = clr;
        if (canColor(a - 1, G, num, color))
            return true;
        color[a] = 0;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, ans;
    cin >> n >> e;

    vector<vector<int>> G(n, vector<int>());

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int num = 1; num <= n; num++)
    {
        vector<bool> valid(n, true);
        vector<int> color(n);

        if (canColor(n - 1, G, num, color))
        {
            ans = num;
            break;
        }
    }

    cout << ans;

    return 0;
}