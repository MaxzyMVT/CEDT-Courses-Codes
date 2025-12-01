#include <iostream>
using namespace std;

#define MOD 100'000'007
#define m(a, b) (a + b) % MOD

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _X = 1, _0 = 1, _X_ = 0, ans = 3, n;
    cin >> n;

    while (--n)
    {
        int next[3];

        next[0] = m((_0 - _X_ + MOD) % MOD, _X);
        next[1] = ans;
        next[2] = _X;

        _X = next[0];
        _0 = next[1];
        _X_ = next[2];

        ans = m(m(_X, _X), _0);
    }

    cout << ans;

    return 0;
}