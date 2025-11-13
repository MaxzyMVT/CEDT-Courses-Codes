#include <iostream>
#include <map>
#include <utility>
using namespace std;

int C(int n, int k, map<pair<int, int>, int> &mem)
{
    if (n == k || k == 0)
        return 1;
    if (mem.find({n, k}) != mem.end())
        return mem[{n, k}];
    mem[{n, k}] = C(n - 1, k - 1, mem) + C(n - 1, k, mem);
    return mem[{n, k}];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    map<pair<int, int>, int> mem;
    cout << C(n, k, mem);

    return 0;
}