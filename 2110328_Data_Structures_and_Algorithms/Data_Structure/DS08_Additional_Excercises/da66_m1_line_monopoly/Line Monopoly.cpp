#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int, int>> R;

    int n;
    cin >> n;

    while (n--)
    {
        int com;
        cin >> com;
        if (com == 2)
        {
            cout << R.size() << "\n";
            continue;
        }

        int a, b;
        cin >> a >> b;

        auto fnd = R.lower_bound(make_pair(a - 1, 0));

        for (auto it = fnd; it != R.end();)
        {
            auto [q, p] = *it;

            // If both ranges are intersect
            if (q >= b + 1 && p <= b + 1 || p <= a - 1 && q >= a - 1 || p >= a && q <= b)
            {
                a = min(a, p), b = max(q, b);
                it = R.erase(it);
            }
            else
                break;
        }
        R.insert({b, a});
    }

    return 0;
}