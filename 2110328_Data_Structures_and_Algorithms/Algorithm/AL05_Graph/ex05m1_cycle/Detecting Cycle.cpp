#include <iostream>
#include <vector>
using namespace std;

int findHead(int u, vector<int> &heads)
{
    if (heads[u] == -1)
        return u;
    return heads[u] = findHead(heads[u], heads);
}

bool connec(int u, int v, vector<int> &heads)
{
    int uH = findHead(u, heads);
    int vH = findHead(v, heads);
    heads[vH] = uH;
    return uH == vH;
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

        vector<int> heads(n, -1);

        bool hasCycle = false;
        while (e--)
        {
            int a, b;
            cin >> a >> b;

            if (hasCycle)
                continue;

            hasCycle = connec(a, b, heads);
        }

        cout << (hasCycle ? "YES\n" : "NO\n");
    }

    return 0;
}