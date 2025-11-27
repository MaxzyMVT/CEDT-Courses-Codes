#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <string>
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define Edge tuple<ll, int, bool> // Distance, End Point, isRed
#define Walk tuple<ll, int>       // Distance, End Point

void printperm(int pos, string ans, vector<ll> &disBlue, vector<ll> &disRed, vector<ll> &disMin, vector<int> &shrine)
{
    if (pos == ans.size())
    {
        cout << ans << "\n";
        return;
    }

    int sh = shrine[pos + 1];
    if (disBlue[sh] == disMin[sh])
    {
        ans[pos] = '0';
        printperm(pos + 1, ans, disBlue, disRed, disMin, shrine);
    }
    if (disRed[sh] == disMin[sh])
    {
        ans[pos] = '1';
        printperm(pos + 1, ans, disBlue, disRed, disMin, shrine);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, a, Final;
    cin >> n >> m >> k >> Final;

    vector<vector<Edge>> V(n + 1);
    vector<ll> disBlue(n + 1, INF);
    vector<ll> disRed(n + 1, INF);
    vector<ll> disMin(n + 1, INF);
    vector<int> shrine(k + 1);

    while (m--)
    {
        int u, v, w;
        bool t;

        cin >> u >> v >> w >> t;
        V[v].push_back({w, u, t});
    }

    for (int i = 1; i <= k; i++)
        cin >> shrine[i];

    priority_queue<Walk, vector<Walk>, greater<Walk>> pq;
    vector<bool> mark(n + 1);

    pq.push({0, Final});
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        mark[u] = true;
        disBlue[u] = w;

        for (auto [w_nx, v, isRed] : V[u])
        {
            if (!isRed && !mark[v])
                pq.push({w + w_nx, v});
        }
    }

    mark.assign(n + 1, false);
    pq.push({0, Final});
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        mark[u] = true;
        disRed[u] = w;

        for (auto [w_nx, v, isRed] : V[u])
        {
            if (isRed && !mark[v])
                pq.push({w + w_nx, v});
        }
    }

    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        int sh = shrine[i];
        disMin[sh] = min(disBlue[sh], disRed[sh]);
        sum += disMin[sh];
    }

    cout << sum << "\n";

    string ans(k, '0');
    printperm(0, ans, disBlue, disRed, disMin, shrine);

    return 0;
}