#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> T(k);
    vector<pair<int, int>> PH(m);

    for (int i = 0; i < m; i++)
        cin >> PH[i].first;

    for (int i = 0; i < m; i++)
        cin >> PH[i].second;

    for (int i = 0; i < k; i++)
        cin >> T[i];

    sort(PH.begin(), PH.end());

    for (int tpos : T)
    {
        int st = lower_bound(PH.begin(), PH.end(), make_pair(tpos - w, 0)) - PH.begin();
        int en = lower_bound(PH.begin(), PH.end(), make_pair(tpos + w + 1, 0)) - PH.begin();

        if (st == en)
            continue;

        int Mx = 0, it = st;
        while (st < en)
        {
            if (Mx < PH[st].second)
                Mx = PH[st].second, it = st;
            st++;
        }

        PH[it].second = max(0, PH[it].second - 1);
    }

    int sum = 0;
    for (auto [pos, hp] : PH)
        sum += hp;
    cout << sum;

    return 0;
}
