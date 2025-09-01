#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, cnt = 0;
    int road[100], L[100] = {}, R[100] = {};

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> road[i];
        L[i] = max(L[i - 1], road[i]);
    }

    for (int i = n; i >= 1; i--)
    {
        R[i] = max(R[i + 1], road[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        cnt += min(L[i], R[i]) - road[i];
    }

    cout << cnt;

    return 0;
}