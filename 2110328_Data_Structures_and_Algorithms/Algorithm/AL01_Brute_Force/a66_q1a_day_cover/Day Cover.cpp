#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void Combination(int pos, int used, vector<int> days, vector<pair<int, vector<int>>> &vacants, int &Mn)
{
    if (used >= Mn)
        return;

    if (pos == vacants.size())
    {
        int cnt = 0;
        for (int d_cnt : days)
            if (d_cnt > 0)
                cnt++;

        if (cnt < days.size())
            return;
        Mn = min(Mn, used);
        return;
    }

    vector<int> tmp_days = days;
    for (int i = pos; i < vacants.size(); i++)
    {
        for (int d : vacants[i].second)
            tmp_days[d]++;
    }

    bool isCoverable = true;
    for (int cnt : tmp_days)
    {
        if (cnt == 0)
            isCoverable = false;
    }

    if (!isCoverable)
        return;

    Combination(pos + 1, used, days, vacants, Mn);

    for (int d : vacants[pos].second)
        days[d]++;
    Combination(pos + 1, used + 1, days, vacants, Mn);
}

int minCombination(int n, int m, vector<pair<int, vector<int>>> &vacants)
{
    vector<int> days(n);
    int Mn = m;
    Combination(0, 0, days, vacants, Mn);
    return Mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, vector<int>>> vacants(m);

    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        vacants[i].first = -p;
        while (p--)
        {
            int d;
            cin >> d;
            vacants[i].second.push_back(d - 1);
        }
    }

    sort(vacants.begin(), vacants.end());
    cout << minCombination(n, m, vacants);

    return 0;
}
