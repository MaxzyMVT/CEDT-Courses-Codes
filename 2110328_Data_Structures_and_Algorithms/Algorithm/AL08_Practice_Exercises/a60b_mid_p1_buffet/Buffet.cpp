#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f, w, n;
    cin >> f >> w >> n;

    vector<int> V(f);
    for (int i = 0; i < f; i++)
        cin >> V[i];

    sort(V.begin(), V.end());

    int siz = w * 2, cnt = 0;

    auto it = V.begin();
    while (it != V.end())
    {
        it = upper_bound(it, V.end(), *it + siz);
        cnt++;
    }

    cout << cnt;

    return 0;
}
