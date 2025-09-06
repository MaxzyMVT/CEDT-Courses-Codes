#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, n, cnt = 0;
    vector<int> V, Unique;

    while (cin >> a)
        V.push_back(a);

    sort(V.begin(), V.end());

    V.push_back(V.back() + 1);

    n = V.size();
    for (int i = 1; i < n; i++)
    {
        if (V[i] != V[i - 1])
        {
            cnt++;
            if (cnt <= 10)
                Unique.push_back(V[i - 1]);
        }
    }

    cout << cnt << "\n";
    for (int x : Unique)
        cout << x << " ";
}