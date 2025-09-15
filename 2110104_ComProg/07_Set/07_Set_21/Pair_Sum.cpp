#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int k, a, cnt = 0;
    set<int> S;
    cin >> k;

    while (cin >> a)
        S.insert(a);

    for (int e : S)
    {
        if (S.find(k - e) != S.end())
            cnt++;
    }

    cout << cnt / 2;

    return 0;
}