#include <iostream>
using namespace std;

#define MOD 100'000'007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p0 = 1, pp0 = 1;
    int px = 2, ppx = 0, pppx = 0;
    int n = 1, ans = 3;

    cin >> n;
    while (--n)
    {
        int p0_nx = ans;
        int px_nx = (((4 * pp0) % MOD + (2 * ppx) % MOD) % MOD - pppx + MOD) % MOD;

        pppx = ppx;
        pp0 = p0;
        ppx = px;
        p0 = p0_nx;
        px = px_nx;

        ans = (p0 + px) % MOD;
    }

    cout << ans;

    return 0;
}