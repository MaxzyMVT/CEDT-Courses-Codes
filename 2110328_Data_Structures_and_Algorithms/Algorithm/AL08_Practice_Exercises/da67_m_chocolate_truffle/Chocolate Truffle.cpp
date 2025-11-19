#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, q, a, b;
    cin >> n >> m >> k;

    ll siz = n * m;

    vector<ll> V(k);

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--, b--;
        V[i] = a * m + b;
    }

    sort(V.begin(), V.end());

    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        a--, b--;
        ll st = a * m + b;

        int pos = lower_bound(V.begin(), V.end(), st) - V.begin();

        if (pos == k)
            pos = 0;

        cout << (V[pos] % siz - st + siz) % siz << "\n";
    }

    return 0;
}
