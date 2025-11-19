#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n;

    vector<pair<int, int>> V(n);
    vector<int> S(n);

    for (int i = 0; i < n; i++)
        cin >> S[i];
    for (int i = 0; i < n; i++)
        cin >> a, V[i] = {a, S[i]};

    sort(V.begin(), V.end());

    int cnt = 1, last = 0;
    for (int i = 1; i < n; i++)
        if (V[i].second >= V[last].first)
            cnt++, last = i;
    cout << cnt;

    return 0;
}
