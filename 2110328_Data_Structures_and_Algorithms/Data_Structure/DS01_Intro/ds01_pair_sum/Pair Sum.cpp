#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> V;

    int n, m, a;
    cin >> n >> m;
    while (n--)
    {
        cin >> a;
        V.push_back(a);
    }

    sort(V.begin(), V.end());

    while (m--)
    {
        cin >> a;

        auto beg = V.begin();
        auto end = V.end() - 1;
        bool Ok = false;

        while (beg != end)
        {
            int sum = *beg + *end;
            if (sum == a)
            {
                Ok = true;
                break;
            }

            if (sum > a)
                --end;
            else
                ++beg;
        }

        cout << (Ok ? "YES\n" : "NO\n");
    }

    return 0;
}
