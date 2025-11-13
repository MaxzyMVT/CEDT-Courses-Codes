#include <iostream>
#include <set>
#include <map>
using namespace std;

#define MOD 1'000'003

int choco(int n, set<int> &nums, map<int, int> &mem)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (mem.find(n) != mem.end())
        return mem[n];

    int ans = 0;
    for (auto e : nums)
    {
        ans = (ans + choco(n - e, nums, mem) % MOD) % MOD;
    }
    mem[n] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a;
    cin >> n >> k;

    set<int> S;
    while (k--)
        cin >> a, S.insert(a);

    map<int, int> mem;
    cout << choco(n, S, mem);

    return 0;
}