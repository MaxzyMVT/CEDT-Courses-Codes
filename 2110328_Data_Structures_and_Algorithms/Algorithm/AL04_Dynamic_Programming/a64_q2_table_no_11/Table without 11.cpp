#include <iostream>
using namespace std;

#define MOD 100'000'007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _00 = 0, _01 = 0, _10 = 0, n;
    cin >> n;

    int ans = 1;

    while (n--)
    {
        _00 = ans;
        _01 = (ans + (MOD - _10)) % MOD;
        _10 = _01; // since _10 always equal to _01
        ans = (((_00 + _01) % MOD) + _10) % MOD;
    }

    cout << ans;

    return 0;
}
/*
n = 1 : 0-0 = 1, 0-1 = 1, 1-0 = 1 | 3
n = 2 : 0-0 = 3, 0-1 = 2, 1-0 = 2 | 7
n = 3 : 0-0 = 7, 0-1 = 5, 1-0 = 5 | 17
*/