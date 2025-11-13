#include <iostream>
#include <vector>
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

    int t;
    cin >> t;

    while (t--)
    {
        int n, e;
        cin >> n >> e;

        vector<int> heads(n);
        iota(heads.begin(), heads.end(), 0);

        bool hasCycle = false;
        while (e--)
        {
            int a, b;
            cin >> a >> b;

            if (hasCycle)
                continue;

            if (findHead(a, heads) == findHead(b, heads))
                hasCycle = true;
            else
                connec(a, b, heads);
        }

        cout << (hasCycle ? "YES\n" : "NO\n");
    }

    return 0;
}