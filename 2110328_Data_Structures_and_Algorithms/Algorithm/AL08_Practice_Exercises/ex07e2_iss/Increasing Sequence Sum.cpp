#include <iostream>
#include <vector>
using namespace std;

int ISSrec(int st, int sum, int n, vector<vector<int>> &mem)
{
    if (sum > n)
        return 0;
    if (sum == n)
        return 1;
    if (mem[st][sum] != -1)
        return mem[st][sum];

    int ans = 0;
    for (int i = st; i <= n - sum; i++)
        ans += ISSrec(i, sum + i, n, mem);
    return mem[st][sum] = ans;
}

int ISS(int n)
{
    vector<vector<int>> mem(n, vector<int>(n, -1));
    return ISSrec(1, 0, n, mem);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << ISS(n);

    return 0;
}
