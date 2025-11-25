#include <iostream>
#include <vector>
using namespace std;

#define MOD 100'000'007

int TableNo11(int n);
int TableNo11_rec(int n, vector<int> &mem, vector<int> &mem2);
int TableNo11End1(int n, vector<int> &mem, vector<int> &mem2);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << TableNo11(n);

    return 0;
}

int TableNo11End1(int n, vector<int> &mem, vector<int> &mem2)
{
    if (n == 1)
        return 1;
    if (mem2[n])
        return mem2[n];

    // 10 doesn't follow by 10 | 01 doesn't follow by 01
    return mem2[n] = (TableNo11_rec(n - 1, mem, mem2) - TableNo11End1(n - 1, mem, mem2) + MOD) % MOD;
}

int TableNo11_rec(int n, vector<int> &mem, vector<int> &mem2)
{
    if (n == 0)
        return 1;
    if (mem[n])
        return mem[n];

    int _00 = TableNo11_rec(n - 1, mem, mem2);         // End with 00
    int _XX = (2 * TableNo11End1(n, mem, mem2)) % MOD; // End with 01 or 10

    return mem[n] = (_00 + _XX) % MOD;
}

int TableNo11(int n)
{
    vector<int> mem(n + 1);
    vector<int> mem2(n + 1);
    return TableNo11_rec(n, mem, mem2);
}