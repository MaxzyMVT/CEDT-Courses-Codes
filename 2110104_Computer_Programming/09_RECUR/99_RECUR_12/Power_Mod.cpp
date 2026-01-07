#include <iostream>
using namespace std;

int pow_mod(int a, int k, int m)
{
    if (k == 0)
        return 1;
    int ans = pow_mod(a, k / 2, m) % m;
    ans = (ans * ans) % m;
    if (k % 2 == 1)
        return (ans * a % m) % m;
    return ans;
}

int main()
{
    int a, k, m;
    cin >> a >> k >> m;
    cout << pow_mod(a, k, m);
}
