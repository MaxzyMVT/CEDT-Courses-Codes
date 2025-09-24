#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool warpable(int st, int en, vector<int> &current_route, map<int, vector<int>> &warps, set<vector<int>> &routes)
{
    if (st == en)
    {
        current_route.push_back(en);
        routes.insert(current_route);
        current_route.pop_back();
        return true;
    }

    if (warps[st].empty())
        return false;

    bool isReached = false;
    current_route.push_back(st);

    for (auto des : warps[st])
    {
        if (warpable(des, en, current_route, warps, routes))
        {
            isReached = true;
        }
    }
    current_route.pop_back();

    return isReached;
}

int main()
{
    int n, st, en;
    map<int, vector<int>> warps;
    set<vector<int>> routes;
    vector<int> current_route;

    cin >> n >> st >> en;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        warps[a].push_back(b);
    }

    if (warpable(st, en, current_route, warps, routes))
    {
        for (auto &route : routes)
        {
            int siz = route.size();
            for (int i = 0; i < siz; i++)
            {
                if (i != 0)
                    cout << " -> ";
                cout << route[i];
            }
            cout << "\n";
        }
    }
    else
        cout << "no\n";

    return 0;
}