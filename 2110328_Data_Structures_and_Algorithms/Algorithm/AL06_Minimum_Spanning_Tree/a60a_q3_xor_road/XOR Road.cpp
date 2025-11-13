#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

#define ull unsigned long long
#define edge tuple<ull, int, int>

int findHead(int u, vector<int> &heads)
{
    if (heads[u] == u)
        return u;
    return heads[u] = findHead(heads[u], heads);
}

bool connec(int u, int v, vector<int> &heads)
{
    int a = findHead(u, heads);
    int b = findHead(v, heads);
    if (a == b)
        return false;
    heads[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<edge> E(n);
    vector<int> id(n);
    vector<int> heads(n);

    for (int u = 0; u < n; u++)
    {
        int a;
        cin >> a;
        id[u] = a;
        heads[u] = u;
    }

    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            ull w = id[u] ^ id[v];
            E.push_back({w, u, v});
        }
    }

    sort(E.begin(), E.end(), greater<edge>());

    ull sum = 0;
    int cnt = 0;
    for (auto [w, u, v] : E)
    {
        if (connec(u, v, heads))
        {
            sum += w;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }

    cout << sum;

    return 0;
}