#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool warpable(int st, int en, map<int, vector<int>> &warps)
{
    if (warps[st].empty())
        return false;
    for (auto des : warps[st])
    {
        if (des == en || warpable(des, en, warps))
            return true;
    }
    return false;
}

int main()
{
    int n, st, en;
    map<int, vector<int>> warps;

    cin >> n >> st >> en;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        warps[a].push_back(b);
    }

    cout << (warpable(st, en, warps) ? "yes" : "no");

    return 0;
}