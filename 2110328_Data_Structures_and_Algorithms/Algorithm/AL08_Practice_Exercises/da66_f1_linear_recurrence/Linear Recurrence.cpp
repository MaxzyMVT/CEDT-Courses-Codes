#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MOD 32717

int R(int n, int k, vector<int> &c, vector<int> &a, map<int, int> &mem)
{
    if (n < k)
        return a[n] % MOD;
    if (mem.find(n) != mem.end())
        return mem[n];

    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum = (sum + (c[i] * R(n - i, k, c, a, mem)) % MOD) % MOD;

    mem[n] = sum;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> c(k + 1);
    vector<int> a(k);

    for (int i = 1; i <= k; i++)
        cin >> c[i], c[i] %= MOD;

    for (int i = 0; i < k; i++)
        cin >> a[i], a[i] %= MOD;

    map<int, int> mem;
    cout << R(n, k, c, a, mem);

    return 0;
}