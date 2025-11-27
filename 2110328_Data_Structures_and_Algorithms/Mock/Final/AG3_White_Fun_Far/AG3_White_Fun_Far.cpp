#include <iostream>
using namespace std;

#define MOD 100'000'007
#define m(a, b) ((a % MOD + b % MOD) % MOD)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int C = 1, E = 1, D = 1, T = 1, ans = 4;

    while (--n)
    {
        int next[4];
        next[0] = m(D, T);
        next[1] = m(C, T);
        next[2] = E;
        next[3] = C;

        C = next[0];
        E = next[1];
        D = next[2];
        T = next[3];

        ans = m(m(m(C, E), D), T);
    }

    cout << ans;

    return 0;
}