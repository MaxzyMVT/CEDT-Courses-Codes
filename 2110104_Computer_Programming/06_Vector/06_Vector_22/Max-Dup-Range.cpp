#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> V;
    vector<tuple<int, int, int>> dupes;
    int a, n, pos = 0, Mx = 0;

    while (cin >> a)
        V.push_back(a);

    V.push_back(V.back() + 1);

    n = V.size();
    for (int i = 1; i < n; i++)
    {
        if (V[i] != V[i - 1])
        {
            if (i - pos > Mx)
            {
                Mx = i - pos;
                dupes.clear();
            }

            if (Mx == i - pos)
                dupes.push_back({V[i - 1], pos, i});

            pos = i;
        }
    }

    sort(dupes.begin(), dupes.end());

    n = dupes.size();
    for (int i = 0; i < n; i++)
    {
        cout << get<0>(dupes[i]) << " --> x[ " << get<1>(dupes[i]) << " : " << get<2>(dupes[i]) << " ]\n";
    }

    return 0;
}