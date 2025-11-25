#include <iostream>
using namespace std;

#define MOD 100'000'007

int TableNo11NotOO(int n)
{
    if (n == 0)
        return 1;
}

int TableNo11(int n)
{
    if (n == 0)
        return 1;

    int _00 = TableNo11(n - 1);
    int _XX = (2 * TableNo11NotOO(n - 1)) % MOD;

    return (_00 + _XX) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << TableNo11(n);

    return 0;
}