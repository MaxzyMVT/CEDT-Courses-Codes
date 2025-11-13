#include <iostream>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int findHead(int u, vector<int> &heads)
{
    if (heads[u] == u)
        return u;
    return heads[u] = findHead(heads[u], heads);
}

void connec(int u, int v, vector<int> &heads)
{
    int uH = findHead(u, heads);
    int vH = findHead(v, heads);
    heads[vH] = uH;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    set<int> distinct_component;
    vector<int> heads(n + 1);
    iota(heads.begin(), heads.end(), 0);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        connec(a, b, heads);
    }

    for (int i = 1; i <= n; i++)
        distinct_component.insert(findHead(i, heads));

    cout << distinct_component.size();

    return 0;
}