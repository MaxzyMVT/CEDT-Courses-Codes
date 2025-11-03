#include <iostream>
#include <numeric>
#include <set>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;

    set<int> A, B;

    for (int i = 1; i <= n; i++)
        A.insert(i);

    for (int i = 1; i <= n; i++)
        cin >> a, B.insert(a);

    cout << (A == B ? "YES" : "NO");

    return 0;
}