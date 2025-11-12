#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> V, Array;
    int n, q, sum = 0;

    cin >> n >> q;
    while (n--)
    {
        int x, c;
        cin >> x >> c;
        if (c > 0)
            V.push_back({x, c});
    }

    sort(V.begin(), V.end());

    int idx = 1;
    for (auto &[x, c] : V)
    {
        Array.push_back({idx, x});
        idx += c;
        sum += c;
    }

    while (q--)
    {
        int idx;
        cin >> idx;
        auto val = make_pair(idx, INT_MAX);
        auto fnd = --upper_bound(Array.begin(), Array.end(), val);
        cout << fnd->second << "\n";
    }

    return 0;
}